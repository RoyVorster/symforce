// -----------------------------------------------------------------------------
// This file was autogenerated by symforce. Do NOT modify by hand.
// -----------------------------------------------------------------------------
#pragma once

#include <Eigen/Dense>

#include <geo/rot3.h>


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
*
*/
template <typename Scalar>
void PriorFactorRot3(const geo::Rot3<Scalar>& value, const geo::Rot3<Scalar>& prior, const Eigen::Matrix<Scalar, 3, 3>& sqrt_info, const Scalar epsilon, Eigen::Matrix<Scalar, 3, 1>* const res, Eigen::Matrix<Scalar, 3, 3>* const jac) {
    // Input arrays
    const Eigen::Matrix<Scalar, 4, 1>& _value = value.Data();
    const Eigen::Matrix<Scalar, 4, 1>& _prior = prior.Data();
    assert( res != nullptr );
    assert( jac != nullptr );

    // Intermediate terms (67)
    const Scalar _tmp0 = -_prior[0]*_value[1] + _prior[1]*_value[0] - _prior[2]*_value[3] + _prior[3]*_value[2];
    const Scalar _tmp1 = _prior[0]*_value[0] + _prior[1]*_value[1] + _prior[2]*_value[2] + _prior[3]*_value[3];
    const Scalar _tmp2 = -epsilon + 1;
    const Scalar _tmp3 = std::min<Scalar>(_tmp1, _tmp2);
    const Scalar _tmp4 = epsilon - 1;
    const Scalar _tmp5 = std::max<Scalar>(_tmp3, _tmp4);
    const Scalar _tmp6 = -(_tmp5 * _tmp5) + 1;
    const Scalar _tmp7 = std::acos(_tmp5);
    const Scalar _tmp8 = 2*_tmp7/std::sqrt(_tmp6);
    const Scalar _tmp9 = _tmp8*sqrt_info(0, 2);
    const Scalar _tmp10 = _prior[0]*_value[2] - _prior[1]*_value[3] - _prior[2]*_value[0] + _prior[3]*_value[1];
    const Scalar _tmp11 = _tmp10*sqrt_info(0, 1);
    const Scalar _tmp12 = -_prior[0]*_value[3] - _prior[1]*_value[2] + _prior[2]*_value[1] + _prior[3]*_value[0];
    const Scalar _tmp13 = _tmp12*_tmp8;
    const Scalar _tmp14 = _tmp8*sqrt_info(1, 2);
    const Scalar _tmp15 = _tmp8*sqrt_info(1, 1);
    const Scalar _tmp16 = _tmp8*sqrt_info(1, 0);
    const Scalar _tmp17 = _tmp0*sqrt_info(2, 2);
    const Scalar _tmp18 = _tmp8*sqrt_info(2, 1);
    const Scalar _tmp19 = _prior[2]*_tmp8;
    const Scalar _tmp20 = _prior[3]*_tmp8;
    const Scalar _tmp21 = (1.0/2.0)*((((-_tmp1 + _tmp2) > 0) - ((-_tmp1 + _tmp2) < 0)) + 1)*((((_tmp3 - _tmp4) > 0) - ((_tmp3 - _tmp4) < 0)) + 1);
    const Scalar _tmp22 = _tmp21*_tmp5*_tmp7/(_tmp6 * std::sqrt(_tmp6));
    const Scalar _tmp23 = _prior[1]*_tmp22;
    const Scalar _tmp24 = _tmp12*_tmp23;
    const Scalar _tmp25 = _tmp21/_tmp6;
    const Scalar _tmp26 = _prior[1]*_tmp25;
    const Scalar _tmp27 = _tmp12*_tmp26;
    const Scalar _tmp28 = _tmp0*sqrt_info(0, 2);
    const Scalar _tmp29 = -_prior[0]*_tmp9 + _tmp11*_tmp23 - _tmp11*_tmp26 + _tmp19*sqrt_info(0, 0) + _tmp20*sqrt_info(0, 1) + _tmp23*_tmp28 + _tmp24*sqrt_info(0, 0) - _tmp26*_tmp28 - _tmp27*sqrt_info(0, 0);
    const Scalar _tmp30 = (1.0/2.0)*_tmp29;
    const Scalar _tmp31 = _prior[3]*_tmp22;
    const Scalar _tmp32 = _tmp12*_tmp31;
    const Scalar _tmp33 = _prior[1]*_tmp8;
    const Scalar _tmp34 = _prior[3]*_tmp25;
    const Scalar _tmp35 = _prior[0]*_tmp8;
    const Scalar _tmp36 = _tmp12*_tmp34;
    const Scalar _tmp37 = (1.0/2.0)*_tmp11*_tmp31 - 1.0/2.0*_tmp11*_tmp34 - 1.0/2.0*_tmp19*sqrt_info(0, 2) + (1.0/2.0)*_tmp28*_tmp31 - 1.0/2.0*_tmp28*_tmp34 + (1.0/2.0)*_tmp32*sqrt_info(0, 0) - 1.0/2.0*_tmp33*sqrt_info(0, 1) - 1.0/2.0*_tmp35*sqrt_info(0, 0) - 1.0/2.0*_tmp36*sqrt_info(0, 0);
    const Scalar _tmp38 = _prior[2]*_tmp22;
    const Scalar _tmp39 = _tmp12*_tmp38;
    const Scalar _tmp40 = _prior[2]*_tmp25;
    const Scalar _tmp41 = _tmp12*_tmp40;
    const Scalar _tmp42 = (1.0/2.0)*_tmp11*_tmp38 - 1.0/2.0*_tmp11*_tmp40 + (1.0/2.0)*_tmp20*sqrt_info(0, 2) + (1.0/2.0)*_tmp28*_tmp38 - 1.0/2.0*_tmp28*_tmp40 - 1.0/2.0*_tmp33*sqrt_info(0, 0) + (1.0/2.0)*_tmp35*sqrt_info(0, 1) + (1.0/2.0)*_tmp39*sqrt_info(0, 0) - 1.0/2.0*_tmp41*sqrt_info(0, 0);
    const Scalar _tmp43 = _prior[0]*_tmp22;
    const Scalar _tmp44 = _tmp12*_tmp43;
    const Scalar _tmp45 = _prior[0]*_tmp25;
    const Scalar _tmp46 = _tmp12*_tmp45;
    const Scalar _tmp47 = _tmp11*_tmp43 - _tmp11*_tmp45 - _tmp19*sqrt_info(0, 1) + _tmp20*sqrt_info(0, 0) + _tmp28*_tmp43 - _tmp28*_tmp45 + _tmp33*sqrt_info(0, 2) + _tmp44*sqrt_info(0, 0) - _tmp46*sqrt_info(0, 0);
    const Scalar _tmp48 = (1.0/2.0)*_value[3];
    const Scalar _tmp49 = (1.0/2.0)*_tmp47;
    const Scalar _tmp50 = _tmp10*sqrt_info(1, 1);
    const Scalar _tmp51 = _tmp0*sqrt_info(1, 2);
    const Scalar _tmp52 = (1.0/2.0)*_prior[0]*_tmp15 + (1.0/2.0)*_prior[3]*_tmp14 - 1.0/2.0*_tmp33*sqrt_info(1, 0) + (1.0/2.0)*_tmp38*_tmp50 + (1.0/2.0)*_tmp38*_tmp51 + (1.0/2.0)*_tmp39*sqrt_info(1, 0) - 1.0/2.0*_tmp40*_tmp50 - 1.0/2.0*_tmp40*_tmp51 - 1.0/2.0*_tmp41*sqrt_info(1, 0);
    const Scalar _tmp53 = -1.0/2.0*_prior[0]*_tmp16 - 1.0/2.0*_prior[2]*_tmp14 + (1.0/2.0)*_tmp31*_tmp50 + (1.0/2.0)*_tmp31*_tmp51 + (1.0/2.0)*_tmp32*sqrt_info(1, 0) - 1.0/2.0*_tmp33*sqrt_info(1, 1) - 1.0/2.0*_tmp34*_tmp50 - 1.0/2.0*_tmp34*_tmp51 - 1.0/2.0*_tmp36*sqrt_info(1, 0);
    const Scalar _tmp54 = -_prior[0]*_tmp14 + _prior[3]*_tmp15 + _tmp19*sqrt_info(1, 0) + _tmp23*_tmp50 + _tmp23*_tmp51 + _tmp24*sqrt_info(1, 0) - _tmp26*_tmp50 - _tmp26*_tmp51 - _tmp27*sqrt_info(1, 0);
    const Scalar _tmp55 = (1.0/2.0)*_tmp54;
    const Scalar _tmp56 = -_prior[2]*_tmp15 + _tmp20*sqrt_info(1, 0) + _tmp33*sqrt_info(1, 2) + _tmp43*_tmp50 + _tmp43*_tmp51 + _tmp44*sqrt_info(1, 0) - _tmp45*_tmp50 - _tmp45*_tmp51 - _tmp46*sqrt_info(1, 0);
    const Scalar _tmp57 = (1.0/2.0)*_tmp56;
    const Scalar _tmp58 = _tmp12*sqrt_info(2, 0);
    const Scalar _tmp59 = _tmp10*sqrt_info(2, 1);
    const Scalar _tmp60 = (1.0/2.0)*_tmp17*_tmp31 - 1.0/2.0*_tmp17*_tmp34 - 1.0/2.0*_tmp19*sqrt_info(2, 2) + (1.0/2.0)*_tmp31*_tmp58 + (1.0/2.0)*_tmp31*_tmp59 - 1.0/2.0*_tmp33*sqrt_info(2, 1) - 1.0/2.0*_tmp34*_tmp59 - 1.0/2.0*_tmp35*sqrt_info(2, 0) - 1.0/2.0*_tmp36*sqrt_info(2, 0);
    const Scalar _tmp61 = _prior[1]*sqrt_info(2, 2);
    const Scalar _tmp62 = _tmp0*_tmp61;
    const Scalar _tmp63 = (1.0/2.0)*_prior[3]*_tmp18 + (1.0/2.0)*_tmp19*sqrt_info(2, 0) + (1.0/2.0)*_tmp22*_tmp62 + (1.0/2.0)*_tmp23*_tmp58 + (1.0/2.0)*_tmp23*_tmp59 - 1.0/2.0*_tmp25*_tmp62 - 1.0/2.0*_tmp26*_tmp59 - 1.0/2.0*_tmp27*sqrt_info(2, 0) - 1.0/2.0*_tmp35*sqrt_info(2, 2);
    const Scalar _tmp64 = (1.0/2.0)*_prior[0]*_tmp18 + (1.0/2.0)*_tmp17*_tmp38 - 1.0/2.0*_tmp17*_tmp40 + (1.0/2.0)*_tmp20*sqrt_info(2, 2) - 1.0/2.0*_tmp33*sqrt_info(2, 0) + (1.0/2.0)*_tmp38*_tmp58 + (1.0/2.0)*_tmp38*_tmp59 - 1.0/2.0*_tmp40*_tmp59 - 1.0/2.0*_tmp41*sqrt_info(2, 0);
    const Scalar _tmp65 = -_prior[2]*_tmp18 + _tmp17*_tmp43 - _tmp17*_tmp45 + _tmp20*sqrt_info(2, 0) + _tmp43*_tmp58 + _tmp43*_tmp59 - _tmp45*_tmp59 - _tmp46*sqrt_info(2, 0) + _tmp61*_tmp8;
    const Scalar _tmp66 = (1.0/2.0)*_tmp65;

    // Output terms (2)
    Eigen::Matrix<Scalar, 3, 1>& _res = (*res);
    Eigen::Matrix<Scalar, 3, 3>& _jac = (*jac);

    _res(0, 0) = _tmp0*_tmp9 + _tmp11*_tmp8 + _tmp13*sqrt_info(0, 0);
    _res(1, 0) = _tmp0*_tmp14 + _tmp10*_tmp15 + _tmp12*_tmp16;
    _res(2, 0) = _tmp10*_tmp18 + _tmp13*sqrt_info(2, 0) + _tmp17*_tmp8;
    _jac(0, 0) = _tmp30*_value[2] - _tmp37*_value[0] - _tmp42*_value[1] + _tmp47*_tmp48;
    _jac(0, 1) = _tmp29*_tmp48 - _tmp37*_value[1] + _tmp42*_value[0] - _tmp49*_value[2];
    _jac(0, 2) = -_tmp30*_value[0] - _tmp37*_value[2] + _tmp42*_value[3] + _tmp49*_value[1];
    _jac(1, 0) = _tmp48*_tmp56 - _tmp52*_value[1] - _tmp53*_value[0] + _tmp55*_value[2];
    _jac(1, 1) = _tmp48*_tmp54 + _tmp52*_value[0] - _tmp53*_value[1] - _tmp57*_value[2];
    _jac(1, 2) = _tmp52*_value[3] - _tmp53*_value[2] - _tmp55*_value[0] + _tmp57*_value[1];
    _jac(2, 0) = _tmp48*_tmp65 - _tmp60*_value[0] + _tmp63*_value[2] - _tmp64*_value[1];
    _jac(2, 1) = -_tmp60*_value[1] + _tmp63*_value[3] + _tmp64*_value[0] - _tmp66*_value[2];
    _jac(2, 2) = -_tmp60*_value[2] - _tmp63*_value[0] + _tmp64*_value[3] + _tmp66*_value[1];



}

}  // namespace sym