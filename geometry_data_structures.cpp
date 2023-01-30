#include "geometry_data_structures.h"
#include "draw_helper.h"

PointInteractionBox createPointInteractionBox (const Point& point, short pointSize) {
    PointInteractionBox pointInteractionBox;

    pointInteractionBox.topLeft.x = point.x - pointSize;
    pointInteractionBox.topLeft.y = point.y - pointSize;

    // fillelipse()'s centre is odd. TODO document fillelipse() and circle() center oddness
    pointInteractionBox.bottomRight.x = point.x + pointSize - 1;
    pointInteractionBox.bottomRight.y = point.y + pointSize - 1;

    return pointInteractionBox;
}

void drawPointInteractionBox (const PointInteractionBox& pointInteractionBox) {
    Square square;

    square.orderedPoints[0] = pointInteractionBox.topLeft;
    square.orderedPoints[1] = pointInteractionBox.topLeft;
    square.orderedPoints[1].x = pointInteractionBox.bottomRight.x;
    square.orderedPoints[2] = pointInteractionBox.bottomRight;
    square.orderedPoints[3] = pointInteractionBox.bottomRight;
    square.orderedPoints[3].x = pointInteractionBox.topLeft.x;

    drawSquare(square);
}
