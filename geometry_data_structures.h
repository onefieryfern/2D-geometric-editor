#ifndef INC_2D_GEOMETRIC_EDITOR_GEOMETRY_DATA_STRUCTURES_H
#define INC_2D_GEOMETRIC_EDITOR_GEOMETRY_DATA_STRUCTURES_H

constexpr short numOfPointsInRectangle {4};

struct CoordinatePair {
    int x{};
    int y{};
};

struct Square {
    CoordinatePair orderedPoints[numOfPointsInRectangle]{};
};

struct PointBoundBox {
    CoordinatePair topLeft{};
    CoordinatePair bottomRight{};
};

PointBoundBox getPointBoundBox (const CoordinatePair& point, short pointSize);
void drawPointBoundBox (const PointBoundBox& pointBoundBox);
Square getSquareFromCentre (const CoordinatePair& centre, short apothem);
Square getSquareFromPointBoundBox (const PointBoundBox& pointBoundBox);
bool isInPointBoundBox (const PointBoundBox& pointBoundBox, const CoordinatePair& point);

#endif //INC_2D_GEOMETRIC_EDITOR_GEOMETRY_DATA_STRUCTURES_H
