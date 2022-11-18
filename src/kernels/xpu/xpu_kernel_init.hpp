#ifndef CORE_KERNELS_CPU_CPU_KERNEL_INIT_HPP
#define CORE_KERNELS_CPU_CPU_KERNEL_INIT_HPP

namespace land {
namespace kernel {
namespace xpu {

void RegisterReluKernel(const char* device_type);

void RegisterAddKernel(const char* device_type);

void RegisterKernels(const char* device_type);

}  // namespace xpu
}  // namespace kernel
}  // namespace land

#endif
