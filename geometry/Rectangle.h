#include "Point.h"

#include "geometry_constants.h"

#include <array>

#ifndef INC_2D_GEOMETRIC_EDITOR_GEOMETRY_RECTANGLE_H
#define INC_2D_GEOMETRIC_EDITOR_GEOMETRY_RECTANGLE_H

class Rectangle {
private:
    std::array<Point, g_numOfPointsInRectangle> m_orderedPoints {};
public:
    Rectangle () = default;
    Rectangle (const Point& centre, short apothem);
    Rectangle (const Point& topLeft, const Point& bottomRight);

    void draw () const;
};


#endif //INC_2D_GEOMETRIC_EDITOR_GEOMETRY_RECTANGLE_H
