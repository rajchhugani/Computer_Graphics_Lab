#include <graphics.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    // 1. Line
    line(100, 100, 250, 100);

    // 2. Circle
    circle(400, 120, 50);

    // 3. Rectangle
    rectangle(100, 200, 250, 320);

    // 4. Triangle
    line(400, 200, 330, 320);
    line(330, 320, 470, 320);
    line(470, 320, 400, 200);

    getch();
    closegraph();
    return 0;
}
