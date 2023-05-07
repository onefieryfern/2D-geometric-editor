#include "Colour.h"

#include <graphics.h>

#include <algorithm>
#include <iostream>

Colour::Colour (int red, int green, int blue) {
    m_red = std::clamp(red, minColourComponentValue, maxColourComponentValue);
    m_green = std::clamp(green, minColourComponentValue, maxColourComponentValue);
    m_blue = std::clamp(blue, minColourComponentValue, maxColourComponentValue);

    // Error alerting
    if (red != m_red || green != m_green || blue != m_blue) {
        std::cerr << "Found invalid colour value and clamped it to the allowed range [" << minColourComponentValue
                  << ", " << maxColourComponentValue << "].\n";
    }
}

// Uses SDL_bgi's COLOR() function
// For use with SDL_bgi color-related functions
int Colour::toInt () const {
    return COLOR(m_red, m_green, m_blue);
}
