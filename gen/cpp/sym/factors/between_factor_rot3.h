// -----------------------------------------------------------------------------
// This file was autogenerated by symforce from template:
//     cpp_templates/function/FUNCTION.h.jinja
// Do NOT modify by hand.
// -----------------------------------------------------------------------------

#pragma once

#include <Eigen/Dense>

#include <sym/rot3.h>

namespace sym {

/**
 * Residual that penalizes the difference between between(a, b) and a_T_b.
 *
 * In vector space terms that would be:
 *     (b - a) - a_T_b
 *
 * In lie group terms:
 *     local_coordinates(a_T_b, between(a, b))
 *     to_tangent(compose(inverse(a_T_b), compose(inverse(a), b)))
 *
 * Args:
 *     sqrt_info: Square root information matrix to whiten residual. This can be computed from
 *                a covariance matrix as the cholesky decomposition of the inverse. In the case
 *                of a diagonal it will contain 1/sigma values. Must match the tangent dim.
 *     jacobian: (3x6) jacobian of res wrt args a (3), b (3)
 *     hessian: (6x6) Gauss-Newton hessian for args a (3), b (3)
 *     rhs: (6x1) Gauss-Newton rhs for args a (3), b (3)
 */
template <typename Scalar>
void BetweenFactorRot3(const sym::Rot3<Scalar>& a, const sym::Rot3<Scalar>& b,
                       const sym::Rot3<Scalar>& a_T_b, const Eigen::Matrix<Scalar, 3, 3>& sqrt_info,
                       const Scalar epsilon, Eigen::Matrix<Scalar, 3, 1>* const res = nullptr,
                       Eigen::Matrix<Scalar, 3, 6>* const jacobian = nullptr,
                       Eigen::Matrix<Scalar, 6, 6>* const hessian = nullptr,
                       Eigen::Matrix<Scalar, 6, 1>* const rhs = nullptr) {
  // Total ops: 866

  // Input arrays
  const Eigen::Matrix<Scalar, 4, 1>& _a = a.Data();
  const Eigen::Matrix<Scalar, 4, 1>& _b = b.Data();
  const Eigen::Matrix<Scalar, 4, 1>& _a_T_b = a_T_b.Data();

  // Intermediate terms (216)
  const Scalar _tmp0 = _a[3] * _b[3];
  const Scalar _tmp1 = _a[2] * _b[2];
  const Scalar _tmp2 = _a[0] * _b[0];
  const Scalar _tmp3 = _a[1] * _b[1];
  const Scalar _tmp4 = _tmp0 + _tmp1 + _tmp2 + _tmp3;
  const Scalar _tmp5 = _a_T_b[3] * _tmp4;
  const Scalar _tmp6 = _a[3] * _b[1];
  const Scalar _tmp7 = _a[2] * _b[0];
  const Scalar _tmp8 = _a[0] * _b[2];
  const Scalar _tmp9 = _a[1] * _b[3];
  const Scalar _tmp10 = _tmp6 - _tmp7 + _tmp8 - _tmp9;
  const Scalar _tmp11 = _a_T_b[1] * _tmp10;
  const Scalar _tmp12 = _a[3] * _b[0];
  const Scalar _tmp13 = _a[2] * _b[1];
  const Scalar _tmp14 = _a[0] * _b[3];
  const Scalar _tmp15 = _a[1] * _b[2];
  const Scalar _tmp16 = _tmp12 + _tmp13 - _tmp14 - _tmp15;
  const Scalar _tmp17 = _a_T_b[0] * _tmp16;
  const Scalar _tmp18 = _a[3] * _b[2];
  const Scalar _tmp19 = _a[2] * _b[3];
  const Scalar _tmp20 = _a[0] * _b[1];
  const Scalar _tmp21 = _a[1] * _b[0];
  const Scalar _tmp22 = _tmp18 - _tmp19 - _tmp20 + _tmp21;
  const Scalar _tmp23 = _a_T_b[2] * _tmp22;
  const Scalar _tmp24 = _tmp11 + _tmp17 + _tmp23 + _tmp5;
  const Scalar _tmp25 = 2 * std::min<Scalar>(0, (((_tmp24) > 0) - ((_tmp24) < 0))) + 1;
  const Scalar _tmp26 = 2 * _tmp25;
  const Scalar _tmp27 = _tmp26 * sqrt_info(0, 2);
  const Scalar _tmp28 =
      -_a_T_b[0] * _tmp10 + _a_T_b[1] * _tmp16 - _a_T_b[2] * _tmp4 + _a_T_b[3] * _tmp22;
  const Scalar _tmp29 = 1 - epsilon;
  const Scalar _tmp30 = std::min<Scalar>(_tmp29, std::fabs(_tmp24));
  const Scalar _tmp31 = std::acos(_tmp30) / std::sqrt(1 - std::pow(_tmp30, Scalar(2)));
  const Scalar _tmp32 = _tmp28 * _tmp31;
  const Scalar _tmp33 =
      _a_T_b[0] * _tmp22 - _a_T_b[1] * _tmp4 - _a_T_b[2] * _tmp16 + _a_T_b[3] * _tmp10;
  const Scalar _tmp34 = _tmp26 * _tmp31;
  const Scalar _tmp35 = _tmp33 * _tmp34;
  const Scalar _tmp36 =
      -_a_T_b[0] * _tmp4 - _a_T_b[1] * _tmp22 + _a_T_b[2] * _tmp10 + _a_T_b[3] * _tmp16;
  const Scalar _tmp37 = _tmp34 * _tmp36;
  const Scalar _tmp38 = _tmp27 * _tmp32 + _tmp35 * sqrt_info(0, 1) + _tmp37 * sqrt_info(0, 0);
  const Scalar _tmp39 = _tmp26 * sqrt_info(1, 2);
  const Scalar _tmp40 = _tmp33 * sqrt_info(1, 1);
  const Scalar _tmp41 = _tmp32 * _tmp39 + _tmp34 * _tmp40 + _tmp37 * sqrt_info(1, 0);
  const Scalar _tmp42 = _tmp26 * sqrt_info(2, 2);
  const Scalar _tmp43 = _tmp32 * _tmp42 + _tmp35 * sqrt_info(2, 1) + _tmp37 * sqrt_info(2, 0);
  const Scalar _tmp44 = (Scalar(1) / Scalar(2)) * _tmp0;
  const Scalar _tmp45 = (Scalar(1) / Scalar(2)) * _tmp1;
  const Scalar _tmp46 = (Scalar(1) / Scalar(2)) * _tmp2;
  const Scalar _tmp47 = (Scalar(1) / Scalar(2)) * _tmp3;
  const Scalar _tmp48 = -_tmp44 - _tmp45 - _tmp46 - _tmp47;
  const Scalar _tmp49 = _a_T_b[3] * _tmp48;
  const Scalar _tmp50 = (Scalar(1) / Scalar(2)) * _tmp6;
  const Scalar _tmp51 = (Scalar(1) / Scalar(2)) * _tmp7;
  const Scalar _tmp52 = (Scalar(1) / Scalar(2)) * _tmp8;
  const Scalar _tmp53 = (Scalar(1) / Scalar(2)) * _tmp9;
  const Scalar _tmp54 = -_tmp50 + _tmp51 - _tmp52 + _tmp53;
  const Scalar _tmp55 = -_a_T_b[1] * _tmp54;
  const Scalar _tmp56 = (Scalar(1) / Scalar(2)) * _tmp18;
  const Scalar _tmp57 = (Scalar(1) / Scalar(2)) * _tmp19;
  const Scalar _tmp58 = (Scalar(1) / Scalar(2)) * _tmp20;
  const Scalar _tmp59 = (Scalar(1) / Scalar(2)) * _tmp21;
  const Scalar _tmp60 = _tmp56 - _tmp57 - _tmp58 + _tmp59;
  const Scalar _tmp61 = _a_T_b[2] * _tmp60;
  const Scalar _tmp62 = (Scalar(1) / Scalar(2)) * _tmp12;
  const Scalar _tmp63 = (Scalar(1) / Scalar(2)) * _tmp13;
  const Scalar _tmp64 = (Scalar(1) / Scalar(2)) * _tmp14;
  const Scalar _tmp65 = (Scalar(1) / Scalar(2)) * _tmp15;
  const Scalar _tmp66 = _tmp62 + _tmp63 - _tmp64 - _tmp65;
  const Scalar _tmp67 = _a_T_b[0] * _tmp66;
  const Scalar _tmp68 = _tmp11 + _tmp17 + _tmp23 + _tmp5;
  const Scalar _tmp69 = std::fabs(_tmp68);
  const Scalar _tmp70 = std::min<Scalar>(_tmp29, _tmp69);
  const Scalar _tmp71 = 1 - std::pow(_tmp70, Scalar(2));
  const Scalar _tmp72 = std::acos(_tmp70);
  const Scalar _tmp73 = _tmp72 / std::sqrt(_tmp71);
  const Scalar _tmp74 = _tmp26 * _tmp73;
  const Scalar _tmp75 = _tmp74 * (_tmp49 + _tmp55 + _tmp61 - _tmp67);
  const Scalar _tmp76 = _tmp36 * sqrt_info(0, 0);
  const Scalar _tmp77 = _a_T_b[3] * _tmp66;
  const Scalar _tmp78 = _a_T_b[0] * _tmp48;
  const Scalar _tmp79 = _a_T_b[2] * _tmp54;
  const Scalar _tmp80 = _a_T_b[1] * _tmp60;
  const Scalar _tmp81 = _tmp79 + _tmp80;
  const Scalar _tmp82 = _tmp77 + _tmp78 + _tmp81;
  const Scalar _tmp83 = _tmp25 * ((((_tmp29 - _tmp69) > 0) - ((_tmp29 - _tmp69) < 0)) + 1) *
                        (((_tmp68) > 0) - ((_tmp68) < 0));
  const Scalar _tmp84 = _tmp83 / _tmp71;
  const Scalar _tmp85 = _tmp82 * _tmp84;
  const Scalar _tmp86 = _tmp33 * _tmp84;
  const Scalar _tmp87 = _tmp86 * sqrt_info(0, 1);
  const Scalar _tmp88 = _tmp70 * _tmp72 * _tmp83 / (_tmp71 * std::sqrt(_tmp71));
  const Scalar _tmp89 = _tmp28 * _tmp88;
  const Scalar _tmp90 = _tmp82 * _tmp89;
  const Scalar _tmp91 = _tmp82 * _tmp88;
  const Scalar _tmp92 = -_a_T_b[1] * _tmp66;
  const Scalar _tmp93 = _a_T_b[2] * _tmp48;
  const Scalar _tmp94 = _a_T_b[0] * _tmp54;
  const Scalar _tmp95 = _a_T_b[3] * _tmp60;
  const Scalar _tmp96 = _tmp94 + _tmp95;
  const Scalar _tmp97 = _tmp92 - _tmp93 + _tmp96;
  const Scalar _tmp98 = _tmp74 * sqrt_info(0, 1);
  const Scalar _tmp99 = _a_T_b[1] * _tmp48;
  const Scalar _tmp100 = _a_T_b[3] * _tmp54;
  const Scalar _tmp101 = -_a_T_b[0] * _tmp60;
  const Scalar _tmp102 = _a_T_b[2] * _tmp66;
  const Scalar _tmp103 = _tmp100 + _tmp101 - _tmp102 + _tmp99;
  const Scalar _tmp104 = _tmp103 * _tmp73;
  const Scalar _tmp105 = _tmp33 * _tmp91;
  const Scalar _tmp106 = _tmp28 * _tmp84;
  const Scalar _tmp107 = _tmp106 * _tmp82;
  const Scalar _tmp108 = _tmp104 * _tmp27 + _tmp105 * sqrt_info(0, 1) - _tmp107 * sqrt_info(0, 2) +
                         _tmp75 * sqrt_info(0, 0) - _tmp76 * _tmp85 + _tmp76 * _tmp91 -
                         _tmp82 * _tmp87 + _tmp90 * sqrt_info(0, 2) + _tmp97 * _tmp98;
  const Scalar _tmp109 = _tmp50 - _tmp51 + _tmp52 - _tmp53;
  const Scalar _tmp110 = _a_T_b[3] * _tmp109;
  const Scalar _tmp111 = -_tmp56 + _tmp57 + _tmp58 - _tmp59;
  const Scalar _tmp112 = _a_T_b[0] * _tmp111;
  const Scalar _tmp113 = _tmp102 + _tmp112;
  const Scalar _tmp114 = _tmp110 + _tmp113 + _tmp99;
  const Scalar _tmp115 = _tmp106 * _tmp114;
  const Scalar _tmp116 = _tmp114 * _tmp84;
  const Scalar _tmp117 = _a_T_b[1] * _tmp109;
  const Scalar _tmp118 = -_a_T_b[2] * _tmp111;
  const Scalar _tmp119 = _tmp118 + _tmp67;
  const Scalar _tmp120 = -_tmp117 + _tmp119 + _tmp49;
  const Scalar _tmp121 = _tmp120 * _tmp74;
  const Scalar _tmp122 = _tmp114 * _tmp88;
  const Scalar _tmp123 = _tmp122 * _tmp33;
  const Scalar _tmp124 = _tmp122 * _tmp28;
  const Scalar _tmp125 = -_a_T_b[2] * _tmp109;
  const Scalar _tmp126 = _a_T_b[1] * _tmp111;
  const Scalar _tmp127 = _tmp126 + _tmp77;
  const Scalar _tmp128 = _tmp125 + _tmp127 - _tmp78;
  const Scalar _tmp129 = _tmp128 * _tmp73;
  const Scalar _tmp130 = _a_T_b[0] * _tmp109;
  const Scalar _tmp131 = _a_T_b[3] * _tmp111;
  const Scalar _tmp132 = _tmp74 * (-_tmp130 + _tmp131 + _tmp92 + _tmp93);
  const Scalar _tmp133 = -_tmp114 * _tmp87 - _tmp115 * sqrt_info(0, 2) - _tmp116 * _tmp76 +
                         _tmp121 * sqrt_info(0, 1) + _tmp122 * _tmp76 + _tmp123 * sqrt_info(0, 1) +
                         _tmp124 * sqrt_info(0, 2) + _tmp129 * _tmp27 + _tmp132 * sqrt_info(0, 0);
  const Scalar _tmp134 = -_tmp62 - _tmp63 + _tmp64 + _tmp65;
  const Scalar _tmp135 = _a_T_b[1] * _tmp134;
  const Scalar _tmp136 = _tmp130 + _tmp135;
  const Scalar _tmp137 = _tmp136 + _tmp93 + _tmp95;
  const Scalar _tmp138 = _tmp137 * _tmp89;
  const Scalar _tmp139 = _tmp137 * _tmp84;
  const Scalar _tmp140 = _tmp137 * _tmp88;
  const Scalar _tmp141 = _tmp140 * _tmp33;
  const Scalar _tmp142 = _a_T_b[2] * _tmp134;
  const Scalar _tmp143 = _tmp110 + _tmp142;
  const Scalar _tmp144 = _tmp74 * (_tmp101 + _tmp143 - _tmp99);
  const Scalar _tmp145 = _a_T_b[3] * _tmp134;
  const Scalar _tmp146 = _tmp125 + _tmp145 + _tmp78 - _tmp80;
  const Scalar _tmp147 = _tmp106 * _tmp137;
  const Scalar _tmp148 = -_a_T_b[0] * _tmp134;
  const Scalar _tmp149 = _tmp117 + _tmp148;
  const Scalar _tmp150 = _tmp149 + _tmp49 - _tmp61;
  const Scalar _tmp151 = _tmp150 * _tmp73;
  const Scalar _tmp152 = -_tmp137 * _tmp87 + _tmp138 * sqrt_info(0, 2) - _tmp139 * _tmp76 +
                         _tmp140 * _tmp76 + _tmp141 * sqrt_info(0, 1) + _tmp144 * sqrt_info(0, 0) +
                         _tmp146 * _tmp98 - _tmp147 * sqrt_info(0, 2) + _tmp151 * _tmp27;
  const Scalar _tmp153 = _tmp44 + _tmp45 + _tmp46 + _tmp47;
  const Scalar _tmp154 = _a_T_b[0] * _tmp153;
  const Scalar _tmp155 = _tmp145 + _tmp154;
  const Scalar _tmp156 = _tmp155 + _tmp81;
  const Scalar _tmp157 = _tmp156 * _tmp84;
  const Scalar _tmp158 = _tmp156 * _tmp88;
  const Scalar _tmp159 = _tmp158 * _tmp33;
  const Scalar _tmp160 = _tmp156 * _tmp89;
  const Scalar _tmp161 = _a_T_b[3] * _tmp153;
  const Scalar _tmp162 = _tmp161 + _tmp55;
  const Scalar _tmp163 = _tmp74 * (_tmp148 + _tmp162 + _tmp61);
  const Scalar _tmp164 = _a_T_b[2] * _tmp153;
  const Scalar _tmp165 = _tmp74 * (-_tmp135 - _tmp164 + _tmp96);
  const Scalar _tmp166 = _a_T_b[1] * _tmp153;
  const Scalar _tmp167 = _tmp100 + _tmp166;
  const Scalar _tmp168 = _tmp101 - _tmp142 + _tmp167;
  const Scalar _tmp169 = _tmp168 * _tmp73;
  const Scalar _tmp170 = _tmp106 * _tmp156;
  const Scalar _tmp171 = -_tmp156 * _tmp87 - _tmp157 * _tmp76 + _tmp158 * _tmp76 +
                         _tmp159 * sqrt_info(0, 1) + _tmp160 * sqrt_info(0, 2) +
                         _tmp163 * sqrt_info(0, 0) + _tmp165 * sqrt_info(0, 1) + _tmp169 * _tmp27 -
                         _tmp170 * sqrt_info(0, 2);
  const Scalar _tmp172 = _tmp113 + _tmp167;
  const Scalar _tmp173 = _tmp172 * _tmp84;
  const Scalar _tmp174 = _tmp173 * _tmp33;
  const Scalar _tmp175 = _tmp172 * _tmp89;
  const Scalar _tmp176 = _tmp172 * _tmp88;
  const Scalar _tmp177 = _tmp176 * _tmp33;
  const Scalar _tmp178 = _tmp119 + _tmp162;
  const Scalar _tmp179 = _tmp178 * _tmp74;
  const Scalar _tmp180 = _tmp131 + _tmp164;
  const Scalar _tmp181 = _tmp74 * (_tmp180 + _tmp92 - _tmp94);
  const Scalar _tmp182 = _tmp106 * _tmp172;
  const Scalar _tmp183 = _tmp127 - _tmp154 - _tmp79;
  const Scalar _tmp184 = _tmp183 * _tmp73;
  const Scalar _tmp185 = -_tmp173 * _tmp76 - _tmp174 * sqrt_info(0, 1) + _tmp175 * sqrt_info(0, 2) +
                         _tmp176 * _tmp76 + _tmp177 * sqrt_info(0, 1) + _tmp179 * sqrt_info(0, 1) +
                         _tmp181 * sqrt_info(0, 0) - _tmp182 * sqrt_info(0, 2) + _tmp184 * _tmp27;
  const Scalar _tmp186 = _tmp136 + _tmp180;
  const Scalar _tmp187 = _tmp186 * _tmp88;
  const Scalar _tmp188 = _tmp73 * (_tmp118 + _tmp149 + _tmp161);
  const Scalar _tmp189 = _tmp187 * _tmp33;
  const Scalar _tmp190 = _tmp106 * _tmp186;
  const Scalar _tmp191 = _tmp186 * _tmp89;
  const Scalar _tmp192 = _tmp186 * _tmp84;
  const Scalar _tmp193 = _tmp125 - _tmp126 + _tmp155;
  const Scalar _tmp194 = _tmp74 * (-_tmp112 + _tmp143 - _tmp166);
  const Scalar _tmp195 = -_tmp186 * _tmp87 + _tmp187 * _tmp76 + _tmp188 * _tmp27 +
                         _tmp189 * sqrt_info(0, 1) - _tmp190 * sqrt_info(0, 2) +
                         _tmp191 * sqrt_info(0, 2) - _tmp192 * _tmp76 + _tmp193 * _tmp98 +
                         _tmp194 * sqrt_info(0, 0);
  const Scalar _tmp196 = _tmp36 * sqrt_info(1, 0);
  const Scalar _tmp197 = _tmp40 * _tmp84;
  const Scalar _tmp198 = _tmp89 * sqrt_info(1, 2);
  const Scalar _tmp199 = _tmp74 * sqrt_info(1, 1);
  const Scalar _tmp200 = _tmp39 * _tmp73;
  const Scalar _tmp201 = _tmp103 * _tmp200 - _tmp107 * sqrt_info(1, 2) - _tmp196 * _tmp85 +
                         _tmp196 * _tmp91 - _tmp197 * _tmp82 + _tmp198 * _tmp82 + _tmp199 * _tmp97 +
                         _tmp40 * _tmp91 + _tmp75 * sqrt_info(1, 0);
  const Scalar _tmp202 = -_tmp114 * _tmp197 - _tmp115 * sqrt_info(1, 2) - _tmp116 * _tmp196 +
                         _tmp121 * sqrt_info(1, 1) + _tmp122 * _tmp196 + _tmp122 * _tmp40 +
                         _tmp124 * sqrt_info(1, 2) + _tmp128 * _tmp200 + _tmp132 * sqrt_info(1, 0);
  const Scalar _tmp203 = -_tmp137 * _tmp197 + _tmp138 * sqrt_info(1, 2) - _tmp139 * _tmp196 +
                         _tmp140 * _tmp196 + _tmp140 * _tmp40 + _tmp144 * sqrt_info(1, 0) +
                         _tmp146 * _tmp199 - _tmp147 * sqrt_info(1, 2) + _tmp150 * _tmp200;
  const Scalar _tmp204 = -_tmp156 * _tmp197 + _tmp156 * _tmp198 - _tmp157 * _tmp196 +
                         _tmp158 * _tmp196 + _tmp158 * _tmp40 + _tmp163 * sqrt_info(1, 0) +
                         _tmp165 * sqrt_info(1, 1) + _tmp168 * _tmp200 - _tmp170 * sqrt_info(1, 2);
  const Scalar _tmp205 = -_tmp173 * _tmp196 - _tmp173 * _tmp40 + _tmp175 * sqrt_info(1, 2) +
                         _tmp176 * _tmp196 + _tmp176 * _tmp40 + _tmp179 * sqrt_info(1, 1) +
                         _tmp181 * sqrt_info(1, 0) - _tmp182 * sqrt_info(1, 2) + _tmp183 * _tmp200;
  const Scalar _tmp206 = -_tmp186 * _tmp197 + _tmp186 * _tmp198 + _tmp187 * _tmp196 +
                         _tmp187 * _tmp40 + _tmp188 * _tmp39 - _tmp190 * sqrt_info(1, 2) -
                         _tmp192 * _tmp196 + _tmp193 * _tmp199 + _tmp194 * sqrt_info(1, 0);
  const Scalar _tmp207 = _tmp36 * sqrt_info(2, 0);
  const Scalar _tmp208 = _tmp86 * sqrt_info(2, 1);
  const Scalar _tmp209 = _tmp74 * sqrt_info(2, 1);
  const Scalar _tmp210 = _tmp104 * _tmp42 + _tmp105 * sqrt_info(2, 1) - _tmp107 * sqrt_info(2, 2) -
                         _tmp207 * _tmp85 + _tmp207 * _tmp91 - _tmp208 * _tmp82 + _tmp209 * _tmp97 +
                         _tmp75 * sqrt_info(2, 0) + _tmp90 * sqrt_info(2, 2);
  const Scalar _tmp211 = -_tmp114 * _tmp208 - _tmp115 * sqrt_info(2, 2) - _tmp116 * _tmp207 +
                         _tmp120 * _tmp209 + _tmp122 * _tmp207 + _tmp123 * sqrt_info(2, 1) +
                         _tmp124 * sqrt_info(2, 2) + _tmp129 * _tmp42 + _tmp132 * sqrt_info(2, 0);
  const Scalar _tmp212 = -_tmp137 * _tmp208 + _tmp138 * sqrt_info(2, 2) - _tmp139 * _tmp207 +
                         _tmp140 * _tmp207 + _tmp141 * sqrt_info(2, 1) + _tmp144 * sqrt_info(2, 0) +
                         _tmp146 * _tmp209 - _tmp147 * sqrt_info(2, 2) + _tmp151 * _tmp42;
  const Scalar _tmp213 = -_tmp156 * _tmp208 - _tmp157 * _tmp207 + _tmp158 * _tmp207 +
                         _tmp159 * sqrt_info(2, 1) + _tmp160 * sqrt_info(2, 2) +
                         _tmp163 * sqrt_info(2, 0) + _tmp165 * sqrt_info(2, 1) + _tmp169 * _tmp42 -
                         _tmp170 * sqrt_info(2, 2);
  const Scalar _tmp214 = -_tmp173 * _tmp207 - _tmp174 * sqrt_info(2, 1) +
                         _tmp175 * sqrt_info(2, 2) + _tmp176 * _tmp207 + _tmp177 * sqrt_info(2, 1) +
                         _tmp178 * _tmp209 + _tmp181 * sqrt_info(2, 0) - _tmp182 * sqrt_info(2, 2) +
                         _tmp184 * _tmp42;
  const Scalar _tmp215 = -_tmp186 * _tmp208 + _tmp187 * _tmp207 + _tmp188 * _tmp42 +
                         _tmp189 * sqrt_info(2, 1) - _tmp190 * sqrt_info(2, 2) +
                         _tmp191 * sqrt_info(2, 2) - _tmp192 * _tmp207 + _tmp193 * _tmp209 +
                         _tmp194 * sqrt_info(2, 0);

  // Output terms (4)
  if (res != nullptr) {
    Eigen::Matrix<Scalar, 3, 1>& _res = (*res);

    _res(0, 0) = _tmp38;
    _res(1, 0) = _tmp41;
    _res(2, 0) = _tmp43;
  }

  if (jacobian != nullptr) {
    Eigen::Matrix<Scalar, 3, 6>& _jacobian = (*jacobian);

    _jacobian(0, 0) = _tmp108;
    _jacobian(0, 1) = _tmp133;
    _jacobian(0, 2) = _tmp152;
    _jacobian(0, 3) = _tmp171;
    _jacobian(0, 4) = _tmp185;
    _jacobian(0, 5) = _tmp195;
    _jacobian(1, 0) = _tmp201;
    _jacobian(1, 1) = _tmp202;
    _jacobian(1, 2) = _tmp203;
    _jacobian(1, 3) = _tmp204;
    _jacobian(1, 4) = _tmp205;
    _jacobian(1, 5) = _tmp206;
    _jacobian(2, 0) = _tmp210;
    _jacobian(2, 1) = _tmp211;
    _jacobian(2, 2) = _tmp212;
    _jacobian(2, 3) = _tmp213;
    _jacobian(2, 4) = _tmp214;
    _jacobian(2, 5) = _tmp215;
  }

  if (hessian != nullptr) {
    Eigen::Matrix<Scalar, 6, 6>& _hessian = (*hessian);

    _hessian(0, 0) =
        std::pow(_tmp108, Scalar(2)) + std::pow(_tmp201, Scalar(2)) + std::pow(_tmp210, Scalar(2));
    _hessian(0, 1) = 0;
    _hessian(0, 2) = 0;
    _hessian(0, 3) = 0;
    _hessian(0, 4) = 0;
    _hessian(0, 5) = 0;
    _hessian(1, 0) = _tmp108 * _tmp133 + _tmp201 * _tmp202 + _tmp210 * _tmp211;
    _hessian(1, 1) =
        std::pow(_tmp133, Scalar(2)) + std::pow(_tmp202, Scalar(2)) + std::pow(_tmp211, Scalar(2));
    _hessian(1, 2) = 0;
    _hessian(1, 3) = 0;
    _hessian(1, 4) = 0;
    _hessian(1, 5) = 0;
    _hessian(2, 0) = _tmp108 * _tmp152 + _tmp201 * _tmp203 + _tmp210 * _tmp212;
    _hessian(2, 1) = _tmp133 * _tmp152 + _tmp202 * _tmp203 + _tmp211 * _tmp212;
    _hessian(2, 2) =
        std::pow(_tmp152, Scalar(2)) + std::pow(_tmp203, Scalar(2)) + std::pow(_tmp212, Scalar(2));
    _hessian(2, 3) = 0;
    _hessian(2, 4) = 0;
    _hessian(2, 5) = 0;
    _hessian(3, 0) = _tmp108 * _tmp171 + _tmp201 * _tmp204 + _tmp210 * _tmp213;
    _hessian(3, 1) = _tmp133 * _tmp171 + _tmp202 * _tmp204 + _tmp211 * _tmp213;
    _hessian(3, 2) = _tmp152 * _tmp171 + _tmp203 * _tmp204 + _tmp212 * _tmp213;
    _hessian(3, 3) =
        std::pow(_tmp171, Scalar(2)) + std::pow(_tmp204, Scalar(2)) + std::pow(_tmp213, Scalar(2));
    _hessian(3, 4) = 0;
    _hessian(3, 5) = 0;
    _hessian(4, 0) = _tmp108 * _tmp185 + _tmp201 * _tmp205 + _tmp210 * _tmp214;
    _hessian(4, 1) = _tmp133 * _tmp185 + _tmp202 * _tmp205 + _tmp211 * _tmp214;
    _hessian(4, 2) = _tmp152 * _tmp185 + _tmp203 * _tmp205 + _tmp212 * _tmp214;
    _hessian(4, 3) = _tmp171 * _tmp185 + _tmp204 * _tmp205 + _tmp213 * _tmp214;
    _hessian(4, 4) =
        std::pow(_tmp185, Scalar(2)) + std::pow(_tmp205, Scalar(2)) + std::pow(_tmp214, Scalar(2));
    _hessian(4, 5) = 0;
    _hessian(5, 0) = _tmp108 * _tmp195 + _tmp201 * _tmp206 + _tmp210 * _tmp215;
    _hessian(5, 1) = _tmp133 * _tmp195 + _tmp202 * _tmp206 + _tmp211 * _tmp215;
    _hessian(5, 2) = _tmp152 * _tmp195 + _tmp203 * _tmp206 + _tmp212 * _tmp215;
    _hessian(5, 3) = _tmp171 * _tmp195 + _tmp204 * _tmp206 + _tmp213 * _tmp215;
    _hessian(5, 4) = _tmp185 * _tmp195 + _tmp205 * _tmp206 + _tmp214 * _tmp215;
    _hessian(5, 5) =
        std::pow(_tmp195, Scalar(2)) + std::pow(_tmp206, Scalar(2)) + std::pow(_tmp215, Scalar(2));
  }

  if (rhs != nullptr) {
    Eigen::Matrix<Scalar, 6, 1>& _rhs = (*rhs);

    _rhs(0, 0) = _tmp108 * _tmp38 + _tmp201 * _tmp41 + _tmp210 * _tmp43;
    _rhs(1, 0) = _tmp133 * _tmp38 + _tmp202 * _tmp41 + _tmp211 * _tmp43;
    _rhs(2, 0) = _tmp152 * _tmp38 + _tmp203 * _tmp41 + _tmp212 * _tmp43;
    _rhs(3, 0) = _tmp171 * _tmp38 + _tmp204 * _tmp41 + _tmp213 * _tmp43;
    _rhs(4, 0) = _tmp185 * _tmp38 + _tmp205 * _tmp41 + _tmp214 * _tmp43;
    _rhs(5, 0) = _tmp195 * _tmp38 + _tmp206 * _tmp41 + _tmp215 * _tmp43;
  }
}  // NOLINT(readability/fn_size)

// NOLINTNEXTLINE(readability/fn_size)
}  // namespace sym
