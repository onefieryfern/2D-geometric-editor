cmake_minimum_required(VERSION 3.24)
project(2D_geometric_editor)

set(CMAKE_CXX_STANDARD 11)

add_executable(2D_geometric_editor main.cpp draw_helper.cpp draw_helper.h geometry_data_structures.h geometry_data_structures.cpp)

target_include_directories(2D_geometric_editor PRIVATE "C:/winbgim")
target_link_directories(2D_geometric_editor PRIVATE "C:/winbgim")
target_link_libraries(2D_geometric_editor bgi gdi32 comdlg32 uuid oleaut32 ole32)
