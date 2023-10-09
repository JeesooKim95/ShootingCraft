/**
\file        ShipMap_InsertBody.h
\author     jeesoo.kim
\brief
This is the header file of ShipMap_InsertBody.cpp

copyright   All content © 2018 DigiPen (USA) Corporation, all rights reserved
*/

#pragma once
#include "MapStatus.h"

void ShipMap_InsertBody(Ship_Map ship_map, bool *insert_body, bool *insert_weapon, int body_power);
void Set_Body(Ship_Map ship_map, int dir, int cursor_x, int cursor_y, bool *only_one_cursor, int *body_power);
bool Check_Next(Ship_Map ship_map, int cursor_x, int cursor_y);
