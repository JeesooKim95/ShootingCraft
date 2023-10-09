/**
\file        Boss_Move.h
\author      jeesoo.kim
\brief
This is the header file of Boss_Move.cpp

copyright   All content ?2018 DigiPen (USA) Corporation, all rights reserved
*/
#pragma once
#include "MapStatus.h"

#define BOSS_MOVE_UP 50
#define BOSS_MOVE_DOWN 51
#define BOSS_MOVE_RIGHT 52
#define BOSS_MOVE_LEFT 53

#define BOSS_Y_DOWN 4
#define BOSS_Y_UP 3
#define BOSS_Y_LEFT 2
#define BOSS_Y_RIGHT 1



void Move_Boss(Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status);
void Move_Boss_Left(Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status);
void Move_Boss_Right(Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status);
void Move_Boss_Up(Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status);
void Move_Boss_Down(Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status);
bool Check_Boss_Move_Is_Good(Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status, int dir);
void Move_Boss_Phase_3_Fast(Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status);