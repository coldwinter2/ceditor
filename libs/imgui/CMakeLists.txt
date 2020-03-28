cmake_minimum_required(VERSION 3.15)

set(lib_name imgui)
set(target_name lib_${lib_name})
project(${lib_name})
include(../../cmake/config.cmake)
set(${target_name}_src
  imgui.cpp
  imgui_draw.cpp
  imgui_widgets.cpp
  imgui_demo.cpp
)

add_library(${target_name} STATIC
  ${${target_name}_src}
)
use_compile_options(${target_name})
target_include_directories(${target_name} PUBLIC . 
INTERFACE .)