#include <iostream>
#include "gotoxy.h"
using namespace std;


const int WIDTH = 80;
const int HEIGHT = 21;

class Border {
    int width, height;

public:
    Border(int _w, int _h): width(_w), height(_h){};

    void draw() const {
        for(int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (i == 0 || i == height-1 || j == 0 || j == width-1) {
                    cout << "#";
                }
                else {
                    cout << " ";
                }
            }
            cout << endl;
        }
        gotoxy(84, 2);
        cout << "x:";
        gotoxy(84, 5);
        cout << "y:";
    }
};


class Circle {
    float x, y;
    float dx, dy;

public:
    Circle(float _x, float _y, float _dx, float _dy): x(_x), y(_y), dx(_dx), dy(_dy){};

    void draw() const {
        gotoxy(x, y);
        cout << "o";

        gotoxy(84, 3);
        cout << x;
        gotoxy(84, 6);
        cout << y;
    }

    void clean_draw() const {
        gotoxy(x, y);
        cout << " ";
    }

    void move() {

        if (y < 19) {
            x += dx;
            y += dy;
        }
        if(x < 2 || x > 77){
            dx = -dx;
        }
        if(y < 2 || y > 17){
            dy = -dy;
        }
        dy += 0.3;
    }
};

int main() {

    HIDE_CURSOR();

    Border border(WIDTH, HEIGHT);
    Circle circle(1, 1, 1, 1);

    border.draw();
    circle.draw();

    while(true) {
        circle.clean_draw();
        circle.move();
        circle.draw();
        Sleep(16);
    }

    return 0;
}
