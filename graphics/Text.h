#ifndef INC_2D_GEOMETRIC_EDITOR_GRAPHICS_TEXT_H
#define INC_2D_GEOMETRIC_EDITOR_GRAPHICS_TEXT_H

#include <graphics.h>

#include <string>

namespace Text {
    // Maximum charsize supported by SDL_bgi
    constexpr int maxCharsize {10};

    // Minimum charsize supported by SDL_bgi
    constexpr int minCharsize {1};

    textsettingstype getSaneDefaults();

    textsettingstype getActiveSettings();
    void setActiveSettings(const textsettingstype& textSettings);

    int getMaxCharsize (std::string text, const textsettingstype& textSettings, int height, int width);
};

#endif //INC_2D_GEOMETRIC_EDITOR_GRAPHICS_TEXT_H
