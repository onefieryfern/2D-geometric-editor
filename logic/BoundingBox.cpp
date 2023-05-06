#include "BoundingBox.h"

#include "geometry_structs.h"
#include "Rectangle.h"

BoundingBox::BoundingBox(const Position& topLeft, const Position& bottomRight)
    : m_topLeft{topLeft}, m_bottomRight{bottomRight} {}

bool BoundingBox::encasesPosition(const Position& point) const {
    if (point.x < m_topLeft.x || point.x > m_bottomRight.x)
        return false;

    if (point.y < m_topLeft.y || point.y > m_bottomRight.y)
        return false;

    return true;
}

void BoundingBox::draw() const {
    Rectangle box{
        {m_topLeft.x, m_topLeft.y},
        {m_bottomRight.x, m_bottomRight.y}
    };

    box.draw();
}
