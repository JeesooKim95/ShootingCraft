
/**
\file        ShipMap_InsertWeapon.h
\author      jeesoo.kim
\brief
This is the header file of ShipMap_InsertWeapon.cpp

copyright   All content © 2018 DigiPen (USA) Corporation, all rights reserved
*/

#pragma once
#include "MapStatus.h"

void ShipMap_InsertWeapon(Ship_Map ship_map, bool *insert_weapon, bool *insert_ship, int weapon_power);
void Set_Weapon(Ship_Map ship_map, int dir, int cursor_x, int cursor_y, bool *only_one_cursor, int *weapon_power);
