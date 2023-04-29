#ifndef INC_2D_GEOMETRIC_EDITOR_GEOMETRY_DATA_STRUCTURES_H
#define INC_2D_GEOMETRIC_EDITOR_GEOMETRY_DATA_STRUCTURES_H

constexpr short numOfPointsInRectangle {4};

struct Point {
    int x{};
    int y{};
};

struct Square {
    Point orderedPoints[numOfPointsInRectangle]{};
};

struct PointBoundBox {
    Point topLeft{};
    Point bottomRight{};
};

PointBoundBox getPointBoundBox (const Point& point, short pointSize);
void drawPointBoundBox (const PointBoundBox& pointBoundBox);
Square getSquareFromCentre (const Point& centre, short apothem);
Square getSquareFromPointBoundBox (const PointBoundBox& pointBoundBox);
bool isInPointBoundBox (const PointBoundBox& pointBoundBox, const Point& point);

#endif //INC_2D_GEOMETRIC_EDITOR_GEOMETRY_DATA_STRUCTURES_H
