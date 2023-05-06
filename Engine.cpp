#include "Engine.h"

#include "Point.h"

#include <graphics.h>

void Engine::drawPoints() const {
    for (auto point : m_points) {
        point.draw();
    }
}

void Engine::addPoint(const Point &point) {
    m_points.insert(m_points.end(), point);
}

void Engine::drawAll() const {
    drawPoints();
}

void Engine::redrawAll() const {
    cleardevice();
    drawAll();
}
