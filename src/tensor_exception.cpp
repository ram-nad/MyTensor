#include <tensor_exception.hpp>

namespace mytensor {

TensorException::TensorException(const char* a) : msg(a) {}

const char* TensorException::what() noexcept { return msg; }

}  // namespace mytensor