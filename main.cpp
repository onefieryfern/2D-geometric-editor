#include "draw_helper.h"
#include "geometry_data_structures.h"

#include <winbgim.h>

#include <vector>
#include <iostream>

int main() {
    constexpr short WINDOW_WIDTH {800};
    constexpr short WINDOW_HEIGHT {600};

    constexpr char WINDOW_TITLE[] = "2D Geometric Editor";
    // const Point SCREEN_CENTRE { WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2 };
    const short POINT_SIZE {8};

    initwindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);

    std::vector<Point> points {{8, 8}};

    bool pointSelected {false};
    while (!kbhit()) {
        Point mouseClick{};
        bool mouseClicked{false};
        if (ismouseclick(WM_LBUTTONDOWN)) {
            mouseClicked = true;
            getmouseclick(WM_LBUTTONDOWN, mouseClick.x, mouseClick.y);

            clearmouseclick(WM_LBUTTONUP);
        }
        
        points.insert(points.end(), mouseClick);

        delay(50);
    }
    getch();

    for (auto point : points) {
        drawPoint(point, POINT_SIZE);
    }

    getch();
    closegraph();

    return 0;
}
