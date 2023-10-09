/**
\file        Enemy_Init2.h
\author      jeesoo.kim
\brief
This is the header file of Enemy_Init2.cpp

copyright   All content © 2018 DigiPen (USA) Corporation, all rights reserved
*/
#pragma once
#include "MapStatus.h"
#include "Enemy_Part.h"

void Initialize_Enemy_Ship2(Game_Map game_map, int* control_enemy_num);
void Control_Enemy_Init2(int enemy_type);
void Make_Ship2();
bool Check_Enemy_Spawnposition2(Game_Map game_map);