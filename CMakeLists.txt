cmake_minimum_required(VERSION 3.10)
project(hw1)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

find_package(FreeImage REQUIRED)

add_library(shaders STATIC "${CMAKE_SOURCE_DIR}/src/shaders/shaders.h")
set_target_properties(shaders PROPERTIES LINKER_LANGUAGE CXX)
target_include_directories(shaders PUBLIC "${CMAKE_SOURCE_DIR}/src/shaders")

add_library(geometry INTERFACE)
target_include_directories(geometry INTERFACE "${CMAKE_SOURCE_DIR}/src/geometry")
#set_target_properties(geometry PROPERTIES LINKER_LANGUAGE CXX)

add_library(glm INTERFACE)  
target_include_directories(glm INTERFACE "${CMAKE_SOURCE_DIR}/glm")

add_executable(mytest3 mytest3.cpp)

target_include_directories(mytest3 PUBLIC $<BUILD_INTERFACE:${FREEIMAGE_INCLUDE_DIRS}>)
target_link_libraries(mytest3 PUBLIC glm shaders geometry ${FREEIMAGE_LIBRARIES} GLEW glut GLU GL X11)

