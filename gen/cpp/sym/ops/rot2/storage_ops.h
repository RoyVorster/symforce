// -----------------------------------------------------------------------------
// This file was autogenerated by symforce from template:
//     cpp_templates/geo_package/ops/CLASS/storage_ops.h.jinja
// Do NOT modify by hand.
// -----------------------------------------------------------------------------

#pragma once

#include <lcmtypes/sym/type_t.hpp>

#include <sym/rot2.h>

namespace sym {

/**
 * C++ StorageOps implementation for <class 'symforce.geo.rot2.Rot2'>.
 */
template <typename ScalarType>
struct StorageOps<Rot2<ScalarType>> {
  using T = Rot2<ScalarType>;
  using Scalar = typename Rot2<ScalarType>::Scalar;

  static constexpr int32_t StorageDim() {
    return 2;
  }

  static void ToStorage(const T& a, ScalarType* out);
  static T FromStorage(const ScalarType* data);

  static type_t TypeEnum() {
    return type_t::ROT2;
  }

  template <typename Generator>
  static T Random(Generator& gen) {
    return T::Random(gen);
  }
};

}  // namespace sym

// Explicit instantiation
extern template struct sym::StorageOps<sym::Rot2<double>>;
extern template struct sym::StorageOps<sym::Rot2<float>>;
