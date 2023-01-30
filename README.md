# 2D-geometric-editor
2D Geometric Editor


main

constexpr short WINDOW_WIDTH = 800;
    constexpr short WINDOW_HEIGHT = 600;

    constexpr char WINDOW_TITLE[] = "2D Geometric Editor";

    const Point SCREEN_CENTRE { WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2 };

    const short POINT_SIZE = 4;


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

    getch();
    closegraph();




draw_helper



void drawPoint (const Point& point, short pointSize) {
    fillellipse(point.x, point.y, pointSize, pointSize);
}

void drawLine(const Point &endpoint1, const Point &endpoint2) {
    line(endpoint1.x, endpoint1.y, endpoint2.x, endpoint2.y);
}








geometry_data

PointInteractionBox createPointInteractionBox (const Point& point, short pointSize) {
    PointInteractionBox pointInteractionBox;

    pointInteractionBox.topLeft.x = static_cast<short>(point.x - pointSize);
    pointInteractionBox.topLeft.y = static_cast<short>(point.y - pointSize);

    pointInteractionBox.bottomRight.x = static_cast<short>(point.x + pointSize);
    pointInteractionBox.bottomRight.y = static_cast<short>(point.y + pointSize);

    return  pointInteractionBox;
}