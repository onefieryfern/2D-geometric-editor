#ifndef INC_2D_GEOMETRIC_EDITOR_GRAPHICS_COLOUR_H
#define INC_2D_GEOMETRIC_EDITOR_GRAPHICS_COLOUR_H

class Colour {
private:
    static constexpr int minColourComponentValue { 0 };
    static constexpr int maxColourComponentValue { 255 };

    int m_red { maxColourComponentValue };
    int m_green { maxColourComponentValue };
    int m_blue { maxColourComponentValue };
public:
    Colour () = default;
    Colour (int red, int green, int blue);

    int toInt () const;
};

#endif //INC_2D_GEOMETRIC_EDITOR_GRAPHICS_COLOUR_H
