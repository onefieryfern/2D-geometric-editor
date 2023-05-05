#include "Point.h"

#include <graphics.h>

// Constructors
Point::Point(int x, int y) { setPosition(x, y); }
Point::Point(int x, int y, int size) : Point{x, y} { setSize(size); }
Point::Point(int x, int y, int size, PointStyle pointStyle) : Point{x, y, size} { setPointStyle(pointStyle); }

// Getters
int Point::getX() const { return m_x; }
int Point::getY() const { return m_y; }

// Setters
void Point::setPosition(int x, int y) {
    m_x = x;
    m_y = y;
}

void Point::setSize(int size) { m_size = size; }
void Point::setPointStyle(PointStyle pointStyle) { m_pointStyle = pointStyle; }

void Point::setAllColours(int colour) {
    m_pointStyle.fillColour = colour;
    m_pointStyle.borderColour = colour;
}

// Other functions
void Point::draw() const {
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
