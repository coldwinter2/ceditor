cmake_minimum_required(VERSION 3.15)

set(APP_NAME CEditor)

project(${APP_NAME})

include(cmake/config.cmake)

# use GLFW
# OPENGL2 or OPENGL3 or vulkan (OPENGL3 is Default)
option(BUILD_OPENGL3_RENDER "Build with OpenGL3 render" ON)
option(BUILD_OPENGL2_RENDER "Build with OpenGL2 render" OFF)

#option(BUILD_VULKAN_RENDER "Build with Vulkan render" OFF) # not avalivle yet
# Metal Avalible in MacOSX
option(BUILD_METAL_RENDER "Build with Metal render" ON)# not avalivle yet

# Use jpeg
option(BUILD_JPEG "Build with lib jpeg" ON)
option(BUILD_PNG "Build with lib png" ON)

set(SOURCES 
src/imgui_impl_glfw.cpp
)

set(HEADERS 
    src
    src/app
)

if(MACOSX AND BUILD_METAL_RENDER)
    # use metal for render
    list(APPEND SOURCES src/main.mm)
else()
    list(APPEND SOURCES src/main.cpp)
endif()
add_subdirectory(libs)

aux_source_directory(src/app APP_SRC)

source_group(app FILES ${APP_SRC})


add_executable(${APP_NAME} ${SOURCES} ${APP_SRC})

target_include_directories(${APP_NAME} PUBLIC ${HEADERS})

include_directories(${HEADERS})

target_link_libraries(${APP_NAME} libs)

if (MSVC)
    set_property(TARGET ${APP_NAME} APPEND PROPERTY LINK_FLAGS "/SUBSYSTEM:WINDOWS")
endif()

if(BUILD_OPENGL3_RENDER)
    add_definitions(-D CEF_OPENGL3_RENDER)
elseif(BUILD_OPENGL2_RENDER)
    add_definitions(-D CEF_OPENGL2_RENDER)
elseif(BUILD_VULKAN_RENDER)
    add_definitions(-D CEF_VULKAN_RENDER)
endif()