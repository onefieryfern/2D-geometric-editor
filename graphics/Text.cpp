#include "Text.h"

#include <graphics.h>

#include <string>

using namespace std::literals;

namespace Text {
    textsettingstype getSaneDefaults() {
        return {DEFAULT_FONT, HORIZ_DIR, minCharsize, LEFT_TEXT, TOP_TEXT};
    }

    textsettingstype getActiveSettings() {
        textsettingstype textSettings{};
        gettextsettings(&textSettings);

        return textSettings;
    }

    void setActiveSettings(const textsettingstype &textSettings) {
        settextstyle(textSettings.font, textSettings.direction, textSettings.charsize);
        settextjustify(textSettings.horiz, textSettings.vert);
    }

/*
 * Finds the maximum charsize possible for the text provided
 *
 * Doesn't use a const std::string& as textheight() and textwidth() have to be provided with a *non-const* pointer to a
 * null-terminated C-style string, and I don't trust them to not modify the C-style string, leading to undefined
 * behaviour in the std::string.
 */
    int getMaxCharsize(std::string text, const textsettingstype &textSettings, int height, int width) {
        // Save state before testing
        textsettingstype initialTextSettings{getActiveSettings()};

        // Do the testing
        int foundMaxCharsize {-1};
        for (int charsize = minCharsize; charsize <= maxCharsize; charsize++) {
            // Set state to text's style
            settextstyle(textSettings.font, textSettings.direction, charsize);

            int textHeight{textheight(const_cast<char *>(text.c_str()))};
            int textWidth{textwidth(const_cast<char *>(text.c_str()))};

            if (textHeight <= height && textWidth <= width)
                foundMaxCharsize = charsize;
            else if (foundMaxCharsize == -1) {
                // First return to state before testing
                setActiveSettings(initialTextSettings);

                throw "The text would be too large for the available space even at the lowest charsize."sv;
            }
            else
                break;
        }

        // Return to state before testing
        setActiveSettings(initialTextSettings);

        return foundMaxCharsize;
    }
}
