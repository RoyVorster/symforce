# -----------------------------------------------------------------------------
# This file was autogenerated by symforce. Do NOT modify by hand.
# -----------------------------------------------------------------------------
import numpy as np
import typing as T

from .ops import rot2 as ops


class Rot2(object):
    """"
    Autogenerated Python implementation of <class 'symforce.geo.rot2.Rot2'>.

    Group of two-dimensional orthogonal matrices with determinant +1, representing rotations
    in 2D space. Backed by a complex number.
    """

    __slots__ = ["data"]

    def __repr__(self):
        # type: () -> str
        return "<{} {}>".format(self.__class__.__name__, self.data)

    # --------------------------------------------------------------------------
    # StorageOps concept
    # --------------------------------------------------------------------------

    @staticmethod
    def storage_dim():
        # type: () -> int
        return 2

    def to_storage(self):
        # type: () -> T.List[float]
        return list(self.data)

    @classmethod
    def from_storage(cls, vec):
        # type: (T.Sequence[float]) -> Rot2
        instance = cls()

        if isinstance(vec, list):
            instance.data = vec
        else:
            instance.data = list(vec)

        assert len(vec) == cls.storage_dim(), "{} has storage dim {}, got {}.".format(
            cls.__name__, cls.storage_dim(), len(vec)
        )

        return instance

    # --------------------------------------------------------------------------
    # GroupOps concept
    # --------------------------------------------------------------------------

    @classmethod
    def identity(cls):
        # type: () -> Rot2
        return cls.from_storage(ops.GroupOps.identity())

    def inverse(self):
        # type: () -> Rot2
        return self.__class__.from_storage(ops.GroupOps.inverse(self))

    def compose(self, b):
        # type: (Rot2) -> Rot2
        return self.__class__.from_storage(ops.GroupOps.compose(self, b))

    def between(self, b):
        # type: (Rot2) -> Rot2
        return self.__class__.from_storage(ops.GroupOps.between(self, b))

    # --------------------------------------------------------------------------
    # LieGroupOps concept
    # --------------------------------------------------------------------------

    @staticmethod
    def tangent_dim():
        # type: () -> int
        return 1

    @classmethod
    def from_tangent(cls, vec, epsilon=1e-8):
        # type: (T.Sequence[float], float) -> Rot2
        assert len(vec) == cls.tangent_dim(), "{}, {}".format(len(vec), cls.tangent_dim())
        return cls.from_storage(ops.LieGroupOps.from_tangent(vec, epsilon))

    def to_tangent(self, epsilon=1e-8):
        # type: (float) -> T.List[float]
        return ops.LieGroupOps.to_tangent(self, epsilon)

    def retract(self, vec, epsilon=1e-8):
        # type: (T.Sequence[float], float) -> Rot2
        assert len(vec) == self.tangent_dim(), "{}, {}".format(len(vec), self.tangent_dim())
        return self.__class__.from_storage(ops.LieGroupOps.retract(self, vec, epsilon))

    def local_coordinates(self, b, epsilon=1e-8):
        # type: (Rot2, float) -> T.List[float]
        return ops.LieGroupOps.local_coordinates(self, b, epsilon)

    # --------------------------------------------------------------------------
    # General Helpers
    # --------------------------------------------------------------------------
    def __eq__(self, other):
        # type: (T.Any) -> bool
        if isinstance(other, Rot2):
            return self.data == other.data
        else:
            raise NotImplementedError("Cannot compare {} to {}".format(type(self), type(other)))

    def __mul__(self, other):
        # type: (Rot2) -> Rot2
        if isinstance(other, Rot2):
            return self.compose(other)
        elif isinstance(other, np.ndarray) and hasattr(self, "_apply_to_vector"):
            return self._apply_to_vector(other)
        else:
            raise NotImplementedError("Cannot compose {} with {}.".format(type(self), type(other)))

    # Included from "custom_methods/rot2.py.jinja":
    # --------------------------------------------------------------------------
    # Handwritten methods for Rot2
    # These will get included into the autogenerated class header.
    # --------------------------------------------------------------------------

    def __init__(self, z=None):
        # type: (T.Sequence[float]) -> None
        if z is None:
            self.data = ops.GroupOps.identity()
        else:
            assert len(z) == self.storage_dim()
            self.data = list(z)

    def to_rotation_matrix(self):
        # type: () -> np.ndarray
        real, imag = self.data

        return np.array([[real, -imag], [imag, real]])

    def _apply_to_vector(self, v):
        # type: (np.ndarray) -> np.ndarray
        v_reshaped = np.reshape(v, (2, 1))
        return np.reshape(np.matmul(self.to_rotation_matrix(), v_reshaped), v.shape)

    # TODO rotation helpers
