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

    bool isInMoving { false };
    Point point;
    bool isInFinalMoving { false };
    while (true) {
        Point mouseClickPoint;

        if (ismouseclick(WM_LBUTTONDOWN) && !isInMoving) {
            getmouseclick(WM_LBUTTONDOWN, mouseClickPoint.x, mouseClickPoint.y);
            drawPoint(mouseClickPoint, POINT_SIZE);

            isInMoving = true;

            point = mouseClickPoint;
        }

        PointBoundingBox interactionBox {createPointBoundingBox(point, POINT_SIZE) };
        if (ismouseclick(WM_LBUTTONDOWN) && isInMoving && !isInFinalMoving) {
            getmouseclick(WM_LBUTTONDOWN, mouseClickPoint.x, mouseClickPoint.y);

            if (isInPointBoundingBox(interactionBox, mouseClickPoint)) {
                colors currentColour { static_cast<colors>(getcolor()) };
                changePointColour(LIGHTBLUE);
                cleardevice();
                drawPoint(point, POINT_SIZE);
                changePointColour(currentColour);

                isInFinalMoving = true;
            }
        }

        if (ismouseclick(WM_LBUTTONDOWN) && isInFinalMoving) {
            getmouseclick(WM_LBUTTONDOWN, mouseClickPoint.x, mouseClickPoint.y);

            cleardevice();
            drawPoint(mouseClickPoint, POINT_SIZE);

            isInFinalMoving = false;
            point = mouseClickPoint;
        }

        if (kbhit() != 0 && getch() == '0')
            break;

        delay(50);
    }

    getch();
    closegraph();


    return 0;
}
