/**
\file        Phase3_Enemy_Init.h
\author      jeesoo.kim
\brief
This is the header file of Phase3_Enemy_Init.cpp

copyright   All content © 2018 DigiPen (USA) Corporation, all rights reserved
*/
#pragma once
#include "MapStatus.h"
#include "Enemy_Part.h"

void Phase3_Initialize_Enemy_Ship(Game_Map game_map, int* control_enemy_num);
void Phase3_Control_Enemy_Init(int enemy_type, int player_pos);
void Phase3_Make_Ship();
bool Phase3_Check_Enemy_Spawnposition(Game_Map game_map);