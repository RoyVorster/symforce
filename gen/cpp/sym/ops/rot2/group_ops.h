// -----------------------------------------------------------------------------
// This file was autogenerated by symforce from template:
//     cpp_templates/geo_package/ops/CLASS/group_ops.h.jinja
// Do NOT modify by hand.
// -----------------------------------------------------------------------------

#pragma once

#include <Eigen/Dense>

#include <sym/rot2.h>

namespace sym {

/**
 * C++ GroupOps implementation for <class 'symforce.geo.rot2.Rot2'>.
 */
template <typename Scalar>
struct GroupOps<Rot2<Scalar>> {
  using T = Rot2<Scalar>;
  using SelfJacobian =
      Eigen::Matrix<Scalar, LieGroupOps<T>::TangentDim(), LieGroupOps<T>::TangentDim()>;

  static T Identity();
  static T Inverse(const T& a);
  static T Compose(const T& a, const T& b);
  static T Between(const T& a, const T& b);
  static T InverseWithJacobian(const T& a, SelfJacobian* const res_D_a = nullptr);
  static T ComposeWithJacobians(const T& a, const T& b, SelfJacobian* const res_D_a = nullptr,
                                SelfJacobian* const res_D_b = nullptr);
  static T BetweenWithJacobians(const T& a, const T& b, SelfJacobian* const res_D_a = nullptr,
                                SelfJacobian* const res_D_b = nullptr);
};

}  // namespace sym

// Explicit instantiation
extern template struct sym::GroupOps<sym::Rot2<double>>;
extern template struct sym::GroupOps<sym::Rot2<float>>;
