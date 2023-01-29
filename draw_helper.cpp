#include "draw_helper.h"
#include "geometry_data_structures.h"

#include <graphics.h>

void drawPoint (const Point& point, short pointSize) {
    fillellipse(point.x, point.y, pointSize, pointSize);
}
