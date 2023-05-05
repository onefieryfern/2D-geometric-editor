#include "geometry_data_structures.h"
#include "draw_helper.h"
#include "Square.h"

// PointBoundBox

PointBoundBox getPointBoundBox (const CoordinatePair& point, short pointSize) {
    PointBoundBox boundBox;

    boundBox.topLeft.x = point.x - pointSize;
    boundBox.topLeft.y = point.y - pointSize;

    // fillelipse()'s centre is odd. TODO document fillelipse() and circle()'s center oddness
    boundBox.bottomRight.x = point.x + pointSize - 1;
    boundBox.bottomRight.y = point.y + pointSize - 1;

    return boundBox;
}

void drawPointBoundBox (const PointBoundBox& pointBoundBox) {
    Square(
            Point(pointBoundBox.topLeft.x, pointBoundBox.topLeft.y),
            Point(pointBoundBox.bottomRight.x, pointBoundBox.bottomRight.y)
            ).draw();
}


bool isInPointBoundBox (const PointBoundBox& pointBoundBox, const CoordinatePair& point) {
    if (point.x < pointBoundBox.topLeft.x || point.x > pointBoundBox.bottomRight.x)
        return false;

    if (point.y < pointBoundBox.topLeft.y || point.y > pointBoundBox.bottomRight.y)
        return false;

    return true;
}
