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

void drawPointInteractionBox (const PointInteractionBox& interactionBox) {
    drawSquare(createSquareFromPointInteractionBox(interactionBox));
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

Square createSquareFromPointInteractionBox (const PointInteractionBox& interactionBox) {
    Square square;

    square.orderedPoints[0] = interactionBox.topLeft;

    square.orderedPoints[1] = interactionBox.topLeft;
    square.orderedPoints[1].x = interactionBox.bottomRight.x;

    square.orderedPoints[2] = interactionBox.bottomRight;
    square.orderedPoints[3] = interactionBox.bottomRight;

    square.orderedPoints[3].x = interactionBox.topLeft.x;

    return square;
}
