#ifndef TENSOR_SHAPE_H
#define TENSOR_SHAPE_H TENSOR_SHAPE_H

#include <tensor_exception.hpp>
#include <type_traits>

namespace mytensor {

template <std::size_t n>
class TensorShape {
  using size_t = std::size_t;

 private:
  static constexpr size_t len = n;
  size_t dimensions[n];

 public:
  TensorShape() = default;

  TensorShape(const list&);

  TensorShape(const TensorShape&);

  ~TensorShape() = default;

  static constexpr size_t rank() const { return len; }
  size_t at(const size_t&) const;
  size_t size() const;

  bool operator==(const TensorShape&);
};

template <std::size_t n>
TensorShape<n>::TensorShape(const TensorShape& T) {
  for (auto i = 0; i < len; i++) {
    dimensions[i] = T.dimensions[i];
  }
}

template <std::size_t n>
std::size_t TensorShape<n>::at(const size_t& index) const {
  if (index >= len || index <= 0) {
    throw TensorException("Invalid Argument");
  }
  if (index <= len && index > 0) {
    return dimensions[index - 1];
  }
  return 0;
}

template <std::size_t n>
std::size_t TensorShape<n>::size() const {
  size_t val = 1;
  for (auto i = 0; i < len; i++) {
    val *= dimensions[i];
  }
  return val;
}

template <std::size_t n>
bool TensorShape<n>::operator==(const TensorShape& T) {
  for (auto i = 0; i < len; i++) {
    if (T.dimensions[i] != dimensions[i]) {
      return false;
    }
  }
  return true;
}

}  // namespace mytensor

#endif