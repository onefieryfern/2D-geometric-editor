#include "geometry_data_structures.h"
#include "draw_helper.h"

PointBoundingBox createPointBoundingBox (const Point& point, short pointSize) {
    PointBoundingBox pointBoundingBox;

    pointBoundingBox.topLeft.x = point.x - pointSize;
    pointBoundingBox.topLeft.y = point.y - pointSize;

    // fillelipse()'s centre is odd. TODO document fillelipse() and circle() center oddness
    pointBoundingBox.bottomRight.x = point.x + pointSize - 1;
    pointBoundingBox.bottomRight.y = point.y + pointSize - 1;

    return pointBoundingBox;
}

void drawPointBoundingBox (const PointBoundingBox& boundingBox) {
    drawSquare(createSquareFromPointBoundingBox(boundingBox));
}

bool isInPointBoundingBox (const PointBoundingBox& boundingBox, const Point& point) {
    if (point.x < boundingBox.topLeft.x || point.x > boundingBox.bottomRight.x)
        return false;

    if (point.y < boundingBox.topLeft.y || point.y > boundingBox.bottomRight.y)
        return false;

    return true;
}

Square createSquareFromCentre (const Point& centre, short apothem) {
    Square square{};

    // fillelipse()'s centre is odd. TODO document fillelipse() and circle() center oddness
    square.orderedPoints[0].x = centre.x - apothem;
    square.orderedPoints[0].y = centre.y - apothem;

    square.orderedPoints[1].x = centre.x + apothem - 1;
    square.orderedPoints[1].y = centre.y - apothem;

    square.orderedPoints[2].x = centre.x + apothem - 1;
    square.orderedPoints[2].y = centre.y + apothem - 1;

    square.orderedPoints[3].x = centre.x - apothem;
    square.orderedPoints[3].y = centre.y + apothem - 1;

    return square;
}

Square createSquareFromPointBoundingBox (const PointBoundingBox& boundingBox) {
    Square square;

    square.orderedPoints[0] = boundingBox.topLeft;

    square.orderedPoints[1] = boundingBox.topLeft;
    square.orderedPoints[1].x = boundingBox.bottomRight.x;

    square.orderedPoints[2] = boundingBox.bottomRight;
    square.orderedPoints[3] = boundingBox.bottomRight;

    square.orderedPoints[3].x = boundingBox.topLeft.x;

    return square;
}


