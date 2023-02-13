#ifndef INC_2D_GEOMETRIC_EDITOR_GEOMETRY_DATA_STRUCTURES_H
#define INC_2D_GEOMETRIC_EDITOR_GEOMETRY_DATA_STRUCTURES_H

constexpr short numOfPointsInRectangle { 4 };

struct Point {
    int x{};
    int y{};
};

struct Square {
    Point orderedPoints[numOfPointsInRectangle]{};
};

struct PointBoundingBox {
    Point topLeft{};
    Point bottomRight{};
};

PointBoundingBox createPointBoundingBox (const Point& point, short pointSize);
void drawPointBoundingBox (const PointBoundingBox& boundingBox);
Square createSquareFromCentre (const Point& centre, short apothem);
Square createSquareFromPointBoundingBox (const PointBoundingBox& boundingBox);
bool isInPointBoundingBox (const PointBoundingBox& boundingBox, const Point& point);

#endif //INC_2D_GEOMETRIC_EDITOR_GEOMETRY_DATA_STRUCTURES_H
