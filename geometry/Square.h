#include "Point.h"

#include "geometry_data_structures.h"

#include <array>

#ifndef INC_2D_GEOMETRIC_EDITOR_SQUARE_H
#define INC_2D_GEOMETRIC_EDITOR_SQUARE_H

class Square {
private:
    std::array<Point, 4> m_orderedPoints{};
public:
    Square() = default;
    Square(const CoordinatePair& centre, short apothem);
    Square(const Point& topLeft, const Point& bottomRight);

    void draw() const;
};


#endif //INC_2D_GEOMETRIC_EDITOR_SQUARE_H
