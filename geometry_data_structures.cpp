#include "geometry_data_structures.h"
#include "draw_helper.h"

// PointBoundBox

PointBoundBox getPointBoundBox (const Point& point, short pointSize) {
    PointBoundBox boundBox;

    boundBox.topLeft.x = point.x - pointSize;
    boundBox.topLeft.y = point.y - pointSize;

    // fillelipse()'s centre is odd. TODO document fillelipse() and circle()'s center oddness
    boundBox.bottomRight.x = point.x + pointSize - 1;
    boundBox.bottomRight.y = point.y + pointSize - 1;

    return boundBox;
}

void drawPointBoundBox (const PointBoundBox& pointBoundBox) {
    drawSquare(getSquareFromPointBoundBox(pointBoundBox));
}

bool isInPointBoundBox (const PointBoundBox& pointBoundBox, const Point& point) {
    if (point.x < pointBoundBox.topLeft.x || point.x > pointBoundBox.bottomRight.x)
        return false;

    if (point.y < pointBoundBox.topLeft.y || point.y > pointBoundBox.bottomRight.y)
        return false;

    return true;
}


// Square

Square getSquareFromCentre (const Point& centre, short apothem) {
    Square square{};

    // fillelipse()'s centre is odd. TODO document fillelipse() and circle()'s center oddness
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

Square getSquareFromPointBoundBox (const PointBoundBox& pointBoundBox) {
    Square square;

    square.orderedPoints[0] = pointBoundBox.topLeft;

    square.orderedPoints[1].x = pointBoundBox.bottomRight.x;
    square.orderedPoints[1].y = pointBoundBox.topLeft.y;

    square.orderedPoints[2] = pointBoundBox.bottomRight;

    square.orderedPoints[3].x = pointBoundBox.topLeft.x;
    square.orderedPoints[3].y = pointBoundBox.bottomRight.y;

    return square;
}


