/**
\file        SetCursor_Position.cpp
\author      Chulseung Lee
\brief
                This will get the x,y position of cursor in screen.
                gotoxy : will set the cursor's position in console screen.
                Initialize_Ship_Map_Cursor : Initialize the first of console when initializing.
                Move_Ship_Map_Cursor : Check the cursor's position also is it able to moving. Based on player's keyboard input.
                Get_Cursor_Position_Ship_Map : change and return by pointer type of cursor's x,y coordinates.
                Check_Cursor_Position_Is_Good: Check the cursor's x,y with the player's keyboard inputs.

                copyright   All content ?2018 DigiPen (USA) Corporation, all rights reserved

*/


#include "windows.h"
#include "MapStatus.h"
#include "SetCursor_Position.h"
#include "SetCursor_Move.h"
#include "Input.h"

void gotoxy(int x, int y)
{
    COORD Pos = { x - 1, y - 1 };

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void Initialize_Ship_Map_Cursor(Ship_Map ship_map)
{
    ship_map[1][1] = Ship_Map_Cursor;
}

void Move_Ship_Map_Cursor(Ship_Map ship_map, int dir, int cursor_x, int cursor_y)
{
    switch (dir)
    {
    case LEFT:
        Move_Cursor_Left(cursor_x, cursor_y, ship_map);
        break;
    case RIGHT:
        Move_Cursor_Right(cursor_x, cursor_y, ship_map);
        break;
    case UP:
        Move_Cursor_Up(cursor_x, cursor_y, ship_map);
        break;
    case DOWN:
        Move_Cursor_Down(cursor_x, cursor_y, ship_map);
        break;
    }
}

void Get_Cursor_Position_Ship_Map(int *cursor_x, int *cursor_y, Ship_Map ship_map)
{
    for (int i = 0; i < SHIP_LOW; i++)
    {
        for (int j = 0; j < SHIP_COL; j++)
        {
            if (ship_map[i][j] == Ship_Map_Cursor)
            {
                *cursor_x = j;
                *cursor_y = i;
            }

        }

    }


}

bool Check_Cursor_Position_Is_Good(int cursor_x, int cursor_y, int dir, Ship_Map ship_map)
{
    if (ship_map[cursor_y][cursor_x - 1] != AIR && dir == LEFT)
    {
        return false;
    }
    else if (ship_map[cursor_y][cursor_x + 1] != AIR && dir == RIGHT)
    {
        return false;
    }

    else if (ship_map[cursor_y - 1][cursor_x] != AIR && dir == UP)
    {
        return false;
    }
    else if (ship_map[cursor_y + 1][cursor_x] != AIR && dir == DOWN)
    {
        return false;
    }
    return true;
}