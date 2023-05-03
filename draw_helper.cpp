#include "draw_helper.h"
#include "geometry_data_structures.h"

#include <graphics.h>

void drawLine (const CoordinatePair& endpoint1, const CoordinatePair& endpoint2) {
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
