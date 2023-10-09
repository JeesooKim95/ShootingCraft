/**
\file        Bef_Boss_Clean.cpp
\author      Chulseung Lee
\brief
This will clear the array when before boss init.

copyright   All content ?2018 DigiPen (USA) Corporation, all rights reserved

*/


#include "Bef_Boss_Clean.h"
#include "MapStatus.h"



void Bef_Boss_Clear_Screen(Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status)
{
    int x, y, end_x, end_y, temp;
    for (int i = 0, a = current_map_status.count_all_enemy - 1; i < current_map_status.count_all_enemy && a >= 0; i++, a--)
    {
        x = current_ship_xy.all_enemy_x[i];
        y = current_ship_xy.all_enemy_y[i];

        end_x = current_ship_xy.all_enemy_x[a];
        end_y = current_ship_xy.all_enemy_y[a];


        if (end_x > (COL / 2))
        {
            temp = game_map[end_y][end_x];
            game_map[end_y][end_x] = AIR;
            game_map[end_y][end_x + 1] = temp;
        }

        if (x <= (COL / 2))
        {
            temp = game_map[y][x];
            game_map[y][x] = AIR;
            game_map[y][x - 1] = temp;
        }
    }

}

void Bef_Boss_Change_Player_Pos(Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status, bool *can_control)
{
    int player_x, player_y;
    int player_move = 0;
    player_x = current_ship_xy.head_ship_x[0];
    player_y = current_ship_xy.head_ship_y[0];
    int temp;

    if (player_y < MOVE_PLAYER_POS_BEF_BOS)
    {
        for (int i = current_map_status.count_whole_ship - 1; i >= 0; i--)
        {
            player_x = current_ship_xy.whole_ship_x[i];
            player_y = current_ship_xy.whole_ship_y[i];

            temp = game_map[player_y][player_x];
            game_map[player_y][player_x] = AIR;
            game_map[player_y + 1][player_x] = temp;
        }
    }
    else
    {
        *can_control = true;
    }
}