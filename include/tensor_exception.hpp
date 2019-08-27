#ifndef TENSOR_EXCEPTION_H
#define TENSOR_EXCEPTION_H TENSOR_EXCEPTION_H

#include <exception>

namespace mytensor {

class TensorException : public std::exception {
 private:
  const char* msg;

 public:
  TensorException(const char*);
  const char* what() noexcept;
};

}  // namespace mytensor

#endif