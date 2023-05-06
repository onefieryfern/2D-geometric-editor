#ifndef INC_2D_GEOMETRIC_EDITOR_ENGINE_H
#define INC_2D_GEOMETRIC_EDITOR_ENGINE_H

#include "Point.h"

#include <vector>

class Engine {
private:
    std::vector<Point> m_points {};

    void drawPoints() const;
public:
    Engine() = default;

    void addPoint(const Point& point);

    void drawAll() const;
    void redrawAll() const;
};

#endif //INC_2D_GEOMETRIC_EDITOR_ENGINE_H
