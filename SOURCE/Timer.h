/**
\file        Timer.h
\author      sangmin.kim
\par         email: ryan95kr@gmail.com
\brief
This is the header file of Timer.cpp

copyright   All content © 2018 DigiPen (USA) Corporation, all rights reserved
*/

#pragma once
#include "time.h"
#include "Game_Control.h"
#define PLAYER_BULLET_MOVE 50
#define ENEMY_1_MOVE 80
#define ENEMY_2_MOVE 100
#define ENEMY_1_SHOOT 2000
#define ENEMY_2_SHOOT 2000
#define ENEMY_1_INIT 20
#define ENEMY_2_INIT 500
#define PHASE_1_CHANGE_ARR 4000
#define PHASE_1_ENEMY_BULLET_MOVE 100

#define PHASE_2_ENEMY_1_MOVE 500
#define PHASE_2_ENEMY_2_MOVE 500
#define PHASE_2_ENEMY_1_INIT 2500
#define PHASE_2_ENEMY_2_INIT 2500
#define PHASE_2_ENEMY_1_SHOOT 3000
#define PHASE_2_ENEMY_2_SHOOT 3000
#define PHASE_2_ENEMY_1_BULLET_MOVE 100
#define PHASE_2_ENEMY_2_BULLET_MOVE 80

#define PHASE_3_ENEMY_1_MOVE 500
#define PHASE_3_ENEMY_2_MOVE 150
#define PHASE_3_ENEMY_1_INIT 2000
#define PHASE_3_ENEMY_2_INIT 2000
#define PHASE_3_ENEMY_1_SHOOT 2000
#define PHASE_3_ENEMY_2_SHOOT 2000
#define PHASE_3_ENEMY_1_BULLET_MOVE 80
#define PHASE_3_ENEMY_2_BULLET_MOVE 50

#define HARD_PHASE_3_ENEMY_1_MOVE 400
#define HARD_PHASE_3_ENEMY_2_MOVE 130
#define HARD_PHASE_3_ENEMY_1_INIT 1800
#define HARD_PHASE_3_ENEMY_2_INIT 1800
#define HARD_PHASE_3_ENEMY_1_SHOOT 1800
#define HARD_PHASE_3_ENEMY_2_SHOOT 1800
#define HARD_PHASE_3_ENEMY_1_BULLET_MOVE 70
#define HARD_PHASE_3_ENEMY_2_BULLET_MOVE 40

#define UPGRADE_MOVE_30 30
#define UPGRADE_MOVE_10 10
#define UPGRADE_INIT_50 50
#define UPGRADE_INIT_20 20
#define UPGRADE_SHOOT_50 50
#define UPGRADE_SHOOT_35 35
#define UPGRADE_BULLET_MOVE_3 3
#define UPGRADE_BULLET_MOVE_1 1

#define UPGRADE_HARD_MOVE_30 65
#define UPGRADE_HARD_MOVE_10 30
#define UPGRADE_HARD_INIT_50 80
#define UPGRADE_HARD_INIT_20 50
#define UPGRADE_HARD_SHOOT_50 65
#define UPGRADE_HARD_SHOOT_35 40
#define UPGRADE_HARD_BULLET_MOVE_3 7
#define UPGRADE_HARD_BULLET_MOVE_1 2

#define PHASE_3_ENEMY_1_MOVE_LIMIT 100
#define PHASE_3_ENEMY_2_MOVE_LIMIT 70
#define PHASE_3_ENEMY_1_INIT_LIMIT 1000
#define PHASE_3_ENEMY_2_INIT_LIMIT 1000
#define PHASE_3_ENEMY_1_BULLET_MOVE_LIMIT 55
#define PHASE_3_ENEMY_2_BULLET_MOVE_LIMIT 25

#define BOSS_MOVE 400
#define BOSS_SHOOT 2000
#define BOSS_BULLET_MOVE_2 100
#define BOSS_BULLET_MOVE_1 100
#define BOSS_SHOOT_UNBREAKABLE_WEAPON 2000
#define BOSS_SHOOT_PHASE_2_WEAPON 3000
#define BOSS_BULLET_PHASE_2_MOVE 100
#define BOSS_SHOOT_PHASE_2_WEAPON2 5000

#define BOSS_SHOOT_PHASE_3_WEAPON2_FAST 500
#define BOSS_SHOOT_PHASE_3_WEAPON3_FAST 400
#define BOSS_MOVE_PHASE_3_MOVE_FAST 60
#define BOSS_SHOOT_PHASE_3_WEAPON2_NORMAL 2000
#define BOSS_SHOOT_PHASE_3_WEAPON3_NORMAL 3000
#define BOSS_MOVE_PHASE_3_MOVE_NORMAL 300
#define BOSS_MOVE_FAST_CLOCK 10000



#define ITEM_MOVE 200
#define BOSS_PHASE_2_MOVE_BACK 200
#define PARTICLE_EFFECT 30
#define WAIT_SEC_COMBINE 300
#define BEF_PHASE_1 3000
#define TWINKLE_LETTERS 400
#define BEF_PHASE_BOSS 3000
#define CLEAR_ENEMY 200
#define CHANGE_PLAYER_POS 100


typedef struct Timer_time {

    int timer_enemy1_init = 10000;
    int timer_enemy2_init = 9000;
    int timer_enemy1_shoot = 5000;
    int timer_enemy2_shoot = 4500;
    int timer_enemy1_move = 1000;
    int timer_enemy_bullet_move = 500;
    int timer_user_bullet_move_speed = 30;

}Timer_time;

