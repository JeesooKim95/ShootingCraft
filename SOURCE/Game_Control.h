/**
\file        Game_Control.h
\author      Chulseung Lee
\brief
This is the header file of Game_Control.cpp

copyright   All content © 2018 DigiPen (USA) Corporation, all rights reserved
*/
#pragma once
#include "stdbool.h"
#include "MapStatus.h"
//#include "Timer.h"

typedef struct In_Game_Seconds2 In_Game_Seconds;

typedef struct Control_Game {

    bool init_enemy = true;
    bool init_enemy2 = true;
    bool init_enemy3 = true;
    bool init_boss = true;
    bool level_up_once = true;
    bool bef_phase_1 = false;
    bool phase_1 = false;
    bool phase_2 = false;
    bool phase_3 = false;
    bool phase_boss = false;
    bool boss_phase_1 = true;
    bool boss_phase_2 = false;
    bool boss_phase_3 = false;
    bool boss_move_fast = false;
    bool boss_move_enough = false;
    bool init_boss_phase_2 = false;
    bool enemy_arr_1 = true;
    bool enemy_arr_2 = false;
    bool enemy_arr_3 = false;
    bool first = true;
    bool second = true;
    bool third = false;
    bool change_phase_1_to_2 = false;
    bool once = false;
    bool is_boss_exist = false;
    bool is_combined = false;
    bool tutorial_enemy_is_exist = false;
    bool bef_boss_init = false;
    bool let_boss_init = false;


}Game_Control;

typedef struct Control_Level {

    int body_power = 1;
    int weapon_power = 1;
    int enemy_type;
    int enemy_type2;
    int player_bullet_move_limitation = 30;
    int PHASE3_ENEMY1_MOVE_UPGRADE = 0;
    int PHASE3_ENEMY2_MOVE_UPGRADE = 0;
    int PHASE3_ENEMY1_INIT_UPGRADE = 0;
    int PHASE3_ENEMY2_INIT_UPGRADE = 0;
    int PHASE3_ENEMY1_SHOOT_UPGRADE = 0;
    int PHASE3_ENEMY2_SHOOT_UPGRADE = 0;
    int PHASE3_ENEMY1_BULLET_MOVE_UPGRADE = 0;
    int PHASE3_ENEMY2_BULLET_MOVE_UPGRADE = 0;

    int control_enemy_num = 0;
    int control_enemy_num2 = 0;
    int score = 0;
    int temp_score;
    int power_up = 5;
    int power_up_tutorial = 10;

    int enemy_arr1_control_x_down = (COL / 2) - 1;
    int enemy_arr1_control_x_up = (COL / 2) - 1;
}Level_Control;

void Init_Control(XY_Position_Ship* current_ship_xy, Map_Status_Count* current_map_status, In_Game_Seconds* in_game_seconds, Game_Control* game_control, Level_Control* level_control);
void Init_Hard_Control(XY_Position_Ship* current_ship_xy, Map_Status_Count* current_map_status, In_Game_Seconds* in_game_seconds, Game_Control* game_control, Level_Control* level_control);


//void Init_Control(XY_Position_Ship* current_ship_xy, Map_Status_Count* current_map_status, In_Game_Seconds* in_game_seconds, Game_Control* game_control, Level_Control* level_control);

