#include <windows.h>

#ifndef BALL_WITH_GRAVITY_GOTOXY_H
#define BALL_WITH_GRAVITY_GOTOXY_H


void gotoxy(float x,float y){
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y= y;
    SetConsoleCursorPosition(hcon,dwPos);
}

void HIDE_CURSOR() {
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize = 2;
    cci.bVisible = FALSE;

    SetConsoleCursorInfo(hcon, &cci);
}


#endif
