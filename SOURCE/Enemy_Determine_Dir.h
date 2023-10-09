/**
\file        Enemy_Determine_Dir.h
\author      jeesoo.kim
\brief
This is the header file of Enemy_Determine_Dir.cpp

copyright   All content © 2018 DigiPen (USA) Corporation, all rights reserved
*/
#pragma once
#include "MapStatus.h"
#include "Game_State.h"
#include "Ship_Status.h"


typedef enum Enemy_Bullet_Dir {


    Bullet_Move_Left = 600,
    Bullet_Move_Right = 601,
    Bullet_Move_Down = 602,
    Bullet_Move_Down_Left = 603,
    Bullet_Move_Down_Right = 604



}Enemy_Bullet_Dir2;

void Determine_Enemy_Bullet_Dir(Game_Map game_map, Map_Status_Count current_map_status, XY_Position_Ship* current_ship_xy);