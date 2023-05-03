#include <graphics.h>

#ifndef INC_2D_GEOMETRIC_EDITOR_POINT_H
#define INC_2D_GEOMETRIC_EDITOR_POINT_H

struct PointStyle {
    int fillColour{WHITE};
    int borderColour{WHITE};

    int fillStyle{SOLID_FILL};
};

class Point {
private:
    int m_x{0};
    int m_y{0};
    int m_size{1};

    PointStyle m_pointStyle{};
    // colors m_colour{WHITE};

public:
    Point();
    Point(int x, int y);
    Point(int x, int y, int size);
    Point(int x, int y, int size, PointStyle pointStyle);

    void draw();

    void setPointStyle (PointStyle pointStyle);
    void setAllColours (int colour);
};

#endif //INC_2D_GEOMETRIC_EDITOR_POINT_H
