cmake_minimum_required(VERSION 3.24)
project(2D_geometric_editor)

set(CMAKE_CXX_STANDARD 17)

add_executable(2D_geometric_editor main.cpp draw_helper.cpp draw_helper.h geometry_data_structures.h geometry_data_structures.cpp geometry/Point.cpp geometry/Point.h geometry/Rectangle.cpp geometry/Rectangle.h)

target_include_directories(2D_geometric_editor PRIVATE ./ geometry/)

target_include_directories(2D_geometric_editor PRIVATE "/run/host/usr/include/" "/run/host/usr/include/x86_64-linux-gnu/")
target_link_directories(2D_geometric_editor PRIVATE "/run/host/usr/lib/" "/run/host/usr/lib/x86_64-linux-gnu/" "/run/host/usr/lib/x86_64-linux-gnu/pulseaudio")
target_link_libraries(2D_geometric_editor SDL_bgi SDL2)

#target_include_directories(2D_geometric_editor PRIVATE "C:/winbgim")
#target_link_directories(2D_geometric_editor PRIVATE "C:/winbgim")
#target_link_libraries(2D_geometric_editor bgi gdi32 comdlg32 uuid oleaut32 ole32)
