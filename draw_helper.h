#ifndef INC_2D_GEOMETRIC_EDITOR_DRAW_HELPER_H
#define INC_2D_GEOMETRIC_EDITOR_DRAW_HELPER_H

#include <graphics.h>
#include "geometry_data_structures.h"

void drawPoint (const Point& point, short pointSize);
void changePointColour (colors color);
void drawLine (const Point& endpoint1, const Point& endpoint2);
void drawSquare (const Square& square);

#endif //INC_2D_GEOMETRIC_EDITOR_DRAW_HELPER_H
