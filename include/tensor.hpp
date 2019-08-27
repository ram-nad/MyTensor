#ifndef TENSOR_H
#define TENSOR_H TENSOR_H

#include <tensor_expression.hpp>
#include <tensor_shape.hpp>
#include <vector>

namespace mystensor {

using size_t = std::size_t;

template <typename T, size_t n>
class Tensor : public TensorExpression<T, n> {
 private:
  TensorShape<n> Shape;
  vector<T> elems;

 public:
  using type = T;
  using const_type = const T;
  using reference_type = T&;
  using const_reference_type = const T&;
  static constexpr rank = n;

  const TensorShape& shape() const { return Shape; }
};

}  // namespace mystensor

#endif