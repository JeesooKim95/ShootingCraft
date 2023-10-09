/**
\file        Boss_Shoot.h
\author      jeesoo.kim
\brief
This is the header file of Boss_Shoot.cpp

copyright   All content © 2018 DigiPen (USA) Corporation, all rights reserved
*/
#pragma once
#include "MapStatus.h"
#include "Enemy_Part.h"
#include "Game_Control.h"

void Boss_Shoot(Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status);
void Boss_Shoot_Unbreakable_weapon(Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status, bool *boss_phase_2, bool *boss_phase_1);
void Boss_Shoot_Weapon_2(Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status);
void Boss_Shoot_Phase_Weapon2(Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status, Game_Control* game_control);
void Boss_Shoot_Phase3_Weapon2(Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status, Game_Control* game_control);