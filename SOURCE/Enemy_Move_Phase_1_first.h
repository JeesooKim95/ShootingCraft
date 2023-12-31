/**
\file        Enemy_Move_Phase_1_first.h
\author      Chulseung Lee
\brief
This is the header file of Enemy_Move_Phase_1_first.cpp

copyright   All content � 2018 DigiPen (USA) Corporation, all rights reserved
*/
#pragma once
#include "MapStatus.h"
#include "Ship_Status.h"
#include "Enemy_Part.h"

void Enemy_Move3(Game_Map game_map, XY_Position_Ship* current_ship_xy, Map_Status_Count current_map_status, bool enemy_arr_2);
