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
 * Residual that penalizes the difference between a value and prior (desired / measured value).
 *
 * In vector space terms that would be:
 *     prior - value
 *
 * In lie group terms:
 *     to_tangent(compose(inverse(value), prior))
 *
 * Args:
 *     sqrt_info: Square root information matrix to whiten residual. This can be computed from
 *                a covariance matrix as the cholesky decomposition of the inverse. In the case
 *                of a diagonal it will contain 1/sigma values. Must match the tangent dim.
 *     jacobian: (3x3) jacobian of res wrt arg value (3)
 *     hessian: (3x3) Gauss-Newton hessian for arg value (3)
 *     rhs: (3x1) Gauss-Newton rhs for arg value (3)
 */
template <typename Scalar>
void PriorFactorRot3(const sym::Rot3<Scalar>& value, const sym::Rot3<Scalar>& prior,
                     const Eigen::Matrix<Scalar, 3, 3>& sqrt_info, const Scalar epsilon,
                     Eigen::Matrix<Scalar, 3, 1>* const res = nullptr,
                     Eigen::Matrix<Scalar, 3, 3>* const jacobian = nullptr,
                     Eigen::Matrix<Scalar, 3, 3>* const hessian = nullptr,
                     Eigen::Matrix<Scalar, 3, 1>* const rhs = nullptr) {
  // Total ops: 415

  // Input arrays
  const Eigen::Matrix<Scalar, 4, 1>& _value = value.Data();
  const Eigen::Matrix<Scalar, 4, 1>& _prior = prior.Data();

  // Intermediate terms (109)
  const Scalar _tmp0 = _prior[3] * _value[1];
  const Scalar _tmp1 = _prior[0] * _value[2];
  const Scalar _tmp2 = _prior[2] * _value[0];
  const Scalar _tmp3 = _prior[1] * _value[3];
  const Scalar _tmp4 = _tmp0 + _tmp1 - _tmp2 - _tmp3;
  const Scalar _tmp5 = _prior[3] * _value[3];
  const Scalar _tmp6 = _prior[0] * _value[0];
  const Scalar _tmp7 = _prior[2] * _value[2];
  const Scalar _tmp8 = _prior[1] * _value[1];
  const Scalar _tmp9 = -_tmp6 - _tmp7 - _tmp8;
  const Scalar _tmp10 = _tmp5 - _tmp9;
  const Scalar _tmp11 = 2 * std::min<Scalar>(0, (((_tmp10) > 0) - ((_tmp10) < 0))) + 1;
  const Scalar _tmp12 = 2 * _tmp11;
  const Scalar _tmp13 = 1 - epsilon;
  const Scalar _tmp14 = std::min<Scalar>(_tmp13, std::fabs(_tmp10));
  const Scalar _tmp15 = std::acos(_tmp14) / std::sqrt(1 - std::pow(_tmp14, Scalar(2)));
  const Scalar _tmp16 = _tmp12 * _tmp15;
  const Scalar _tmp17 = _tmp16 * _tmp4;
  const Scalar _tmp18 = _prior[3] * _value[0];
  const Scalar _tmp19 = _prior[0] * _value[3];
  const Scalar _tmp20 = _prior[2] * _value[1];
  const Scalar _tmp21 = _prior[1] * _value[2];
  const Scalar _tmp22 = _tmp18 - _tmp19 + _tmp20 - _tmp21;
  const Scalar _tmp23 = _tmp16 * _tmp22;
  const Scalar _tmp24 = _prior[3] * _value[2];
  const Scalar _tmp25 = _prior[0] * _value[1];
  const Scalar _tmp26 = _prior[2] * _value[3];
  const Scalar _tmp27 = _prior[1] * _value[0];
  const Scalar _tmp28 = _tmp24 - _tmp25 - _tmp26 + _tmp27;
  const Scalar _tmp29 = _tmp16 * _tmp28;
  const Scalar _tmp30 =
      _tmp17 * sqrt_info(0, 1) + _tmp23 * sqrt_info(0, 0) + _tmp29 * sqrt_info(0, 2);
  const Scalar _tmp31 = _tmp12 * sqrt_info(1, 1);
  const Scalar _tmp32 =
      _tmp15 * _tmp31 * _tmp4 + _tmp23 * sqrt_info(1, 0) + _tmp29 * sqrt_info(1, 2);
  const Scalar _tmp33 = _tmp22 * sqrt_info(2, 0);
  const Scalar _tmp34 = _tmp16 * _tmp33 + _tmp17 * sqrt_info(2, 1) + _tmp29 * sqrt_info(2, 2);
  const Scalar _tmp35 = (Scalar(1) / Scalar(2)) * _tmp18;
  const Scalar _tmp36 = (Scalar(1) / Scalar(2)) * _tmp19;
  const Scalar _tmp37 = (Scalar(1) / Scalar(2)) * _tmp20;
  const Scalar _tmp38 = (Scalar(1) / Scalar(2)) * _tmp21;
  const Scalar _tmp39 = _tmp35 - _tmp36 + _tmp37 - _tmp38;
  const Scalar _tmp40 = _tmp39 * sqrt_info(0, 2);
  const Scalar _tmp41 = std::fabs(_tmp5 + _tmp6 + _tmp7 + _tmp8);
  const Scalar _tmp42 = std::min<Scalar>(_tmp13, _tmp41);
  const Scalar _tmp43 = std::acos(_tmp42);
  const Scalar _tmp44 = 1 - std::pow(_tmp42, Scalar(2));
  const Scalar _tmp45 = _tmp11 * ((((_tmp13 - _tmp41) > 0) - ((_tmp13 - _tmp41) < 0)) + 1) *
                        (((-_tmp5 + _tmp9) > 0) - ((-_tmp5 + _tmp9) < 0));
  const Scalar _tmp46 = _tmp42 * _tmp45 / (_tmp44 * std::sqrt(_tmp44));
  const Scalar _tmp47 = _tmp43 * _tmp46;
  const Scalar _tmp48 = _tmp28 * _tmp47;
  const Scalar _tmp49 = (Scalar(1) / Scalar(2)) * _tmp24;
  const Scalar _tmp50 = (Scalar(1) / Scalar(2)) * _tmp25;
  const Scalar _tmp51 = (Scalar(1) / Scalar(2)) * _tmp26;
  const Scalar _tmp52 = (Scalar(1) / Scalar(2)) * _tmp27;
  const Scalar _tmp53 = _tmp49 - _tmp50 - _tmp51 + _tmp52;
  const Scalar _tmp54 = _tmp43 * _tmp53;
  const Scalar _tmp55 = std::pow(_tmp44, Scalar(Scalar(-1) / Scalar(2)));
  const Scalar _tmp56 = _tmp12 * _tmp55;
  const Scalar _tmp57 = _tmp54 * _tmp56;
  const Scalar _tmp58 = _tmp22 * sqrt_info(0, 0);
  const Scalar _tmp59 = _tmp39 * _tmp47;
  const Scalar _tmp60 = _tmp45 / _tmp44;
  const Scalar _tmp61 = _tmp22 * _tmp60;
  const Scalar _tmp62 = _tmp61 * sqrt_info(0, 0);
  const Scalar _tmp63 = _tmp39 * _tmp60;
  const Scalar _tmp64 = _tmp4 * _tmp63;
  const Scalar _tmp65 = (Scalar(1) / Scalar(2)) * _tmp0;
  const Scalar _tmp66 = (Scalar(1) / Scalar(2)) * _tmp1;
  const Scalar _tmp67 = (Scalar(1) / Scalar(2)) * _tmp2;
  const Scalar _tmp68 = (Scalar(1) / Scalar(2)) * _tmp3;
  const Scalar _tmp69 = _tmp43 * _tmp56;
  const Scalar _tmp70 = _tmp69 * (-_tmp65 - _tmp66 + _tmp67 + _tmp68);
  const Scalar _tmp71 =
      _tmp43 * ((Scalar(1) / Scalar(2)) * _tmp5 + (Scalar(1) / Scalar(2)) * _tmp6 +
                (Scalar(1) / Scalar(2)) * _tmp7 + (Scalar(1) / Scalar(2)) * _tmp8);
  const Scalar _tmp72 = _tmp56 * _tmp71;
  const Scalar _tmp73 = _tmp4 * sqrt_info(0, 1);
  const Scalar _tmp74 = _tmp28 * _tmp60;
  const Scalar _tmp75 = -_tmp39 * _tmp62 + _tmp40 * _tmp48 - _tmp40 * _tmp74 +
                        _tmp57 * sqrt_info(0, 1) + _tmp58 * _tmp59 + _tmp59 * _tmp73 -
                        _tmp64 * sqrt_info(0, 1) + _tmp70 * sqrt_info(0, 2) +
                        _tmp72 * sqrt_info(0, 0);
  const Scalar _tmp76 = _tmp65 + _tmp66 - _tmp67 - _tmp68;
  const Scalar _tmp77 = _tmp47 * _tmp76;
  const Scalar _tmp78 = _tmp4 * _tmp77;
  const Scalar _tmp79 = _tmp60 * _tmp76;
  const Scalar _tmp80 = _tmp4 * _tmp79;
  const Scalar _tmp81 = _tmp48 * _tmp76;
  const Scalar _tmp82 = _tmp69 * (-_tmp49 + _tmp50 + _tmp51 - _tmp52);
  const Scalar _tmp83 = _tmp74 * _tmp76;
  const Scalar _tmp84 = _tmp40 * _tmp69 + _tmp58 * _tmp77 - _tmp62 * _tmp76 +
                        _tmp72 * sqrt_info(0, 1) + _tmp78 * sqrt_info(0, 1) -
                        _tmp80 * sqrt_info(0, 1) + _tmp81 * sqrt_info(0, 2) +
                        _tmp82 * sqrt_info(0, 0) - _tmp83 * sqrt_info(0, 2);
  const Scalar _tmp85 = _tmp46 * _tmp54;
  const Scalar _tmp86 = _tmp69 * _tmp76;
  const Scalar _tmp87 = _tmp53 * _tmp74;
  const Scalar _tmp88 = _tmp28 * _tmp85;
  const Scalar _tmp89 = -_tmp35 + _tmp36 - _tmp37 + _tmp38;
  const Scalar _tmp90 = _tmp69 * _tmp89;
  const Scalar _tmp91 = _tmp53 * _tmp60;
  const Scalar _tmp92 = _tmp4 * _tmp91;
  const Scalar _tmp93 = -_tmp53 * _tmp62 + _tmp58 * _tmp85 + _tmp72 * sqrt_info(0, 2) +
                        _tmp73 * _tmp85 + _tmp86 * sqrt_info(0, 0) - _tmp87 * sqrt_info(0, 2) +
                        _tmp88 * sqrt_info(0, 2) + _tmp90 * sqrt_info(0, 1) -
                        _tmp92 * sqrt_info(0, 1);
  const Scalar _tmp94 = _tmp39 * _tmp48;
  const Scalar _tmp95 = _tmp31 * _tmp55;
  const Scalar _tmp96 = _tmp22 * sqrt_info(1, 0);
  const Scalar _tmp97 = _tmp61 * sqrt_info(1, 0);
  const Scalar _tmp98 = _tmp4 * sqrt_info(1, 1);
  const Scalar _tmp99 = _tmp39 * _tmp74;
  const Scalar _tmp100 = -_tmp39 * _tmp97 + _tmp54 * _tmp95 + _tmp59 * _tmp96 + _tmp59 * _tmp98 -
                         _tmp64 * sqrt_info(1, 1) + _tmp70 * sqrt_info(1, 2) +
                         _tmp72 * sqrt_info(1, 0) + _tmp94 * sqrt_info(1, 2) -
                         _tmp99 * sqrt_info(1, 2);
  const Scalar _tmp101 = _tmp39 * _tmp69;
  const Scalar _tmp102 = _tmp101 * sqrt_info(1, 2) + _tmp71 * _tmp95 - _tmp76 * _tmp97 +
                         _tmp77 * _tmp96 + _tmp78 * sqrt_info(1, 1) - _tmp80 * sqrt_info(1, 1) +
                         _tmp81 * sqrt_info(1, 2) + _tmp82 * sqrt_info(1, 0) -
                         _tmp83 * sqrt_info(1, 2);
  const Scalar _tmp103 = _tmp43 * _tmp89 * _tmp95 - _tmp53 * _tmp97 + _tmp72 * sqrt_info(1, 2) +
                         _tmp85 * _tmp96 + _tmp85 * _tmp98 + _tmp86 * sqrt_info(1, 0) -
                         _tmp87 * sqrt_info(1, 2) + _tmp88 * sqrt_info(1, 2) -
                         _tmp92 * sqrt_info(1, 1);
  const Scalar _tmp104 = _tmp4 * sqrt_info(2, 1);
  const Scalar _tmp105 = _tmp104 * _tmp59 - _tmp104 * _tmp63 + _tmp33 * _tmp59 - _tmp33 * _tmp63 +
                         _tmp57 * sqrt_info(2, 1) + _tmp70 * sqrt_info(2, 2) +
                         _tmp72 * sqrt_info(2, 0) + _tmp94 * sqrt_info(2, 2) -
                         _tmp99 * sqrt_info(2, 2);
  const Scalar _tmp106 = _tmp74 * sqrt_info(2, 2);
  const Scalar _tmp107 = _tmp101 * sqrt_info(2, 2) + _tmp104 * _tmp77 - _tmp104 * _tmp79 -
                         _tmp106 * _tmp76 + _tmp33 * _tmp77 - _tmp33 * _tmp79 +
                         _tmp72 * sqrt_info(2, 1) + _tmp81 * sqrt_info(2, 2) +
                         _tmp82 * sqrt_info(2, 0);
  const Scalar _tmp108 = _tmp104 * _tmp85 - _tmp104 * _tmp91 - _tmp106 * _tmp53 + _tmp33 * _tmp85 -
                         _tmp33 * _tmp91 + _tmp72 * sqrt_info(2, 2) + _tmp86 * sqrt_info(2, 0) +
                         _tmp88 * sqrt_info(2, 2) + _tmp90 * sqrt_info(2, 1);

  // Output terms (4)
  if (res != nullptr) {
    Eigen::Matrix<Scalar, 3, 1>& _res = (*res);

    _res(0, 0) = _tmp30;
    _res(1, 0) = _tmp32;
    _res(2, 0) = _tmp34;
  }

  if (jacobian != nullptr) {
    Eigen::Matrix<Scalar, 3, 3>& _jacobian = (*jacobian);

    _jacobian(0, 0) = _tmp75;
    _jacobian(0, 1) = _tmp84;
    _jacobian(0, 2) = _tmp93;
    _jacobian(1, 0) = _tmp100;
    _jacobian(1, 1) = _tmp102;
    _jacobian(1, 2) = _tmp103;
    _jacobian(2, 0) = _tmp105;
    _jacobian(2, 1) = _tmp107;
    _jacobian(2, 2) = _tmp108;
  }

  if (hessian != nullptr) {
    Eigen::Matrix<Scalar, 3, 3>& _hessian = (*hessian);

    _hessian(0, 0) =
        std::pow(_tmp100, Scalar(2)) + std::pow(_tmp105, Scalar(2)) + std::pow(_tmp75, Scalar(2));
    _hessian(0, 1) = 0;
    _hessian(0, 2) = 0;
    _hessian(1, 0) = _tmp100 * _tmp102 + _tmp105 * _tmp107 + _tmp75 * _tmp84;
    _hessian(1, 1) =
        std::pow(_tmp102, Scalar(2)) + std::pow(_tmp107, Scalar(2)) + std::pow(_tmp84, Scalar(2));
    _hessian(1, 2) = 0;
    _hessian(2, 0) = _tmp100 * _tmp103 + _tmp105 * _tmp108 + _tmp75 * _tmp93;
    _hessian(2, 1) = _tmp102 * _tmp103 + _tmp107 * _tmp108 + _tmp84 * _tmp93;
    _hessian(2, 2) =
        std::pow(_tmp103, Scalar(2)) + std::pow(_tmp108, Scalar(2)) + std::pow(_tmp93, Scalar(2));
  }

  if (rhs != nullptr) {
    Eigen::Matrix<Scalar, 3, 1>& _rhs = (*rhs);

    _rhs(0, 0) = _tmp100 * _tmp32 + _tmp105 * _tmp34 + _tmp30 * _tmp75;
    _rhs(1, 0) = _tmp102 * _tmp32 + _tmp107 * _tmp34 + _tmp30 * _tmp84;
    _rhs(2, 0) = _tmp103 * _tmp32 + _tmp108 * _tmp34 + _tmp30 * _tmp93;
  }
}  // NOLINT(readability/fn_size)

// NOLINTNEXTLINE(readability/fn_size)
}  // namespace sym
