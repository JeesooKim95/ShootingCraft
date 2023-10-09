/**
\file        Tutorial.h
\author      Chulseung Lee
\brief
This is the header file of Tutorial.cpp

copyright   All content ?2018 DigiPen (USA) Corporation, all rights reserved
*/
#pragma once
#include "MapStatus.h"

#define TUTORIAL_ITEM_POS 6
#define TUTORIAL_INTRO_POS 2
#define TUTORIAL_INTRO_MOVE_POS 4
#define TUTORIAL_INTRO_SHOOT_POS 6
#define TUTORIAL_INTRO_POWER_POS 8
#define TUTORIAL_INTRO_END_POS 10

void Init_Tutorial_Enemy(Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status);
void Introduction(Game_Map game_map);