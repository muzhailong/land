add_library(${LIB_NAME}_PROFILER
    OBJECT
    ${CMAKE_CURRENT_SOURCE_DIR}/plugin_profiler.cpp
)

set_target_properties(${LIB_NAME}_PROFILER
    PROPERTIES
    POSITION_INDEPENDENT_CODE ON

    # CXX_VISIBILITY_PRESET "hidden"
    # VISIBILITY_INLINES_HIDDEN 1
)

set_property(GLOBAL APPEND PROPERTY ${LIB_NAME}_DEPS $<TARGET_OBJECTS:${LIB_NAME}_PROFILER>)
