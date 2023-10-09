/**
\file        GameMap_Clear.h
\author      Chulseung Lee
\brief
This is the header file of GameMap_Clear.cpp

copyright   All content © 2018 DigiPen (USA) Corporation, all rights reserved
*/
#pragma once
#include "MapStatus.h"
#include "Ship_Status.h"

void GameMap_Clear_Trash(Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status);
bool Check_Proper_Ship(Game_Map game_map, int y, int x);