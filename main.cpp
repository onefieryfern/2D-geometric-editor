#include <iostream>
#include <graphics.h>

#include "draw_helper.h"
#include "geometry_data_structures.h"

int main() {
    constexpr short WINDOW_WIDTH = 800;
    constexpr short WINDOW_HEIGHT = 600;

    constexpr char WINDOW_TITLE[] = "2D Geometric Editor";
    const Point SCREEN_CENTRE { WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2 };
    const short POINT_SIZE = 8;

    initwindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);

    Point point{8, 8};
    drawPoint(point, POINT_SIZE);

    // bool isInMoving { true };
    bool pointSelected{false};

    while (true) {
        /*
        if (ismouseclick(WM_LBUTTONDOWN) && !isInMoving) {
            getmouseclick(WM_LBUTTONDOWN, mouseClickPoint.x, mouseClickPoint.y);
            drawPoint(mouseClickPoint, POINT_SIZE);

            isInMoving = true;

            point = mouseClickPoint;
        }
         */

        Point mouseClickPoint{};
        bool mouseClicked{false};

        if (ismouseclick(WM_LBUTTONDOWN)) {
            mouseClicked = true;
            getmouseclick(WM_LBUTTONDOWN, mouseClickPoint.x, mouseClickPoint.y);

            clearmouseclick(WM_LBUTTONUP);
        }

        if (mouseClicked && !pointSelected) {
            PointBoundingBox boundingBox {createPointBoundingBox(point, POINT_SIZE) };
            if (isInPointBoundingBox(boundingBox, mouseClickPoint)) {
                colors initialColour{static_cast<colors>(getcolor())};
                changePointColour(LIGHTBLUE);

                cleardevice();
                drawPoint(point, POINT_SIZE);

                changePointColour(initialColour);

                pointSelected = true;
            }
            mouseClicked = false;
        }

        if (mouseClicked && pointSelected) {
            point = mouseClickPoint;

            cleardevice();
            drawPoint(point, POINT_SIZE);

            pointSelected = false;
            mouseClicked = false;
        }

        if (kbhit() != 0 && getch() == '0')
            break;

        delay(50);
    }


    getch();
    closegraph();

    return 0;
}
