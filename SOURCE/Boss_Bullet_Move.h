/**
\file        Boss_Bullet_Move.h
\author      jeesoo.kim
\brief
This is the header file of Boss_Bullet_Move.cpp

copyright   All content ?2018 DigiPen (USA) Corporation, all rights reserved
*/
#pragma once
#include "MapStatus.h"

#define BOSS_PHASE_2_BULLET_MOVE_ENOUGH 30
#define BOSS_BULLET_SECOND_MOVE_ENOUGH 31


void Boss_Bullet_2_Move(Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status);
void Boss_phase_2_bullet_move(Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status);