/**
\file        Game_Control.cpp
\author      Chulseung Lee
\brief
This file will initialize the value to allocated memory.

copyright   All content ?2018 DigiPen (USA) Corporation, all rights reserved
*/
#include "Timer.h"
#include "Game_Control.h"
#include "MapStatus.h"

void Init_Control(XY_Position_Ship* current_ship_xy, Map_Status_Count* current_map_status, In_Game_Seconds* in_game_seconds, Game_Control* game_control, Level_Control* level_control)
{
    game_control->init_enemy = true;
    game_control->init_enemy2 = true;
    game_control->init_enemy3 = true;
    game_control->init_boss = true;
    game_control->level_up_once = true;
    game_control->bef_phase_1 = false;
    game_control->phase_1 = false;
    game_control->phase_2 = false;
    game_control->phase_3 = false;
    game_control->phase_boss = false;
    game_control->boss_phase_1 = true;
    game_control->boss_phase_2 = false;
    game_control->boss_move_enough = false;
    game_control->init_boss_phase_2 = false;
    game_control->enemy_arr_1 = true;
    game_control->enemy_arr_2 = false;
    game_control->enemy_arr_3 = false;
    game_control->first = true;
    game_control->second = true;
    game_control->third = false;
    game_control->change_phase_1_to_2 = false;
    game_control->once = false;
    game_control->is_boss_exist = false;
    game_control->is_combined = false;
    game_control->tutorial_enemy_is_exist = false;
    game_control->bef_boss_init = false;
    game_control->let_boss_init = false;
    game_control->boss_move_fast = false;

    level_control->body_power = 1;
    level_control->weapon_power = 1;
    level_control->player_bullet_move_limitation = 30;
    level_control->enemy_arr1_control_x_down = (COL / 2) - 1;
    level_control->enemy_arr1_control_x_up = (COL / 2) - 1;

    in_game_seconds->bullet_move = PLAYER_BULLET_MOVE;

    in_game_seconds->enemy_1_move = ENEMY_1_MOVE;
    in_game_seconds->enemy_2_move = ENEMY_2_MOVE;
    in_game_seconds->enemy_1_shoot = ENEMY_1_SHOOT;
    in_game_seconds->enemy_2_shoot = ENEMY_2_SHOOT;
    in_game_seconds->enemy_1_init = ENEMY_1_INIT;
    in_game_seconds->enemy_2_init = ENEMY_2_INIT;
    in_game_seconds->phase_1_enemy_bullet_move = PHASE_1_ENEMY_BULLET_MOVE;
    in_game_seconds->phase_1_change_arr = PHASE_1_CHANGE_ARR;
    in_game_seconds->phase_2_enemy_1_move = PHASE_2_ENEMY_1_MOVE;
    in_game_seconds->phase_2_enemy_2_move = PHASE_2_ENEMY_2_MOVE;
    in_game_seconds->phase_2_enemy_1_init = PHASE_2_ENEMY_1_INIT;
    in_game_seconds->phase_2_enemy_2_init = PHASE_2_ENEMY_2_INIT;
    in_game_seconds->phase_2_enemy_1_shoot = PHASE_2_ENEMY_1_SHOOT;
    in_game_seconds->phase_2_enemy_2_shoot = PHASE_2_ENEMY_2_SHOOT;
    in_game_seconds->phase_2_enemy_1_bullet_move = PHASE_2_ENEMY_1_BULLET_MOVE;
    in_game_seconds->phase_2_enemy_2_bullet_move = PHASE_2_ENEMY_2_BULLET_MOVE;
    in_game_seconds->phase_3_enemy_1_move = PHASE_3_ENEMY_1_MOVE;
    in_game_seconds->phase_3_enemy_2_move = PHASE_3_ENEMY_2_MOVE;
    in_game_seconds->phase_3_enemy_1_init = PHASE_3_ENEMY_1_INIT;
    in_game_seconds->phase_3_enemy_2_init = PHASE_3_ENEMY_2_INIT;
    in_game_seconds->phase_3_enemy_1_shoot = PHASE_3_ENEMY_1_SHOOT;
    in_game_seconds->phase_3_enemy_2_shoot = PHASE_3_ENEMY_2_SHOOT;
    in_game_seconds->phase_3_enemy_1_bullet_move = PHASE_3_ENEMY_1_BULLET_MOVE;
    in_game_seconds->phase_3_enemy_2_bullet_move = PHASE_3_ENEMY_2_BULLET_MOVE;
    in_game_seconds->boss_move_fast_enouth = BOSS_MOVE_FAST_CLOCK;
    in_game_seconds->boss_move = BOSS_MOVE;
    in_game_seconds->boss_shoot = BOSS_SHOOT;
    in_game_seconds->boss_bullet_move_2 = BOSS_BULLET_MOVE_2;
    in_game_seconds->boss_bullet_move_1 = BOSS_BULLET_MOVE_1;
    in_game_seconds->boss_shoot_unbreakable_weapon = BOSS_SHOOT_UNBREAKABLE_WEAPON;
    in_game_seconds->boss_phase_2_bullet_move = BOSS_BULLET_PHASE_2_MOVE;
    in_game_seconds->boss_shoot_phase_3_weapon2_fast = BOSS_SHOOT_PHASE_3_WEAPON2_FAST;
    in_game_seconds->boss_shoot_phase_3_weapon3_fast = BOSS_SHOOT_PHASE_3_WEAPON3_FAST;
    in_game_seconds->boss_move_phase_3_fast = BOSS_MOVE_PHASE_3_MOVE_FAST;
    in_game_seconds->boss_shoot_phase_3_weapon2_normal = BOSS_SHOOT_PHASE_3_WEAPON2_NORMAL;
    in_game_seconds->boss_shoot_phase_3_weapon3_normal = BOSS_SHOOT_PHASE_3_WEAPON3_NORMAL;
    in_game_seconds->boss_move_phase_3_normal = BOSS_MOVE_PHASE_3_MOVE_NORMAL;
    in_game_seconds->item_move = ITEM_MOVE;
    in_game_seconds->boss_shoot_weapon_2 = BOSS_SHOOT_PHASE_2_WEAPON;
    in_game_seconds->boss_phase_2_move_back = BOSS_PHASE_2_MOVE_BACK;
    in_game_seconds->particle_effext = PARTICLE_EFFECT;
    in_game_seconds->wait_boss_combine = WAIT_SEC_COMBINE;
    in_game_seconds->bef_phase_1 = BEF_PHASE_1;
    in_game_seconds->bef_boss_phase = BEF_PHASE_BOSS;
    in_game_seconds->clear_enemy = CLEAR_ENEMY;
    in_game_seconds->twinkle_letters = TWINKLE_LETTERS;
    in_game_seconds->change_player_pos = CHANGE_PLAYER_POS;

}

