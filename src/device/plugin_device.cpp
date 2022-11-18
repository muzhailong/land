#include "device/cpu/cpu_device_plugin.hpp"
#include "device/plugin_device.hpp"
#include "tensorflow/c/experimental/stream_executor/stream_executor.h"
void SE_InitPlugin(SE_PlatformRegistrationParams* params, TF_Status* status) {
    params->platform->struct_size = SP_PLATFORM_STRUCT_SIZE;
    params->platform->name = DEVICE_NAME;
    params->platform->type = DEVICE_TYPE;
    land::device::cpu::SE_InitPluginFns(params, status);
}
