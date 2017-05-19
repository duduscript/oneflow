#ifndef ONEFLOW_REGISTER_BLOB_H_
#define ONEFLOW_REGISTER_BLOB_H_

#include <functional>
#include "common/shape.h"

namespace oneflow {

class Blob {
 public:
  OF_DISALLOW_COPY_AND_MOVE(Blob);
  Blob(char* dptr, const Shape& shape) : dptr_(dptr), shape_(shape) {}
  ~Blob() {}

  const char* dptr() const { return dptr_; }
  const Shape& shape() const { return shape_; }
  
  char* mut_dptr() { return dptr_; }

 private:
  char* dptr_ ;
  Shape shape_;
};

}  // namespace oneflow

#endif  // ONEFLOW_REGISTER_BLOB_H_
