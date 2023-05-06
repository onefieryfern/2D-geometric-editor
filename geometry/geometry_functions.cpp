#include "geometry_functions.h"

#include "Point.h"

void drawLine (const Point& end1, const Point& end2) {
    line(end1.getX(), end1.getY(), end2.getX(), end2.getY());
}
