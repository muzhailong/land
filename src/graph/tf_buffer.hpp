#ifndef CORE_GRAPH_TF_BUFFER_HPP
#define CORE_GRAPH_TF_BUFFER_HPP

#include "google/protobuf/arena.h"
#include "google/protobuf/descriptor.h"
#include "google/protobuf/descriptor.pb.h"
#include "google/protobuf/dynamic_message.h"
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/io/tokenizer.h"
#include "google/protobuf/io/zero_copy_stream.h"
#include "google/protobuf/io/zero_copy_stream_impl_lite.h"
#include "google/protobuf/map.h"
#include "google/protobuf/message.h"
#include "google/protobuf/repeated_field.h"
#include "google/protobuf/text_format.h"
#include "google/protobuf/util/json_util.h"
#include "google/protobuf/util/type_resolver_util.h"
#include "tensorflow/c/c_api.h"

namespace protobuf = ::google::protobuf;

namespace land {
namespace graph {

void MessageToBuffer(protobuf::MessageLite& in, TF_Buffer* out,
                     TF_Status* status);

void BufferToMessage(const TF_Buffer* in, protobuf::MessageLite& out,
                     TF_Status* status);
}  // namespace graph
}  // namespace land

#endif
