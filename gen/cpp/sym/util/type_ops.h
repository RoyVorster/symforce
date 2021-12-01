// -----------------------------------------------------------------------------
// This file was autogenerated by symforce from template:
//     cpp_templates/type_ops.h.jinja
// Do NOT modify by hand.
// -----------------------------------------------------------------------------

#pragma once

// Import all the known types.
#include <lcmtypes/sym/type_t.hpp>

#include <sym/linear_camera_cal.h>
#include <sym/ops/lie_group_ops.h>
#include <sym/ops/storage_ops.h>
#include <sym/pose2.h>
#include <sym/pose3.h>
#include <sym/rot2.h>
#include <sym/rot3.h>
#include <sym/util/typedefs.h>

namespace sym {

template <typename T>
static constexpr const bool kIsEigenType = std::is_base_of<Eigen::MatrixBase<T>, T>::value;

/**
 * Helper to handle polymorphism by creating a switch from a runtime type enum to dispatch
 * to the templated method func. Used to perform type-aware operations.
 *
 * Args:
 *   name: Name of the output function (ex: FormatByType)
 *   func: Name of a function template (ex: FormatHelper)
 */
#define BY_TYPE_HELPER(name, func)                         \
  template <typename Scalar, typename... Args>             \
  auto name(const type_t type, Args&&... args) {           \
    switch (type.value) {                                  \
      case type_t::ROT2:                                   \
        return func<sym::Rot2<Scalar>>(args...);           \
      case type_t::ROT3:                                   \
        return func<sym::Rot3<Scalar>>(args...);           \
      case type_t::POSE2:                                  \
        return func<sym::Pose2<Scalar>>(args...);          \
      case type_t::POSE3:                                  \
        return func<sym::Pose3<Scalar>>(args...);          \
      case type_t::SCALAR:                                 \
        return func<Scalar>(args...);                      \
      case type_t::VECTOR1:                                \
        return func<Eigen::Matrix<Scalar, 1, 1>>(args...); \
      case type_t::VECTOR2:                                \
        return func<Eigen::Matrix<Scalar, 2, 1>>(args...); \
      case type_t::VECTOR3:                                \
        return func<Eigen::Matrix<Scalar, 3, 1>>(args...); \
      case type_t::VECTOR4:                                \
        return func<Eigen::Matrix<Scalar, 4, 1>>(args...); \
      case type_t::VECTOR5:                                \
        return func<Eigen::Matrix<Scalar, 5, 1>>(args...); \
      case type_t::VECTOR6:                                \
        return func<Eigen::Matrix<Scalar, 6, 1>>(args...); \
      case type_t::VECTOR7:                                \
        return func<Eigen::Matrix<Scalar, 7, 1>>(args...); \
      case type_t::VECTOR8:                                \
        return func<Eigen::Matrix<Scalar, 8, 1>>(args...); \
      case type_t::VECTOR9:                                \
        return func<Eigen::Matrix<Scalar, 9, 1>>(args...); \
      case type_t::MATRIX12:                               \
        return func<Eigen::Matrix<Scalar, 1, 2>>(args...); \
      case type_t::MATRIX13:                               \
        return func<Eigen::Matrix<Scalar, 1, 3>>(args...); \
      case type_t::MATRIX14:                               \
        return func<Eigen::Matrix<Scalar, 1, 4>>(args...); \
      case type_t::MATRIX15:                               \
        return func<Eigen::Matrix<Scalar, 1, 5>>(args...); \
      case type_t::MATRIX16:                               \
        return func<Eigen::Matrix<Scalar, 1, 6>>(args...); \
      case type_t::MATRIX17:                               \
        return func<Eigen::Matrix<Scalar, 1, 7>>(args...); \
      case type_t::MATRIX18:                               \
        return func<Eigen::Matrix<Scalar, 1, 8>>(args...); \
      case type_t::MATRIX19:                               \
        return func<Eigen::Matrix<Scalar, 1, 9>>(args...); \
      case type_t::MATRIX22:                               \
        return func<Eigen::Matrix<Scalar, 2, 2>>(args...); \
      case type_t::MATRIX23:                               \
        return func<Eigen::Matrix<Scalar, 2, 3>>(args...); \
      case type_t::MATRIX24:                               \
        return func<Eigen::Matrix<Scalar, 2, 4>>(args...); \
      case type_t::MATRIX25:                               \
        return func<Eigen::Matrix<Scalar, 2, 5>>(args...); \
      case type_t::MATRIX26:                               \
        return func<Eigen::Matrix<Scalar, 2, 6>>(args...); \
      case type_t::MATRIX27:                               \
        return func<Eigen::Matrix<Scalar, 2, 7>>(args...); \
      case type_t::MATRIX28:                               \
        return func<Eigen::Matrix<Scalar, 2, 8>>(args...); \
      case type_t::MATRIX29:                               \
        return func<Eigen::Matrix<Scalar, 2, 9>>(args...); \
      case type_t::MATRIX32:                               \
        return func<Eigen::Matrix<Scalar, 3, 2>>(args...); \
      case type_t::MATRIX33:                               \
        return func<Eigen::Matrix<Scalar, 3, 3>>(args...); \
      case type_t::MATRIX34:                               \
        return func<Eigen::Matrix<Scalar, 3, 4>>(args...); \
      case type_t::MATRIX35:                               \
        return func<Eigen::Matrix<Scalar, 3, 5>>(args...); \
      case type_t::MATRIX36:                               \
        return func<Eigen::Matrix<Scalar, 3, 6>>(args...); \
      case type_t::MATRIX37:                               \
        return func<Eigen::Matrix<Scalar, 3, 7>>(args...); \
      case type_t::MATRIX38:                               \
        return func<Eigen::Matrix<Scalar, 3, 8>>(args...); \
      case type_t::MATRIX39:                               \
        return func<Eigen::Matrix<Scalar, 3, 9>>(args...); \
      case type_t::MATRIX42:                               \
        return func<Eigen::Matrix<Scalar, 4, 2>>(args...); \
      case type_t::MATRIX43:                               \
        return func<Eigen::Matrix<Scalar, 4, 3>>(args...); \
      case type_t::MATRIX44:                               \
        return func<Eigen::Matrix<Scalar, 4, 4>>(args...); \
      case type_t::MATRIX45:                               \
        return func<Eigen::Matrix<Scalar, 4, 5>>(args...); \
      case type_t::MATRIX46:                               \
        return func<Eigen::Matrix<Scalar, 4, 6>>(args...); \
      case type_t::MATRIX47:                               \
        return func<Eigen::Matrix<Scalar, 4, 7>>(args...); \
      case type_t::MATRIX48:                               \
        return func<Eigen::Matrix<Scalar, 4, 8>>(args...); \
      case type_t::MATRIX49:                               \
        return func<Eigen::Matrix<Scalar, 4, 9>>(args...); \
      case type_t::MATRIX52:                               \
        return func<Eigen::Matrix<Scalar, 5, 2>>(args...); \
      case type_t::MATRIX53:                               \
        return func<Eigen::Matrix<Scalar, 5, 3>>(args...); \
      case type_t::MATRIX54:                               \
        return func<Eigen::Matrix<Scalar, 5, 4>>(args...); \
      case type_t::MATRIX55:                               \
        return func<Eigen::Matrix<Scalar, 5, 5>>(args...); \
      case type_t::MATRIX56:                               \
        return func<Eigen::Matrix<Scalar, 5, 6>>(args...); \
      case type_t::MATRIX57:                               \
        return func<Eigen::Matrix<Scalar, 5, 7>>(args...); \
      case type_t::MATRIX58:                               \
        return func<Eigen::Matrix<Scalar, 5, 8>>(args...); \
      case type_t::MATRIX59:                               \
        return func<Eigen::Matrix<Scalar, 5, 9>>(args...); \
      case type_t::MATRIX62:                               \
        return func<Eigen::Matrix<Scalar, 6, 2>>(args...); \
      case type_t::MATRIX63:                               \
        return func<Eigen::Matrix<Scalar, 6, 3>>(args...); \
      case type_t::MATRIX64:                               \
        return func<Eigen::Matrix<Scalar, 6, 4>>(args...); \
      case type_t::MATRIX65:                               \
        return func<Eigen::Matrix<Scalar, 6, 5>>(args...); \
      case type_t::MATRIX66:                               \
        return func<Eigen::Matrix<Scalar, 6, 6>>(args...); \
      case type_t::MATRIX67:                               \
        return func<Eigen::Matrix<Scalar, 6, 7>>(args...); \
      case type_t::MATRIX68:                               \
        return func<Eigen::Matrix<Scalar, 6, 8>>(args...); \
      case type_t::MATRIX69:                               \
        return func<Eigen::Matrix<Scalar, 6, 9>>(args...); \
      case type_t::MATRIX72:                               \
        return func<Eigen::Matrix<Scalar, 7, 2>>(args...); \
      case type_t::MATRIX73:                               \
        return func<Eigen::Matrix<Scalar, 7, 3>>(args...); \
      case type_t::MATRIX74:                               \
        return func<Eigen::Matrix<Scalar, 7, 4>>(args...); \
      case type_t::MATRIX75:                               \
        return func<Eigen::Matrix<Scalar, 7, 5>>(args...); \
      case type_t::MATRIX76:                               \
        return func<Eigen::Matrix<Scalar, 7, 6>>(args...); \
      case type_t::MATRIX77:                               \
        return func<Eigen::Matrix<Scalar, 7, 7>>(args...); \
      case type_t::MATRIX78:                               \
        return func<Eigen::Matrix<Scalar, 7, 8>>(args...); \
      case type_t::MATRIX79:                               \
        return func<Eigen::Matrix<Scalar, 7, 9>>(args...); \
      case type_t::MATRIX82:                               \
        return func<Eigen::Matrix<Scalar, 8, 2>>(args...); \
      case type_t::MATRIX83:                               \
        return func<Eigen::Matrix<Scalar, 8, 3>>(args...); \
      case type_t::MATRIX84:                               \
        return func<Eigen::Matrix<Scalar, 8, 4>>(args...); \
      case type_t::MATRIX85:                               \
        return func<Eigen::Matrix<Scalar, 8, 5>>(args...); \
      case type_t::MATRIX86:                               \
        return func<Eigen::Matrix<Scalar, 8, 6>>(args...); \
      case type_t::MATRIX87:                               \
        return func<Eigen::Matrix<Scalar, 8, 7>>(args...); \
      case type_t::MATRIX88:                               \
        return func<Eigen::Matrix<Scalar, 8, 8>>(args...); \
      case type_t::MATRIX89:                               \
        return func<Eigen::Matrix<Scalar, 8, 9>>(args...); \
      case type_t::MATRIX92:                               \
        return func<Eigen::Matrix<Scalar, 9, 2>>(args...); \
      case type_t::MATRIX93:                               \
        return func<Eigen::Matrix<Scalar, 9, 3>>(args...); \
      case type_t::MATRIX94:                               \
        return func<Eigen::Matrix<Scalar, 9, 4>>(args...); \
      case type_t::MATRIX95:                               \
        return func<Eigen::Matrix<Scalar, 9, 5>>(args...); \
      case type_t::MATRIX96:                               \
        return func<Eigen::Matrix<Scalar, 9, 6>>(args...); \
      case type_t::MATRIX97:                               \
        return func<Eigen::Matrix<Scalar, 9, 7>>(args...); \
      case type_t::MATRIX98:                               \
        return func<Eigen::Matrix<Scalar, 9, 8>>(args...); \
      case type_t::MATRIX99:                               \
        return func<Eigen::Matrix<Scalar, 9, 9>>(args...); \
      default:                                             \
        SYM_ASSERT(false);                                 \
    }                                                      \
  }

}  // namespace sym
