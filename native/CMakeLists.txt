cmake_minimum_required(VERSION 3.0)
project(demo)

set(CMAKE_CXX_STANDARD 11)
set(DEMO_SOURCE ../src/demo.cpp)

message(STATUS ${CMAKE_MODULE_PATH})

message(STATUS "Native build enabled")

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

include_directories(${OPENGL_INCLUDE_DIR})

add_executable(native ${DEMO_SOURCE})
target_link_libraries(native ${OPENGL_gl_LIBRARY} glfw)
