add_library(
    ${LIB_NAME}_KERNELS
    OBJECT
    ${CMAKE_CURRENT_SOURCE_DIR}/plugin_kernel.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/xpu/add_kernel.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/xpu/relu_kernel.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/xpu/xpu_kernel_init.cpp
)
target_compile_options(${LIB_NAME}_KERNELS
    PRIVATE -Wno-unused-result
)

set_target_properties(${LIB_NAME}_KERNELS
    PROPERTIES
    POSITION_INDEPENDENT_CODE ON

    # CXX_VISIBILITY_PRESET "hidden"
    # VISIBILITY_INLINES_HIDDEN 1
)

set_property(GLOBAL APPEND PROPERTY ${LIB_NAME}_DEPS $<TARGET_OBJECTS:${LIB_NAME}_KERNELS>)
