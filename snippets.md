```C++
OldPoint mouseClickPoint;
while (true) {
    getmouseclick(WM_LBUTTONDOWN, mouseClickPoint.x, mouseClickPoint.y);
    delay(50);

    if (mouseClickPoint.x != -1 && mouseClickPoint.y != -1)
        drawPoint(mouseClickPoint, POINT_SIZE);

    if (kbhit() != 0 && getch() == '0')
            break;
}
```

```C++
OldPoint mouseClickPoint;
OldPoint emptyPoint { -1, -1 };
OldPoint lineSegment[2] { emptyPoint, emptyPoint };
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
```

```C++
OldPoint mouseClickPoint;
while (true) {
    if (ismouseclick(WM_LBUTTONDOWN)) {
        getmouseclick(WM_LBUTTONDOWN, mouseClickPoint.x, mouseClickPoint.y);
        drawPoint(mouseClickPoint, POINT_SIZE);

        colors currentColour { static_cast<colors>(getcolor()) };
        setcolor(RED);
        
        PointBoundBox pointInteractionBox = getPointBoundBox(mouseClickPoint, POINT_SIZE);
        drawPointBoundBox(pointInteractionBox);
        setcolor(currentColour);
    }

    if (kbhit() != 0 && getch() == '0')
        break;

    delay(50);
}
```

```C++
if (ismouseclick(WM_LBUTTONDOWN) && !isInMoving) {
    getmouseclick(WM_LBUTTONDOWN, mouseClick.x, mouseClick.y);
    drawPoint(mouseClick, POINT_SIZE);

    isInMoving = true;

    point = mouseClick;
}
```

"Edit mode":
```C++
OldPoint mouseClick{};
bool mouseClicked{false};

if (ismouseclick(WM_LBUTTONDOWN)) {
    mouseClicked = true;
    getmouseclick(WM_LBUTTONDOWN, mouseClick.x, mouseClick.y);

    clearmouseclick(WM_LBUTTONUP);
}

if (mouseClicked && !pointSelected) {
    if (isInPointBoundBox(getPointBoundBox(point, POINT_SIZE), mouseClick)) {
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
```
