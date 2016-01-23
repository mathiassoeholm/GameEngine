cmake_minimum_required(VERSION 3.3)
project(OpenGLPlayground)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

FIND_PACKAGE(OpenGL REQUIRED)
if(NOT OPENGL_FOUND)
    message(ERROR " OPENGL not found!")
endif(NOT OPENGL_FOUND)

add_subdirectory(glfw)

include_directories(glfw/include)
include_directories(glm)
include_directories(Math-ias/src)
include_directories(glew)

SET(LIBRARIES glfw ${OPENGL_LIBRARY} ${CMAKE_DL_LIBS})

set(SOURCE_FILES main.cpp glew/glew.c GLLog.cpp Scenes/WorldScene.cpp)
add_executable(OpenGLPlayground ${SOURCE_FILES})
target_link_libraries(OpenGLPlayground ${LIBRARIES})