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

public:
    Point() = default;
    Point(int x, int y);
    Point(int x, int y, int size);
    Point(int x, int y, int size, PointStyle pointStyle);

    int getX() const;
    int getY() const;

    void setPosition (int x, int y);
    void setSize (int size);
    void setPointStyle (PointStyle pointStyle);
    void setAllColours (int colour);

    void draw() const;
};

#endif //INC_2D_GEOMETRIC_EDITOR_POINT_H
