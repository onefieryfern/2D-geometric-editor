#include "draw_helper.h"
#include "geometry_data_structures.h"

#include <graphics.h>

void drawPoint (const Point& point, const short POINT_SIZE) {
    fillellipse(point.x, point.y, POINT_SIZE, POINT_SIZE);
}
