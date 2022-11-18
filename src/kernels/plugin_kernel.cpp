#include "device/plugin_device.hpp"
#include "kernels/xpu/xpu_kernel_init.hpp"
#include "tensorflow/c/kernels.h"

void TF_InitKernel() { land::kernel::xpu::RegisterKernels(DEVICE_TYPE); }
