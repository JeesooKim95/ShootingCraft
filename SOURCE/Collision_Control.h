/**
\file        Collision_Control.h
\author      sangmin.kim
\par         email: ryan95kr@gmail.com
\brief
This is the header file of Bomb.cpp

copyright   All content © 2018 DigiPen (USA) Corporation, all rights reserved
*/

#pragma once
#include "MapStatus.h"
#include "Ship_Status.h"
#include "Game_State.h"


void Check_Collision(Game_Map game_map,XY_Position_Ship* current_ship_xy,Map_Status_Count current_map_status, int *score, int *power_up, GameState* gameState, bool* should_run, bool is_hack);