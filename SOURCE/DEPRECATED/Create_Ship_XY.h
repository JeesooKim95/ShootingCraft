/**
\file        Create_Ship_XY.h
\author      sangmin.kim
\par         email: ryan95kr@gmail.com
\brief
This is the header file of Create_Ship_XY.cpp

copyright   All content © 2018 DigiPen (USA) Corporation, all rights reserved
*/

#pragma once

#include "Game_State.h"

void Create_Ship_XY(XY_Position_Ship *current_ship_xy, Map_Status_Count current_map_status);
void Alloc_xy_array(XY_Position_Ship* current_ship_xy);