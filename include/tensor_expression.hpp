#ifndef TENSOR_EXPRESSION_H
#define TENSOR_EXPRESSION_H TENSOR_EXPRESSION_H

#include <type_traits>

#include <tensor_shape.hpp>

namespace mytensor {

template <typename T, std::size_t n>
class TensorExpression {
  static_assert(std::is_arithmetic_v<T>,
                "Tensor Expressions can only be made for arithmetic types.");

 public:
  using type = T;
  using const_type = const T;
  using reference_type = T&;
  using const_reference_type = const T&;
  static constexpr size_t rank = n;

  virtual TensorShape<n> shape() const = 0;
};

template <typename V>
struct is_valid_tensor_expression {
  static constexpr bool value =
      std::is_base_of_v<TensorExpression<typename V::type, V::rank>, V> &&
      !std::is_abstract_v<V>;
};

template <typename V>
inline constexpr bool is_valid_tensor_expression_v =
    is_valid_tensor_expression<V>::value;

}  // namespace mytensor

#endif