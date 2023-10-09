/**
\file        Determine_Dir.cpp
\author      jeesoo.kim
\brief
This file determines the enemies' bullet direction.

copyright   All content ?2018 DigiPen (USA) Corporation, all rights reserved
*/


#include "MapStatus.h"
#include "Determine_Dir.h"
#include "Enemy_Determine_Dir.h"
#include "stdlib.h"
#include "time.h"

int Determine_Enemy_Bullet_Dir(Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status, int x, int y, int i)
{
    int rand_move;
    rand_move = rand() % 2;

    if (x < current_ship_xy.head_ship_x[i] && rand_move == 0)
    {
        return Bullet_Move_Right;
    }
    else if (x < current_ship_xy.head_ship_x[i] && rand_move == 1)
    {
        return Bullet_Move_Down_Right;
    }
    else if (x > current_ship_xy.head_ship_x[i] && rand_move == 0)
    {
        return Bullet_Move_Left;
    }
    else if (x > current_ship_xy.head_ship_x[i] && rand_move == 1)
    {
        return Bullet_Move_Down_Left;
    }
    else
    {
        return Bullet_Move_Down;
    }
    return 0;

}