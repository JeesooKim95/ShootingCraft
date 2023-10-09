/**
\file        Enemy_Move.h
\author      jeesoo.kim
\brief
This is the header file of Enemy_Move.cpp

copyright   All content © 2018 DigiPen (USA) Corporation, all rights reserved
*/
#pragma once
#include "Enemy_Move.h"
#include "MapStatus.h"
#include "Ship_Status.h"
#include "Enemy_Part.h"

void Enemy_Move(Game_Map game_map, XY_Position_Ship* current_ship_xy, Map_Status_Count current_map_status);
void Enemy_Move2(Game_Map game_map, XY_Position_Ship* current_ship_xy, Map_Status_Count current_map_status);
void Phase3_Enemy_Move(Game_Map game_map, XY_Position_Ship* current_ship_xy, Map_Status_Count current_map_status, int player_pos);