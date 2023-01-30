#include "draw_helper.h"
#include "geometry_data_structures.h"

#include <graphics.h>

void drawPoint (const Point& point, short pointSize) {
    fillellipse(point.x, point.y, pointSize, pointSize);
}

void drawLine (const Point& endpoint1, const Point& endpoint2) {
    line(endpoint1.x, endpoint1.y, endpoint2.x, endpoint2.y);
}

void drawSquare (const Square& square) {
    constexpr short numOfSquarePoints { 4 };
    /*
    Point squarePoints[numOfSquarePoints];

    squarePoints[0].x = centre.x - apothem;
    squarePoints[0].y = centre.y - apothem;

    squarePoints[1].x = centre.x + apothem;
    squarePoints[1].y = centre.y - apothem;

    squarePoints[2].x = centre.x + apothem;
    squarePoints[2].y = centre.y + apothem;

    squarePoints[3].x = centre.x - apothem;
    squarePoints[3].y = centre.y + apothem;
     */

    for (short i = 0; i < numOfSquarePoints; i++) {
        if (i == 3)
            drawLine(square.orderedPoints[i], square.orderedPoints[0]);
        else
            drawLine(square.orderedPoints[i], square.orderedPoints[i + 1]);
    }
}
