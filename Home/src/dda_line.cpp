#include <graphics.h>
#include <conio.h>
#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

// Digital Differential Analyzer (DDA) Line Drawing Function
void drawDDA(float x1, float y1, float x2, float y2, int color = WHITE) {
    // 1. Calculate dx and dy
    float dx = x2 - x1;
    float dy = y2 - y1;

    // 2. Calculate steps required based on max(|dx|, |dy|)
    float steps = (abs(dx) > abs(dy)) ? abs(dx) : abs(dy);

    if (steps == 0) {
        putpixel((int)round(x1), (int)round(y1), color);
        return;
    }

    // 3. Calculate increment factors for x and y
    float xInc = dx / steps;
    float yInc = dy / steps;

    // Initial coordinates
    float x = x1;
    float y = y1;

    // 4. Plot pixel-by-pixel along the line path
    for (int i = 0; i <= steps; i++) {
        putpixel((int)round(x), (int)round(y), color);
        x += xInc;
        y += yInc;
    }
}

int main() {
    float x1, y1, x2, y2;

    cout << "========================================" << endl;
    cout << "   DDA Line Drawing Algorithm (C++)    " << endl;
    cout << "========================================" << endl;
    cout << "Enter starting coordinates (x1 y1): ";
    cin >> x1 >> y1;

    cout << "Enter ending coordinates (x2 y2): ";
    cin >> x2 >> y2;

    // Initialize graphics window
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    // Display title on the graphics window
    outtextxy(20, 20, (char*)"CGM Lab Assignment 2: DDA Line Drawing Algorithm");

    // Draw the straight line using DDA algorithm
    drawDDA(x1, y1, x2, y2, WHITE);

    // Highlight starting and ending points
    circle((int)round(x1), (int)round(y1), 3);
    circle((int)round(x2), (int)round(y2), 3);

    // Coordinate labels
    char label1[64], label2[64];
    sprintf(label1, "(%.0f, %.0f)", x1, y1);
    sprintf(label2, "(%.0f, %.0f)", x2, y2);
    outtextxy((int)round(x1) + 10, (int)round(y1) - 15, label1);
    outtextxy((int)round(x2) + 10, (int)round(y2) + 5, label2);

    // Wait for user keystroke then close
    getch();
    closegraph();
    return 0;
}
