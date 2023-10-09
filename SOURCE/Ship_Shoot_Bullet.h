/**
\file        Ship_Shoot_Bullet.h
\author      hyun.gang
\par         email: hangam131313@gmail.com
\brief
This is the header file of Ship_Shoot_Bullet.cpp

copyright   All content ?2018 DigiPen (USA) Corporation, all rights reserved
*/
#pragma once

#include "MapStatus.h"
#include "Ship_Status.h"
void Shoot_Bullet(Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status);
void Enemy_Shoot_Bullet(Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_statue);
void Enemy_Shoot_Bullet2(Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_statue);
void Enemy_Shoot_Bullet3(Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_statue);
void Enemy_Shoot_Bullet4(Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_statue);