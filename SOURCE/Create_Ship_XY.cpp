/**
\file        Create_Ship_XY.cpp
\author      sangmin.kim
\par         email: ryan95kr@gmail.com
\brief
This file will allocate the size of array each pointer.

copyright   All content ?2018 DigiPen (USA) Corporation, all rights reserved
*/
#include "Game_State.h"
#include "Create_Ship_XY.h"
#include "stdlib.h"

void Create_Ship_XY(XY_Position_Ship *current_ship_xy, Map_Status_Count current_map_status)
{

}

void Alloc_xy_array(XY_Position_Ship* current_ship_xy)
{
    current_ship_xy->whole_ship_x_ship_map = (int *)calloc(SHIP_ALLOC, sizeof(int));
    current_ship_xy->whole_ship_y_ship_map = (int *)calloc(SHIP_ALLOC, sizeof(int));
    current_ship_xy->whole_ship_x = (int *)calloc(SHIP_ALLOC, sizeof(int));
    current_ship_xy->whole_ship_y = (int *)calloc(SHIP_ALLOC, sizeof(int));
    current_ship_xy->body_ship_x = (int *)calloc(SHIP_ALLOC, sizeof(int));
    current_ship_xy->body_ship_y = (int *)calloc(SHIP_ALLOC, sizeof(int));
    current_ship_xy->weapon_ship_x = (int *)calloc(SHIP_ALLOC, sizeof(int));
    current_ship_xy->weapon_ship_y = (int *)calloc(SHIP_ALLOC, sizeof(int));
    current_ship_xy->head_ship_x = (int *)calloc(SHIP_ALLOC, sizeof(int));
    current_ship_xy->head_ship_y = (int *)calloc(SHIP_ALLOC, sizeof(int));
    current_ship_xy->bullet_x = (int *)calloc(BULLET_ALLOC, sizeof(int));
    current_ship_xy->bullet_y = (int *)calloc(BULLET_ALLOC, sizeof(int));

    current_ship_xy->enemy_body_x = (int *)calloc(ENEMY_ALLOC, sizeof(int));
    current_ship_xy->enemy_body_y = (int *)calloc(ENEMY_ALLOC, sizeof(int));
    current_ship_xy->enemy_weapon_x = (int *)calloc(ENEMY_ALLOC, sizeof(int));
    current_ship_xy->enemy_weapon_y = (int *)calloc(ENEMY_ALLOC, sizeof(int));
    current_ship_xy->enemy_head_x = (int *)calloc(ENEMY_ALLOC, sizeof(int));
    current_ship_xy->enemy_head_y = (int *)calloc(ENEMY_ALLOC, sizeof(int));

    current_ship_xy->whole_enemy_x = (int *)calloc(ENEMY_ALLOC, sizeof(int));
    current_ship_xy->whole_enemy_y = (int *)calloc(ENEMY_ALLOC, sizeof(int));
    current_ship_xy->enemy_bullet_x = (int *)calloc(ENEMY_ALLOC, sizeof(int));
    current_ship_xy->enemy_bullet_y = (int *)calloc(ENEMY_ALLOC, sizeof(int));
    current_ship_xy->enemy_bullet_x2 = (int *)calloc(ENEMY_ALLOC, sizeof(int));
    current_ship_xy->enemy_bullet_y2 = (int *)calloc(ENEMY_ALLOC, sizeof(int));
    current_ship_xy->enemy_bullet_x3 = (int *)calloc(ENEMY_ALLOC, sizeof(int));
    current_ship_xy->enemy_bullet_y3 = (int *)calloc(ENEMY_ALLOC, sizeof(int));

    current_ship_xy->enemy_body_x2 = (int *)calloc(ENEMY_ALLOC, sizeof(int));
    current_ship_xy->enemy_body_y2 = (int *)calloc(ENEMY_ALLOC, sizeof(int));
    current_ship_xy->enemy_weapon_x2 = (int *)calloc(ENEMY_ALLOC, sizeof(int));
    current_ship_xy->enemy_weapon_y2 = (int *)calloc(ENEMY_ALLOC, sizeof(int));
    current_ship_xy->enemy_head_x2 = (int *)calloc(ENEMY_ALLOC, sizeof(int));
    current_ship_xy->enemy_head_y2 = (int *)calloc(ENEMY_ALLOC, sizeof(int));
    current_ship_xy->whole_enemy_x2 = (int *)calloc(ENEMY_ALLOC, sizeof(int));
    current_ship_xy->whole_enemy_y2 = (int *)calloc(ENEMY_ALLOC, sizeof(int));

    current_ship_xy->enemy_body_x3 = (int *)calloc(ENEMY_ALLOC, sizeof(int));
    current_ship_xy->enemy_body_y3 = (int *)calloc(ENEMY_ALLOC, sizeof(int));
    current_ship_xy->enemy_weapon_x3 = (int *)calloc(ENEMY_ALLOC, sizeof(int));
    current_ship_xy->enemy_weapon_y3 = (int *)calloc(ENEMY_ALLOC, sizeof(int));
    current_ship_xy->enemy_head_x3 = (int *)calloc(ENEMY_ALLOC, sizeof(int));
    current_ship_xy->enemy_head_y3 = (int *)calloc(ENEMY_ALLOC, sizeof(int));
    current_ship_xy->whole_enemy_x3 = (int *)calloc(ENEMY_ALLOC, sizeof(int));
    current_ship_xy->whole_enemy_y3 = (int *)calloc(ENEMY_ALLOC, sizeof(int));

    current_ship_xy->enemy_body_x4 = (int *)calloc(ENEMY_ALLOC, sizeof(int));
    current_ship_xy->enemy_body_y4 = (int *)calloc(ENEMY_ALLOC, sizeof(int));
    current_ship_xy->enemy_weapon_x4 = (int *)calloc(ENEMY_ALLOC, sizeof(int));
    current_ship_xy->enemy_weapon_y4 = (int *)calloc(ENEMY_ALLOC, sizeof(int));
    current_ship_xy->enemy_head_x4 = (int *)calloc(ENEMY_ALLOC, sizeof(int));
    current_ship_xy->enemy_head_y4 = (int *)calloc(ENEMY_ALLOC, sizeof(int));
    current_ship_xy->whole_enemy_x4 = (int *)calloc(ENEMY_ALLOC, sizeof(int));
    current_ship_xy->whole_enemy_y4 = (int *)calloc(ENEMY_ALLOC, sizeof(int));

    current_ship_xy->boss_body_x = (int *)calloc(ENEMY_ALLOC, sizeof(int));
    current_ship_xy->boss_body_y = (int *)calloc(ENEMY_ALLOC, sizeof(int));
    current_ship_xy->boss_weapon_x = (int *)calloc(ENEMY_ALLOC, sizeof(int));
    current_ship_xy->boss_weapon_y = (int *)calloc(ENEMY_ALLOC, sizeof(int));
    current_ship_xy->boss_head_x = (int *)calloc(ENEMY_ALLOC, sizeof(int));
    current_ship_xy->boss_head_y = (int *)calloc(ENEMY_ALLOC, sizeof(int));
    current_ship_xy->boss_whole_x = (int *)calloc(ENEMY_ALLOC, sizeof(int));
    current_ship_xy->boss_whole_y = (int *)calloc(ENEMY_ALLOC, sizeof(int));
    current_ship_xy->boss_weapon_core_x = (int *)calloc(ENEMY_ALLOC, sizeof(int));
    current_ship_xy->boss_weapon_core_y = (int *)calloc(ENEMY_ALLOC, sizeof(int));
    current_ship_xy->boss_body_core_x = (int *)calloc(ENEMY_ALLOC, sizeof(int));
    current_ship_xy->boss_body_core_y = (int *)calloc(ENEMY_ALLOC, sizeof(int));
    current_ship_xy->boss_head_in_body_x = (int *)calloc(ENEMY_ALLOC, sizeof(int));
    current_ship_xy->boss_head_in_body_y = (int *)calloc(ENEMY_ALLOC, sizeof(int));
    current_ship_xy->boss_bullet_2_x = (int *)calloc(ENEMY_ALLOC, sizeof(int));
    current_ship_xy->boss_bullet_2_y = (int *)calloc(ENEMY_ALLOC, sizeof(int));
    current_ship_xy->boss_body_unbreakable_x = (int *)calloc(ENEMY_ALLOC, sizeof(int));
    current_ship_xy->boss_body_unbreakable_y = (int *)calloc(ENEMY_ALLOC, sizeof(int));
    current_ship_xy->boss_weapon_unbreakable_x = (int *)calloc(ENEMY_ALLOC, sizeof(int));
    current_ship_xy->boss_weapon_unbreakable_y = (int *)calloc(ENEMY_ALLOC, sizeof(int));
    current_ship_xy->boss_weapon_2_x = (int *)calloc(ENEMY_ALLOC, sizeof(int));
    current_ship_xy->boss_weapon_2_y = (int *)calloc(ENEMY_ALLOC, sizeof(int));
    current_ship_xy->boss_weapon_3_x = (int *)calloc(ENEMY_ALLOC, sizeof(int));
    current_ship_xy->boss_weapon_3_y = (int *)calloc(ENEMY_ALLOC, sizeof(int));

    current_ship_xy->all_enemy_x = (int *)calloc(ENEMY_ALLOC, sizeof(int));
    current_ship_xy->all_enemy_y = (int *)calloc(ENEMY_ALLOC, sizeof(int));
    current_ship_xy->all_enemy_weapon_x = (int *)calloc(ENEMY_ALLOC, sizeof(int));
    current_ship_xy->all_enemy_weapon_y = (int *)calloc(ENEMY_ALLOC, sizeof(int));
    current_ship_xy->all_enemy_weapon_x2 = (int *)calloc(ENEMY_ALLOC, sizeof(int));
    current_ship_xy->all_enemy_weapon_y2 = (int *)calloc(ENEMY_ALLOC, sizeof(int));
    current_ship_xy->bullet_col_x = (int *)calloc(ENEMY_ALLOC, sizeof(int));
    current_ship_xy->bullet_col_y = (int *)calloc(ENEMY_ALLOC, sizeof(int));
    current_ship_xy->bullet_col_enemy_x = (int *)calloc(ENEMY_ALLOC, sizeof(int));
    current_ship_xy->bullet_col_enemy_y = (int *)calloc(ENEMY_ALLOC, sizeof(int));

    current_ship_xy->overlap = (int *)calloc(ENEMY_ALLOC, sizeof(int));
    current_ship_xy->overlap_x = (int *)calloc(ENEMY_ALLOC, sizeof(int));
    current_ship_xy->overlap_y = (int *)calloc(ENEMY_ALLOC, sizeof(int));
    current_ship_xy->ship_particle_x = (int *)calloc(ENEMY_ALLOC, sizeof(int));
    current_ship_xy->ship_particle_y = (int *)calloc(ENEMY_ALLOC, sizeof(int));
    current_ship_xy->particle_manager_x = (int *)calloc(ENEMY_ALLOC, sizeof(int));
    current_ship_xy->particle_manager_y = (int *)calloc(ENEMY_ALLOC, sizeof(int));
    current_ship_xy->bomb_particle_x = (int *)calloc(ENEMY_ALLOC, sizeof(int));
    current_ship_xy->bomb_particle_y = (int *)calloc(ENEMY_ALLOC, sizeof(int));


    current_ship_xy->bullet_dir_x = (int *)calloc(ENEMY_ALLOC, sizeof(int));
    current_ship_xy->bullet_dir_y = (int *)calloc(ENEMY_ALLOC, sizeof(int));
    current_ship_xy->power_up_x = (int *)calloc(ENEMY_ALLOC, sizeof(int));
    current_ship_xy->power_up_y = (int *)calloc(ENEMY_ALLOC, sizeof(int));
    current_ship_xy->user_bomb_x = (int *)calloc(ENEMY_ALLOC, sizeof(int));
    current_ship_xy->user_bomb_y = (int *)calloc(ENEMY_ALLOC, sizeof(int));
    current_ship_xy->user_bomb_particle_x = (int *)calloc(ENEMY_ALLOC, sizeof(int));
    current_ship_xy->user_bomb_particle_y = (int *)calloc(ENEMY_ALLOC, sizeof(int));
    current_ship_xy->bomb_ready_x = (int *)calloc(ENEMY_ALLOC, sizeof(int));
    current_ship_xy->bomb_ready_y = (int *)calloc(ENEMY_ALLOC, sizeof(int));
}