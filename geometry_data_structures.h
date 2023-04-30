#ifndef INC_2D_GEOMETRIC_EDITOR_GEOMETRY_DATA_STRUCTURES_H
#define INC_2D_GEOMETRIC_EDITOR_GEOMETRY_DATA_STRUCTURES_H

constexpr short numOfPointsInRectangle {4};

struct OldPoint {
    int x{};
    int y{};
};

struct Square {
    OldPoint orderedPoints[numOfPointsInRectangle]{};
};

struct PointBoundBox {
    OldPoint topLeft{};
    OldPoint bottomRight{};
};

PointBoundBox getPointBoundBox (const OldPoint& point, short pointSize);
void drawPointBoundBox (const PointBoundBox& pointBoundBox);
Square getSquareFromCentre (const OldPoint& centre, short apothem);
Square getSquareFromPointBoundBox (const PointBoundBox& pointBoundBox);
bool isInPointBoundBox (const PointBoundBox& pointBoundBox, const OldPoint& point);

#endif //INC_2D_GEOMETRIC_EDITOR_GEOMETRY_DATA_STRUCTURES_H
