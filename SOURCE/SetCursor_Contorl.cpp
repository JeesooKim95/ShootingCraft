/**
\file        SetCursor_Move.cpp
\author      Chulseung Lee
\brief
                This will change cursor's x,y position in console screen.

                copyright   All content ?2018 DigiPen (USA) Corporation, all rights reserved

*/


#include "SetCursor_Move.h"
#include "MapStatus.h"
#include "Ship_Status.h"

void Move_Cursor_Left(int cursor_x, int cursor_y, Ship_Map ship_map)
{
    int temp;
    int check_air = 0;

    if (ship_map[cursor_y][cursor_x - 1] == Body || ship_map[cursor_y][cursor_x - 1] == Head ||
        ship_map[cursor_y][cursor_x - 1] == Weapon)
    {
        while (ship_map[cursor_y][cursor_x - check_air] != AIR)
        {
            check_air++;

            if (ship_map[cursor_y][cursor_x - check_air] == AIR)
            {
                break;

            }
            else if (ship_map[cursor_y][cursor_x - check_air] == WALL)
            {
                break;

            }

        }
        if (ship_map[cursor_y][cursor_x - check_air] == AIR)
        {
            temp = ship_map[cursor_y][cursor_x];
            ship_map[cursor_y][cursor_x] = AIR;
            ship_map[cursor_y][cursor_x - check_air] = temp;
        }

    }
    if (ship_map[cursor_y][cursor_x - 1] == AIR)
    {
        temp = ship_map[cursor_y][cursor_x];
        ship_map[cursor_y][cursor_x] = AIR;
        ship_map[cursor_y][cursor_x - 1] = temp;
    }

}
void Move_Cursor_Right(int cursor_x, int cursor_y, Ship_Map ship_map)
{
    int temp;
    int check_air = 0;


    if (ship_map[cursor_y][cursor_x + 1] == Body || ship_map[cursor_y][cursor_x + 1] == Head ||
        ship_map[cursor_y][cursor_x + 1] == Weapon)
    {
        while (ship_map[cursor_y][cursor_x + check_air] != AIR)
        {
            check_air++;

            if (ship_map[cursor_y][cursor_x + check_air] == AIR)
            {
                break;

            }
            else if (ship_map[cursor_y][cursor_x + check_air] == WALL)
            {
                break;
            }

        }
        if (ship_map[cursor_y][cursor_x + check_air] == AIR)
        {
            temp = ship_map[cursor_y][cursor_x];
            ship_map[cursor_y][cursor_x] = AIR;
            ship_map[cursor_y][cursor_x + check_air] = temp;
        }

    }
    if (ship_map[cursor_y][cursor_x + 1] == AIR)
    {
        temp = ship_map[cursor_y][cursor_x];
        ship_map[cursor_y][cursor_x] = AIR;
        ship_map[cursor_y][cursor_x + 1] = temp;
    }


}
void Move_Cursor_Up(int cursor_x, int cursor_y, Ship_Map ship_map)
{
    int temp;
    int check_air = 0;

    if (ship_map[cursor_y - 1][cursor_x] == Body || ship_map[cursor_y - 1][cursor_x] == Head ||
        ship_map[cursor_y - 1][cursor_x] == Weapon)
    {
        while (ship_map[cursor_y - check_air][cursor_x] != AIR)
        {
            check_air++;

            if (ship_map[cursor_y - check_air][cursor_x] == AIR)
            {
                break;

            }
            else if (ship_map[cursor_y - check_air][cursor_x] == WALL)
            {
                break;

            }

        }
        if (ship_map[cursor_y - check_air][cursor_x] != WALL)
        {
            temp = ship_map[cursor_y][cursor_x];
            ship_map[cursor_y][cursor_x] = AIR;
            ship_map[cursor_y - check_air][cursor_x] = temp;
        }

    }
    if (ship_map[cursor_y - 1][cursor_x] == AIR)
    {
        temp = ship_map[cursor_y][cursor_x];
        ship_map[cursor_y][cursor_x] = AIR;
        ship_map[cursor_y - 1][cursor_x] = temp;
    }

}
void Move_Cursor_Down(int cursor_x, int cursor_y, Ship_Map ship_map)
{
    int temp;
    int check_air = 0;


    if (ship_map[cursor_y + 1][cursor_x] == Body || ship_map[cursor_y + 1][cursor_x] == Head ||
        ship_map[cursor_y + 1][cursor_x] == Weapon)
    {
        while (ship_map[cursor_y + check_air][cursor_x] != AIR)
        {
            check_air++;

            if (ship_map[cursor_y + check_air][cursor_x] == AIR)
            {
                break;

            }
            else if (ship_map[cursor_y + check_air][cursor_x] == WALL)
            {

                break;
            }
        }
        if (ship_map[cursor_y + check_air][cursor_x] == AIR)
        {
            temp = ship_map[cursor_y][cursor_x];
            ship_map[cursor_y][cursor_x] = AIR;
            ship_map[cursor_y + check_air][cursor_x] = temp;
        }

    }
    if (ship_map[cursor_y + 1][cursor_x] == AIR)
    {
        temp = ship_map[cursor_y][cursor_x];
        ship_map[cursor_y][cursor_x] = AIR;
        ship_map[cursor_y + 1][cursor_x] = temp;
    }

}