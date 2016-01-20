cmake_minimum_required(VERSION 3.3)
project(OpenGLPlayground)

find_package(OpenGL REQUIRED)
find_package(Boost)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_subdirectory(glfw)

include_directories(glfw/include)
include_directories(glm)
include_directories(Math-ias/src)

set(SOURCE_FILES main.cpp)
add_executable(OpenGLPlayground ${SOURCE_FILES})