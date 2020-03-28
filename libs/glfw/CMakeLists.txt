cmake_minimum_required(VERSION 3.15)

set(lib_name glfw3)
set(target_name lib_${lib_name})
include(../../cmake/config.cmake)
project(${lib_name})

add_library(${target_name} STATIC IMPORTED GLOBAL)


set_target_properties(${target_name} PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

if(WINDOWS)
    if (CMAKE_CL_64)
        set_target_properties(${target_name} PROPERTIES
            IMPORTED_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/win64/${lib_name}.lib"
        )
    else()
        set_target_properties(${target_name} PROPERTIES
            IMPORTED_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/win32/${lib_name}.lib"
        )
    endif()
elseif(MACOSX)
    set_target_properties(${target_name} PROPERTIES
        IMPORTED_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/mac/lib${lib_name}.a"
    )
else()
    message("Platform not Support")
endif()