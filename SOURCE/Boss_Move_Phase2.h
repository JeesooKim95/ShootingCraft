/**
\file        Boss_Move_Phase2.h
\author      jeesoo.kim
\brief
This is the header file of Boss_Move_Phase2.cpp

copyright   All content ?2018 DigiPen (USA) Corporation, all rights reserved
*/
#pragma once
#include "MapStatus.h"

#define HALF 2
#define MOVE_UP_ENOUGH 9 
#define BOSS_MOVE_ENOUGH 7 


void Move_Boss_Phase_2_Back(Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status, bool *boss_move_enough, bool *init_boss_phase_2);
void Move_Boss_Left_Phase2(Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status);
void Move_Boss_Right_Phase2(Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status);
void Move_Boss_Up_Phase2(Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status);
void Move_Boss_Down_Phase2(Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status);
