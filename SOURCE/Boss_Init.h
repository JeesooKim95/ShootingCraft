/**
\file        Boss_Init.h
\author      hyun.gang
\par         email: hangam131313@gmail.com
\brief
This is the header file of Boss_Init.cpp

copyright   All content ?2018 DigiPen (USA) Corporation, all rights reserved
*/
#pragma once
#include "MapStatus.h"

void Boss_Init(Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status, bool *is_boss_exist);
void Boss_Init2(Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status);
void Make_Boss();
void Boss_Combine(Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status, bool *is_combined);