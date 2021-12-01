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
 * Return the 2dof residual of reprojecting the landmark into the target camera and comparing
 * against the correspondence in the target camera.
 *
 * The landmark is specified as a pixel in the source camera and an inverse range; this means the
 * landmark is fixed in the source camera and always has residual 0 there (this 0 residual is not
 * returned, only the residual in the target camera is returned).
 *
 * The norm of the residual is whitened using the Barron noise model.  Whitening each component of
 * the reprojection error separately would result in rejecting individual components as outliers.
 * Instead, we minimize the whitened norm of the full reprojection error for each point.  See the
 * docstring for `NoiseModel.whiten_norm` for more information on this, and the docstring of
 * `BarronNoiseModel` for more information on the noise model.
 *
 * Args:
 *     source_pose: The pose of the source camera
 *     source_calibration_storage: The storage vector of the source (Linear) camera calibration
 *     target_pose: The pose of the target camera
 *     target_calibration_storage: The storage vector of the target (Linear) camera calibration
 *     source_inverse_range: The inverse range of the landmark in the source camera
 *     source_pixel: The location of the landmark in the source camera
 *     target_pixel: The location of the correspondence in the target camera
 *     weight: The weight of the factor
 *     gnc_mu: The mu convexity parameter for the Barron noise model
 *     gnc_scale: The scale parameter for the Barron noise model
 *     epsilon: Small positive value
 *
 * Outputs:
 *     res: 2dof residual of the reprojection
 *     jacobian: (2x13) jacobian of res wrt args source_pose (6), target_pose (6),
 *               source_inverse_range (1)
 *     hessian: (13x13) Gauss-Newton hessian for args source_pose (6), target_pose (6),
 *              source_inverse_range (1)
 *     rhs: (13x1) Gauss-Newton rhs for args source_pose (6), target_pose (6), source_inverse_range
 *          (1)
 */
