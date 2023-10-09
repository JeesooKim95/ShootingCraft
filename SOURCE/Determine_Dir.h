/**
\file        Determine_Dir.h
\author      jeesoo.kim
\brief
This is the header file of Determine_Dir.cpp

copyright   All content © 2018 DigiPen (USA) Corporation, all rights reserved
*/

#pragma once
#include "MapStatus.h"
#include "Ship_Status.h"

int Determine_Enemy_Bullet_Dir(Game_Map game_map, XY_Position_Ship current_ship_xy,Map_Status_Count current_map_status,int x,int y, int i);