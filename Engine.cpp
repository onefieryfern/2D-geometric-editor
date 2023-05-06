#include "Engine.h"

void Engine::addPoint(const Point &point) {
    m_points.insert(m_points.end(), point);
}

void Engine::drawPoints() const {
    for (auto point : m_points) {
        point.draw();
    }
}
