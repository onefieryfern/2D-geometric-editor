#include "draw_helper.h"
#include "geometry_data_structures.h"

#include <winbgim.h>

// #include <iostream>

int main() {
    constexpr short WINDOW_WIDTH {800};
    constexpr short WINDOW_HEIGHT {600};

    constexpr char WINDOW_TITLE[] = "2D Geometric Editor";
    // const Point SCREEN_CENTRE { WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2 };
    const short POINT_SIZE {8};

    initwindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);

    Point point {8, 8};
    drawPoint(point, POINT_SIZE);

    bool pointSelected {false};
    while (true) {
        Point mouseClick{};
        bool mouseClicked{false};

        if (ismouseclick(WM_LBUTTONDOWN)) {
            mouseClicked = true;
            getmouseclick(WM_LBUTTONDOWN, mouseClick.x, mouseClick.y);

            clearmouseclick(WM_LBUTTONUP);
        }

        if (mouseClicked && !pointSelected) {
            if (isInPointBoundingBox(createPointBoundingBox(point, POINT_SIZE), mouseClick)) {
                cleardevice();
                drawColouredPoint(point, POINT_SIZE, LIGHTBLUE);

                pointSelected = true;
            }
        }
        else if (mouseClicked) {
            point = mouseClick;

            cleardevice();
            drawPoint(point, POINT_SIZE);

            pointSelected = false;
        }

        if (kbhit() != 0 && getch() == '0')
            break;

        delay(50);
    }


    getch();
    closegraph();

    return 0;
}
