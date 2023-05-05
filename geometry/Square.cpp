#include "Square.h"

#include "geometry_data_structures.h"

#include <graphics.h>

// Constructors

// Initialise a Square from a centre point
Square::Square(const CoordinatePair& centre, short apothem) {
    // fillelipse()'s centre is odd. TODO document fillelipse() and circle()'s center oddness
    m_orderedPoints.at(0) = {centre.x - apothem, centre.y - apothem};
    m_orderedPoints.at(1) = {centre.x + apothem - 1, centre.y - apothem};
    m_orderedPoints.at(2) = {centre.x + apothem - 1, centre.y + apothem - 1};
    m_orderedPoints.at(3) = {centre.x - apothem, centre.y + apothem - 1};
}

// Initialise a Square from the top left point and the bottom right point
// Can be used, for example, to get a Square object from a bounding box's coordinates
Square::Square(const Point& topLeft, const Point& bottomRight) {
    m_orderedPoints.at(0) = topLeft;
    m_orderedPoints.at(1) = {bottomRight.getX(), topLeft.getY()};
    m_orderedPoints.at(2) = bottomRight;
    m_orderedPoints.at(3) = {topLeft.getX(), bottomRight.getY()};
}

// Other functions

void Square::draw() const {
    short next{1};
    for (short current{0}; current < numOfPointsInRectangle; current++) {
        line(
                m_orderedPoints.at(current).getX(),
                m_orderedPoints.at(current).getY(),
                m_orderedPoints.at(next).getX(),
                m_orderedPoints.at(next).getY()
                );

        if (next >= 3)
            next = 0;
        else
            next++;
    }
}
