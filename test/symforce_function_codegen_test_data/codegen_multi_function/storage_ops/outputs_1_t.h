// ----------------------------------------------------------------------------
// This file was autogenerated by symforce. Do NOT modify by hand.
// ----------------------------------------------------------------------------
#pragma once

#include <cassert>
#include <vector>

namespace codegen_multi_function {
namespace StorageOps {

template<>
inline size_t StorageDim<outputs_1_t>() {
  return 2;
};

template<>
inline void ToStorage<outputs_1_t>(const outputs_1_t& value, std::vector<double>* vec) {
  assert(vec != nullptr);
  std::vector<double>& v = (*vec);
  v.resize(2);

  v[0] = value.foo;
  v[1] = value.bar;
}

template<typename Container>
void FromStorage(const Container& elements, outputs_1_t* out) {
  assert(out != nullptr);
  out->foo = elements[0];
  out->bar = elements[1];
}

}  // namespace StorageOps
}  // namespace codegen_multi_function