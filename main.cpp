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

    /*
    Point mouseClickPoint;
    while (true) {
        getmouseclick(WM_LBUTTONDOWN, mouseClickPoint.x, mouseClickPoint.y);
        delay(50);

        if (mouseClickPoint.x != -1 && mouseClickPoint.y != -1)
            drawPoint(mouseClickPoint, POINT_SIZE);

        if (kbhit() != 0 && getch() == '0')
                break;
    }
     */

    /*
    Point mouseClickPoint;
    Point emptyPoint { -1, -1 };
    Point lineSegment[2] { emptyPoint, emptyPoint };
    while (true) {
        getmouseclick(WM_LBUTTONDOWN, mouseClickPoint.x, mouseClickPoint.y);
        delay(50);

        if (mouseClickPoint.x != -1 && mouseClickPoint.y != -1) {
            drawPoint(mouseClickPoint, POINT_SIZE);

            if (lineSegment[0].x == -1 && lineSegment[0].y == -1) {
                lineSegment[0] = mouseClickPoint;
            }
            else if (lineSegment[1].x == -1 && lineSegment[1].y == -1) {
                lineSegment[1] = mouseClickPoint;

                drawLine(lineSegment[0], lineSegment[1]);

                lineSegment[0] = emptyPoint;
                lineSegment[1] = emptyPoint;
            }
        }

        if (kbhit() != 0 && getch() == '0')
            break;
    }
     */

    Point mouseClickPoint;
    while (true) {
        if (ismouseclick(WM_LBUTTONDOWN)) {
            getmouseclick(WM_LBUTTONDOWN, mouseClickPoint.x, mouseClickPoint.y);
            drawPoint(mouseClickPoint, POINT_SIZE);

            colors currentColour { static_cast<colors>(getcolor()) };
            setcolor(RED);
            
            PointInteractionBox pointInteractionBox = createPointInteractionBox(mouseClickPoint, POINT_SIZE);
            drawPointInteractionBox(pointInteractionBox);
            setcolor(currentColour);
        }

        if (kbhit() != 0 && getch() == '0')
            break;

        delay(50);
    }

    getch();
    closegraph();


    return 0;
}
