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
 * Composition of two elements in the group.
 *
 * Returns:
 *     Element: a @ b
 *     res_D_a: (6x6) jacobian of res (6) wrt arg a (6)
 *     res_D_b: (6x6) jacobian of res (6) wrt arg b (6)
 */
template <typename Scalar>
sym::Pose3<Scalar> ComposePose3WithJacobians(const sym::Pose3<Scalar>& a,
                                             const sym::Pose3<Scalar>& b,
                                             Eigen::Matrix<Scalar, 6, 6>* const res_D_a = nullptr,
                                             Eigen::Matrix<Scalar, 6, 6>* const res_D_b = nullptr) {
  // Total ops: 365

  // Input arrays
  const Eigen::Matrix<Scalar, 7, 1>& _a = a.Data();
  const Eigen::Matrix<Scalar, 7, 1>& _b = b.Data();

  // Intermediate terms (137)
  const Scalar _tmp0 = _a[3] * _b[0];
  const Scalar _tmp1 = _a[0] * _b[3];
  const Scalar _tmp2 = _a[1] * _b[2];
  const Scalar _tmp3 = _a[2] * _b[1];
  const Scalar _tmp4 = _a[3] * _b[1];
  const Scalar _tmp5 = _a[1] * _b[3];
  const Scalar _tmp6 = _a[2] * _b[0];
  const Scalar _tmp7 = _a[0] * _b[2];
  const Scalar _tmp8 = _a[3] * _b[2];
  const Scalar _tmp9 = _a[0] * _b[1];
  const Scalar _tmp10 = _a[2] * _b[3];
  const Scalar _tmp11 = _a[1] * _b[0];
  const Scalar _tmp12 = _a[3] * _b[3];
  const Scalar _tmp13 = _a[0] * _b[0];
  const Scalar _tmp14 = _a[1] * _b[1];
  const Scalar _tmp15 = _a[2] * _b[2];
  const Scalar _tmp16 = 2 * _a[3];
  const Scalar _tmp17 = _a[2] * _tmp16;
  const Scalar _tmp18 = -_tmp17;
  const Scalar _tmp19 = 2 * _a[0];
  const Scalar _tmp20 = _a[1] * _tmp19;
  const Scalar _tmp21 = _tmp18 + _tmp20;
  const Scalar _tmp22 = _a[1] * _tmp16;
  const Scalar _tmp23 = _a[2] * _tmp19;
  const Scalar _tmp24 = _tmp22 + _tmp23;
  const Scalar _tmp25 = std::pow(_a[1], Scalar(2));
  const Scalar _tmp26 = -2 * _tmp25;
  const Scalar _tmp27 = std::pow(_a[2], Scalar(2));
  const Scalar _tmp28 = 1 - 2 * _tmp27;
  const Scalar _tmp29 = _tmp26 + _tmp28;
  const Scalar _tmp30 = _tmp17 + _tmp20;
  const Scalar _tmp31 = _a[0] * _tmp16;
  const Scalar _tmp32 = -_tmp31;
  const Scalar _tmp33 = 2 * _a[1] * _a[2];
  const Scalar _tmp34 = _tmp32 + _tmp33;
  const Scalar _tmp35 = std::pow(_a[0], Scalar(2));
  const Scalar _tmp36 = -2 * _tmp35;
  const Scalar _tmp37 = _tmp28 + _tmp36;
  const Scalar _tmp38 = -_tmp22;
  const Scalar _tmp39 = _tmp23 + _tmp38;
  const Scalar _tmp40 = _tmp31 + _tmp33;
  const Scalar _tmp41 = _tmp26 + _tmp36 + 1;
  const Scalar _tmp42 = (Scalar(1) / Scalar(2)) * _tmp14;
  const Scalar _tmp43 = (Scalar(1) / Scalar(2)) * _tmp13;
  const Scalar _tmp44 = -_tmp43;
  const Scalar _tmp45 = (Scalar(1) / Scalar(2)) * _tmp12;
  const Scalar _tmp46 = (Scalar(1) / Scalar(2)) * _tmp15;
  const Scalar _tmp47 = _tmp45 + _tmp46;
  const Scalar _tmp48 = _tmp42 + _tmp44 + _tmp47;
  const Scalar _tmp49 = 2 * _tmp12 - 2 * _tmp13 - 2 * _tmp14 - 2 * _tmp15;
  const Scalar _tmp50 = 2 * _tmp0;
  const Scalar _tmp51 = 2 * _tmp1;
  const Scalar _tmp52 = 2 * _tmp2;
  const Scalar _tmp53 = 2 * _tmp3;
  const Scalar _tmp54 = -_tmp50 - _tmp51 - _tmp52 + _tmp53;
  const Scalar _tmp55 = (Scalar(1) / Scalar(2)) * _tmp2;
  const Scalar _tmp56 = (Scalar(1) / Scalar(2)) * _tmp1;
  const Scalar _tmp57 = -_tmp56;
  const Scalar _tmp58 = (Scalar(1) / Scalar(2)) * _tmp0;
  const Scalar _tmp59 = -_tmp58;
  const Scalar _tmp60 = (Scalar(1) / Scalar(2)) * _tmp3;
  const Scalar _tmp61 = -_tmp60;
  const Scalar _tmp62 = _tmp59 + _tmp61;
  const Scalar _tmp63 = _tmp55 + _tmp57 + _tmp62;
  const Scalar _tmp64 = 2 * _tmp4;
  const Scalar _tmp65 = 2 * _tmp7;
  const Scalar _tmp66 = 2 * _tmp5;
  const Scalar _tmp67 = 2 * _tmp6;
  const Scalar _tmp68 = -_tmp64 + _tmp65 - _tmp66 - _tmp67;
  const Scalar _tmp69 = (Scalar(1) / Scalar(2)) * _tmp4;
  const Scalar _tmp70 = (Scalar(1) / Scalar(2)) * _tmp6;
  const Scalar _tmp71 = -_tmp70;
  const Scalar _tmp72 = (Scalar(1) / Scalar(2)) * _tmp7;
  const Scalar _tmp73 = -_tmp72;
  const Scalar _tmp74 = (Scalar(1) / Scalar(2)) * _tmp5;
  const Scalar _tmp75 = -_tmp74;
  const Scalar _tmp76 = _tmp73 + _tmp75;
  const Scalar _tmp77 = _tmp69 + _tmp71 + _tmp76;
  const Scalar _tmp78 = (Scalar(1) / Scalar(2)) * _tmp10;
  const Scalar _tmp79 = (Scalar(1) / Scalar(2)) * _tmp8;
  const Scalar _tmp80 = -_tmp79;
  const Scalar _tmp81 = (Scalar(1) / Scalar(2)) * _tmp9;
  const Scalar _tmp82 = -_tmp81;
  const Scalar _tmp83 = (Scalar(1) / Scalar(2)) * _tmp11;
  const Scalar _tmp84 = -_tmp83;
  const Scalar _tmp85 = _tmp82 + _tmp84;
  const Scalar _tmp86 = _tmp78 + _tmp80 + _tmp85;
  const Scalar _tmp87 = 2 * _tmp8;
  const Scalar _tmp88 = 2 * _tmp9;
  const Scalar _tmp89 = 2 * _tmp11;
  const Scalar _tmp90 = 2 * _tmp10;
  const Scalar _tmp91 = _tmp87 + _tmp88 - _tmp89 + _tmp90;
  const Scalar _tmp92 = -_tmp42;
  const Scalar _tmp93 = _tmp43 + _tmp47 + _tmp92;
  const Scalar _tmp94 = -_tmp78;
  const Scalar _tmp95 = _tmp79 + _tmp85 + _tmp94;
  const Scalar _tmp96 = -_tmp69;
  const Scalar _tmp97 = _tmp70 + _tmp76 + _tmp96;
  const Scalar _tmp98 = -_tmp55;
  const Scalar _tmp99 = _tmp56 + _tmp62 + _tmp98;
  const Scalar _tmp100 = _tmp45 - _tmp46;
  const Scalar _tmp101 = _tmp100 + _tmp42 + _tmp43;
  const Scalar _tmp102 = _tmp71 + _tmp96;
  const Scalar _tmp103 = _tmp73 + _tmp74;
  const Scalar _tmp104 = _tmp102 + _tmp103;
  const Scalar _tmp105 = _tmp81 + _tmp84;
  const Scalar _tmp106 = _tmp80 + _tmp94;
  const Scalar _tmp107 = _tmp105 + _tmp106;
  const Scalar _tmp108 = _tmp57 + _tmp98;
  const Scalar _tmp109 = _tmp58 + _tmp61;
  const Scalar _tmp110 = _tmp108 + _tmp109;
  const Scalar _tmp111 = -_tmp87 - _tmp88 + _tmp89 - _tmp90;
  const Scalar _tmp112 = _tmp50 + _tmp51 + _tmp52 - _tmp53;
  const Scalar _tmp113 = _tmp64 - _tmp65 + _tmp66 + _tmp67;
  const Scalar _tmp114 = -_tmp20;
  const Scalar _tmp115 = -_tmp23;
  const Scalar _tmp116 = -_tmp25;
  const Scalar _tmp117 = _tmp116 + _tmp35;
  const Scalar _tmp118 = std::pow(_a[3], Scalar(2));
  const Scalar _tmp119 = -_tmp27;
  const Scalar _tmp120 = _tmp118 + _tmp119;
  const Scalar _tmp121 = -_tmp118;
  const Scalar _tmp122 = _tmp121 + _tmp27;
  const Scalar _tmp123 = -_tmp35;
  const Scalar _tmp124 = _tmp123 + _tmp25;
  const Scalar _tmp125 = -_tmp33;
  const Scalar _tmp126 = _tmp105 + _tmp78 + _tmp79;
  const Scalar _tmp127 = _tmp108 + _tmp59 + _tmp60;
  const Scalar _tmp128 = _tmp127 * _tmp54;
  const Scalar _tmp129 = _tmp100 + _tmp44 + _tmp92;
  const Scalar _tmp130 = _tmp129 * _tmp49;
  const Scalar _tmp131 = _tmp102 + _tmp72 + _tmp75;
  const Scalar _tmp132 = _tmp130 + _tmp131 * _tmp68;
  const Scalar _tmp133 = _tmp106 + _tmp82 + _tmp83;
  const Scalar _tmp134 = _tmp109 + _tmp55 + _tmp56;
  const Scalar _tmp135 = _tmp103 + _tmp69 + _tmp70;
  const Scalar _tmp136 = _tmp111 * _tmp133;

  // Output terms (3)
  Eigen::Matrix<Scalar, 7, 1> _res;

  _res[0] = _tmp0 + _tmp1 + _tmp2 - _tmp3;
  _res[1] = _tmp4 + _tmp5 + _tmp6 - _tmp7;
  _res[2] = _tmp10 - _tmp11 + _tmp8 + _tmp9;
  _res[3] = _tmp12 - _tmp13 - _tmp14 - _tmp15;
  _res[4] = _a[4] + _b[4] * _tmp29 + _b[5] * _tmp21 + _b[6] * _tmp24;
  _res[5] = _a[5] + _b[4] * _tmp30 + _b[5] * _tmp37 + _b[6] * _tmp34;
  _res[6] = _a[6] + _b[4] * _tmp39 + _b[5] * _tmp40 + _b[6] * _tmp41;

  if (res_D_a != nullptr) {
    Eigen::Matrix<Scalar, 6, 6>& _res_D_a = (*res_D_a);

    _res_D_a(0, 0) = _tmp48 * _tmp49 + _tmp54 * _tmp63 + _tmp68 * _tmp77 + _tmp86 * _tmp91;
    _res_D_a(0, 1) = _tmp49 * _tmp95 + _tmp54 * _tmp97 + _tmp68 * _tmp99 + _tmp91 * _tmp93;
    _res_D_a(0, 2) = _tmp101 * _tmp68 + _tmp104 * _tmp49 + _tmp107 * _tmp54 + _tmp110 * _tmp91;
    _res_D_a(0, 3) = 0;
    _res_D_a(0, 4) = 0;
    _res_D_a(0, 5) = 0;
    _res_D_a(1, 0) = _tmp111 * _tmp48 + _tmp112 * _tmp77 + _tmp49 * _tmp86 + _tmp63 * _tmp68;
    _res_D_a(1, 1) = _tmp111 * _tmp95 + _tmp112 * _tmp99 + _tmp49 * _tmp93 + _tmp68 * _tmp97;
    _res_D_a(1, 2) = _tmp101 * _tmp112 + _tmp104 * _tmp111 + _tmp107 * _tmp68 + _tmp110 * _tmp49;
    _res_D_a(1, 3) = 0;
    _res_D_a(1, 4) = 0;
    _res_D_a(1, 5) = 0;
    _res_D_a(2, 0) = _tmp111 * _tmp63 + _tmp113 * _tmp48 + _tmp49 * _tmp77 + _tmp54 * _tmp86;
    _res_D_a(2, 1) = _tmp111 * _tmp97 + _tmp113 * _tmp95 + _tmp49 * _tmp99 + _tmp54 * _tmp93;
    _res_D_a(2, 2) = _tmp101 * _tmp49 + _tmp104 * _tmp113 + _tmp107 * _tmp111 + _tmp110 * _tmp54;
    _res_D_a(2, 3) = 0;
    _res_D_a(2, 4) = 0;
    _res_D_a(2, 5) = 0;
    _res_D_a(3, 0) = _b[5] * _tmp24 + _b[6] * (_tmp114 + _tmp17);
    _res_D_a(3, 1) = _b[4] * (_tmp115 + _tmp38) + _b[6] * (_tmp117 + _tmp120);
    _res_D_a(3, 2) = _b[4] * _tmp21 + _b[5] * (_tmp122 + _tmp124);
    _res_D_a(3, 3) = 1;
    _res_D_a(3, 4) = 0;
    _res_D_a(3, 5) = 0;
    _res_D_a(4, 0) = _b[5] * _tmp34 + _b[6] * (_tmp117 + _tmp122);
    _res_D_a(4, 1) = _b[4] * (_tmp125 + _tmp31) + _b[6] * _tmp30;
    _res_D_a(4, 2) = _b[4] * (_tmp120 + _tmp124) + _b[5] * (_tmp114 + _tmp18);
    _res_D_a(4, 3) = 0;
    _res_D_a(4, 4) = 1;
    _res_D_a(4, 5) = 0;
    _res_D_a(5, 0) = _b[5] * (_tmp116 + _tmp118 + _tmp123 + _tmp27) + _b[6] * (_tmp125 + _tmp32);
    _res_D_a(5, 1) = _b[4] * (_tmp119 + _tmp121 + _tmp25 + _tmp35) + _b[6] * _tmp39;
    _res_D_a(5, 2) = _b[4] * _tmp40 + _b[5] * (_tmp115 + _tmp22);
    _res_D_a(5, 3) = 0;
    _res_D_a(5, 4) = 0;
    _res_D_a(5, 5) = 1;
  }

  if (res_D_b != nullptr) {
    Eigen::Matrix<Scalar, 6, 6>& _res_D_b = (*res_D_b);

    _res_D_b(0, 0) = _tmp126 * _tmp91 + _tmp128 + _tmp132;
    _res_D_b(0, 1) = _tmp129 * _tmp91 + _tmp131 * _tmp54 + _tmp133 * _tmp49 + _tmp134 * _tmp68;
    _res_D_b(0, 2) = _tmp127 * _tmp91 + _tmp129 * _tmp68 + _tmp133 * _tmp54 + _tmp135 * _tmp49;
    _res_D_b(0, 3) = 0;
    _res_D_b(0, 4) = 0;
    _res_D_b(0, 5) = 0;
    _res_D_b(1, 0) = _tmp111 * _tmp129 + _tmp112 * _tmp131 + _tmp126 * _tmp49 + _tmp127 * _tmp68;
    _res_D_b(1, 1) = _tmp112 * _tmp134 + _tmp132 + _tmp136;
    _res_D_b(1, 2) = _tmp111 * _tmp135 + _tmp112 * _tmp129 + _tmp127 * _tmp49 + _tmp133 * _tmp68;
    _res_D_b(1, 3) = 0;
    _res_D_b(1, 4) = 0;
    _res_D_b(1, 5) = 0;
    _res_D_b(2, 0) = _tmp111 * _tmp127 + _tmp113 * _tmp129 + _tmp126 * _tmp54 + _tmp131 * _tmp49;
    _res_D_b(2, 1) = _tmp111 * _tmp131 + _tmp113 * _tmp133 + _tmp129 * _tmp54 + _tmp134 * _tmp49;
    _res_D_b(2, 2) = _tmp113 * _tmp135 + _tmp128 + _tmp130 + _tmp136;
    _res_D_b(2, 3) = 0;
    _res_D_b(2, 4) = 0;
    _res_D_b(2, 5) = 0;
    _res_D_b(3, 0) = 0;
    _res_D_b(3, 1) = 0;
    _res_D_b(3, 2) = 0;
    _res_D_b(3, 3) = _tmp29;
    _res_D_b(3, 4) = _tmp21;
    _res_D_b(3, 5) = _tmp24;
    _res_D_b(4, 0) = 0;
    _res_D_b(4, 1) = 0;
    _res_D_b(4, 2) = 0;
    _res_D_b(4, 3) = _tmp30;
    _res_D_b(4, 4) = _tmp37;
    _res_D_b(4, 5) = _tmp34;
    _res_D_b(5, 0) = 0;
    _res_D_b(5, 1) = 0;
    _res_D_b(5, 2) = 0;
    _res_D_b(5, 3) = _tmp39;
    _res_D_b(5, 4) = _tmp40;
    _res_D_b(5, 5) = _tmp41;
  }

  return sym::Pose3<Scalar>(_res);
}  // NOLINT(readability/fn_size)

// NOLINTNEXTLINE(readability/fn_size)
}  // namespace sym
