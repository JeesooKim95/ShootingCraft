/**
\file        Apply_Two_Map.h
\author      sangmin.kim
\par         email: ryan95kr@gmail.com
\brief
This is the header file of Apply_Two_Map.c

copyright   All content ?2018 DigiPen (USA) Corporation, all rights reserved
*/

#pragma once
#include "MapStatus.h"

#define FIRST_SHIP_INIT_BODY_Y 4
#define FIRST_SHIP_INIT_WEAPON_Y 6
#define FIRST_SHIP_INIT_HEAD_Y 5

#define HACK_SHIP_BODY_INIT_1 5
#define HACK_SHIP_BODY_INIT_2 4 
#define HACK_SHIP_WEAPON_INIT_1 6
#define HACK_SHIP_WEAPON_INIT_2 7

void ShipMap_To_GameMap(Ship_Map ship_map, Game_Map game_map);
void ShipMap_To_GameMap2(Ship_Map ship_map, Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status);
void Save_GameMap(Game_Map game_map, Game_Map save_map);
void Save_Ship_To_Ship_Map(Game_Map game_map, Ship_Map ship_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status);
void Save_Ship_To_Game_Map(Game_Map game_map, Game_Map save_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status);
void Erase_Ship(Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status);
void Save_Position_Ship_in_Ship_Map(Ship_Map ship_map, Game_Map game_map, XY_Position_Ship *current_ship_xy, Map_Status_Count* current_map_status);
void Hack_ShipMap_To_GameMap(Ship_Map ship_map, Game_Map game_map);
