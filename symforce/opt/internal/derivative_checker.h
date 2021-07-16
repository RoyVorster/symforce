#include <iostream>

#include "../linearization.h"
#include "../linearizer.h"
#include "../util.h"
#include "../values.h"

namespace sym {
namespace internal {

/**
 * Check that the given linearization matches numerical derivatives
 *
 * Assumes that all variables in values are optimized
 *
 * Args:
 *   linearizer:     Linearizer used to compute the residual
 *   values:         Values around which to check the linearization
 *   index:          Index for values
 *   linearization:  Linearization to check (should be the linearization at values)
 *   verbose:        Print information to stdout on failure?
 *
 * Returns:
 *   true if `linearization` and numerical derivatives match
 */
template <typename Scalar>
bool CheckDerivatives(Linearizer<Scalar>* const linearizer, const Values<Scalar>& values,
                      const index_t& index, const Linearization<Scalar>& linearization,
                      const Scalar epsilon, const bool verbose = true) {
  SYM_ASSERT(linearizer != nullptr);

  // Make a copy of the linearization that we can relinearize into
  Linearization<Scalar> perturbed_linearization = linearization;

  bool success = true;

  // Check numerical jacobian
  {
    const auto wrapped_residual =
        [&perturbed_linearization, &linearizer, &values, &index,
         epsilon](const VectorX<Scalar>& values_perturbation) -> VectorX<Scalar> {
      Values<Scalar> perturbed_values = values;
      perturbed_values.Retract(index, values_perturbation.data(), epsilon);

      linearizer->Relinearize(perturbed_values, &perturbed_linearization);
      return perturbed_linearization.residual;
    };

    const MatrixX<Scalar> numerical_jacobian = NumericalDerivative(
        wrapped_residual, VectorX<Scalar>::Zero(linearization.jacobian.cols()).eval(), epsilon,
        std::sqrt(epsilon));

    const bool jacobian_matches =
        numerical_jacobian.isApprox(MatrixX<Scalar>(linearization.jacobian), std::sqrt(epsilon));

    if (!jacobian_matches) {
      if (verbose) {
        std::ostringstream ss;
        ss << "Symbolic and numerical jacobians don't match" << std::endl;
        ss << "Symbolic Jacobian: \n" << linearization.jacobian << std::endl;
        ss << "Numerical Jacobian: \n" << numerical_jacobian << std::endl;
        ss << "Additive Difference: \n" << linearization.jacobian - numerical_jacobian;
        std::cout << ss.str() << std::endl;
      }

      success = false;
    }
  }

  // Check hessian
  {
    const MatrixX<Scalar> hessian_lower_dense = linearization.hessian_lower;
    MatrixX<Scalar> full_hessian = hessian_lower_dense + hessian_lower_dense.transpose();
    full_hessian.diagonal() = hessian_lower_dense.diagonal();

    const MatrixX<Scalar> numerical_hessian =
        linearization.jacobian.transpose() * linearization.jacobian;
    const bool hessian_matches = full_hessian.isApprox(numerical_hessian, std::sqrt(epsilon));
    if (!hessian_matches) {
      if (verbose) {
        std::ostringstream ss;
        ss << "Hessian does not match J^T J" << std::endl;
        ss << "Symbolic (sym::Linearizer) Hessian:\n" << full_hessian << std::endl;
        ss << "Numerical (J^T * J) Hessian:\n" << numerical_hessian << std::endl;
        ss << "Additive Difference: \n" << full_hessian - numerical_hessian;
        std::cout << ss.str() << std::endl;
      }

      success = false;
    }
  }

  // Check Jtb
  {
    const VectorX<Scalar> numerical_rhs =
        linearization.jacobian.transpose() * linearization.residual;
    const bool Jtb_matches = linearization.rhs.isApprox(numerical_rhs, std::sqrt(epsilon));
    if (!Jtb_matches) {
      if (verbose) {
        std::ostringstream ss;
        ss << "Generated Jtb does not match J^T * b" << std::endl;
        ss << "Symbolic (sym::Linearization) Jtb:\n" << linearization.rhs.transpose() << std::endl;
        ss << "Numerical (J^T * b) Jtb:\n" << numerical_rhs.transpose() << std::endl;
        ss << "Additive Difference: \n"
           << linearization.rhs.transpose() - numerical_rhs.transpose();
        std::cout << ss.str() << std::endl;
      }

      success = false;
    }
  }

  return success;
}

}  // namespace internal
}  // namespace sym
