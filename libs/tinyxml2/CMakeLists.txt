cmake_minimum_required(VERSION 3.6)

set(lib_name tinyxml2)
set(target_name lib_${lib_name})

project(${lib_name})

set(${target_name}_src
  tinyxml2.cpp
  tinyxml2.h
)

add_library(${target_name} STATIC
  ${${target_name}_src}
)

target_include_directories(${target_name} PUBLIC .
INTERFACE .)

include(../../cmake/config.cmake)
if(WINDOWS)
    target_compile_definitions(${target_name} PRIVATE CC_STATIC)
endif()

