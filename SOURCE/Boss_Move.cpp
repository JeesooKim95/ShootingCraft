/**
\file        Boss_Move.cpp
\author      jeesoo.kim
\brief
This file moves the boss by the given value.

copyright   All content ?2018 DigiPen (USA) Corporation, all rights reserved
*/
#include "Boss_Move.h"
#include "MapStatus.h"
#include "stdlib.h"

bool is_right_enough = false;
bool is_left_enough = true;

void Move_Boss(Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status)
{
    int rand_move = 0;

    rand_move = rand() % BOSS_Y_DOWN;

    switch (rand_move)
    {
    case 0:
        if (Check_Boss_Move_Is_Good(game_map, current_ship_xy, current_map_status, rand_move))
            Move_Boss_Left(game_map, current_ship_xy, current_map_status);
        break;
    case 1:
        if (Check_Boss_Move_Is_Good(game_map, current_ship_xy, current_map_status, rand_move))
            Move_Boss_Right(game_map, current_ship_xy, current_map_status);
        break;
    case 2:
        if (Check_Boss_Move_Is_Good(game_map, current_ship_xy, current_map_status, rand_move))
            Move_Boss_Up(game_map, current_ship_xy, current_map_status);
        break;
    case 3:
        if (Check_Boss_Move_Is_Good(game_map, current_ship_xy, current_map_status, rand_move))
            Move_Boss_Down(game_map, current_ship_xy, current_map_status);
        break;
    }
}

void Move_Boss_Phase_3_Fast(Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status)
{
    int boss_x = 0, boss_y = 0;
    int boss_move = 0;
    int rand_move = 0;


    boss_x = current_ship_xy.boss_head_x[0];
    boss_y = current_ship_xy.boss_head_y[0];

    if (boss_y > BOSS_Y_DOWN)
    {
        boss_move = BOSS_MOVE_UP;
    }
    else
    {
        if (is_left_enough)
        {
            boss_move = BOSS_MOVE_RIGHT;
        }
        else if (is_right_enough)
        {
            boss_move = BOSS_MOVE_LEFT;
        }


    }

    if (game_map[boss_y][boss_x + BOSS_Y_UP] == WALL)
    {
        is_right_enough = true;
        is_left_enough = false;

    }
    else if (game_map[boss_y][boss_x - BOSS_Y_UP] == WALL)
    {
        is_left_enough = true;
        is_right_enough = false;

    }

    switch (boss_move)
    {
    case BOSS_MOVE_LEFT:
        if (Check_Boss_Move_Is_Good(game_map, current_ship_xy, current_map_status, boss_move))
            Move_Boss_Left(game_map, current_ship_xy, current_map_status);
        break;
    case BOSS_MOVE_RIGHT:
        if (Check_Boss_Move_Is_Good(game_map, current_ship_xy, current_map_status, boss_move))
            Move_Boss_Right(game_map, current_ship_xy, current_map_status);
        break;
    case BOSS_MOVE_UP:
        if (Check_Boss_Move_Is_Good(game_map, current_ship_xy, current_map_status, boss_move))
            Move_Boss_Up(game_map, current_ship_xy, current_map_status);
        break;
    }
}


bool Check_Boss_Move_Is_Good(Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status, int dir)
{
    int leftest_x = current_ship_xy.boss_whole_x[0];
    int rightest_x = current_ship_xy.boss_whole_x[0];
    int upest_y = current_ship_xy.boss_whole_y[0];
    int downest_y = current_ship_xy.boss_whole_y[0];

    int leftest_y = current_ship_xy.boss_whole_y[0];
    int rightest_y = current_ship_xy.boss_whole_y[0];
    int upest_x = current_ship_xy.boss_whole_x[0];
    int downest_x = current_ship_xy.boss_whole_x[0];

    for (int i = 0; i < current_map_status.count_boss_whole; i++)
    {
        if (leftest_x > current_ship_xy.boss_whole_x[i])
        {
            leftest_x = current_ship_xy.boss_whole_x[i];
            leftest_y = current_ship_xy.boss_whole_y[i];
        }
        if (rightest_x < current_ship_xy.boss_whole_x[i])
        {
            rightest_x = current_ship_xy.boss_whole_x[i];
            rightest_y = current_ship_xy.boss_whole_y[i];
        }
        if (downest_y < current_ship_xy.boss_whole_y[i])
        {
            downest_y = current_ship_xy.boss_whole_y[i];
            downest_x = current_ship_xy.boss_whole_x[i];
        }
        if (upest_y > current_ship_xy.boss_whole_y[i])
        {
            upest_y = current_ship_xy.boss_whole_y[i];
            upest_x = current_ship_xy.boss_whole_x[i];
        }
    }
    if (game_map[leftest_y][leftest_x - 1] != AIR && dir == 0)
    {
        return false;
    }
    if (game_map[rightest_y][rightest_x + 1] != AIR && dir == 1)
    {
        return false;
    }
    if (upest_y - 1 == 2 && dir == BOSS_Y_LEFT)
    {
        return false;
    }
    if (game_map[downest_y + 1][downest_x] != AIR && dir == BOSS_Y_UP)
    {
        return false;
    }

    return true;

}

void Move_Boss_Left(Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status)
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
void Move_Boss_Right(Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status)
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
void Move_Boss_Down(Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status)
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
void Move_Boss_Up(Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status)
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
