#include "draw_helper.h"
#include "geometry_data_structures.h"

#include <graphics.h>

void drawPoint (const OldPoint& point, short pointSize) {
    fillellipse(point.x, point.y, pointSize, pointSize);
}

void drawColouredPoint (const OldPoint& point, short pointSize, int colour) {
    int initialColour {getcolor()};
    changePointColour(colour);

    drawPoint(point, pointSize);

    changePointColour(initialColour);
}

void changePointColour (int color) {
    setcolor(color);
    setfillstyle(SOLID_FILL, color);
}

void drawLine (const OldPoint& endpoint1, const OldPoint& endpoint2) {
    line(endpoint1.x, endpoint1.y, endpoint2.x, endpoint2.y);
}

void drawSquare (const Square& square) {
    for (short i = 0; i < numOfPointsInRectangle; i++) {
        if (i == 3)
            drawLine(square.orderedPoints[i], square.orderedPoints[0]);
        else
            drawLine(square.orderedPoints[i], square.orderedPoints[i + 1]);
    }
}
