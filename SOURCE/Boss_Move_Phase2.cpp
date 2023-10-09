/**
\file        Boss_Move_Phase2.cpp
\author      jeesoo.kim
\brief
This file moves the boss when it is in the boss phase 2.

copyright   All content ?2018 DigiPen (USA) Corporation, all rights reserved
*/
#include "MapStatus.h"
#include "Enemy_Part.h"
#include "Boss_Move_Phase2.h"
#include "stdlib.h"
#include "Boss_Move.h"
#include "stdio.h"


void Move_Boss_Phase_2_Back(Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status, bool* boss_move_enough, bool* init_boss_phase_2)
{

    int boss_move = 0;
    int boss_x = 0, boss_y = 0;

    boss_x = current_ship_xy.boss_head_x[0];
    boss_y = current_ship_xy.boss_head_y[0];


    if (boss_x > COL / HALF)
    {
        boss_move = BOSS_MOVE_LEFT;

    }
    else if (boss_x < COL / HALF)
    {
        boss_move = BOSS_MOVE_RIGHT;

    }
    else if (boss_y < MOVE_UP_ENOUGH)
    {
        boss_move = BOSS_MOVE_DOWN;

    }
    else if (boss_y > MOVE_UP_ENOUGH)
    {
        boss_move = BOSS_MOVE_UP;

    }
    else if (boss_y == MOVE_UP_ENOUGH && boss_x == COL / HALF)
    {
        boss_move = BOSS_MOVE_ENOUGH;
    }

    switch (boss_move)
    {
    case BOSS_MOVE_LEFT:
        Move_Boss_Left_Phase2(game_map, current_ship_xy, current_map_status);
        break;
    case BOSS_MOVE_RIGHT:
        Move_Boss_Right_Phase2(game_map, current_ship_xy, current_map_status);
        break;
    case BOSS_MOVE_UP:
        Move_Boss_Up_Phase2(game_map, current_ship_xy, current_map_status);
        break;
    case BOSS_MOVE_DOWN:
        Move_Boss_Down_Phase2(game_map, current_ship_xy, current_map_status);
        break;
    case BOSS_MOVE_ENOUGH:
        *boss_move_enough = true;
        *init_boss_phase_2 = true;
        break;

    }

}

void Move_Boss_Left_Phase2(Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status)
{
    int x = 0, y = 0, temp = 0;

    for (int i = 0; i < current_map_status.count_boss_whole; i++)
    {
        x = current_ship_xy.boss_whole_x[i];
        y = current_ship_xy.boss_whole_y[i];

        temp = game_map[y][x];
        game_map[y][x] = AIR;
        game_map[y][x - 1] = temp;

    }

}
void Move_Boss_Right_Phase2(Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status)
{
    int x = 0, y = 0, temp = 0;

    for (int i = current_map_status.count_boss_whole - 1; i >= 0; i--)
    {
        x = current_ship_xy.boss_whole_x[i];
        y = current_ship_xy.boss_whole_y[i];

        temp = game_map[y][x];
        game_map[y][x] = AIR;
        game_map[y][x + 1] = temp;

    }

}
void Move_Boss_Up_Phase2(Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status)
{
    int x = 0, y = 0, temp = 0;

    for (int i = 0; i < current_map_status.count_boss_whole; i++)
    {
        x = current_ship_xy.boss_whole_x[i];
        y = current_ship_xy.boss_whole_y[i];

        temp = game_map[y][x];
        game_map[y][x] = AIR;
        game_map[y - 1][x] = temp;
    }

}
void Move_Boss_Down_Phase2(Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status)
{
    int x = 0, y = 0, temp = 0;

    for (int i = current_map_status.count_boss_whole - 1; i >= 0; i--)
    {
        x = current_ship_xy.boss_whole_x[i];
        y = current_ship_xy.boss_whole_y[i];

        temp = game_map[y][x];
        game_map[y][x] = AIR;
        game_map[y + 1][x] = temp;
    }

}
