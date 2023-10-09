/**
\file        Item_Move.h
\author      hyun.gang
\par         email: ryan95kr@gmail.com
\brief
This is the header file of Item_Move.cpp

copyright   All content ?2018 DigiPen (USA) Corporation, all rights reserved
*/
#pragma once
#include "MapStatus.h"


void Item_Move(Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status);
void Item_Twinkle(Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status);