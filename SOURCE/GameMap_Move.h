/**
\file        GameMap_Move.h
\author     jeesoo.kim
\brief
This is the header file of GameMap_Move.cpp

copyright   All content © 2018 DigiPen (USA) Corporation, all rights reserved
*/
#pragma once
#include "Game_State.h"

void Move_Ship_Left(Game_Map game_map,XY_Position_Ship current_ship_xy,Map_Status_Count current_map_status, int *power_up);
void Move_Ship_Right(Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status, int *power_up);
void Move_Ship_Up(Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status, int *power_up);
void Move_Game_Map_Ship(Game_Map game_map, int dir, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status, int *power_up);
void GameMap_ControlShip(Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status);
bool Check_Ship_Position_Is_Good(XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status, int dir, Game_Map game_map);
void Move_Ship_Down(Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status, int *power_up);