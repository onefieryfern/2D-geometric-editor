#include "Rectangle.h"

#include "geometry_constants.h"
#include "geometry_functions.h"

#include <graphics.h>

// Constructors

// Initialise a Rectangle from a centre point
// This is actually a Square
Rectangle::Rectangle(const Point& centre, short apothem) {
    // fillelipse()'s centre is odd. TODO document fillelipse() and circle()'s center oddness
    m_orderedPoints.at(0) = {centre.getX() - apothem, centre.getY() - apothem};
    m_orderedPoints.at(1) = {centre.getX() + apothem - 1, centre.getY() - apothem};
    m_orderedPoints.at(2) = {centre.getX() + apothem - 1, centre.getY() + apothem - 1};
    m_orderedPoints.at(3) = {centre.getX() - apothem, centre.getY() + apothem - 1};
}

// Initialise a Rectangle from the top left point and the bottom right point
// Can be used, for example, to get a Rectangle object from a bounding box's coordinates
Rectangle::Rectangle(const Point& topLeft, const Point& bottomRight) {
    m_orderedPoints.at(0) = topLeft;
    m_orderedPoints.at(1) = {bottomRight.getX(), topLeft.getY()};
    m_orderedPoints.at(2) = bottomRight;
    m_orderedPoints.at(3) = {topLeft.getX(), bottomRight.getY()};
}

// Other functions

void Rectangle::draw() const {
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
