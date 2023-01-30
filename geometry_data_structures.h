#ifndef INC_2D_GEOMETRIC_EDITOR_GEOMETRY_DATA_STRUCTURES_H
#define INC_2D_GEOMETRIC_EDITOR_GEOMETRY_DATA_STRUCTURES_H

struct Point {
    int x;
    int y;
};

struct Square {
    Point orderedPoints[4];
};

struct PointInteractionBox {
    Point topLeft;
    Point bottomRight;
};

PointInteractionBox createPointInteractionBox (const Point& point, short pointSize);
void drawPointInteractionBox (const PointInteractionBox& pointInteractionBox);

#endif //INC_2D_GEOMETRIC_EDITOR_GEOMETRY_DATA_STRUCTURES_H
