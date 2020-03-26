cmake_minimum_required(VERSION 3.6)

set(lib_name gl3w)
set(target_name lib_${lib_name})

project(${lib_name})

include(../../cmake/config.cmake)

add_library(${target_name} STATIC 
    GL/gl3w.c
)

target_include_directories(${target_name} 
PRIVATE .
INTERFACE .)