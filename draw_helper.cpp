#include "draw_helper.h"
#include "geometry_data_structures.h"

#include <graphics.h>

void drawPoint (const Point& point, short pointSize) {
    fillellipse(point.x, point.y, pointSize, pointSize);
}

void changePointColour (colors color) {
    setcolor(color);
    setfillstyle(SOLID_FILL, color);
}

void drawLine (const Point& endpoint1, const Point& endpoint2) {
    line(endpoint1.x, endpoint1.y, endpoint2.x, endpoint2.y);
}

void drawSquare (const Square& square) {
    for (short i = 0; i < numOfPointsInSquare; i++) {
        if (i == 3)
            drawLine(square.orderedPoints[i], square.orderedPoints[0]);
        else
            drawLine(square.orderedPoints[i], square.orderedPoints[i + 1]);
    }
}
