/**
\file        Timer.cpp
\author      sangmin.kim
\par         email: ryan95kr@gmail.com
\brief
This file will decrease the set of long value by delta time.

copyright   All content ?2018 DigiPen (USA) Corporation, all rights reserved
*/

#include "Timer.h"
typedef Game_Control Game_Control;

void Decrease_Time(In_Game_Seconds* in_game_seconds, long dt, bool boss_phase_2, bool bef_phase_1, bool bef_boss_init, Game_Control* game_control)
{
    if (bef_phase_1)
    {
        in_game_seconds->bef_phase_1 -= dt;
    }
    in_game_seconds->bullet_move -= dt;
    in_game_seconds->enemy_1_move -= dt;
    in_game_seconds->enemy_2_move -= dt;
    in_game_seconds->enemy_1_shoot -= dt;
    in_game_seconds->enemy_2_shoot -= dt;
    in_game_seconds->enemy_1_init -= dt;
    in_game_seconds->enemy_2_init -= dt;
    in_game_seconds->phase_1_enemy_bullet_move -= dt;
    in_game_seconds->phase_1_change_arr -= dt;

    in_game_seconds->phase_2_enemy_1_move -= dt;
    in_game_seconds->phase_2_enemy_2_move -= dt;
    in_game_seconds->phase_2_enemy_1_init -= dt;
    in_game_seconds->phase_2_enemy_2_init -= dt;
    in_game_seconds->phase_2_enemy_1_shoot -= dt;
    in_game_seconds->phase_2_enemy_2_shoot -= dt;
    in_game_seconds->phase_2_enemy_1_bullet_move -= dt;
    in_game_seconds->phase_2_enemy_2_bullet_move -= dt;

    in_game_seconds->phase_3_enemy_1_move -= dt;
    in_game_seconds->phase_3_enemy_2_move -= dt;
    in_game_seconds->phase_3_enemy_1_init -= dt;
    in_game_seconds->phase_3_enemy_2_init -= dt;
    in_game_seconds->phase_3_enemy_1_shoot -= dt;
    in_game_seconds->phase_3_enemy_2_shoot -= dt;
    in_game_seconds->phase_3_enemy_1_bullet_move -= dt;
    in_game_seconds->phase_3_enemy_2_bullet_move -= dt;

    in_game_seconds->boss_move -= dt;
    in_game_seconds->boss_shoot -= dt;

    in_game_seconds->boss_shoot_unbreakable_weapon -= dt;
    in_game_seconds->boss_bullet_move_2 -= dt;
    in_game_seconds->boss_bullet_move_1 -= dt;
    in_game_seconds->item_move -= dt;
    in_game_seconds->particle_effext -= dt;
    in_game_seconds->boss_phase_2_move_back -= dt;
    in_game_seconds->boss_phase_2_shoot_weapon2 -= dt;
    in_game_seconds->boss_phase_2_bullet_move -= dt;
    if (game_control->boss_phase_3 && game_control->boss_move_fast)
    {
        in_game_seconds->boss_move_fast_enouth -= dt;

    }
    if (!game_control->boss_move_fast)
    {
        in_game_seconds->boss_shoot_phase_3_weapon2_normal -= dt;
        in_game_seconds->boss_shoot_phase_3_weapon3_normal -= dt;
        in_game_seconds->boss_move_phase_3_normal -= dt;
    }
    if (game_control->boss_move_fast)
    {
        in_game_seconds->boss_move_phase_3_fast -= dt;
        in_game_seconds->boss_shoot_phase_3_weapon2_fast -= dt;
        in_game_seconds->boss_shoot_phase_3_weapon3_fast -= dt;
    }
    if (boss_phase_2)
    {
        in_game_seconds->wait_boss_combine -= dt;
        in_game_seconds->boss_shoot_weapon_2 -= dt;
    }
    if (bef_boss_init)
    {
        in_game_seconds->clear_enemy -= dt;
        in_game_seconds->bef_boss_phase -= dt;
        in_game_seconds->change_player_pos -= dt;
    }
}