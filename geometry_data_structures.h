#ifndef INC_2D_GEOMETRIC_EDITOR_GEOMETRY_DATA_STRUCTURES_H
#define INC_2D_GEOMETRIC_EDITOR_GEOMETRY_DATA_STRUCTURES_H

constexpr short numOfPointsInSquare { 4 };

struct Point {
    int x{};
    int y{};
};

struct Square {
    Point orderedPoints[numOfPointsInSquare]{};
};

struct PointInteractionBox {
    Point topLeft{};
    Point bottomRight{};
};

PointInteractionBox createPointInteractionBox (const Point& point, short pointSize);
void drawPointInteractionBox (const PointInteractionBox& interactionBox);
Square createSquareFromCentre (const Point& centre, short apothem);
Square createSquareFromPointInteractionBox (const PointInteractionBox& interactionBox);
bool isInPointInteractionBox (const PointInteractionBox& interactionBox, const Point& point);

#endif //INC_2D_GEOMETRIC_EDITOR_GEOMETRY_DATA_STRUCTURES_H
