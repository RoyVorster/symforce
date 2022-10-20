# -----------------------------------------------------------------------------
# This file was autogenerated by symforce from template:
#     cam_package/CLASS.py.jinja
# Do NOT modify by hand.
# -----------------------------------------------------------------------------

import typing as T

import numpy

from .ops import spherical_camera_cal as ops


class SphericalCameraCal(object):
    """
    Autogenerated Python implementation of <class 'symforce.cam.spherical_camera_cal.SphericalCameraCal'>.

    Kannala-Brandt camera model, where radial distortion is modeled relative to the 3D angle theta
    off the optical axis as opposed to radius within the image plane (i.e. ATANCamera)

    I.e. the radius in the image plane as a function of the angle theta from the camera z-axis is
    assumed to be given by:

        r(theta) = theta + d[0] * theta^3 + d[1] * theta^5 + d[2] * theta^7 + d[3] * theta^9

    With no tangential coefficients, this model is over-parameterized in that we may scale all the
    distortion coefficients by a constant, and the focal length by the inverse of that constant. To
    fix this issue, we peg the first coefficient at 1. So while the distortion dimension is '4',
    the actual total number of coeffs is 5.

    Additionally, the storage for this class includes the critical theta, the maximum angle from the
    optical axis where projection is invertible; although the critical theta is a function of the
    other parameters, this function requires polynomial root finding, so it should be computed
    externally at runtime and set to the computed value.

    Paper:
    A generic camera model and calibration method for conventional, wide-angle, and fish-eye lenses
    Kannala, Juho; Brandt, Sami S.
    PAMI 2006

    This is the simpler "P9" model without any non-radially-symmetric distortion params.

    The storage for this class is:
    [ fx fy cx cy critical_theta d0 d1 d2 d3 ]
    """

    __slots__ = ["data"]

    # This is because of an issue where mypy doesn't recognize attributes defined in __slots__
    # See https://github.com/python/mypy/issues/5941
    if T.TYPE_CHECKING:
        data = []  # type: T.List[float]

    def __init__(self, focal_length, principal_point, critical_theta, distortion_coeffs):
        # type: (T.Union[T.Sequence[float], numpy.ndarray], T.Union[T.Sequence[float], numpy.ndarray], float, T.Union[T.Sequence[float], numpy.ndarray]) -> None
        self.data = []
        if isinstance(focal_length, numpy.ndarray):
            if focal_length.shape in [(2, 1), (1, 2)]:
                focal_length = focal_length.flatten()
            elif focal_length.shape != (2,):
                raise IndexError(
                    "Expected focal_length to be a vector of length 2; instead had shape {}".format(
                        focal_length.shape
                    )
                )
        elif len(focal_length) != 2:
            raise IndexError(
                "Expected focal_length to be a sequence of length 2, was instead length {}.".format(
                    len(focal_length)
                )
            )
        if isinstance(principal_point, numpy.ndarray):
            if principal_point.shape in [(2, 1), (1, 2)]:
                principal_point = principal_point.flatten()
            elif principal_point.shape != (2,):
                raise IndexError(
                    "Expected principal_point to be a vector of length 2; instead had shape {}".format(
                        principal_point.shape
                    )
                )
        elif len(principal_point) != 2:
            raise IndexError(
                "Expected principal_point to be a sequence of length 2, was instead length {}.".format(
                    len(principal_point)
                )
            )
        if isinstance(distortion_coeffs, numpy.ndarray):
            if distortion_coeffs.shape in [(4, 1), (1, 4)]:
                distortion_coeffs = distortion_coeffs.flatten()
            elif distortion_coeffs.shape != (4,):
                raise IndexError(
                    "Expected distortion_coeffs to be a vector of length 4; instead had shape {}".format(
                        distortion_coeffs.shape
                    )
                )
        elif len(distortion_coeffs) != 4:
            raise IndexError(
                "Expected distortion_coeffs to be a sequence of length 4, was instead length {}.".format(
                    len(distortion_coeffs)
                )
            )

        self.data.extend(focal_length)
        self.data.extend(principal_point)
        self.data.append(critical_theta)
        self.data.extend(distortion_coeffs)

    def __repr__(self):
        # type: () -> str
        return "<{} {}>".format(self.__class__.__name__, self.data)

    # --------------------------------------------------------------------------
    # CameraOps
    # --------------------------------------------------------------------------

    def focal_length(self):
        # type: (SphericalCameraCal) -> numpy.ndarray
        """
        Return the focal length.
        """

        return ops.CameraOps.focal_length(self)

    def principal_point(self):
        # type: (SphericalCameraCal) -> numpy.ndarray
        """
        Return the principal point.
        """

        return ops.CameraOps.principal_point(self)

    def pixel_from_camera_point(self, point, epsilon):
        # type: (SphericalCameraCal, numpy.ndarray, float) -> T.Tuple[numpy.ndarray, float]
        """
        Project a 3D point in the camera frame into 2D pixel coordinates.

        Return:
            pixel: (x, y) coordinate in pixels if valid
            is_valid: 1 if the operation is within bounds else 0
        """

        return ops.CameraOps.pixel_from_camera_point(self, point, epsilon)

    def pixel_from_camera_point_with_jacobians(self, point, epsilon):
        # type: (SphericalCameraCal, numpy.ndarray, float) -> T.Tuple[numpy.ndarray, float, numpy.ndarray, numpy.ndarray]
        """
        Project a 3D point in the camera frame into 2D pixel coordinates.

        Return:
            pixel: (x, y) coordinate in pixels if valid
            is_valid: 1 if the operation is within bounds else 0
            pixel_D_cal: Derivative of pixel with respect to intrinsic calibration parameters
            pixel_D_point: Derivative of pixel with respect to point
        """

        return ops.CameraOps.pixel_from_camera_point_with_jacobians(self, point, epsilon)

    # --------------------------------------------------------------------------
    # StorageOps concept
    # --------------------------------------------------------------------------

    @staticmethod
    def storage_dim():
        # type: () -> int
        return 9

    def to_storage(self):
        # type: () -> T.List[float]
        return list(self.data)

    @classmethod
    def from_storage(cls, vec):
        # type: (T.Sequence[float]) -> SphericalCameraCal
        instance = cls.__new__(cls)

        if isinstance(vec, list):
            instance.data = vec
        else:
            instance.data = list(vec)

        if len(vec) != cls.storage_dim():
            raise ValueError(
                "{} has storage dim {}, got {}.".format(cls.__name__, cls.storage_dim(), len(vec))
            )

        return instance

    # --------------------------------------------------------------------------
    # LieGroupOps concept
    # --------------------------------------------------------------------------

    @staticmethod
    def tangent_dim():
        # type: () -> int
        return 9

    @classmethod
    def from_tangent(cls, vec, epsilon=1e-8):
        # type: (numpy.ndarray, float) -> SphericalCameraCal
        if len(vec) != cls.tangent_dim():
            raise ValueError(
                "Vector dimension ({}) not equal to tangent space dimension ({}).".format(
                    len(vec), cls.tangent_dim()
                )
            )
        return ops.LieGroupOps.from_tangent(vec, epsilon)

    def to_tangent(self, epsilon=1e-8):
        # type: (float) -> numpy.ndarray
        return ops.LieGroupOps.to_tangent(self, epsilon)

    def retract(self, vec, epsilon=1e-8):
        # type: (numpy.ndarray, float) -> SphericalCameraCal
        if len(vec) != self.tangent_dim():
            raise ValueError(
                "Vector dimension ({}) not equal to tangent space dimension ({}).".format(
                    len(vec), self.tangent_dim()
                )
            )
        return ops.LieGroupOps.retract(self, vec, epsilon)

    def local_coordinates(self, b, epsilon=1e-8):
        # type: (SphericalCameraCal, float) -> numpy.ndarray
        return ops.LieGroupOps.local_coordinates(self, b, epsilon)

    # --------------------------------------------------------------------------
    # General Helpers
    # --------------------------------------------------------------------------
    def __eq__(self, other):
        # type: (T.Any) -> bool
        if isinstance(other, SphericalCameraCal):
            return self.data == other.data
        else:
            return False
