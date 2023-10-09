/**
\file        Overlapped_Control.cpp
\author      hyun.gang
\par         email: hangam131313@gmail.com
\brief
This will manage overlapped element's in array.

copyright   All content ?2018 DigiPen (USA) Corporation, all rights reserved
*/
#define MAX_ARRAY_LENGTH 50
#include "Overlapped_Control.h"
#include "MapStatus.h"

void Check_Overlapped(Game_Map game_map, XY_Position_Ship* current_ship_xy, Map_Status_Count current_map_status)
{
    int x, y;
    int temp;

    for (int i = 0; i < MAX_ARRAY_LENGTH; i++)
    {
        if (current_ship_xy->overlap_x[i] == 0 && current_ship_xy->overlap_y[i] == 0 && current_ship_xy->overlap[i] == AIR)
        {
            continue;
        }
        if (current_ship_xy->overlap_x[i] != 0 && current_ship_xy->overlap_y[i] != 0 && current_ship_xy->overlap[i] != AIR)
        {
            x = current_ship_xy->overlap_x[i];
            y = current_ship_xy->overlap_y[i];
            temp = current_ship_xy->overlap[i];

            if (game_map[y][x] == AIR)
            {
                game_map[y][x] = temp;
                current_ship_xy->overlap_x[i] = 0;
                current_ship_xy->overlap_y[i] = 0;
                current_ship_xy->overlap[i] = AIR;
            }
        }
    }
}