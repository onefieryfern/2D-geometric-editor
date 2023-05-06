cmake_minimum_required(VERSION 3.24)
project(2D_geometric_editor)

set(CMAKE_CXX_STANDARD 17)

# Project files
add_executable(2D_geometric_editor)

target_sources(2D_geometric_editor PRIVATE main.cpp)

target_sources(2D_geometric_editor PRIVATE draw_helper.cpp draw_helper.h)

target_sources(2D_geometric_editor PRIVATE geometry/geometry_constants.h)
target_sources(2D_geometric_editor PRIVATE geometry/geometry_common.cpp geometry/geometry_common.h)
target_sources(2D_geometric_editor PRIVATE geometry/Point.cpp geometry/Point.h)
target_sources(2D_geometric_editor PRIVATE geometry/Rectangle.cpp geometry/Rectangle.h)

target_sources(2D_geometric_editor PRIVATE logic/BoundingBox.cpp logic/BoundingBox.h)

# Internal includes
target_include_directories(2D_geometric_editor PRIVATE ./)
target_include_directories(2D_geometric_editor PRIVATE geometry/ logic/)

# External includes

## for Flatpak
target_include_directories(2D_geometric_editor PRIVATE "/run/host/usr/include/" "/run/host/usr/include/x86_64-linux-gnu/")
target_link_directories(2D_geometric_editor PRIVATE "/run/host/usr/lib/" "/run/host/usr/lib/x86_64-linux-gnu/" "/run/host/usr/lib/x86_64-linux-gnu/pulseaudio")

target_link_libraries(2D_geometric_editor PRIVATE SDL_bgi SDL2)

#target_include_directories(2D_geometric_editor PRIVATE "C:/winbgim")
#target_link_directories(2D_geometric_editor PRIVATE "C:/winbgim")
#target_link_libraries(2D_geometric_editor bgi gdi32 comdlg32 uuid oleaut32 ole32)
