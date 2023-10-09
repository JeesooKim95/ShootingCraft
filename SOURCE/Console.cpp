/**
\file		 Console.cpp
\author      jeesoo.kim
\brief
This file adjusts console sizes so that it fits the game screen. It also has functions to change fonts.

copyright   All content ?2018 DigiPen (USA) Corporation, all rights reserved
*/

#include "Console.h"


void adjustWindowSize(int Tmp_x, int Tmp_y)
{
    SMALL_RECT test;

    HANDLE hStdout;
    COORD coord;

    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    coord.X = Tmp_x;
    coord.Y = Tmp_y;

    test.Left = 0;
    test.Top = 0;
    test.Right = coord.X - 1;
    test.Bottom = coord.Y - 1;

    SetConsoleWindowInfo(hStdout, TRUE, &test);

}

void changefont()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_FONT_INFOEX cfInfo;
    cfInfo.cbSize = sizeof(CONSOLE_FONT_INFOEX);

    cfInfo.dwFontSize.X = 0;
    cfInfo.dwFontSize.Y = 20;


    lstrcpyW(cfInfo.FaceName, L"lucida console");

    SetCurrentConsoleFontEx(hConsole, TRUE, &cfInfo);
}