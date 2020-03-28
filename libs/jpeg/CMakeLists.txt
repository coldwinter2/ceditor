cmake_minimum_required(VERSION 3.6)

set(lib_name jpeg)
set(target_name lib_${lib_name})

project(${lib_name})

include(../../cmake/config.cmake)

add_library(${target_name} STATIC IMPORTED GLOBAL)

if(WINDOWS)
  set_target_properties(${target_name} PROPERTIES
    INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_CURRENT_SOURCE_DIR}/include/win32"
  )
  set_target_properties(${target_name} PROPERTIES
    IMPORTED_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/prebuilt/win32/lib${lib_name}.lib"
  )
elseif(MACOSX)
  set_target_properties(${target_name} PROPERTIES
    INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_CURRENT_SOURCE_DIR}/include/mac"
  )
  set_target_properties(${target_name} PROPERTIES
    IMPORTED_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/prebuilt/mac/lib${lib_name}.a"
  )
else()
  message("Error Jpeg lib not found for target platform")
endif()


set_target_properties(${target_name}
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    FOLDER "External"
)
