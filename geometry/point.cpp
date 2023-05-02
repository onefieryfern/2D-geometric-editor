#include "point.h"

#include <graphics.h>

Point::Point(int x, int y) : m_x{x}, m_y{y}
{
}

Point::Point(int x, int y, int size) : m_x{x}, m_y{y}, m_size{size}
{
}

Point::Point(int x, int y, int size, PointStyle pointStyle) : m_x{x}, m_y{y}, m_size{size}, m_pointStyle(pointStyle)
{
}

void Point::draw() {
    // Save state before draw
    fillsettingstype initialFillSettings{};
    getfillsettings(&initialFillSettings);

    int initialColour {getcolor()};

    // Set state to point's style
    setfillstyle(m_pointStyle.fillStyle, m_pointStyle.fillColour);
    setcolor(m_pointStyle.borderColour);

    // Actually draw point
    fillellipse(m_x, m_y, m_size, m_size);

    // Return to state before draw
    setfillstyle(initialFillSettings.pattern, initialFillSettings.color);
    setcolor(initialColour);
}

void Point::setPointStyle(PointStyle pointStyle) {
    m_pointStyle = pointStyle;
}

void Point::setAllColours(int colour) {
    m_pointStyle.fillColour = colour;
    m_pointStyle.borderColour = colour;
}
