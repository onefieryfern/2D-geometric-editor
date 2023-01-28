cmake_minimum_required(VERSION 3.24)
project(2D_geometric_editor)

set(CMAKE_CXX_STANDARD 11)

add_executable(2D_geometric_editor main.cpp draw_helper.cpp draw_helper.h geometry_data_structures.h)

target_link_libraries(2D_geometric_editor SDL_bgi)
target_link_libraries(2D_geometric_editor SDL2)
