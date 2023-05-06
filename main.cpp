#include "geometry_common.h"
#include "Point.h"

#include <graphics.h>

#include <vector>
// #include <iostream>

int main() {
    constexpr short WINDOW_WIDTH {800};
    constexpr short WINDOW_HEIGHT {600};

    constexpr char WINDOW_TITLE[] {"2D Geometric Editor (pre-Alpha)"};
    // const Position SCREEN_CENTRE { WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2 };
    const short POINT_SIZE {8};

    initwindow(WINDOW_WIDTH, WINDOW_HEIGHT);
    setwintitle(0, const_cast<char *>(WINDOW_TITLE));

    std::vector<Point> points {{8, 8, POINT_SIZE}};

    while (!xkb_hit()) {
        Position mouseClickPoint{};
        bool mouseClicked{false};
        if (ismouseclick(WM_LBUTTONDOWN)) {
            mouseClicked = true;
            getmouseclick(WM_LBUTTONDOWN, &mouseClickPoint.x, &mouseClickPoint.y);

            // Clear "left mouse button up" click
            int clear{};
            getmouseclick(WM_LBUTTONUP, &clear, &clear);
        }

        if (mouseClicked)
            points.insert(points.end(), Point(mouseClickPoint.x, mouseClickPoint.y, POINT_SIZE));

        delay(50);
    }

    for (auto point : points) {
        point.draw();
    }

    bgi_getch();
    closegraph();

    return 0;
}
