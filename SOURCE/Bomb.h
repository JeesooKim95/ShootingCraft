/**
\file        Bomb.h
\author      sangmin.kim
\par         email: ryan95kr@gmail.com
\brief
This is the header file of Bomb.cpp

copyright   All content © 2018 DigiPen (USA) Corporation, all rights reserved
*/


#pragma once
#include "MapStatus.h"

void Bomb_Move(Game_Map game_map,XY_Position_Ship current_ship_xy,Map_Status_Count current_map_status);
void Shoot_Bomb(Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status);
void User_Particle_Bomb(Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status);
void User_Bomb_Particle(Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status);
void Set_Bomb(Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status);