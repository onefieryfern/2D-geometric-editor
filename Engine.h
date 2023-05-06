#ifndef INC_2D_GEOMETRIC_EDITOR_ENGINE_H
#define INC_2D_GEOMETRIC_EDITOR_ENGINE_H

#include "Point.h"

#include <vector>

class Engine {
private:
    std::vector<Point> m_points {};
public:
    Engine() = default;

    void addPoint(const Point& point);

    void drawPoints() const;
};

#endif //INC_2D_GEOMETRIC_EDITOR_ENGINE_H
