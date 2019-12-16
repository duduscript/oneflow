#ifndef ONEFLOW_CORE_COMMON_DATA_TYPE_SEQ_H_
#define ONEFLOW_CORE_COMMON_DATA_TYPE_SEQ_H_

#include "oneflow/core/common/preprocessor.h"

// SEQ

#define FLOATING_DATA_TYPE_SEQ                  \
  OF_PP_MAKE_TUPLE_SEQ(float, DataType::kFloat) \
  OF_PP_MAKE_TUPLE_SEQ(double, DataType::kDouble)

#define SIGNED_INT_DATA_TYPE_SEQ                  \
  OF_PP_MAKE_TUPLE_SEQ(int8_t, DataType::kInt8)   \
  OF_PP_MAKE_TUPLE_SEQ(int32_t, DataType::kInt32) \
  OF_PP_MAKE_TUPLE_SEQ(int64_t, DataType::kInt64)

#define UNSIGNED_INT_DATA_TYPE_SEQ OF_PP_MAKE_TUPLE_SEQ(uint8_t, DataType::kUInt8)

#define INT_DATA_TYPE_SEQ SIGNED_INT_DATA_TYPE_SEQ

#define CHAR_DATA_TYPE_SEQ OF_PP_MAKE_TUPLE_SEQ(char, DataType::kChar)

#define ARITHMETIC_DATA_TYPE_SEQ \
  FLOATING_DATA_TYPE_SEQ         \
  INT_DATA_TYPE_SEQ

#define POD_DATA_TYPE_SEQ ARITHMETIC_DATA_TYPE_SEQ CHAR_DATA_TYPE_SEQ UNSIGNED_INT_DATA_TYPE_SEQ
#define PB_DATA_TYPE_SEQ OF_PP_MAKE_TUPLE_SEQ(OFRecord, DataType::kOFRecord)
#define ALL_DATA_TYPE_SEQ POD_DATA_TYPE_SEQ PB_DATA_TYPE_SEQ

#define INDEX_DATA_TYPE_SEQ                       \
  OF_PP_MAKE_TUPLE_SEQ(int32_t, DataType::kInt32) \
  OF_PP_MAKE_TUPLE_SEQ(int64_t, DataType::kInt64)

#endif  // ONEFLOW_CORE_COMMON_DATA_TYPE_SEQ_H_
