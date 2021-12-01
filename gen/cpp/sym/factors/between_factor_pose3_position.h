// -----------------------------------------------------------------------------
// This file was autogenerated by symforce from template:
//     cpp_templates/function/FUNCTION.h.jinja
// Do NOT modify by hand.
// -----------------------------------------------------------------------------

#pragma once

#include <Eigen/Dense>

#include <sym/pose3.h>

namespace sym {

/**
 * Residual that penalizes the difference between between(a, b) and a_t_b.
 *
 * In vector space terms that would be:
 *     (b - a) - a_t_b
 *
 * In lie group terms:
 *     local_coordinates(a_t_b, between(a, b))
 *     to_tangent(compose(inverse(a_t_b), compose(inverse(a), b)))
 *
 * Args:
 *     sqrt_info: Square root information matrix to whiten residual. This can be computed from
 *                a covariance matrix as the cholesky decomposition of the inverse. In the case
 *                of a diagonal it will contain 1/sigma values. Must match the tangent dim.
 *     jacobian: (3x12) jacobian of res wrt args a (6), b (6)
 *     hessian: (12x12) Gauss-Newton hessian for args a (6), b (6)
 *     rhs: (12x1) Gauss-Newton rhs for args a (6), b (6)
 */
template <typename Scalar>
void BetweenFactorPose3Position(const sym::Pose3<Scalar>& a, const sym::Pose3<Scalar>& b,
                                const Eigen::Matrix<Scalar, 3, 1>& a_t_b,
                                const Eigen::Matrix<Scalar, 3, 3>& sqrt_info, const Scalar epsilon,
                                Eigen::Matrix<Scalar, 3, 1>* const res = nullptr,
                                Eigen::Matrix<Scalar, 3, 12>* const jacobian = nullptr,
                                Eigen::Matrix<Scalar, 12, 12>* const hessian = nullptr,
                                Eigen::Matrix<Scalar, 12, 1>* const rhs = nullptr) {
  // Total ops: 578

  // Input arrays
  const Eigen::Matrix<Scalar, 7, 1>& _a = a.Data();
  const Eigen::Matrix<Scalar, 7, 1>& _b = b.Data();

  // Intermediate terms (105)
  const Scalar _tmp0 = std::pow(_a[2], Scalar(2));
  const Scalar _tmp1 = 2 * _tmp0;
  const Scalar _tmp2 = -_tmp1;
  const Scalar _tmp3 = std::pow(_a[1], Scalar(2));
  const Scalar _tmp4 = 2 * _tmp3;
  const Scalar _tmp5 = 1 - _tmp4;
  const Scalar _tmp6 = _tmp2 + _tmp5;
  const Scalar _tmp7 = 2 * _a[0] * _a[1];
  const Scalar _tmp8 = 2 * _a[3];
  const Scalar _tmp9 = _a[2] * _tmp8;
  const Scalar _tmp10 = _tmp7 + _tmp9;
  const Scalar _tmp11 = _a[5] * _tmp10;
  const Scalar _tmp12 = _a[1] * _tmp8;
  const Scalar _tmp13 = -_tmp12;
  const Scalar _tmp14 = 2 * _a[2];
  const Scalar _tmp15 = _a[0] * _tmp14;
  const Scalar _tmp16 = _tmp13 + _tmp15;
  const Scalar _tmp17 = _a[6] * _tmp16;
  const Scalar _tmp18 = _b[5] * _tmp10 + _b[6] * _tmp16;
  const Scalar _tmp19 = -_a[4] * _tmp6 + _b[4] * _tmp6 - _tmp11 - _tmp17 + _tmp18 - a_t_b(0, 0);
  const Scalar _tmp20 = std::pow(_a[0], Scalar(2));
  const Scalar _tmp21 = 2 * _tmp20;
  const Scalar _tmp22 = -_tmp21;
  const Scalar _tmp23 = _tmp2 + _tmp22 + 1;
  const Scalar _tmp24 = -_tmp9;
  const Scalar _tmp25 = _tmp24 + _tmp7;
  const Scalar _tmp26 = _a[4] * _tmp25;
  const Scalar _tmp27 = _a[0] * _tmp8;
  const Scalar _tmp28 = _a[1] * _tmp14;
  const Scalar _tmp29 = _tmp27 + _tmp28;
  const Scalar _tmp30 = _a[6] * _tmp29;
  const Scalar _tmp31 = _b[4] * _tmp25 + _b[6] * _tmp29;
  const Scalar _tmp32 = -_a[5] * _tmp23 + _b[5] * _tmp23 - _tmp26 - _tmp30 + _tmp31 - a_t_b(1, 0);
  const Scalar _tmp33 = _tmp22 + _tmp5;
  const Scalar _tmp34 = -_tmp27;
  const Scalar _tmp35 = _tmp28 + _tmp34;
  const Scalar _tmp36 = _a[5] * _tmp35;
  const Scalar _tmp37 = _tmp12 + _tmp15;
  const Scalar _tmp38 = _a[4] * _tmp37;
  const Scalar _tmp39 = _b[4] * _tmp37 + _b[5] * _tmp35;
  const Scalar _tmp40 = -_a[6] * _tmp33 + _b[6] * _tmp33 - _tmp36 - _tmp38 + _tmp39 - a_t_b(2, 0);
  const Scalar _tmp41 =
      _tmp19 * sqrt_info(0, 0) + _tmp32 * sqrt_info(0, 1) + _tmp40 * sqrt_info(0, 2);
  const Scalar _tmp42 =
      _tmp19 * sqrt_info(1, 0) + _tmp32 * sqrt_info(1, 1) + _tmp40 * sqrt_info(1, 2);
  const Scalar _tmp43 =
      _tmp19 * sqrt_info(2, 0) + _tmp32 * sqrt_info(2, 1) + _tmp40 * sqrt_info(2, 2);
  const Scalar _tmp44 = -_tmp3;
  const Scalar _tmp45 = std::pow(_a[3], Scalar(2));
  const Scalar _tmp46 = -_tmp45;
  const Scalar _tmp47 = _tmp0 + _tmp20 + _tmp44 + _tmp46;
  const Scalar _tmp48 = -_tmp7;
  const Scalar _tmp49 = _tmp48 + _tmp9;
  const Scalar _tmp50 = -_tmp28;
  const Scalar _tmp51 = _tmp34 + _tmp50;
  const Scalar _tmp52 = -_a[4] * _tmp49 - _a[5] * _tmp47 - _a[6] * _tmp51 + _b[4] * _tmp49 +
                        _b[5] * _tmp47 + _b[6] * _tmp51;
  const Scalar _tmp53 = -_tmp20;
  const Scalar _tmp54 = _tmp0 + _tmp53;
  const Scalar _tmp55 = _tmp44 + _tmp45;
  const Scalar _tmp56 = _tmp54 + _tmp55;
  const Scalar _tmp57 = -_a[6] * _tmp56 + _b[6] * _tmp56 - _tmp36 - _tmp38 + _tmp39;
  const Scalar _tmp58 = _tmp52 * sqrt_info(0, 2) + _tmp57 * sqrt_info(0, 1);
  const Scalar _tmp59 = -_tmp0;
  const Scalar _tmp60 = _tmp20 + _tmp59;
  const Scalar _tmp61 = _tmp55 + _tmp60;
  const Scalar _tmp62 = -_a[4] * _tmp61 + _b[4] * _tmp61 - _tmp11 - _tmp17 + _tmp18;
  const Scalar _tmp63 = _tmp3 + _tmp46;
  const Scalar _tmp64 = _tmp60 + _tmp63;
  const Scalar _tmp65 = _tmp27 + _tmp50;
  const Scalar _tmp66 = -_tmp15;
  const Scalar _tmp67 = _tmp13 + _tmp66;
  const Scalar _tmp68 = -_a[4] * _tmp67 - _a[5] * _tmp65 - _a[6] * _tmp64 + _b[4] * _tmp67 +
                        _b[5] * _tmp65 + _b[6] * _tmp64;
  const Scalar _tmp69 = _tmp62 * sqrt_info(0, 2) + _tmp68 * sqrt_info(0, 0);
  const Scalar _tmp70 = _tmp3 + _tmp45 + _tmp53 + _tmp59;
  const Scalar _tmp71 = -_a[5] * _tmp70 + _b[5] * _tmp70 - _tmp26 - _tmp30 + _tmp31;
  const Scalar _tmp72 = _tmp54 + _tmp63;
  const Scalar _tmp73 = _tmp24 + _tmp48;
  const Scalar _tmp74 = _tmp12 + _tmp66;
  const Scalar _tmp75 = -_a[4] * _tmp72 - _a[5] * _tmp73 - _a[6] * _tmp74 + _b[4] * _tmp72 +
                        _b[5] * _tmp73 + _b[6] * _tmp74;
  const Scalar _tmp76 = _tmp71 * sqrt_info(0, 0) + _tmp75 * sqrt_info(0, 1);
  const Scalar _tmp77 = _tmp4 - 1;
  const Scalar _tmp78 = _tmp1 + _tmp77;
  const Scalar _tmp79 =
      _tmp49 * sqrt_info(0, 1) + _tmp67 * sqrt_info(0, 2) + _tmp78 * sqrt_info(0, 0);
  const Scalar _tmp80 = _tmp1 + _tmp21 - 1;
  const Scalar _tmp81 =
      _tmp65 * sqrt_info(0, 2) + _tmp73 * sqrt_info(0, 0) + _tmp80 * sqrt_info(0, 1);
  const Scalar _tmp82 = _tmp21 + _tmp77;
  const Scalar _tmp83 =
      _tmp51 * sqrt_info(0, 1) + _tmp74 * sqrt_info(0, 0) + _tmp82 * sqrt_info(0, 2);
  const Scalar _tmp84 =
      _tmp25 * sqrt_info(0, 1) + _tmp37 * sqrt_info(0, 2) + _tmp6 * sqrt_info(0, 0);
  const Scalar _tmp85 =
      _tmp10 * sqrt_info(0, 0) + _tmp23 * sqrt_info(0, 1) + _tmp35 * sqrt_info(0, 2);
  const Scalar _tmp86 =
      _tmp16 * sqrt_info(0, 0) + _tmp29 * sqrt_info(0, 1) + _tmp33 * sqrt_info(0, 2);
  const Scalar _tmp87 = _tmp52 * sqrt_info(1, 2) + _tmp57 * sqrt_info(1, 1);
  const Scalar _tmp88 = _tmp62 * sqrt_info(1, 2) + _tmp68 * sqrt_info(1, 0);
  const Scalar _tmp89 = _tmp71 * sqrt_info(1, 0) + _tmp75 * sqrt_info(1, 1);
  const Scalar _tmp90 =
      _tmp49 * sqrt_info(1, 1) + _tmp67 * sqrt_info(1, 2) + _tmp78 * sqrt_info(1, 0);
  const Scalar _tmp91 =
      _tmp65 * sqrt_info(1, 2) + _tmp73 * sqrt_info(1, 0) + _tmp80 * sqrt_info(1, 1);
  const Scalar _tmp92 =
      _tmp51 * sqrt_info(1, 1) + _tmp74 * sqrt_info(1, 0) + _tmp82 * sqrt_info(1, 2);
  const Scalar _tmp93 =
      _tmp25 * sqrt_info(1, 1) + _tmp37 * sqrt_info(1, 2) + _tmp6 * sqrt_info(1, 0);
  const Scalar _tmp94 =
      _tmp10 * sqrt_info(1, 0) + _tmp23 * sqrt_info(1, 1) + _tmp35 * sqrt_info(1, 2);
  const Scalar _tmp95 =
      _tmp16 * sqrt_info(1, 0) + _tmp29 * sqrt_info(1, 1) + _tmp33 * sqrt_info(1, 2);
  const Scalar _tmp96 = _tmp52 * sqrt_info(2, 2) + _tmp57 * sqrt_info(2, 1);
  const Scalar _tmp97 = _tmp62 * sqrt_info(2, 2) + _tmp68 * sqrt_info(2, 0);
  const Scalar _tmp98 = _tmp71 * sqrt_info(2, 0) + _tmp75 * sqrt_info(2, 1);
  const Scalar _tmp99 =
      _tmp49 * sqrt_info(2, 1) + _tmp67 * sqrt_info(2, 2) + _tmp78 * sqrt_info(2, 0);
  const Scalar _tmp100 =
      _tmp65 * sqrt_info(2, 2) + _tmp73 * sqrt_info(2, 0) + _tmp80 * sqrt_info(2, 1);
  const Scalar _tmp101 =
      _tmp51 * sqrt_info(2, 1) + _tmp74 * sqrt_info(2, 0) + _tmp82 * sqrt_info(2, 2);
  const Scalar _tmp102 =
      _tmp25 * sqrt_info(2, 1) + _tmp37 * sqrt_info(2, 2) + _tmp6 * sqrt_info(2, 0);
  const Scalar _tmp103 =
      _tmp10 * sqrt_info(2, 0) + _tmp23 * sqrt_info(2, 1) + _tmp35 * sqrt_info(2, 2);
  const Scalar _tmp104 =
      _tmp16 * sqrt_info(2, 0) + _tmp29 * sqrt_info(2, 1) + _tmp33 * sqrt_info(2, 2);

  // Output terms (4)
  if (res != nullptr) {
    Eigen::Matrix<Scalar, 3, 1>& _res = (*res);

    _res(0, 0) = _tmp41;
    _res(1, 0) = _tmp42;
    _res(2, 0) = _tmp43;
  }

  if (jacobian != nullptr) {
    Eigen::Matrix<Scalar, 3, 12>& _jacobian = (*jacobian);

    _jacobian(0, 0) = _tmp58;
    _jacobian(0, 1) = _tmp69;
    _jacobian(0, 2) = _tmp76;
    _jacobian(0, 3) = _tmp79;
    _jacobian(0, 4) = _tmp81;
    _jacobian(0, 5) = _tmp83;
    _jacobian(0, 6) = 0;
    _jacobian(0, 7) = 0;
    _jacobian(0, 8) = 0;
    _jacobian(0, 9) = _tmp84;
    _jacobian(0, 10) = _tmp85;
    _jacobian(0, 11) = _tmp86;
    _jacobian(1, 0) = _tmp87;
    _jacobian(1, 1) = _tmp88;
    _jacobian(1, 2) = _tmp89;
    _jacobian(1, 3) = _tmp90;
    _jacobian(1, 4) = _tmp91;
    _jacobian(1, 5) = _tmp92;
    _jacobian(1, 6) = 0;
    _jacobian(1, 7) = 0;
    _jacobian(1, 8) = 0;
    _jacobian(1, 9) = _tmp93;
    _jacobian(1, 10) = _tmp94;
    _jacobian(1, 11) = _tmp95;
    _jacobian(2, 0) = _tmp96;
    _jacobian(2, 1) = _tmp97;
    _jacobian(2, 2) = _tmp98;
    _jacobian(2, 3) = _tmp99;
    _jacobian(2, 4) = _tmp100;
    _jacobian(2, 5) = _tmp101;
    _jacobian(2, 6) = 0;
    _jacobian(2, 7) = 0;
    _jacobian(2, 8) = 0;
    _jacobian(2, 9) = _tmp102;
    _jacobian(2, 10) = _tmp103;
    _jacobian(2, 11) = _tmp104;
  }

  if (hessian != nullptr) {
    Eigen::Matrix<Scalar, 12, 12>& _hessian = (*hessian);

    _hessian(0, 0) =
        std::pow(_tmp58, Scalar(2)) + std::pow(_tmp87, Scalar(2)) + std::pow(_tmp96, Scalar(2));
    _hessian(0, 1) = 0;
    _hessian(0, 2) = 0;
    _hessian(0, 3) = 0;
    _hessian(0, 4) = 0;
    _hessian(0, 5) = 0;
    _hessian(0, 6) = 0;
    _hessian(0, 7) = 0;
    _hessian(0, 8) = 0;
    _hessian(0, 9) = 0;
    _hessian(0, 10) = 0;
    _hessian(0, 11) = 0;
    _hessian(1, 0) = _tmp58 * _tmp69 + _tmp87 * _tmp88 + _tmp96 * _tmp97;
    _hessian(1, 1) =
        std::pow(_tmp69, Scalar(2)) + std::pow(_tmp88, Scalar(2)) + std::pow(_tmp97, Scalar(2));
    _hessian(1, 2) = 0;
    _hessian(1, 3) = 0;
    _hessian(1, 4) = 0;
    _hessian(1, 5) = 0;
    _hessian(1, 6) = 0;
    _hessian(1, 7) = 0;
    _hessian(1, 8) = 0;
    _hessian(1, 9) = 0;
    _hessian(1, 10) = 0;
    _hessian(1, 11) = 0;
    _hessian(2, 0) = _tmp58 * _tmp76 + _tmp87 * _tmp89 + _tmp96 * _tmp98;
    _hessian(2, 1) = _tmp69 * _tmp76 + _tmp88 * _tmp89 + _tmp97 * _tmp98;
    _hessian(2, 2) =
        std::pow(_tmp76, Scalar(2)) + std::pow(_tmp89, Scalar(2)) + std::pow(_tmp98, Scalar(2));
    _hessian(2, 3) = 0;
    _hessian(2, 4) = 0;
    _hessian(2, 5) = 0;
    _hessian(2, 6) = 0;
    _hessian(2, 7) = 0;
    _hessian(2, 8) = 0;
    _hessian(2, 9) = 0;
    _hessian(2, 10) = 0;
    _hessian(2, 11) = 0;
    _hessian(3, 0) = _tmp58 * _tmp79 + _tmp87 * _tmp90 + _tmp96 * _tmp99;
    _hessian(3, 1) = _tmp69 * _tmp79 + _tmp88 * _tmp90 + _tmp97 * _tmp99;
    _hessian(3, 2) = _tmp76 * _tmp79 + _tmp89 * _tmp90 + _tmp98 * _tmp99;
    _hessian(3, 3) =
        std::pow(_tmp79, Scalar(2)) + std::pow(_tmp90, Scalar(2)) + std::pow(_tmp99, Scalar(2));
    _hessian(3, 4) = 0;
    _hessian(3, 5) = 0;
    _hessian(3, 6) = 0;
    _hessian(3, 7) = 0;
    _hessian(3, 8) = 0;
    _hessian(3, 9) = 0;
    _hessian(3, 10) = 0;
    _hessian(3, 11) = 0;
    _hessian(4, 0) = _tmp100 * _tmp96 + _tmp58 * _tmp81 + _tmp87 * _tmp91;
    _hessian(4, 1) = _tmp100 * _tmp97 + _tmp69 * _tmp81 + _tmp88 * _tmp91;
    _hessian(4, 2) = _tmp100 * _tmp98 + _tmp76 * _tmp81 + _tmp89 * _tmp91;
    _hessian(4, 3) = _tmp100 * _tmp99 + _tmp79 * _tmp81 + _tmp90 * _tmp91;
    _hessian(4, 4) =
        std::pow(_tmp100, Scalar(2)) + std::pow(_tmp81, Scalar(2)) + std::pow(_tmp91, Scalar(2));
    _hessian(4, 5) = 0;
    _hessian(4, 6) = 0;
    _hessian(4, 7) = 0;
    _hessian(4, 8) = 0;
    _hessian(4, 9) = 0;
    _hessian(4, 10) = 0;
    _hessian(4, 11) = 0;
    _hessian(5, 0) = _tmp101 * _tmp96 + _tmp58 * _tmp83 + _tmp87 * _tmp92;
    _hessian(5, 1) = _tmp101 * _tmp97 + _tmp69 * _tmp83 + _tmp88 * _tmp92;
    _hessian(5, 2) = _tmp101 * _tmp98 + _tmp76 * _tmp83 + _tmp89 * _tmp92;
    _hessian(5, 3) = _tmp101 * _tmp99 + _tmp79 * _tmp83 + _tmp90 * _tmp92;
    _hessian(5, 4) = _tmp100 * _tmp101 + _tmp81 * _tmp83 + _tmp91 * _tmp92;
    _hessian(5, 5) =
        std::pow(_tmp101, Scalar(2)) + std::pow(_tmp83, Scalar(2)) + std::pow(_tmp92, Scalar(2));
    _hessian(5, 6) = 0;
    _hessian(5, 7) = 0;
    _hessian(5, 8) = 0;
    _hessian(5, 9) = 0;
    _hessian(5, 10) = 0;
    _hessian(5, 11) = 0;
    _hessian(6, 0) = 0;
    _hessian(6, 1) = 0;
    _hessian(6, 2) = 0;
    _hessian(6, 3) = 0;
    _hessian(6, 4) = 0;
    _hessian(6, 5) = 0;
    _hessian(6, 6) = 0;
    _hessian(6, 7) = 0;
    _hessian(6, 8) = 0;
    _hessian(6, 9) = 0;
    _hessian(6, 10) = 0;
    _hessian(6, 11) = 0;
    _hessian(7, 0) = 0;
    _hessian(7, 1) = 0;
    _hessian(7, 2) = 0;
    _hessian(7, 3) = 0;
    _hessian(7, 4) = 0;
    _hessian(7, 5) = 0;
    _hessian(7, 6) = 0;
    _hessian(7, 7) = 0;
    _hessian(7, 8) = 0;
    _hessian(7, 9) = 0;
    _hessian(7, 10) = 0;
    _hessian(7, 11) = 0;
    _hessian(8, 0) = 0;
    _hessian(8, 1) = 0;
    _hessian(8, 2) = 0;
    _hessian(8, 3) = 0;
    _hessian(8, 4) = 0;
    _hessian(8, 5) = 0;
    _hessian(8, 6) = 0;
    _hessian(8, 7) = 0;
    _hessian(8, 8) = 0;
    _hessian(8, 9) = 0;
    _hessian(8, 10) = 0;
    _hessian(8, 11) = 0;
    _hessian(9, 0) = _tmp102 * _tmp96 + _tmp58 * _tmp84 + _tmp87 * _tmp93;
    _hessian(9, 1) = _tmp102 * _tmp97 + _tmp69 * _tmp84 + _tmp88 * _tmp93;
    _hessian(9, 2) = _tmp102 * _tmp98 + _tmp76 * _tmp84 + _tmp89 * _tmp93;
    _hessian(9, 3) = _tmp102 * _tmp99 + _tmp79 * _tmp84 + _tmp90 * _tmp93;
    _hessian(9, 4) = _tmp100 * _tmp102 + _tmp81 * _tmp84 + _tmp91 * _tmp93;
    _hessian(9, 5) = _tmp101 * _tmp102 + _tmp83 * _tmp84 + _tmp92 * _tmp93;
    _hessian(9, 6) = 0;
    _hessian(9, 7) = 0;
    _hessian(9, 8) = 0;
    _hessian(9, 9) =
        std::pow(_tmp102, Scalar(2)) + std::pow(_tmp84, Scalar(2)) + std::pow(_tmp93, Scalar(2));
    _hessian(9, 10) = 0;
    _hessian(9, 11) = 0;
    _hessian(10, 0) = _tmp103 * _tmp96 + _tmp58 * _tmp85 + _tmp87 * _tmp94;
    _hessian(10, 1) = _tmp103 * _tmp97 + _tmp69 * _tmp85 + _tmp88 * _tmp94;
    _hessian(10, 2) = _tmp103 * _tmp98 + _tmp76 * _tmp85 + _tmp89 * _tmp94;
    _hessian(10, 3) = _tmp103 * _tmp99 + _tmp79 * _tmp85 + _tmp90 * _tmp94;
    _hessian(10, 4) = _tmp100 * _tmp103 + _tmp81 * _tmp85 + _tmp91 * _tmp94;
    _hessian(10, 5) = _tmp101 * _tmp103 + _tmp83 * _tmp85 + _tmp92 * _tmp94;
    _hessian(10, 6) = 0;
    _hessian(10, 7) = 0;
    _hessian(10, 8) = 0;
    _hessian(10, 9) = _tmp102 * _tmp103 + _tmp84 * _tmp85 + _tmp93 * _tmp94;
    _hessian(10, 10) =
        std::pow(_tmp103, Scalar(2)) + std::pow(_tmp85, Scalar(2)) + std::pow(_tmp94, Scalar(2));
    _hessian(10, 11) = 0;
    _hessian(11, 0) = _tmp104 * _tmp96 + _tmp58 * _tmp86 + _tmp87 * _tmp95;
    _hessian(11, 1) = _tmp104 * _tmp97 + _tmp69 * _tmp86 + _tmp88 * _tmp95;
    _hessian(11, 2) = _tmp104 * _tmp98 + _tmp76 * _tmp86 + _tmp89 * _tmp95;
    _hessian(11, 3) = _tmp104 * _tmp99 + _tmp79 * _tmp86 + _tmp90 * _tmp95;
    _hessian(11, 4) = _tmp100 * _tmp104 + _tmp81 * _tmp86 + _tmp91 * _tmp95;
    _hessian(11, 5) = _tmp101 * _tmp104 + _tmp83 * _tmp86 + _tmp92 * _tmp95;
    _hessian(11, 6) = 0;
    _hessian(11, 7) = 0;
    _hessian(11, 8) = 0;
    _hessian(11, 9) = _tmp102 * _tmp104 + _tmp84 * _tmp86 + _tmp93 * _tmp95;
    _hessian(11, 10) = _tmp103 * _tmp104 + _tmp85 * _tmp86 + _tmp94 * _tmp95;
    _hessian(11, 11) =
        std::pow(_tmp104, Scalar(2)) + std::pow(_tmp86, Scalar(2)) + std::pow(_tmp95, Scalar(2));
  }

  if (rhs != nullptr) {
    Eigen::Matrix<Scalar, 12, 1>& _rhs = (*rhs);

    _rhs(0, 0) = _tmp41 * _tmp58 + _tmp42 * _tmp87 + _tmp43 * _tmp96;
    _rhs(1, 0) = _tmp41 * _tmp69 + _tmp42 * _tmp88 + _tmp43 * _tmp97;
    _rhs(2, 0) = _tmp41 * _tmp76 + _tmp42 * _tmp89 + _tmp43 * _tmp98;
    _rhs(3, 0) = _tmp41 * _tmp79 + _tmp42 * _tmp90 + _tmp43 * _tmp99;
    _rhs(4, 0) = _tmp100 * _tmp43 + _tmp41 * _tmp81 + _tmp42 * _tmp91;
    _rhs(5, 0) = _tmp101 * _tmp43 + _tmp41 * _tmp83 + _tmp42 * _tmp92;
    _rhs(6, 0) = 0;
    _rhs(7, 0) = 0;
    _rhs(8, 0) = 0;
    _rhs(9, 0) = _tmp102 * _tmp43 + _tmp41 * _tmp84 + _tmp42 * _tmp93;
    _rhs(10, 0) = _tmp103 * _tmp43 + _tmp41 * _tmp85 + _tmp42 * _tmp94;
    _rhs(11, 0) = _tmp104 * _tmp43 + _tmp41 * _tmp86 + _tmp42 * _tmp95;
  }
}  // NOLINT(readability/fn_size)

// NOLINTNEXTLINE(readability/fn_size)
}  // namespace sym