typedef struct In_Game_Seconds2 {

    long bullet_move = PLAYER_BULLET_MOVE;

    long enemy_1_move = ENEMY_1_MOVE;
    long enemy_2_move = ENEMY_2_MOVE;
    long enemy_1_shoot = ENEMY_1_SHOOT;
    long enemy_2_shoot = ENEMY_2_SHOOT;
    long enemy_1_init = ENEMY_1_INIT;
    long enemy_2_init = ENEMY_2_INIT;
    long phase_1_enemy_bullet_move = PHASE_1_ENEMY_BULLET_MOVE;
    long phase_1_change_arr = PHASE_1_CHANGE_ARR;

    long phase_2_enemy_1_move = PHASE_2_ENEMY_1_MOVE;
    long phase_2_enemy_2_move = PHASE_2_ENEMY_2_MOVE;
    long phase_2_enemy_1_init = PHASE_2_ENEMY_1_INIT;
    long phase_2_enemy_2_init = PHASE_2_ENEMY_2_INIT;
    long phase_2_enemy_1_shoot = PHASE_2_ENEMY_1_SHOOT;
    long phase_2_enemy_2_shoot = PHASE_2_ENEMY_2_SHOOT;
    long phase_2_enemy_1_bullet_move = PHASE_2_ENEMY_1_BULLET_MOVE;
    long phase_2_enemy_2_bullet_move = PHASE_2_ENEMY_2_BULLET_MOVE;

    long phase_3_enemy_1_move = PHASE_3_ENEMY_1_MOVE;
    long phase_3_enemy_2_move = PHASE_3_ENEMY_2_MOVE;
    long phase_3_enemy_1_init = PHASE_3_ENEMY_1_INIT;
    long phase_3_enemy_2_init = PHASE_3_ENEMY_2_INIT;
    long phase_3_enemy_1_shoot = PHASE_3_ENEMY_1_SHOOT;
    long phase_3_enemy_2_shoot = PHASE_3_ENEMY_2_SHOOT;
    long phase_3_enemy_1_bullet_move = PHASE_3_ENEMY_1_BULLET_MOVE;
    long phase_3_enemy_2_bullet_move = PHASE_3_ENEMY_2_BULLET_MOVE;

    long hard_phase_3_enemy_1_move = HARD_PHASE_3_ENEMY_1_MOVE;
    long hard_phase_3_enemy_2_move = HARD_PHASE_3_ENEMY_2_MOVE;
    long hard_phase_3_enemy_1_init = HARD_PHASE_3_ENEMY_1_INIT;
    long hard_phase_3_enemy_2_init = HARD_PHASE_3_ENEMY_2_INIT;
    long hard_phase_3_enemy_1_shoot = HARD_PHASE_3_ENEMY_1_SHOOT;
    long hard_phase_3_enemy_2_shoot = HARD_PHASE_3_ENEMY_2_SHOOT;
    long hard_phase_3_enemy_1_bullet_move = HARD_PHASE_3_ENEMY_1_BULLET_MOVE;
    long hard_phase_3_enemy_2_bullet_move = HARD_PHASE_3_ENEMY_2_BULLET_MOVE;

    long boss_move = BOSS_MOVE;
    long boss_shoot = BOSS_SHOOT;
    long boss_bullet_move_2 = BOSS_BULLET_MOVE_2;
    long boss_bullet_move_1 = BOSS_BULLET_MOVE_1;
    long boss_shoot_unbreakable_weapon = BOSS_SHOOT_UNBREAKABLE_WEAPON;
    long boss_phase_2_bullet_move = BOSS_BULLET_PHASE_2_MOVE;
    long item_move = ITEM_MOVE;
    long boss_shoot_weapon_2 = BOSS_SHOOT_PHASE_2_WEAPON;
    long boss_phase_2_move_back = BOSS_PHASE_2_MOVE_BACK;
    long particle_effext = PARTICLE_EFFECT;
    long wait_boss_combine = WAIT_SEC_COMBINE;
    long bef_phase_1 = BEF_PHASE_1;
    long bef_boss_phase = BEF_PHASE_BOSS;
    long clear_enemy = CLEAR_ENEMY;
    long boss_phase_2_shoot_weapon2 = BOSS_SHOOT_PHASE_2_WEAPON2;
    long boss_move_fast_enouth = BOSS_MOVE_FAST_CLOCK;
    long change_player_pos = CHANGE_PLAYER_POS;


    long boss_shoot_phase_3_weapon2_fast = BOSS_SHOOT_PHASE_3_WEAPON2_FAST;
    long boss_shoot_phase_3_weapon3_fast = BOSS_SHOOT_PHASE_3_WEAPON3_FAST;
    long boss_move_phase_3_fast = BOSS_MOVE_PHASE_3_MOVE_FAST;
    long boss_shoot_phase_3_weapon2_normal = BOSS_SHOOT_PHASE_3_WEAPON2_NORMAL;
    long boss_shoot_phase_3_weapon3_normal = BOSS_SHOOT_PHASE_3_WEAPON3_NORMAL;
    long boss_move_phase_3_normal = BOSS_MOVE_PHASE_3_MOVE_NORMAL;



    long twinkle_letters = TWINKLE_LETTERS;

}In_Game_Seconds;

void Decrease_Time(In_Game_Seconds* in_game_seconds, long dt, bool boss_phase_2, bool bef_phase_1, bool bef_boss_init, Game_Control* game_control);