import logging
import math
import os
import sys
import tempfile

from symforce import logger
from symforce import python_util
from symforce import types as T
from symforce import sympy as sm
from symforce import geo
from symforce import cam
from symforce.test_util import TestCase
from symforce.codegen import Codegen
from symforce.codegen import CodegenMode
from symforce.codegen import codegen_util
from symforce.codegen import cam_package_codegen


SYMFORCE_DIR = os.path.dirname(os.path.dirname(__file__))
TEST_DATA_DIR = os.path.join(SYMFORCE_DIR, "test", "symforce_function_codegen_test_data")

# For testing generation of functions that take camera objects as arguments
def pixel_to_ray_and_back(pixel, cam, epsilon=0):
    # type: (geo.Matrix, cam.LinearCameraCal, T.Scalar) -> geo.Matrix
    """
    Transform a given pixel into a ray and project the ray back to
    pixel coordinates. Input and output should match.
    """
    camera_ray, _ = cam.camera_ray_from_pixel(pixel, epsilon)
    reprojected_pixel, _ = cam.pixel_from_camera_point(camera_ray, epsilon)
    return reprojected_pixel


class SymforceCamCodegenTest(TestCase):
    """
    Test symforce.codegen.cam_package_codegen.
    """

    def generate_example_function(self, output_dir):
        # type: (str) -> None

        # Create the specification
        my_func = Codegen.function(
            name="PixelToRayAndBack",
            func=pixel_to_ray_and_back,
            input_types=[geo.V2, cam.LinearCameraCal, sm.Symbol],
            mode=CodegenMode.CPP,
        )
        function_path = os.path.join(output_dir, "symforce_function_codegen_test_data")
        cpp_data = my_func.generate_function(function_path)

        expected_code_file = os.path.join(TEST_DATA_DIR, "pixel_to_ray_and_back.h")
        output_function = os.path.join(function_path, "pixel_to_ray_and_back.h")
        self.compare_or_update_file(expected_code_file, output_function)

    def test_codegen_cpp(self):
        # type: () -> None
        """
        Test C++ code generation from camera types.
        """
        output_dir = tempfile.mkdtemp(prefix="sf_cam_package_codegen_test_", dir="/tmp")
        logger.debug("Creating temp directory: {}".format(output_dir))

        try:
            # Generate cam package + tests
            cam_package_codegen.generate(mode=CodegenMode.CPP, output_dir=output_dir)

            self.compare_or_update_directory(
                actual_dir=os.path.join(output_dir, "cam"),
                expected_dir=os.path.join(SYMFORCE_DIR, "gen", "cpp", "cam"),
            )

            # Compare against the checked-in tests
            for test_name in (
                "cam_package_cpp_test.cc",
                "cam_function_codegen_cpp_test.cc",
            ):
                expected_code_file = os.path.join(SYMFORCE_DIR, "test", test_name)
                generated_code_file = os.path.join(output_dir, "example", test_name)
                self.compare_or_update_file(expected_code_file, generated_code_file)

            # Generate function that uses camera object as argument
            self.generate_example_function(output_dir)

            # Compile and run the test
            if not self.UPDATE:
                example_dir = os.path.join(output_dir, "example")
                TestCase.compile_and_run_cpp(
                    example_dir, ("cam_package_cpp_test", "cam_function_codegen_cpp_test")
                )

        finally:
            if logger.level != logging.DEBUG:
                python_util.remove_if_exists(output_dir)


if __name__ == "__main__":
    TestCase.main()