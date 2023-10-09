/**
\file        GameMap_Control.h
\author      Chulseung Lee
\brief
This is the header file of GameMap_Control.cpp

copyright   All content ?2018 DigiPen (USA) Corporation, all rights reserved
*/

#pragma once
#include "Game_State.h"
#include "Timer.h"

#define BULLET_LEVEL_UP 4
#define SHOOT_SPEED_UP 10

void GameMap_ControlShip(Game_Map game_map, XY_Position_Ship* current_ship_xy, Map_Status_Count* current_map_status, Ship_Map ship_map, GameState* gameState , int *power_up , int *player_bullet_speed_limitation);
void GameMap_ControlShip_Tutorial(Game_Map game_map, XY_Position_Ship* current_ship_xy, Map_Status_Count* current_map_status, Ship_Map ship_map, GameState* gameState, int *power_up, int *player_bullet_speed_limitation, GameState* game_State);
