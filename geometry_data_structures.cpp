#include "geometry_data_structures.h"

PointInteractionBox createPointInteractionBox (const Point& point, short pointSize) {
    PointInteractionBox pointInteractionBox;

    pointInteractionBox.topLeft.x = static_cast<short>(point.x - pointSize);
    pointInteractionBox.topLeft.y = static_cast<short>(point.y - pointSize);

    pointInteractionBox.bottomRight.x = static_cast<short>(point.x + pointSize);
    pointInteractionBox.bottomRight.y = static_cast<short>(point.y + pointSize);

    return  pointInteractionBox;
}
