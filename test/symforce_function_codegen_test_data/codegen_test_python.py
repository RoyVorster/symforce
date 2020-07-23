import numpy

import codegen_test_python_ns

def codegen_test_python(x, y, rot, constants, states):
    """
    This function was autogenerated. Do not modify by hand.

    Arg type(s): Symbol, Symbol, Rot3, Values, Values
    Return type(s): Add, Add

    """
    # Input arrays
    _rot = rot.data
    _constants = constants.to_storage()
    _states = states.to_storage()

    # Intermediate terms
    _tmp0 = x**2

    # Output terms
    _foo = _rot[3] + _tmp0
    _bar = _constants[0] + _tmp0 + numpy.sin(y)
    return _foo,  _bar