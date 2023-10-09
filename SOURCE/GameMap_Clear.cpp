/**
\file        GameMap_Clear.cpp
\author      Chulseung Lee
\brief
This file will clean if the trash value is in map array.

copyright   All content ?2018 DigiPen (USA) Corporation, all rights reserved

*/

#include "GameMap_Clear.h"
#include "MapStatus.h"
#include "Ship_Status.h"
#include "Enemy_Part.h"

void GameMap_Clear_Trash(Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status)
{
    int x = 0, y = 0;

    for (int i = 0; i < current_map_status.count_all_enemy; i++)
    {
        x = current_ship_xy.all_enemy_x[i];
        y = current_ship_xy.all_enemy_y[i];

        if (game_map[y][x] <= Enemy_Head && game_map[y][x] >= Enemy_Head - 2)
        {
            if (!(game_map[y + 1][x] <= Enemy_Weapon && game_map[y + 1][x] >= Enemy_Weapon - 2))
            {
                game_map[y][x] = AIR;

            }

        }
        else if ((game_map[y][x] <= Enemy_Head2 && game_map[y][x] >= Enemy_Head2 - 2))
        {
            if (!(game_map[y + 1][x] <= Enemy_Weapon2 && game_map[y + 1][x] >= Enemy_Weapon2 - 2))
            {
                game_map[y][x] = AIR;

            }

        }
        else if ((game_map[y][x] <= Enemy_Head3 && game_map[y][x] >= Enemy_Head3 - 2))
        {
            if (!(game_map[y + 1][x] <= Enemy_Weapon3 && game_map[y + 1][x] >= Enemy_Weapon3 - 2))
            {
                game_map[y][x] = AIR;

            }

        }
        else if ((game_map[y][x] <= Enemy_Head4 && game_map[y][x] >= Enemy_Head4 - 2))
        {
            if (!(game_map[y + 1][x] <= Enemy_Weapon4 && game_map[y + 1][x] >= Enemy_Weapon4 - 2))
            {
                game_map[y][x] = AIR;

            }

        }
        else if ((game_map[y][x] <= Enemy_Body_Left && game_map[y][x] >= Enemy_Body_Left - 2))
        {
            if (!(game_map[y][x + 1] <= Enemy_Head && game_map[y][x + 1] >= Enemy_Head - 2))
            {
                game_map[y][x] = AIR;

            }

        }
        else if ((game_map[y][x] <= Enemy_Body_Left2 && game_map[y][x] >= Enemy_Body_Left2 - 2))
        {
            if (!(game_map[y][x + 1] <= Enemy_Head2 && game_map[y][x + 1] >= Enemy_Head2 - 2))
            {
                game_map[y][x] = AIR;

            }

        }
        else if ((game_map[y][x] <= Enemy_Body_Left3 && game_map[y][x] >= Enemy_Body_Left3 - 2))
        {
            if (!(game_map[y][x + 1] <= Enemy_Head3 && game_map[y][x + 1] >= Enemy_Head3 - 2))
            {
                game_map[y][x] = AIR;

            }

        }
        else if ((game_map[y][x] <= Enemy_Body_Left4 && game_map[y][x] >= Enemy_Body_Left4 - 2))
        {
            if (!(game_map[y][x + 1] <= Enemy_Head4 && game_map[y][x + 1] >= Enemy_Head4 - 2))
            {
                game_map[y][x] = AIR;

            }

        }
        else if ((game_map[y][x] <= Enemy_Body_Right && game_map[y][x] >= Enemy_Body_Right - 2))
        {
            if (!(game_map[y][x - 1] <= Enemy_Head && game_map[y][x - 1] >= Enemy_Head - 2))
            {
                game_map[y][x] = AIR;

            }

        }
        else if ((game_map[y][x] <= Enemy_Body_Right2 && game_map[y][x] >= Enemy_Body_Right2 - 2))
        {
            if (!(game_map[y][x - 1] <= Enemy_Head2 && game_map[y][x - 1] >= Enemy_Head2 - 2))
            {
                game_map[y][x] = AIR;

            }

        }
        else if ((game_map[y][x] <= Enemy_Body_Right3 && game_map[y][x] >= Enemy_Body_Right3 - 2))
        {
            if (!(game_map[y][x - 1] <= Enemy_Head3 && game_map[y][x - 1] >= Enemy_Head3 - 2))
            {
                game_map[y][x] = AIR;

            }

        }
        else if ((game_map[y][x] <= Enemy_Body_Right4 && game_map[y][x] >= Enemy_Body_Right4 - 2))
        {
            if (!(game_map[y][x - 1] <= Enemy_Head4 && game_map[y][x - 1] >= Enemy_Head4 - 2))
            {
                game_map[y][x] = AIR;

            }

        }
        else if ((game_map[y][x] <= Enemy_Weapon && game_map[y][x] >= Enemy_Weapon - 2))
        {
            if (!(game_map[y - 1][x] <= Enemy_Head && game_map[y - 1][x] >= Enemy_Head - 2))
            {
                game_map[y][x] = AIR;

            }

        }
        else if ((game_map[y][x] <= Enemy_Weapon2 && game_map[y][x] >= Enemy_Weapon2 - 2))
        {
            if (!(game_map[y - 1][x] <= Enemy_Head2 && game_map[y - 1][x] >= Enemy_Head2 - 2))
            {
                game_map[y][x] = AIR;

            }

        }
        else if ((game_map[y][x] <= Enemy_Weapon3 && game_map[y][x] >= Enemy_Weapon3 - 2))
        {
            if (!(game_map[y - 1][x] <= Enemy_Head3 && game_map[y - 1][x] >= Enemy_Head3 - 2))
            {
                game_map[y][x] = AIR;

            }

        }
        else if ((game_map[y][x] <= Enemy_Weapon4 && game_map[y][x] >= Enemy_Weapon4 - 2))
        {
            if (!(game_map[y - 1][x] <= Enemy_Head4 && game_map[y - 1][x] >= Enemy_Head4 - 2))
            {
                game_map[y][x] = AIR;

            }

        }
        else if (game_map[y][x] == -1)
            game_map[y][x] = AIR;
    }


}