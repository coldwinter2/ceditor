cmake_minimum_required(VERSION 3.6)

project(libs)

set(SOURCES empty.cpp)

if(BUILD_TINYDIR)
    set(TINYDIR_SRC tinydir/tinydir.h)
    source_group(tinydir FILES ${TINYDIR_SRC})
    list(APPEND SOURCES ${TINYDIR_SRC})
endif(BUILD_TINYDIR)

if(BUILD_RAPIDXML)
    set(RAPIDXML_SRC rapidxml/rapidxml_iterators.hpp
    rapidxml/rapidxml_print.hpp
    rapidxml/rapidxml_sax3.hpp
    rapidxml/rapidxml_utils.hpp
    rapidxml/rapidxml.hpp)

    source_group(rapidxml ${RAPIDXML})
    list(APPEND SOURCES ${RAPIDXML})
endif(BUILD_RAPIDXML)

add_library(libs STATIC ${SOURCES})

target_include_directories(libs INTERFACE ./tinydir)
target_include_directories(libs INTERFACE ./rapidxml)

include(../cmake/config.cmake)
use_compile_options(libs)


if(MACOSX AND BUILD_METAL_RENDER)

else()
    add_subdirectory(glfw)
    target_link_libraries(libs 
        lib_glfw3
    )
endif()



if(BUILD_OPENGL3_RENDER)
    # use opengl3 for render
    add_subdirectory(gl3w) 
    target_link_libraries(libs lib_gl3w) 
endif()


# build jpeg
if(BUILD_JPEG)
    add_subdirectory(jpeg)
    target_link_libraries(libs lib_jpeg) 
endif(BUILD_JPEG)

#build tinyxml2
if(BUILD_TINYXML2)
add_subdirectory(tinyxml2)
target_link_libraries(libs lib_tinyxml2) 
endif(BUILD_TINYXML2)

#BUILD_IMGUI
add_subdirectory(imgui)
target_link_libraries(libs lib_imgui)

# include render
add_subdirectory(render)
target_link_libraries(libs lib_render)


target_include_directories(libs INTERFACE .)
