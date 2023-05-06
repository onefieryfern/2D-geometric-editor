#include "draw_helper.h"
#include "Point.h"

#include <graphics.h>

void drawLine (const Point& endpoint1, const Point& endpoint2) {
    line(endpoint1.getX(), endpoint1.getY(), endpoint2.getX(), endpoint2.getY());
}
