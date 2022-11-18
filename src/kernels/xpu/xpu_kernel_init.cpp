#include <mutex>

#include "device/cpu/cpu_device_plugin.hpp"
#include "kernels/xpu/xpu_kernel_init.hpp"
#include "ops/op_init.hpp"

namespace {

void CallOneRegisterOps() {
    // static std::once_flag flag;
    // std::call_once(flag, land::op::RegisterOps);
}

}  // namespace

namespace land {
namespace kernel {
namespace xpu {

void RegisterKernels(const char* device_type) {
    CallOneRegisterOps();
    RegisterAddKernel(device_type);
    RegisterReluKernel(device_type);
}

}  // namespace xpu
}  // namespace kernel
}  // namespace land
