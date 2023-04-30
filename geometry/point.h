#include <winbgim.h>

#ifndef INC_2D_GEOMETRIC_EDITOR_POINT_H
#define INC_2D_GEOMETRIC_EDITOR_POINT_H

struct PointStyle {
    colors fillColour{WHITE};
    colors borderColour{WHITE};

    fill_styles fillStyle{SOLID_FILL};
};

class Point {
private:
    int m_x{0};
    int m_y{0};
    int m_size{1};

    PointStyle m_pointStyle{};
    // colors m_colour{WHITE};

public:
    Point(int x, int y);
    Point(int x, int y, int size);
    Point(int x, int y, int size, PointStyle pointStyle);

    void draw();

    void setPointStyle (PointStyle pointStyle);
    void setAllColours (colors colour);
};

#endif //INC_2D_GEOMETRIC_EDITOR_POINT_H
