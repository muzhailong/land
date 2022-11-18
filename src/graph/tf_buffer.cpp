#include "graph/tf_buffer.hpp"

namespace land {
namespace graph {

void MessageToBuffer(protobuf::MessageLite& in, TF_Buffer* out,
                     TF_Status* status) {
    if (out->data != nullptr) {
        TF_SetStatus(status, TF_Code::TF_INVALID_ARGUMENT,
                     "tf_buffer is not empty");
        return;
    }

    const size_t proto_size = in.ByteSizeLong();
    void* buf = malloc(proto_size);

    if (buf == nullptr) {
        TF_SetStatus(status, TF_Code::TF_RESOURCE_EXHAUSTED, "malloc failed");
        return;
    }

    if (!in.SerializeWithCachedSizesToArray(static_cast<unsigned char*>(buf))) {
        free(buf);
        TF_SetStatus(status, TF_Code::TF_INVALID_ARGUMENT,
                     "unable to serialize protocol buff");
        return;
    }

    out->data = buf;
    out->length = proto_size;
    out->data_deallocator = [](void* data, size_t length) { free(data); };
    TF_SetStatus(status, TF_Code::TF_OK, "");
}

void BufferToMessage(const TF_Buffer* in, protobuf::MessageLite& out,
                     TF_Status* status) {
    if (in == nullptr || !out.ParseFromArray(in->data, in->length)) {
        TF_SetStatus(status, TF_Code::TF_INVALID_ARGUMENT, "unparsable proto.");
        return;
    }

    TF_SetStatus(status, TF_Code::TF_OK, "");
}

}  // namespace graph
}  // namespace land
