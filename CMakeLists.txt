cmake_minimum_required(VERSION 3.24)
project(2D_geometric_editor)

set(CMAKE_CXX_STANDARD 17)


# Project files
add_executable(2D_geometric_editor)

target_sources(2D_geometric_editor PRIVATE main.cpp)

target_sources(2D_geometric_editor PRIVATE Engine.cpp Engine.h)

target_sources(2D_geometric_editor PRIVATE geometry/geometry_constants.h)
target_sources(2D_geometric_editor PRIVATE geometry/geometry_structs.h)
target_sources(2D_geometric_editor PRIVATE geometry/geometry_functions.cpp geometry/geometry_functions.h)
target_sources(2D_geometric_editor PRIVATE geometry/Point.cpp geometry/Point.h)
target_sources(2D_geometric_editor PRIVATE geometry/Rectangle.cpp geometry/Rectangle.h)

target_sources(2D_geometric_editor PRIVATE graphics/graphics_structs.h)
target_sources(2D_geometric_editor PRIVATE graphics/Colour.cpp graphics/Colour.h)
target_sources(2D_geometric_editor PRIVATE graphics/SimpleTextBox.cpp graphics/SimpleTextBox.h)
target_sources(2D_geometric_editor PRIVATE graphics/Text.cpp graphics/Text.h)

target_sources(2D_geometric_editor PRIVATE logic/BoundingBox.cpp logic/BoundingBox.h)


# Internal includes
target_include_directories(2D_geometric_editor PRIVATE ./)
target_include_directories(2D_geometric_editor PRIVATE geometry/ logic/ graphics/)


# TODO: Better automatic includes (include correct libraries & headers based on the OS it's being built on)
# External includes

## Linux (flatpak)
if (${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    target_include_directories(2D_geometric_editor PRIVATE "/run/host/usr/include/" "/run/host/usr/include/x86_64-linux-gnu/")
    target_link_directories(2D_geometric_editor PRIVATE "/run/host/usr/lib/" "/run/host/usr/lib/x86_64-linux-gnu/" "/run/host/usr/lib/x86_64-linux-gnu/pulseaudio")
endif ()

## macOS
if (${CMAKE_SYSTEM_NAME} STREQUAL "Darwin")
    target_include_directories(2D_geometric_editor PRIVATE "/usr/local/include/")
    target_link_directories(2D_geometric_editor PRIVATE "/usr/local/lib/")
endif ()

# Windows (using winbgim)
# TODO: Create new Windows-specific config for using SDL_bgi & SDL2
if (${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
    #target_include_directories(2D_geometric_editor PRIVATE "C:/winbgim")
    #target_link_directories(2D_geometric_editor PRIVATE "C:/winbgim")
    #target_link_libraries(2D_geometric_editor bgi gdi32 comdlg32 uuid oleaut32 ole32)
endif ()

# Link libraries
target_link_libraries(2D_geometric_editor PRIVATE SDL_bgi SDL2)
