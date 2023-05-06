#ifndef INC_2D_GEOMETRIC_EDITOR_GRAPHICS_COLOUR_H
#define INC_2D_GEOMETRIC_EDITOR_GRAPHICS_COLOUR_H

constexpr int MIN_COLOUR_COMPONENT_VALUE {0};
constexpr int MAX_COLOUR_COMPONENT_VALUE {255};

class Colour {
private:
    int m_red {MAX_COLOUR_COMPONENT_VALUE};
    int m_green {MAX_COLOUR_COMPONENT_VALUE};
    int m_blue {MAX_COLOUR_COMPONENT_VALUE};
public:
    Colour() = default;
    Colour(int red, int green, int blue);

    int toInt() const;
};

#endif //INC_2D_GEOMETRIC_EDITOR_GRAPHICS_COLOUR_H
