#ifndef DEVICE_CPU_CPU_DEVICE_PLUGIN_HPP
#define DEVICE_CPU_CPU_DEVICE_PLUGIN_HPP
#include <stddef.h>

#include <string>

#include "tensorflow/c/experimental/stream_executor/stream_executor.h"
#include "tensorflow/c/tf_status.h"
namespace land {
namespace device {
namespace cpu {

const std::string PLATFORM_NAME = "MY_PLATFORM";
const std::string PLATFORM_TYPE = "MZL_CPU";
const size_t ALIGMENT_BYTE_NUMS = 64;

void SE_InitPluginFns(SE_PlatformRegistrationParams* const params,
                      TF_Status* const status);

}  // namespace cpu
}  // namespace device
}  // namespace land

struct SP_Stream_st {
    explicit SP_Stream_st(void* handle) : stream_handle(handle) {}
    void* stream_handle;
};

struct SP_Event_st {
    explicit SP_Event_st(void* handle) : event_handle(handle) {}
    void* event_handle;
};

struct SP_Timer_st {
    explicit SP_Timer_st(int id) : timer_handle(id) {}
    int timer_handle;
};

#endif
