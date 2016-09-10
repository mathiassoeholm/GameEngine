cmake_minimum_required(VERSION 3.3)
project(GameEngine)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

FIND_PACKAGE(OpenGL REQUIRED)
if(NOT OPENGL_FOUND)
    message(ERROR " OPENGL not found!")
endif(NOT OPENGL_FOUND)

file(COPY Shaders DESTINATION ${CMAKE_BINARY_DIR})
file(COPY Images DESTINATION ${CMAKE_BINARY_DIR})

add_subdirectory(glfw)

include_directories(glfw/include)
include_directories(glm)
include_directories(Math-ias/src)
include_directories(glew)

add_definitions(-DGLEW_STATIC)

SET(LIBRARIES glfw ${OPENGL_LIBRARY} ${CMAKE_DL_LIBS})

set(SOURCE_FILES main.cpp glew/glew.c GameEngine/GameObject.cpp GameEngine/GameObject.h GameEngine/Component.cpp GameEngine/Component.h GameEngine/MeshRenderer.cpp GameEngine/MeshRenderer.h GameEngine/Scene.cpp GameEngine/Scene.h GameEngine/Camera.cpp GameEngine/Camera.h GameEngine/Engine.cpp GameEngine/Engine.h GameEngine/Mesh.cpp GameEngine/Mesh.h GameEngine/Material.cpp GameEngine/Material.h GameEngine/Vertex.h GameEngine/Primitives.cpp GameEngine/Primitives.h GameEngineTest/TestScene.cpp GameEngineTest/TestScene.h GameEngineTest/CustomComponent.cpp GameEngineTest/CustomComponent.h GameEngine/Time.cpp GameEngine/Time.h GameEngine/Keyboard.cpp GameEngine/Keyboard.cpp GameEngine/Keyboard.h GameEngine/UpdateInfo.h GameEngine/Lighting/Light.cpp GameEngine/Lighting/Light.h GameEngine/Lighting/DirectionalLight.cpp GameEngine/Lighting/DirectionalLight.h GameEngine/Lighting/LightManager.cpp GameEngine/Lighting/LightManager.h)
add_executable(GameEngine ${SOURCE_FILES})
target_link_libraries(GameEngine ${LIBRARIES})