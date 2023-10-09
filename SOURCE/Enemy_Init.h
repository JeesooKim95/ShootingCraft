/**
\file        Enemy_Init.h
\author      jeesoo.kim
\brief
This is the header file of Enemy_Init.cpp

copyright   All content © 2018 DigiPen (USA) Corporation, all rights reserved
*/
#pragma once
#include "MapStatus.h"
#include "Enemy_Part.h"

void Initialize_Enemy_Ship(Game_Map game_map, int* control_enemy_num);
void Control_Enemy_Init(int enemy_type);
void Make_Ship();
bool Check_Enemy_Spawnposition(Game_Map game_map);