template <typename Scalar>
void InverseRangeLandmarkReprojectionErrorFactor(
    const sym::Pose3<Scalar>& source_pose,
    const Eigen::Matrix<Scalar, 4, 1>& source_calibration_storage,
    const sym::Pose3<Scalar>& target_pose,
    const Eigen::Matrix<Scalar, 4, 1>& target_calibration_storage,
    const Scalar source_inverse_range, const Eigen::Matrix<Scalar, 2, 1>& source_pixel,
    const Eigen::Matrix<Scalar, 2, 1>& target_pixel, const Scalar weight, const Scalar gnc_mu,
    const Scalar gnc_scale, const Scalar epsilon, Eigen::Matrix<Scalar, 2, 1>* const res = nullptr,
    Eigen::Matrix<Scalar, 2, 13>* const jacobian = nullptr,
    Eigen::Matrix<Scalar, 13, 13>* const hessian = nullptr,
    Eigen::Matrix<Scalar, 13, 1>* const rhs = nullptr) {
  // Total ops: 965

  // Input arrays
  const Eigen::Matrix<Scalar, 7, 1>& _source_pose = source_pose.Data();
  const Eigen::Matrix<Scalar, 7, 1>& _target_pose = target_pose.Data();

  // Intermediate terms (227)
  const Scalar _tmp0 = std::pow(_target_pose[2], Scalar(2));
  const Scalar _tmp1 = -2 * _tmp0;
  const Scalar _tmp2 = std::pow(_target_pose[1], Scalar(2));
  const Scalar _tmp3 = 1 - 2 * _tmp2;
  const Scalar _tmp4 = _tmp1 + _tmp3;
  const Scalar _tmp5 = 2 * _source_pose[1];
  const Scalar _tmp6 = _source_pose[3] * _tmp5;
  const Scalar _tmp7 = 2 * _source_pose[2];
  const Scalar _tmp8 = _source_pose[0] * _tmp7;
  const Scalar _tmp9 = -source_calibration_storage(3, 0) + source_pixel(1, 0);
  const Scalar _tmp10 = -source_calibration_storage(2, 0) + source_pixel(0, 0);
  const Scalar _tmp11 = std::pow(
      Scalar(std::pow(_tmp10, Scalar(2)) / std::pow(source_calibration_storage(0, 0), Scalar(2)) +
             std::pow(_tmp9, Scalar(2)) / std::pow(source_calibration_storage(1, 0), Scalar(2)) +
             1),
      Scalar(Scalar(-1) / Scalar(2)));
  const Scalar _tmp12 = _tmp11 * (_tmp6 + _tmp8);
  const Scalar _tmp13 = std::pow(_source_pose[2], Scalar(2));
  const Scalar _tmp14 = -2 * _tmp13;
  const Scalar _tmp15 = std::pow(_source_pose[1], Scalar(2));
  const Scalar _tmp16 = 1 - 2 * _tmp15;
  const Scalar _tmp17 = _tmp10 / source_calibration_storage(0, 0);
  const Scalar _tmp18 = _tmp11 * _tmp17;
  const Scalar _tmp19 = _source_pose[4] - _target_pose[4];
  const Scalar _tmp20 = _source_pose[0] * _tmp5;
  const Scalar _tmp21 = _source_pose[3] * _tmp7;
  const Scalar _tmp22 = -_tmp21;
  const Scalar _tmp23 = _tmp20 + _tmp22;
  const Scalar _tmp24 = _tmp9 / source_calibration_storage(1, 0);
  const Scalar _tmp25 = _tmp11 * _tmp24;
  const Scalar _tmp26 =
      _tmp12 + _tmp18 * (_tmp14 + _tmp16) + _tmp19 * source_inverse_range + _tmp23 * _tmp25;
  const Scalar _tmp27 = 2 * _target_pose[0] * _target_pose[2];
  const Scalar _tmp28 = 2 * _target_pose[3];
  const Scalar _tmp29 = _target_pose[1] * _tmp28;
  const Scalar _tmp30 = -_tmp29;
  const Scalar _tmp31 = _tmp27 + _tmp30;
  const Scalar _tmp32 = std::pow(_source_pose[0], Scalar(2));
  const Scalar _tmp33 = -2 * _tmp32;
  const Scalar _tmp34 = _source_pose[1] * _tmp7;
  const Scalar _tmp35 = 2 * _source_pose[0] * _source_pose[3];
  const Scalar _tmp36 = _tmp11 * (_tmp34 + _tmp35);
  const Scalar _tmp37 = -_tmp6;
  const Scalar _tmp38 = _tmp11 * (_tmp37 + _tmp8);
  const Scalar _tmp39 = _source_pose[6] - _target_pose[6];
  const Scalar _tmp40 = _tmp11 * (_tmp16 + _tmp33) + _tmp17 * _tmp38 + _tmp24 * _tmp36 +
                        _tmp39 * source_inverse_range;
  const Scalar _tmp41 = _target_pose[2] * _tmp28;
  const Scalar _tmp42 = 2 * _target_pose[1];
  const Scalar _tmp43 = _target_pose[0] * _tmp42;
  const Scalar _tmp44 = _tmp41 + _tmp43;
  const Scalar _tmp45 = -_tmp35;
  const Scalar _tmp46 = _tmp11 * (_tmp34 + _tmp45);
  const Scalar _tmp47 = _source_pose[5] - _target_pose[5];
  const Scalar _tmp48 = _tmp11 * (_tmp20 + _tmp21);
  const Scalar _tmp49 =
      _tmp17 * _tmp48 + _tmp25 * (_tmp14 + _tmp33 + 1) + _tmp46 + _tmp47 * source_inverse_range;
  const Scalar _tmp50 = _tmp31 * _tmp40 + _tmp44 * _tmp49;
  const Scalar _tmp51 = _tmp26 * _tmp4 + _tmp50;
  const Scalar _tmp52 = std::pow(_target_pose[0], Scalar(2));
  const Scalar _tmp53 = -2 * _tmp52;
  const Scalar _tmp54 = _tmp3 + _tmp53;
  const Scalar _tmp55 = _target_pose[2] * _tmp42;
  const Scalar _tmp56 = _target_pose[0] * _tmp28;
  const Scalar _tmp57 = -_tmp56;
  const Scalar _tmp58 = _tmp55 + _tmp57;
  const Scalar _tmp59 = _tmp27 + _tmp29;
  const Scalar _tmp60 = _tmp26 * _tmp59 + _tmp49 * _tmp58;
  const Scalar _tmp61 = _tmp40 * _tmp54 + _tmp60;
  const Scalar _tmp62 = std::fabs(_tmp61);
  const Scalar _tmp63 = std::max<Scalar>(_tmp62, epsilon);
  const Scalar _tmp64 = Scalar(1.0) / (_tmp63);
  const Scalar _tmp65 = _tmp64 * target_calibration_storage(0, 0);
  const Scalar _tmp66 = _tmp51 * _tmp65 + target_calibration_storage(2, 0) - target_pixel(0, 0);
  const Scalar _tmp67 = _tmp1 + _tmp53 + 1;
  const Scalar _tmp68 = _tmp55 + _tmp56;
  const Scalar _tmp69 = -_tmp41;
  const Scalar _tmp70 = _tmp43 + _tmp69;
  const Scalar _tmp71 = _tmp26 * _tmp70 + _tmp40 * _tmp68;
  const Scalar _tmp72 = _tmp49 * _tmp67 + _tmp71;
  const Scalar _tmp73 = _tmp64 * target_calibration_storage(1, 0);
  const Scalar _tmp74 = _tmp72 * _tmp73 + target_calibration_storage(3, 0) - target_pixel(1, 0);
  const Scalar _tmp75 = std::pow(_tmp66, Scalar(2)) + std::pow(_tmp74, Scalar(2)) + epsilon;
  const Scalar _tmp76 = std::pow(_tmp75, Scalar(Scalar(-1) / Scalar(2)));
  const Scalar _tmp77 = Scalar(1.0) / (epsilon - gnc_mu + 1);
  const Scalar _tmp78 = epsilon + std::fabs(_tmp77);
  const Scalar _tmp79 = std::pow(gnc_scale, Scalar(-2));
  const Scalar _tmp80 = _tmp75 * _tmp79 / _tmp78 + 1;
  const Scalar _tmp81 = 2 - _tmp77;
  const Scalar _tmp82 =
      _tmp81 + epsilon * (2 * std::min<Scalar>(0, (((_tmp81) > 0) - ((_tmp81) < 0))) + 1);
  const Scalar _tmp83 = (Scalar(1) / Scalar(2)) * _tmp82;
  const Scalar _tmp84 = std::sqrt(2) * std::sqrt(_tmp78 * (std::pow(_tmp80, _tmp83) - 1) / _tmp82);
  const Scalar _tmp85 = (((_tmp61) > 0) - ((_tmp61) < 0));
  const Scalar _tmp86 = std::sqrt(weight) * std::sqrt(std::max<Scalar>(0, _tmp85));
  const Scalar _tmp87 = _tmp84 * _tmp86;
  const Scalar _tmp88 = _tmp76 * _tmp87;
  const Scalar _tmp89 = _tmp66 * _tmp88;
  const Scalar _tmp90 = _tmp74 * _tmp88;
  const Scalar _tmp91 = -_tmp20;
  const Scalar _tmp92 = _tmp11 * (_tmp21 + _tmp91) + _tmp12 * _tmp24;
  const Scalar _tmp93 = std::pow(_source_pose[3], Scalar(2));
  const Scalar _tmp94 = -_tmp93;
  const Scalar _tmp95 = _tmp13 + _tmp94;
  const Scalar _tmp96 = -_tmp15;
  const Scalar _tmp97 = _tmp32 + _tmp96;
  const Scalar _tmp98 = _tmp11 * (_tmp95 + _tmp97) + _tmp24 * _tmp46;
  const Scalar _tmp99 = -_tmp34;
  const Scalar _tmp100 = -_tmp32;
  const Scalar _tmp101 = _tmp11 * (_tmp45 + _tmp99) + _tmp25 * (_tmp100 + _tmp13 + _tmp93 + _tmp96);
  const Scalar _tmp102 = _tmp101 * _tmp54 + _tmp58 * _tmp98 + _tmp59 * _tmp92;
  const Scalar _tmp103 = _tmp72 * target_calibration_storage(1, 0);
  const Scalar _tmp104 = _tmp85 * ((((_tmp62 - epsilon) > 0) - ((_tmp62 - epsilon) < 0)) + 1) /
                         std::pow(_tmp63, Scalar(2));
  const Scalar _tmp105 = (Scalar(1) / Scalar(2)) * _tmp104;
  const Scalar _tmp106 = _tmp103 * _tmp105;
  const Scalar _tmp107 =
      -_tmp102 * _tmp106 + _tmp73 * (_tmp101 * _tmp68 + _tmp67 * _tmp98 + _tmp70 * _tmp92);
  const Scalar _tmp108 = 2 * _tmp74;
  const Scalar _tmp109 = _tmp51 * target_calibration_storage(0, 0);
  const Scalar _tmp110 = _tmp105 * _tmp109;
  const Scalar _tmp111 =
      -_tmp102 * _tmp110 + _tmp65 * (_tmp101 * _tmp31 + _tmp4 * _tmp92 + _tmp44 * _tmp98);
  const Scalar _tmp112 = 2 * _tmp66;
  const Scalar _tmp113 = _tmp107 * _tmp108 + _tmp111 * _tmp112;
  const Scalar _tmp114 = _tmp87 / (_tmp75 * std::sqrt(_tmp75));
  const Scalar _tmp115 = (Scalar(1) / Scalar(2)) * _tmp66;
  const Scalar _tmp116 = _tmp114 * _tmp115;
  const Scalar _tmp117 = _tmp76 * _tmp79 * std::pow(_tmp80, Scalar(_tmp83 - 1)) * _tmp86 / _tmp84;
  const Scalar _tmp118 = _tmp115 * _tmp117;
  const Scalar _tmp119 = _tmp111 * _tmp88 - _tmp113 * _tmp116 + _tmp113 * _tmp118;
  const Scalar _tmp120 = -_tmp13;
  const Scalar _tmp121 = _tmp18 * (_tmp120 + _tmp15 + _tmp32 + _tmp94) + _tmp38;
  const Scalar _tmp122 = _tmp120 + _tmp93;
  const Scalar _tmp123 = -_tmp8;
  const Scalar _tmp124 = _tmp11 * (_tmp122 + _tmp97) + _tmp18 * (_tmp123 + _tmp37);
  const Scalar _tmp125 = _tmp18 * (_tmp35 + _tmp99) + _tmp48;
  const Scalar _tmp126 = _tmp121 * _tmp54 + _tmp124 * _tmp59 + _tmp125 * _tmp58;
  const Scalar _tmp127 =
      -_tmp106 * _tmp126 + _tmp73 * (_tmp121 * _tmp68 + _tmp124 * _tmp70 + _tmp125 * _tmp67);
  const Scalar _tmp128 =
      -_tmp110 * _tmp126 + _tmp65 * (_tmp121 * _tmp31 + _tmp124 * _tmp4 + _tmp125 * _tmp44);
  const Scalar _tmp129 = _tmp108 * _tmp127 + _tmp112 * _tmp128;
  const Scalar _tmp130 = -_tmp116 * _tmp129 + _tmp118 * _tmp129 + _tmp128 * _tmp88;
  const Scalar _tmp131 = _tmp100 + _tmp15;
  const Scalar _tmp132 = _tmp18 * (_tmp122 + _tmp131) + _tmp25 * (_tmp22 + _tmp91);
  const Scalar _tmp133 = _tmp18 * _tmp23 + _tmp25 * (_tmp131 + _tmp95);
  const Scalar _tmp134 = _tmp17 * _tmp36 + _tmp25 * (_tmp123 + _tmp6);
  const Scalar _tmp135 = _tmp132 * _tmp58 + _tmp133 * _tmp59 + _tmp134 * _tmp54;
  const Scalar _tmp136 =
      -_tmp110 * _tmp135 + _tmp65 * (_tmp132 * _tmp44 + _tmp133 * _tmp4 + _tmp134 * _tmp31);
  const Scalar _tmp137 =
      -_tmp106 * _tmp135 + _tmp73 * (_tmp132 * _tmp67 + _tmp133 * _tmp70 + _tmp134 * _tmp68);
  const Scalar _tmp138 = _tmp108 * _tmp137 + _tmp112 * _tmp136;
  const Scalar _tmp139 = -_tmp116 * _tmp138 + _tmp118 * _tmp138 + _tmp136 * _tmp88;
  const Scalar _tmp140 = _tmp65 * source_inverse_range;
  const Scalar _tmp141 = _tmp140 * _tmp4;
  const Scalar _tmp142 = _tmp110 * source_inverse_range;
  const Scalar _tmp143 = _tmp142 * _tmp59;
  const Scalar _tmp144 = _tmp141 - _tmp143;
  const Scalar _tmp145 = _tmp73 * source_inverse_range;
  const Scalar _tmp146 = _tmp145 * _tmp70;
  const Scalar _tmp147 = _tmp106 * source_inverse_range;
  const Scalar _tmp148 = _tmp147 * _tmp59;
  const Scalar _tmp149 = _tmp146 - _tmp148;
  const Scalar _tmp150 = _tmp108 * _tmp149 + _tmp112 * _tmp144;
  const Scalar _tmp151 = -_tmp116 * _tmp150 + _tmp118 * _tmp150 + _tmp144 * _tmp88;
  const Scalar _tmp152 = _tmp140 * _tmp44;
  const Scalar _tmp153 = _tmp142 * _tmp58;
  const Scalar _tmp154 = _tmp152 - _tmp153;
  const Scalar _tmp155 = _tmp147 * _tmp58;
  const Scalar _tmp156 = _tmp145 * _tmp67;
  const Scalar _tmp157 = -_tmp155 + _tmp156;
  const Scalar _tmp158 = _tmp108 * _tmp157 + _tmp112 * _tmp154;
  const Scalar _tmp159 = -_tmp116 * _tmp158 + _tmp118 * _tmp158 + _tmp154 * _tmp88;
  const Scalar _tmp160 = _tmp145 * _tmp68;
  const Scalar _tmp161 = _tmp147 * _tmp54;
  const Scalar _tmp162 = _tmp160 - _tmp161;
  const Scalar _tmp163 = _tmp140 * _tmp31;
  const Scalar _tmp164 = _tmp142 * _tmp54;
  const Scalar _tmp165 = _tmp163 - _tmp164;
  const Scalar _tmp166 = _tmp108 * _tmp162 + _tmp112 * _tmp165;
  const Scalar _tmp167 = -_tmp116 * _tmp166 + _tmp118 * _tmp166 + _tmp165 * _tmp88;
  const Scalar _tmp168 = -_tmp55;
  const Scalar _tmp169 = std::pow(_target_pose[3], Scalar(2));
  const Scalar _tmp170 = -_tmp169;
  const Scalar _tmp171 = -_tmp2;
  const Scalar _tmp172 = -_tmp43;
  const Scalar _tmp173 = _tmp26 * (_tmp172 + _tmp41) + _tmp40 * (_tmp168 + _tmp57) +
                         _tmp49 * (_tmp0 + _tmp170 + _tmp171 + _tmp52);
  const Scalar _tmp174 = _tmp169 + _tmp171;
  const Scalar _tmp175 = -_tmp52;
  const Scalar _tmp176 = _tmp0 + _tmp175;
  const Scalar _tmp177 = -_tmp106 * _tmp173 + _tmp73 * (_tmp40 * (_tmp174 + _tmp176) + _tmp60);
  const Scalar _tmp178 = -_tmp104 * _tmp109 * _tmp173 * _tmp66 + _tmp108 * _tmp177;
  const Scalar _tmp179 = -_tmp110 * _tmp173 * _tmp88 - _tmp116 * _tmp178 + _tmp118 * _tmp178;
  const Scalar _tmp180 = -_tmp0;
  const Scalar _tmp181 = _tmp180 + _tmp52;
  const Scalar _tmp182 = _tmp104 * (_tmp26 * (_tmp174 + _tmp181) + _tmp50);
  const Scalar _tmp183 = _tmp103 * _tmp182;
  const Scalar _tmp184 = _tmp170 + _tmp2;
  const Scalar _tmp185 = -_tmp27;
  const Scalar _tmp186 = -Scalar(1) / Scalar(2) * _tmp109 * _tmp182 +
                         _tmp65 * (_tmp26 * (_tmp185 + _tmp30) + _tmp40 * (_tmp181 + _tmp184) +
                                   _tmp49 * (_tmp168 + _tmp56));
  const Scalar _tmp187 = _tmp112 * _tmp186 - _tmp183 * _tmp74;
  const Scalar _tmp188 = -_tmp116 * _tmp187 + _tmp118 * _tmp187 + _tmp186 * _tmp88;
  const Scalar _tmp189 = _tmp65 * (_tmp49 * (_tmp169 + _tmp175 + _tmp180 + _tmp2) + _tmp71);
  const Scalar _tmp190 = _tmp73 * (_tmp26 * (_tmp176 + _tmp184) + _tmp40 * (_tmp185 + _tmp29) +
                                   _tmp49 * (_tmp172 + _tmp69));
  const Scalar _tmp191 = _tmp108 * _tmp190 + _tmp112 * _tmp189;
  const Scalar _tmp192 = -_tmp116 * _tmp191 + _tmp118 * _tmp191 + _tmp189 * _tmp88;
  const Scalar _tmp193 = -_tmp141 + _tmp143;
  const Scalar _tmp194 = -_tmp146 + _tmp148;
  const Scalar _tmp195 = _tmp108 * _tmp194 + _tmp112 * _tmp193;
  const Scalar _tmp196 = -_tmp116 * _tmp195 + _tmp118 * _tmp195 + _tmp193 * _tmp88;
  const Scalar _tmp197 = -_tmp152 + _tmp153;
  const Scalar _tmp198 = _tmp155 - _tmp156;
  const Scalar _tmp199 = _tmp108 * _tmp198 + _tmp112 * _tmp197;
  const Scalar _tmp200 = -_tmp116 * _tmp199 + _tmp118 * _tmp199 + _tmp197 * _tmp88;
  const Scalar _tmp201 = -_tmp163 + _tmp164;
  const Scalar _tmp202 = -_tmp160 + _tmp161;
  const Scalar _tmp203 = _tmp108 * _tmp202 + _tmp112 * _tmp201;
  const Scalar _tmp204 = -_tmp116 * _tmp203 + _tmp118 * _tmp203 + _tmp201 * _tmp88;
  const Scalar _tmp205 = _tmp19 * _tmp59 + _tmp39 * _tmp54 + _tmp47 * _tmp58;
  const Scalar _tmp206 =
      -_tmp106 * _tmp205 + _tmp73 * (_tmp19 * _tmp70 + _tmp39 * _tmp68 + _tmp47 * _tmp67);
  const Scalar _tmp207 =
      -_tmp110 * _tmp205 + _tmp65 * (_tmp19 * _tmp4 + _tmp31 * _tmp39 + _tmp44 * _tmp47);
  const Scalar _tmp208 = _tmp108 * _tmp206 + _tmp112 * _tmp207;
  const Scalar _tmp209 = -_tmp116 * _tmp208 + _tmp118 * _tmp208 + _tmp207 * _tmp88;
  const Scalar _tmp210 = (Scalar(1) / Scalar(2)) * _tmp74;
  const Scalar _tmp211 = _tmp114 * _tmp210;
  const Scalar _tmp212 = _tmp117 * _tmp210;
  const Scalar _tmp213 = _tmp107 * _tmp88 - _tmp113 * _tmp211 + _tmp113 * _tmp212;
  const Scalar _tmp214 = _tmp127 * _tmp88 - _tmp129 * _tmp211 + _tmp129 * _tmp212;
  const Scalar _tmp215 = _tmp137 * _tmp88 - _tmp138 * _tmp211 + _tmp138 * _tmp212;
  const Scalar _tmp216 = _tmp149 * _tmp88 - _tmp150 * _tmp211 + _tmp150 * _tmp212;
  const Scalar _tmp217 = _tmp157 * _tmp88 - _tmp158 * _tmp211 + _tmp158 * _tmp212;
  const Scalar _tmp218 = _tmp162 * _tmp88 - _tmp166 * _tmp211 + _tmp166 * _tmp212;
  const Scalar _tmp219 = _tmp177 * _tmp88 - _tmp178 * _tmp211 + _tmp178 * _tmp212;
  const Scalar _tmp220 =
      -Scalar(1) / Scalar(2) * _tmp183 * _tmp88 - _tmp187 * _tmp211 + _tmp187 * _tmp212;
  const Scalar _tmp221 = _tmp190 * _tmp88 - _tmp191 * _tmp211 + _tmp191 * _tmp212;
  const Scalar _tmp222 = _tmp194 * _tmp88 - _tmp195 * _tmp211 + _tmp195 * _tmp212;
  const Scalar _tmp223 = _tmp199 * _tmp210;
  const Scalar _tmp224 = -_tmp114 * _tmp223 + _tmp117 * _tmp223 + _tmp198 * _tmp88;
  const Scalar _tmp225 = _tmp202 * _tmp88 - _tmp203 * _tmp211 + _tmp203 * _tmp212;
  const Scalar _tmp226 = _tmp206 * _tmp88 - _tmp208 * _tmp211 + _tmp208 * _tmp212;

  // Output terms (4)
  if (res != nullptr) {
    Eigen::Matrix<Scalar, 2, 1>& _res = (*res);

    _res(0, 0) = _tmp89;
    _res(1, 0) = _tmp90;
  }

  if (jacobian != nullptr) {
    Eigen::Matrix<Scalar, 2, 13>& _jacobian = (*jacobian);

    _jacobian(0, 0) = _tmp119;
    _jacobian(0, 1) = _tmp130;
    _jacobian(0, 2) = _tmp139;
    _jacobian(0, 3) = _tmp151;
    _jacobian(0, 4) = _tmp159;
    _jacobian(0, 5) = _tmp167;
    _jacobian(0, 6) = _tmp179;
    _jacobian(0, 7) = _tmp188;
    _jacobian(0, 8) = _tmp192;
    _jacobian(0, 9) = _tmp196;
    _jacobian(0, 10) = _tmp200;
    _jacobian(0, 11) = _tmp204;
    _jacobian(0, 12) = _tmp209;
    _jacobian(1, 0) = _tmp213;
    _jacobian(1, 1) = _tmp214;
    _jacobian(1, 2) = _tmp215;
    _jacobian(1, 3) = _tmp216;
    _jacobian(1, 4) = _tmp217;
    _jacobian(1, 5) = _tmp218;
    _jacobian(1, 6) = _tmp219;
    _jacobian(1, 7) = _tmp220;
    _jacobian(1, 8) = _tmp221;
    _jacobian(1, 9) = _tmp222;
    _jacobian(1, 10) = _tmp224;
    _jacobian(1, 11) = _tmp225;
    _jacobian(1, 12) = _tmp226;
  }

  if (hessian != nullptr) {
    Eigen::Matrix<Scalar, 13, 13>& _hessian = (*hessian);

    _hessian(0, 0) = std::pow(_tmp119, Scalar(2)) + std::pow(_tmp213, Scalar(2));
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
    _hessian(0, 12) = 0;
    _hessian(1, 0) = _tmp119 * _tmp130 + _tmp213 * _tmp214;
    _hessian(1, 1) = std::pow(_tmp130, Scalar(2)) + std::pow(_tmp214, Scalar(2));
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
    _hessian(1, 12) = 0;
    _hessian(2, 0) = _tmp119 * _tmp139 + _tmp213 * _tmp215;
    _hessian(2, 1) = _tmp130 * _tmp139 + _tmp214 * _tmp215;
    _hessian(2, 2) = std::pow(_tmp139, Scalar(2)) + std::pow(_tmp215, Scalar(2));
    _hessian(2, 3) = 0;
    _hessian(2, 4) = 0;
    _hessian(2, 5) = 0;
    _hessian(2, 6) = 0;
    _hessian(2, 7) = 0;
    _hessian(2, 8) = 0;
    _hessian(2, 9) = 0;
    _hessian(2, 10) = 0;
    _hessian(2, 11) = 0;
    _hessian(2, 12) = 0;
    _hessian(3, 0) = _tmp119 * _tmp151 + _tmp213 * _tmp216;
    _hessian(3, 1) = _tmp130 * _tmp151 + _tmp214 * _tmp216;
    _hessian(3, 2) = _tmp139 * _tmp151 + _tmp215 * _tmp216;
    _hessian(3, 3) = std::pow(_tmp151, Scalar(2)) + std::pow(_tmp216, Scalar(2));
    _hessian(3, 4) = 0;
    _hessian(3, 5) = 0;
    _hessian(3, 6) = 0;
    _hessian(3, 7) = 0;
    _hessian(3, 8) = 0;
    _hessian(3, 9) = 0;
    _hessian(3, 10) = 0;
    _hessian(3, 11) = 0;
    _hessian(3, 12) = 0;
    _hessian(4, 0) = _tmp119 * _tmp159 + _tmp213 * _tmp217;
    _hessian(4, 1) = _tmp130 * _tmp159 + _tmp214 * _tmp217;
    _hessian(4, 2) = _tmp139 * _tmp159 + _tmp215 * _tmp217;
    _hessian(4, 3) = _tmp151 * _tmp159 + _tmp216 * _tmp217;
    _hessian(4, 4) = std::pow(_tmp159, Scalar(2)) + std::pow(_tmp217, Scalar(2));
    _hessian(4, 5) = 0;
    _hessian(4, 6) = 0;
    _hessian(4, 7) = 0;
    _hessian(4, 8) = 0;
    _hessian(4, 9) = 0;
    _hessian(4, 10) = 0;
    _hessian(4, 11) = 0;
    _hessian(4, 12) = 0;
    _hessian(5, 0) = _tmp119 * _tmp167 + _tmp213 * _tmp218;
    _hessian(5, 1) = _tmp130 * _tmp167 + _tmp214 * _tmp218;
    _hessian(5, 2) = _tmp139 * _tmp167 + _tmp215 * _tmp218;
    _hessian(5, 3) = _tmp151 * _tmp167 + _tmp216 * _tmp218;
    _hessian(5, 4) = _tmp159 * _tmp167 + _tmp217 * _tmp218;
    _hessian(5, 5) = std::pow(_tmp167, Scalar(2)) + std::pow(_tmp218, Scalar(2));
    _hessian(5, 6) = 0;
    _hessian(5, 7) = 0;
    _hessian(5, 8) = 0;
    _hessian(5, 9) = 0;
    _hessian(5, 10) = 0;
    _hessian(5, 11) = 0;
    _hessian(5, 12) = 0;
    _hessian(6, 0) = _tmp119 * _tmp179 + _tmp213 * _tmp219;
    _hessian(6, 1) = _tmp130 * _tmp179 + _tmp214 * _tmp219;
    _hessian(6, 2) = _tmp139 * _tmp179 + _tmp215 * _tmp219;
    _hessian(6, 3) = _tmp151 * _tmp179 + _tmp216 * _tmp219;
    _hessian(6, 4) = _tmp159 * _tmp179 + _tmp217 * _tmp219;
    _hessian(6, 5) = _tmp167 * _tmp179 + _tmp218 * _tmp219;
    _hessian(6, 6) = std::pow(_tmp179, Scalar(2)) + std::pow(_tmp219, Scalar(2));
    _hessian(6, 7) = 0;
    _hessian(6, 8) = 0;
    _hessian(6, 9) = 0;
    _hessian(6, 10) = 0;
    _hessian(6, 11) = 0;
    _hessian(6, 12) = 0;
    _hessian(7, 0) = _tmp119 * _tmp188 + _tmp213 * _tmp220;
    _hessian(7, 1) = _tmp130 * _tmp188 + _tmp214 * _tmp220;
    _hessian(7, 2) = _tmp139 * _tmp188 + _tmp215 * _tmp220;
    _hessian(7, 3) = _tmp151 * _tmp188 + _tmp216 * _tmp220;
    _hessian(7, 4) = _tmp159 * _tmp188 + _tmp217 * _tmp220;
    _hessian(7, 5) = _tmp167 * _tmp188 + _tmp218 * _tmp220;
    _hessian(7, 6) = _tmp179 * _tmp188 + _tmp219 * _tmp220;
    _hessian(7, 7) = std::pow(_tmp188, Scalar(2)) + std::pow(_tmp220, Scalar(2));
    _hessian(7, 8) = 0;
    _hessian(7, 9) = 0;
    _hessian(7, 10) = 0;
    _hessian(7, 11) = 0;
    _hessian(7, 12) = 0;
    _hessian(8, 0) = _tmp119 * _tmp192 + _tmp213 * _tmp221;
    _hessian(8, 1) = _tmp130 * _tmp192 + _tmp214 * _tmp221;
    _hessian(8, 2) = _tmp139 * _tmp192 + _tmp215 * _tmp221;
    _hessian(8, 3) = _tmp151 * _tmp192 + _tmp216 * _tmp221;
    _hessian(8, 4) = _tmp159 * _tmp192 + _tmp217 * _tmp221;
    _hessian(8, 5) = _tmp167 * _tmp192 + _tmp218 * _tmp221;
    _hessian(8, 6) = _tmp179 * _tmp192 + _tmp219 * _tmp221;
    _hessian(8, 7) = _tmp188 * _tmp192 + _tmp220 * _tmp221;
    _hessian(8, 8) = std::pow(_tmp192, Scalar(2)) + std::pow(_tmp221, Scalar(2));
    _hessian(8, 9) = 0;
    _hessian(8, 10) = 0;
    _hessian(8, 11) = 0;
    _hessian(8, 12) = 0;
    _hessian(9, 0) = _tmp119 * _tmp196 + _tmp213 * _tmp222;
    _hessian(9, 1) = _tmp130 * _tmp196 + _tmp214 * _tmp222;
    _hessian(9, 2) = _tmp139 * _tmp196 + _tmp215 * _tmp222;
    _hessian(9, 3) = _tmp151 * _tmp196 + _tmp216 * _tmp222;
    _hessian(9, 4) = _tmp159 * _tmp196 + _tmp217 * _tmp222;
    _hessian(9, 5) = _tmp167 * _tmp196 + _tmp218 * _tmp222;
    _hessian(9, 6) = _tmp179 * _tmp196 + _tmp219 * _tmp222;
    _hessian(9, 7) = _tmp188 * _tmp196 + _tmp220 * _tmp222;
    _hessian(9, 8) = _tmp192 * _tmp196 + _tmp221 * _tmp222;
    _hessian(9, 9) = std::pow(_tmp196, Scalar(2)) + std::pow(_tmp222, Scalar(2));
    _hessian(9, 10) = 0;
    _hessian(9, 11) = 0;
    _hessian(9, 12) = 0;
    _hessian(10, 0) = _tmp119 * _tmp200 + _tmp213 * _tmp224;
    _hessian(10, 1) = _tmp130 * _tmp200 + _tmp214 * _tmp224;
    _hessian(10, 2) = _tmp139 * _tmp200 + _tmp215 * _tmp224;
    _hessian(10, 3) = _tmp151 * _tmp200 + _tmp216 * _tmp224;
    _hessian(10, 4) = _tmp159 * _tmp200 + _tmp217 * _tmp224;
    _hessian(10, 5) = _tmp167 * _tmp200 + _tmp218 * _tmp224;
    _hessian(10, 6) = _tmp179 * _tmp200 + _tmp219 * _tmp224;
    _hessian(10, 7) = _tmp188 * _tmp200 + _tmp220 * _tmp224;
    _hessian(10, 8) = _tmp192 * _tmp200 + _tmp221 * _tmp224;
    _hessian(10, 9) = _tmp196 * _tmp200 + _tmp222 * _tmp224;
    _hessian(10, 10) = std::pow(_tmp200, Scalar(2)) + std::pow(_tmp224, Scalar(2));
    _hessian(10, 11) = 0;
    _hessian(10, 12) = 0;
    _hessian(11, 0) = _tmp119 * _tmp204 + _tmp213 * _tmp225;
    _hessian(11, 1) = _tmp130 * _tmp204 + _tmp214 * _tmp225;
    _hessian(11, 2) = _tmp139 * _tmp204 + _tmp215 * _tmp225;
    _hessian(11, 3) = _tmp151 * _tmp204 + _tmp216 * _tmp225;
    _hessian(11, 4) = _tmp159 * _tmp204 + _tmp217 * _tmp225;
    _hessian(11, 5) = _tmp167 * _tmp204 + _tmp218 * _tmp225;
    _hessian(11, 6) = _tmp179 * _tmp204 + _tmp219 * _tmp225;
    _hessian(11, 7) = _tmp188 * _tmp204 + _tmp220 * _tmp225;
    _hessian(11, 8) = _tmp192 * _tmp204 + _tmp221 * _tmp225;
    _hessian(11, 9) = _tmp196 * _tmp204 + _tmp222 * _tmp225;
    _hessian(11, 10) = _tmp200 * _tmp204 + _tmp224 * _tmp225;
    _hessian(11, 11) = std::pow(_tmp204, Scalar(2)) + std::pow(_tmp225, Scalar(2));
    _hessian(11, 12) = 0;
    _hessian(12, 0) = _tmp119 * _tmp209 + _tmp213 * _tmp226;
    _hessian(12, 1) = _tmp130 * _tmp209 + _tmp214 * _tmp226;
    _hessian(12, 2) = _tmp139 * _tmp209 + _tmp215 * _tmp226;
    _hessian(12, 3) = _tmp151 * _tmp209 + _tmp216 * _tmp226;
    _hessian(12, 4) = _tmp159 * _tmp209 + _tmp217 * _tmp226;
    _hessian(12, 5) = _tmp167 * _tmp209 + _tmp218 * _tmp226;
    _hessian(12, 6) = _tmp179 * _tmp209 + _tmp219 * _tmp226;
    _hessian(12, 7) = _tmp188 * _tmp209 + _tmp220 * _tmp226;
    _hessian(12, 8) = _tmp192 * _tmp209 + _tmp221 * _tmp226;
    _hessian(12, 9) = _tmp196 * _tmp209 + _tmp222 * _tmp226;
    _hessian(12, 10) = _tmp200 * _tmp209 + _tmp224 * _tmp226;
    _hessian(12, 11) = _tmp204 * _tmp209 + _tmp225 * _tmp226;
    _hessian(12, 12) = std::pow(_tmp209, Scalar(2)) + std::pow(_tmp226, Scalar(2));
  }

  if (rhs != nullptr) {
    Eigen::Matrix<Scalar, 13, 1>& _rhs = (*rhs);

    _rhs(0, 0) = _tmp119 * _tmp89 + _tmp213 * _tmp90;
    _rhs(1, 0) = _tmp130 * _tmp89 + _tmp214 * _tmp90;
    _rhs(2, 0) = _tmp139 * _tmp89 + _tmp215 * _tmp90;
    _rhs(3, 0) = _tmp151 * _tmp89 + _tmp216 * _tmp90;
    _rhs(4, 0) = _tmp159 * _tmp89 + _tmp217 * _tmp90;
    _rhs(5, 0) = _tmp167 * _tmp89 + _tmp218 * _tmp90;
    _rhs(6, 0) = _tmp179 * _tmp89 + _tmp219 * _tmp90;
    _rhs(7, 0) = _tmp188 * _tmp89 + _tmp220 * _tmp90;
    _rhs(8, 0) = _tmp192 * _tmp89 + _tmp221 * _tmp90;
    _rhs(9, 0) = _tmp196 * _tmp89 + _tmp222 * _tmp90;
    _rhs(10, 0) = _tmp200 * _tmp89 + _tmp224 * _tmp90;
    _rhs(11, 0) = _tmp204 * _tmp89 + _tmp225 * _tmp90;
    _rhs(12, 0) = _tmp209 * _tmp89 + _tmp226 * _tmp90;
  }
}  // NOLINT(readability/fn_size)

// NOLINTNEXTLINE(readability/fn_size)
}  // namespace sym
