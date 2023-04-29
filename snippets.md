```C++
Point mouseClickPoint;
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
```

```C++
Point mouseClickPoint;
while (true) {
    if (ismouseclick(WM_LBUTTONDOWN)) {
        getmouseclick(WM_LBUTTONDOWN, mouseClickPoint.x, mouseClickPoint.y);
        drawPoint(mouseClickPoint, POINT_SIZE);

        colors currentColour { static_cast<colors>(getcolor()) };
        setcolor(RED);
        
        PointBoundingBox pointInteractionBox = createPointBoundingBox(mouseClickPoint, POINT_SIZE);
        drawPointBoundingBox(pointInteractionBox);
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
