/**
\file        Item_Move.cpp
\author      hyun.gang
\par         email: ryan95kr@gmail.com
\brief
This file will move the Item each array by 1.

copyright   All content ?2018 DigiPen (USA) Corporation, all rights reserved
*/

#include "Item_Move.h"
#include "Item.h"

void Item_Move(Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status)
{
    int x = 0, y = 0;
    int temp = 0;

    for (int i = 0; i < current_map_status.count_item; i++)
    {
        x = current_ship_xy.power_up_x[i];
        y = current_ship_xy.power_up_y[i];


        if (game_map[y][x] == Item_Red)
        {
            temp = game_map[y][x];
            game_map[y][x] = AIR;
            game_map[y + 1][x] = Item_Yellow;

        }
        else if (game_map[y][x] == Item_Yellow)
        {
            temp = game_map[y][x];
            game_map[y][x] = AIR;
            game_map[y + 1][x] = Item_Blue;

        }
        else if (game_map[y][x] == Item_Blue)
        {
            temp = game_map[y][x];
            game_map[y][x] = AIR;
            game_map[y + 1][x] = Item_Green;

        }
        else if (game_map[y][x] == Item_Green)
        {
            temp = game_map[y][x];
            game_map[y][x] = AIR;
            game_map[y + 1][x] = Item_Puple;

        }
        else if (game_map[y][x] == Item_Puple)
        {
            temp = game_map[y][x];
            game_map[y][x] = AIR;
            game_map[y + 1][x] = Item_White;

        }
        else if (game_map[y][x] == Item_White)
        {
            temp = game_map[y][x];
            game_map[y][x] = AIR;
            game_map[y + 1][x] = Item_Red;

        }
    }
}

void Item_Twinkle(Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status)
{
    int x = 0, y = 0;

    for (int i = 0; i < current_map_status.count_item; i++)
    {
        x = current_ship_xy.power_up_x[i];
        y = current_ship_xy.power_up_y[i];

        if (game_map[y][x] == Item_Red)
        {
            game_map[y][x] = Item_Yellow;
        }
        else if (game_map[y][x] == Item_Yellow)
        {
            game_map[y][x] = Item_Blue;
        }
        else if (game_map[y][x] == Item_Blue)
        {
            game_map[y][x] = Item_Green;
        }
        else if (game_map[y][x] == Item_Green)
        {
            game_map[y][x] = Item_Puple;
        }
        else if (game_map[y][x] == Item_Puple)
        {
            game_map[y][x] = Item_White;
        }
        else if (game_map[y][x] == Item_White)
        {
            game_map[y][x] = Item_Red;
        }
    }
}