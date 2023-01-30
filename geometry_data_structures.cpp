#include "geometry_data_structures.h"

PointInteractionBox createPointInteractionBox (const Point& point, short pointSize) {
    PointInteractionBox pointInteractionBox;

    pointInteractionBox.topLeft.x = point.x - pointSize;
    pointInteractionBox.topLeft.y = point.y - pointSize;

    // fillelipse()'s centre is odd. TODO document fillelipse() and circle() center oddness
    pointInteractionBox.bottomRight.x = point.x + pointSize - 1;
    pointInteractionBox.bottomRight.y = point.y + pointSize - 1;

    return pointInteractionBox;
}
