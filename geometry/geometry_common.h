#ifndef INC_2D_GEOMETRIC_EDITOR_GEOMETRY_COMMON_H
#define INC_2D_GEOMETRIC_EDITOR_GEOMETRY_COMMON_H

#include "Point.h"

struct Position {
    int x{};
    int y{};
};

void drawLine (const Point& end1, const Point& end2);

#endif //INC_2D_GEOMETRIC_EDITOR_GEOMETRY_COMMON_H
