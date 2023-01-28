#include <iostream>
#include <graphics.h>

using namespace std;

int main()
{
    constexpr short WINDOW_WIDTH = 800;
    constexpr short WINDOW_HEIGHT = 600;

    initwindow(WINDOW_WIDTH, WINDOW_HEIGHT);



    getch();
    closegraph();

    return 0;
}
