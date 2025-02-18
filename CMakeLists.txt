cmake_minimum_required(VERSION 3.20)

set(LIBNAME "vcl")

project(${LIBNAME}
        DESCRIPTION "VCL - graphical library based on OpenGL")

set(CMAKE_CXX_STANDARD 20)

#include VCL lib directory
include("${CMAKE_CURRENT_LIST_DIR}/vcl/CMakeLists.txt")
#include Third party
include("${CMAKE_CURRENT_LIST_DIR}/third_party/CMakeLists.txt")

file(GLOB_RECURSE src_files_core
        ${CMAKE_CURRENT_LIST_DIR}/core/*.cc
        ${CMAKE_CURRENT_LIST_DIR}/events/*.cc
)

find_package(Threads)

# Allow to sort and explore source directories as a tree structure in Visual Studio
if(MSVC)
    source_group(TREE library FILES ${src_files_vcl} ${src_files_third_party})
endif()

set(LIB_SOURCES ${src_files_vcl} ${src_files_third_party})
add_library(${LIBNAME} STATIC ${src_files_vcl} ${src_files_third_party} ${src_files_core})

target_link_libraries(${LIBNAME} Threads::Threads)

target_include_directories(${LIBNAME}
    PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
)
