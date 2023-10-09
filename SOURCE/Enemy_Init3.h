/**
\file        Enemy_Init3.h
\author      Chulseung Lee
\brief
This is the header file of Enemy_Init3.cpp

copyright   All content © 2018 DigiPen (USA) Corporation, all rights reserved
*/
#pragma once
#include "MapStatus.h"
#include "Enemy_Part.h"

void Initialize_Enemy_Ship3(Game_Map game_map, int* control_enemy_num);
void Control_Enemy_Init3(int enemy_type);
void Make_Ship3();
