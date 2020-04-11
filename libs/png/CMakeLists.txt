cmake_minimum_required(VERSION 3.6)

set(lib_name png)
set(target_name lib_${lib_name})
include(../../cmake/config.cmake)

project(${lib_name})

add_library(${target_name} STATIC IMPORTED GLOBAL)


if(WINDOWS)
    set_target_properties(${target_name} PROPERTIES
        INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_CURRENT_SOURCE_DIR}/include/win32"
    )
    set_target_properties(${target_name} PROPERTIES
        IMPORTED_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/prebuilt/win32/lib${lib_name}.lib"
    )
else()
    set_target_properties(${target_name} PROPERTIES
        IMPORTED_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/prebuilt/mac/lib${lib_name}.a"
    )
    set_target_properties(${target_name} PROPERTIES
        INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_CURRENT_SOURCE_DIR}/include/mac"
    )
endif()
