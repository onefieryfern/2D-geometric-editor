#include <iostream>
#include <graphics.h>

#include "draw_helper.h"
#include "geometry_data_structures.h"

int main() {
    constexpr short WINDOW_WIDTH = 800;
    constexpr short WINDOW_HEIGHT = 600;

    const Point SCREEN_CENTRE { WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2 };

    const short POINT_SIZE = 4;


    initwindow(WINDOW_WIDTH, WINDOW_HEIGHT);


    drawPoint(SCREEN_CENTRE, POINT_SIZE);


    getch();
    closegraph();

    return 0;
}
