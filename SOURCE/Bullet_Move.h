/**
\file        Bullet_Move.h
\author      hyun.gang
\par         email: hangam131313@gmail.com
\brief
This is the header file of Bullet_Move.cpp

copyright   All content ?2018 DigiPen (USA) Corporation, all rights reserved
*/
#pragma once
#include "MapStatus.h"
#include "Game_State.h"

void Move_Bullet(Game_Map game_map, Map_Status_Count current_map_status, XY_Position_Ship current_ship_xy);
void Move_Enemy_Bullet(Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status);
void Move_Enemy_Bullet2(Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status);