#ifndef INC_2D_GEOMETRIC_EDITOR_DRAW_HELPER_H
#define INC_2D_GEOMETRIC_EDITOR_DRAW_HELPER_H

#include <graphics.h>
#include "geometry_data_structures.h"

void drawPoint (const OldPoint& point, short pointSize);
void drawColouredPoint (const OldPoint& point, short pointSize, colors colour);
void changePointColour (colors color);
void drawLine (const OldPoint& endpoint1, const OldPoint& endpoint2);
void drawSquare (const Square& square);

#endif //INC_2D_GEOMETRIC_EDITOR_DRAW_HELPER_H
