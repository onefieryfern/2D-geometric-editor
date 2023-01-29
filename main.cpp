#include <iostream>
#include <graphics.h>

#include "draw_helper.h"
#include "geometry_data_structures.h"

int main() {
    constexpr short WINDOW_WIDTH = 800;
    constexpr short WINDOW_HEIGHT = 600;

    constexpr char WINDOW_TITLE[] = "2D Geometric Editor";

    const Point SCREEN_CENTRE { WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2 };

    const short POINT_SIZE = 4;


    initwindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);

    Point mouseClickPoint;
    while (true) {
        do {
            getmouseclick(WM_LBUTTONDOWN, mouseClickPoint.x, mouseClickPoint.y);
            delay(50);
        } while (mouseClickPoint.x == -1 && mouseClickPoint.y == -1);

        drawPoint(mouseClickPoint, POINT_SIZE);

        if (kbhit() != 0 && getch() == '0')
                break;
    }

    getch();
    closegraph();

    return 0;
}
