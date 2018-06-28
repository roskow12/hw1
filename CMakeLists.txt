cmake_minimum_required(VERSION 3.10)
project(hw1)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

find_package(FreeImage REQUIRED)

add_library(shaders STATIC 
	"${CMAKE_SOURCE_DIR}/src/shaders/shaders.h"
	"${CMAKE_SOURCE_DIR}/src/shaders/shaders.cpp")
set_target_properties(shaders PROPERTIES LINKER_LANGUAGE CXX)
target_include_directories(shaders PUBLIC "${CMAKE_SOURCE_DIR}/src/shaders")

add_library(geometry STATIC
	"${CMAKE_SOURCE_DIR}/src/geometry/Geometry.h"
	"${CMAKE_SOURCE_DIR}/src/geometry/Geometry.cpp")
target_link_libraries(geometry PUBLIC glm)
target_include_directories(geometry PUBLIC "${CMAKE_SOURCE_DIR}/src/geometry")
#target_include_directories(geometry INTERFACE "${CMAKE_SOURCE_DIR}/src/geometry")
#set_target_properties(geometry PROPERTIES LINKER_LANGUAGE CXX)

add_library(transform STATIC
	"${CMAKE_SOURCE_DIR}/src/transform/Transform.h"
	"${CMAKE_SOURCE_DIR}/src/transform/Transform.cpp")
target_link_libraries(transform PUBLIC glm)
target_include_directories(transform PUBLIC "${CMAKE_SOURCE_DIR}/src/transform")

add_library(grader STATIC
	"${CMAKE_SOURCE_DIR}/src/grader/grader.h"
	"${CMAKE_SOURCE_DIR}/src/grader/grader.cpp")
target_link_libraries(grader PUBLIC glm)
target_include_directories(grader PUBLIC "${CMAKE_SOURCE_DIR}/src/grader")
add_library(glm INTERFACE)  
target_include_directories(glm INTERFACE "${CMAKE_SOURCE_DIR}/glm")

add_executable(hw1 main.cpp)

target_include_directories(hw1 PUBLIC $<BUILD_INTERFACE:${FREEIMAGE_INCLUDE_DIRS}>)
target_link_libraries(hw1 PUBLIC glm grader transform shaders geometry ${FREEIMAGE_LIBRARIES} GLEW glut GLU GL X11)

