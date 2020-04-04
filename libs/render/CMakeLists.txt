cmake_minimum_required(VERSION 3.6)

set(lib_name render)
set(target_name lib_${lib_name})

project(${lib_name})
include(../../cmake/config.cmake)

# static link library
set(${target_name}_libs lib_imgui)


list(APPEND ${target_name}_libs lib_glfw3)
# add opengl lib
if(WINDOWS)
    list(APPEND ${target_name}_libs opengl32.lib gdi32.lib shell32.lib)
endif()

if(BUILD_OPENGL3_RENDER)
    list(APPEND ${target_name}_libs lib_gl3w)
    add_definitions(-D IMGUI_IMPL_OPENGL_LOADER_GL3W)
    set(${target_name}_path opengl3)
elseif(BUILD_OPENGL2_RENDER)
    set(${target_name}_path opengl2)
elseif(BUILD_VULKAN_RENDER)
    set(${target_name}_path vulkan)
endif()

set(${target_name}_src
    ${${target_name}_path}/imgui_render.cpp
)

add_library(${target_name} STATIC ${${target_name}_src})

target_include_directories(${target_name} PUBLIC ${${target_name}_path}
INTERFACE ${${target_name}_path})

# link library
target_link_libraries(${target_name} ${${target_name}_libs})
