add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/device)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/ops)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/kernels)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/graph)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/utils)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/profiler)

get_property(DEPS GLOBAL PROPERTY ${LIB_NAME}_DEPS)

link_directories(
    /home/muzhailong/Applications/Anaconda3-2020.02/envs/plugin/lib/python3.8/site-packages/tensorflow/python/
    /home/muzhailong/Applications/Anaconda3-2020.02/envs/plugin/lib/python3.8/site-packages/tensorflow/
)

# add_library(PYWRAP_TENSORFLOW SHARED IMPORTED)
# set_target_properties(PYWRAP_TENSORFLOW
# PROPERTIES
# IMPORTED_LOCATION /home/muzhailong/Applications/Anaconda3-2020.02/envs/plugin/lib/python3.8/site-packages/tensorflow/python/_pywrap_tensorflow_internal.so)

# add_library(TENSORFLOW_DEPS SHARED IMPORTED)
# set_target_properties(TENSORFLOW_DEPS
# PROPERTIES
# IMPORTED_LOCATION /home/muzhailong/Applications/Anaconda3-2020.02/envs/plugin/lib/python3.8/site-packages/tensorflow/libtensorflow_framework.so.2)

# add_library(PROTOBUF SHARED IMPORTED)
# set_target_properties(PROTOBUF
# PROPERTIES
# IMPORTED_LOCATION /opt/protobuf-3.9.1/lib/libprotobuf.so)
add_library(
    ${LIB_NAME}
    SHARED
    ${DEPS}
)

target_link_directories(
    ${LIB_NAME}
    PUBLIC /home/muzhailong/Applications/Anaconda3-2020.02/envs/plugin/lib/python3.8/site-packages/tensorflow/
    PUBLIC /opt/protobuf-3.9.1/lib/
)

target_link_libraries(
    ${LIB_NAME}
    tensorflow_framework
    protobuf
)
