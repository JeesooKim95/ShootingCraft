/**
\file        Bef_Boss_Clean.h
\author      Chulseung Lee
\brief
	This is the header file of Bef_Boss_Clean.cpp

	copyright   All content © 2018 DigiPen (USA) Corporation, all rights reserved
*/

#pragma once

#define PLAYER_MOVE_DOWN 50000
#define PLAYER_MOVE_UP 50001
#define PLAYER_MOVE_LEFT 50002
#define PLAYER_MOVE_RIGHT 50003

#include "MapStatus.h"
void Bef_Boss_Clear_Screen(Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status);
void Bef_Boss_Change_Player_Pos(Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status, bool *can_control);