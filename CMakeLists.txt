cmake_minimum_required(VERSION 3.16)

project(land VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)

# tensorflow include
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/src)

set(LIB_NAME ${PROJECT_NAME})

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/src)
