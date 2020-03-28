cmake_minimum_required(VERSION 3.6)

project(libs)

add_library(libs empty.cpp)
include(../cmake/config.cmake)
use_compile_options(libs)


if(MACOSX AND BUILD_METAL_RENDER)

else()
    add_subdirectory(glfw)
    target_link_libraries(libs 
        lib_glfw3
    )
endif()


#BUILD_IMGUI
add_subdirectory(imgui)
target_link_libraries(libs lib_imgui)

if(BUILD_OPENGL3_RENDER)
    # use opengl3 for render
    add_subdirectory(gl3w) 
    target_link_libraries(libs lib_gl3w) 
endif()

# include render
add_subdirectory(render)
target_link_libraries(libs lib_render)
# build jpeg
if(BUILD_JPEG)
    add_subdirectory(jpeg)
    target_link_libraries(libs lib_jpeg) 
endif(BUILD_JPEG)

add_subdirectory(tinyxml2)
target_link_libraries(libs lib_tinyxml2) 


target_include_directories(libs INTERFACE ./tinydir)
target_include_directories(libs INTERFACE ./rapidxml)



target_include_directories(libs INTERFACE .)