void Init_Hard_Control(XY_Position_Ship* current_ship_xy, Map_Status_Count* current_map_status, In_Game_Seconds* in_game_seconds, Game_Control* game_control, Level_Control* level_control)
{
    game_control->init_enemy = true;
    game_control->init_enemy2 = true;
    game_control->init_enemy3 = true;
    game_control->init_boss = true;
    game_control->level_up_once = true;
    game_control->bef_phase_1 = false;
    game_control->phase_1 = false;
    game_control->phase_2 = false;
    game_control->phase_3 = false;
    game_control->phase_boss = false;
    game_control->boss_phase_1 = true;
    game_control->boss_phase_2 = false;
    game_control->boss_move_enough = false;
    game_control->init_boss_phase_2 = false;
    game_control->enemy_arr_1 = true;
    game_control->enemy_arr_2 = false;
    game_control->enemy_arr_3 = false;
    game_control->first = true;
    game_control->second = true;
    game_control->third = false;
    game_control->change_phase_1_to_2 = false;
    game_control->once = false;
    game_control->is_boss_exist = false;
    game_control->is_combined = false;
    game_control->tutorial_enemy_is_exist = false;
    game_control->bef_boss_init = false;
    game_control->let_boss_init = false;
    game_control->boss_move_fast = false;

    level_control->body_power = 1;
    level_control->weapon_power = 1;
    level_control->player_bullet_move_limitation = 30;
    level_control->enemy_arr1_control_x_down = (COL / 2) - 1;
    level_control->enemy_arr1_control_x_up = (COL / 2) - 1;

    in_game_seconds->bullet_move = PLAYER_BULLET_MOVE;

    in_game_seconds->enemy_1_move = ENEMY_1_MOVE;
    in_game_seconds->enemy_2_move = ENEMY_2_MOVE;
    in_game_seconds->enemy_1_shoot = ENEMY_1_SHOOT;
    in_game_seconds->enemy_2_shoot = ENEMY_2_SHOOT;
    in_game_seconds->enemy_1_init = ENEMY_1_INIT;
    in_game_seconds->enemy_2_init = ENEMY_2_INIT;
    in_game_seconds->phase_1_enemy_bullet_move = PHASE_1_ENEMY_BULLET_MOVE;
    in_game_seconds->phase_1_change_arr = PHASE_1_CHANGE_ARR;
    in_game_seconds->phase_2_enemy_1_move = PHASE_2_ENEMY_1_MOVE;
    in_game_seconds->phase_2_enemy_2_move = PHASE_2_ENEMY_2_MOVE;
    in_game_seconds->phase_2_enemy_1_init = PHASE_2_ENEMY_1_INIT;
    in_game_seconds->phase_2_enemy_2_init = PHASE_2_ENEMY_2_INIT;
    in_game_seconds->phase_2_enemy_1_shoot = PHASE_2_ENEMY_1_SHOOT;
    in_game_seconds->phase_2_enemy_2_shoot = PHASE_2_ENEMY_2_SHOOT;
    in_game_seconds->phase_2_enemy_1_bullet_move = PHASE_2_ENEMY_1_BULLET_MOVE;
    in_game_seconds->phase_2_enemy_2_bullet_move = PHASE_2_ENEMY_2_BULLET_MOVE;
    in_game_seconds->phase_3_enemy_1_move = PHASE_3_ENEMY_1_MOVE;
    in_game_seconds->phase_3_enemy_2_move = PHASE_3_ENEMY_2_MOVE;
    in_game_seconds->phase_3_enemy_1_init = PHASE_3_ENEMY_1_INIT;
    in_game_seconds->phase_3_enemy_2_init = PHASE_3_ENEMY_2_INIT;
    in_game_seconds->phase_3_enemy_1_shoot = PHASE_3_ENEMY_1_SHOOT;
    in_game_seconds->phase_3_enemy_2_shoot = PHASE_3_ENEMY_2_SHOOT;
    in_game_seconds->phase_3_enemy_1_bullet_move = PHASE_3_ENEMY_1_BULLET_MOVE;
    in_game_seconds->phase_3_enemy_2_bullet_move = PHASE_3_ENEMY_2_BULLET_MOVE;
    in_game_seconds->boss_move_fast_enouth = BOSS_MOVE_FAST_CLOCK;
    in_game_seconds->boss_move = BOSS_MOVE;
    in_game_seconds->boss_shoot = BOSS_SHOOT;
    in_game_seconds->boss_bullet_move_2 = BOSS_BULLET_MOVE_2;
    in_game_seconds->boss_bullet_move_1 = BOSS_BULLET_MOVE_1;
    in_game_seconds->boss_shoot_unbreakable_weapon = BOSS_SHOOT_UNBREAKABLE_WEAPON;
    in_game_seconds->boss_phase_2_bullet_move = BOSS_BULLET_PHASE_2_MOVE;
    in_game_seconds->boss_shoot_phase_3_weapon2_fast = BOSS_SHOOT_PHASE_3_WEAPON2_FAST;
    in_game_seconds->boss_shoot_phase_3_weapon3_fast = BOSS_SHOOT_PHASE_3_WEAPON3_FAST;
    in_game_seconds->boss_move_phase_3_fast = BOSS_MOVE_PHASE_3_MOVE_FAST;
    in_game_seconds->boss_shoot_phase_3_weapon2_normal = BOSS_SHOOT_PHASE_3_WEAPON2_NORMAL;
    in_game_seconds->boss_shoot_phase_3_weapon3_normal = BOSS_SHOOT_PHASE_3_WEAPON3_NORMAL;
    in_game_seconds->boss_move_phase_3_normal = BOSS_MOVE_PHASE_3_MOVE_NORMAL;
    in_game_seconds->item_move = ITEM_MOVE;
    in_game_seconds->boss_shoot_weapon_2 = BOSS_SHOOT_PHASE_2_WEAPON;
    in_game_seconds->boss_phase_2_move_back = BOSS_PHASE_2_MOVE_BACK;
    in_game_seconds->particle_effext = PARTICLE_EFFECT;
    in_game_seconds->wait_boss_combine = WAIT_SEC_COMBINE;
    in_game_seconds->bef_phase_1 = BEF_PHASE_1;
    in_game_seconds->bef_boss_phase = BEF_PHASE_BOSS;
    in_game_seconds->clear_enemy = CLEAR_ENEMY;
    in_game_seconds->twinkle_letters = TWINKLE_LETTERS;
    in_game_seconds->change_player_pos = CHANGE_PLAYER_POS;

}