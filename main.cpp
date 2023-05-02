#include "draw_helper.h"
#include "geometry_data_structures.h"
#include "geometry/point.h"

#include <graphics.h>

#include <vector>
#include <iostream>

int main() {
    constexpr short WINDOW_WIDTH {800};
    constexpr short WINDOW_HEIGHT {600};

    constexpr char WINDOW_TITLE[] = "2D Geometric Editor";
    // const OldPoint SCREEN_CENTRE { WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2 };
    const short POINT_SIZE {8};

    initwindow(WINDOW_WIDTH, WINDOW_HEIGHT);

    std::vector<OldPoint> points {{8, 8}};

    bool pointSelected {false};
    while (!xkb_hit()) {
        OldPoint mouseClick{};
        bool mouseClicked{false};
        if (ismouseclick(WM_LBUTTONDOWN)) {
            mouseClicked = true;
            getmouseclick(WM_LBUTTONDOWN, &mouseClick.x, &mouseClick.y);

            // clearmouseclick(WM_LBUTTONUP);
        }

        if (mouseClicked)
            points.insert(points.end(), mouseClick);

        delay(50);
    }
    // bgi_getch();

    for (auto point : points) {
        drawPoint(point, POINT_SIZE);
    }

    bgi_getch();
    closegraph();

    return 0;
}
