
#include <iostream>

#include "kernels/xpu/xpu_kernel_init.hpp"
#include "tensorflow/c/kernels.h"
#include "tensorflow/c/tf_datatype.h"
#include "tensorflow/c/tf_status.h"

namespace {
void* Create(TF_OpKernelConstruction* ctx) { return 0; }

void Compute(void*, TF_OpKernelContext* context) { std::cout << "mzl relu\n"; }

void Destroy(void*) {}

}  // namespace

namespace land {
namespace kernel {
namespace xpu {

void RegisterReluKernel(const char* device_type) {
    TF_Status* s = TF_NewStatus();
    auto* builder =
        TF_NewKernelBuilder("Relu", "MY_DEVICE", &Create, &Compute, &Destroy);
    TF_KernelBuilder_TypeConstraint(builder, "T", TF_FLOAT, s);
    if (TF_GetCode(s) != TF_OK) { /* handle errors*/
    }
    TF_RegisterKernelBuilder("ReluOp", builder, s);
    if (TF_GetCode(s) != TF_OK) { /* handle errors*/
    }
    TF_DeleteStatus(s);
}

}  // namespace xpu
}  // namespace kernel
}  // namespace land
