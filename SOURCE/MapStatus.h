/**
\file        MapStatus.h
\author      Chulseung Lee
\brief
This is the header file of MapStatus.cpp

copyright   All content ?2018 DigiPen (USA) Corporation, all rights reserved
*/


#pragma once

#define SHIP_LOW 10
#define SHIP_COL 10
#define LOW 35
#define COL 25

//Enemy init position.
#define FIRST_ENEMY_INIT_X 2
#define FIRST_ENEMY_INIT_Y 7
#define SECOND_ENEMY_INIT_X 20
#define SECOND_ENEMY_INIT_Y 7
#define THIRD_ENEMY_INIT_X 2
#define THIRD_ENEMY_INIT_Y 2
#define FOURTH_ENEMY_INIT_X 20
#define FOURTH_ENEMY_INIT_Y 2
#define FIFTH_ENEMY_INIT_Y 2
#define SIXTH_ENEMY_INIT_Y 2

#define MOVE_PLAYER_POS_BEF_BOS 29

#define Enemy_Arr1_Shoot_Range ((LOW / 2) - 2)
#define SCORE__LOW 5
#define SCORE_BOARD_COL 5
#define POWER_UP_BOARD_LOW 5
#define POWER_UP_BOARD_COL 5
#define STATUS_BOARD_LOW 13
#define STATUS_BOARD_COL 15


typedef enum Map {

    AIR = 10000,
    WALL = 10001


}Map;

#define ANSI_COLOR_RED     "\x1b[91m"
#define ANSI_COLOR_RESET   "\x1b[0m"
#define ANSI_COLOR_MAGENTA "\x1b[95m"
#define ANSI_COLOR_BLUE    "\x1b[94m"
#define ANSI_COLOR_YELLOW  "\x1b[93m"
#define ANSI_COLOR_GREEN   "\x1b[92m"
#define ANSI_COLOR_CYAN    "\x1b[96m"
#define ANSI_COLOR_WHITE   "\x1b[97m"
#define ANSI_COLOR_GRAY	   "\x1b[90m"

typedef struct Map_Status_count {

    int count_whole_ship_in_ship_world;
    int count_whole_ship;
    int count_ship_body;
    int count_ship_head;
    int count_ship_weapon;
    int count_ship_bullet;

    int count_enemy_body;
    int count_enemy_head;
    int count_enemy_weapon;
    int count_enemy_whole_ship;
    int count_enemy_bullet;
    int count_enemy_bullet2;
    int count_enemy_bullet3;

    int count_enemy_body2;
    int count_enemy_head2;
    int count_enemy_weapon2;
    int count_enemy_whole_ship2;

    int count_enemy_body3;
    int count_enemy_head3;
    int count_enemy_weapon3;
    int count_enemy_whole_ship3;


    int count_enemy_body4;
    int count_enemy_head4;
    int count_enemy_weapon4;
    int count_enemy_whole_ship4;

    int count_boss_body;
    int count_boss_weapon;
    int count_boss_head;
    int count_boss_core_body;
    int count_boss_core_weapon;
    int count_boss_whole;
    int count_boss_head_in_body;
    int count_boss_bullet_2;
    int count_boss_body_unbreakable;
    int count_boss_weapon_unbreakable;
    int count_boss_weapon_2;
    int count_boss_weapon_3;

    int count_all_enemy;
    int count_all_enemy_weapon;
    int count_all_enemy_weapon2;
    int count_bullet_col;
    int count_bullet_col_enemy;

    int count_ship_particle;
    int count_particle_manager;
    int count_item;

    int count_bome_particle;
    int user_bomb_count;
    int user_bomb_particle_count;
    int bomb_ready_count;


}Map_Status_Count;

typedef struct XY_Position_Ship {
    int* whole_ship_x_ship_map;
    int* whole_ship_y_ship_map;

    int* whole_ship_x;
    int* whole_ship_y;
    int* body_ship_x;
    int* body_ship_y;
    int* weapon_ship_x;
    int* weapon_ship_y;
    int* head_ship_x;
    int* head_ship_y;
    int* bullet_x;
    int* bullet_y;

    int* enemy_body_x;
    int* enemy_body_y;
    int* enemy_weapon_x;
    int* enemy_weapon_y;
    int* enemy_head_x;
    int* enemy_head_y;
    int* whole_enemy_x;
    int* whole_enemy_y;
    int* enemy_bullet_x;
    int* enemy_bullet_y;
    int* enemy_bullet_x2;
    int* enemy_bullet_y2;
    int* enemy_bullet_x3;
    int* enemy_bullet_y3;

    int* enemy_body_x2;
    int* enemy_body_y2;
    int* enemy_weapon_x2;
    int* enemy_weapon_y2;
    int* enemy_head_x2;
    int* enemy_head_y2;
    int* whole_enemy_x2;
    int* whole_enemy_y2;

    int* enemy_body_x3;
    int* enemy_body_y3;
    int* enemy_weapon_x3;
    int* enemy_weapon_y3;
    int* enemy_head_x3;
    int* enemy_head_y3;
    int* whole_enemy_x3;
    int* whole_enemy_y3;

    int* enemy_body_x4;
    int* enemy_body_y4;
    int* enemy_weapon_x4;
    int* enemy_weapon_y4;
    int* enemy_head_x4;
    int* enemy_head_y4;
    int* whole_enemy_x4;
    int* whole_enemy_y4;
    int* boss_body_x;
    int* boss_body_y;
    int* boss_weapon_x;
    int* boss_weapon_y;
    int* boss_head_x;
    int* boss_head_y;
    int* boss_whole_x;
    int* boss_whole_y;
    int* boss_weapon_core_x;
    int* boss_weapon_core_y;
    int* boss_body_core_x;
    int* boss_body_core_y;
    int* boss_head_in_body_x;
    int* boss_head_in_body_y;
    int* boss_bullet_2_x;
    int* boss_bullet_2_y;
    int* boss_body_unbreakable_x;
    int* boss_body_unbreakable_y;
    int* boss_weapon_unbreakable_x;
    int* boss_weapon_unbreakable_y;
    int* boss_weapon_2_x;
    int* boss_weapon_2_y;
    int* boss_weapon_3_x;
    int* boss_weapon_3_y;
    int* all_enemy_x;
    int* all_enemy_y;
    int* all_enemy_weapon_x;
    int* all_enemy_weapon_y;
    int* all_enemy_weapon_x2;
    int* all_enemy_weapon_y2;
    int* bullet_col_x;
    int* bullet_col_y;
    int* bullet_col_enemy_x;
    int* bullet_col_enemy_y;
    int* overlap;
    int* overlap_x;
    int* overlap_y;
    int* ship_particle_x;
    int* ship_particle_y;
    int* particle_manager_x;
    int* particle_manager_y;
    int* bomb_particle_x;
    int* bomb_particle_y;
    int* bullet_dir_x;
    int* bullet_dir_y;
    int* power_up_x;
    int* power_up_y;
    int* user_bomb_x;
    int* user_bomb_y;
    int* user_bomb_particle_x;
    int* user_bomb_particle_y;
    int* bomb_ready_x;
    int* bomb_ready_y;

}XY_Position_Ship;

typedef int Ship_Map[SHIP_LOW][SHIP_COL];
typedef int Game_Map[LOW][COL];
typedef int Status_Board[STATUS_BOARD_LOW][STATUS_BOARD_COL];

void Initialize_ShipMap(Ship_Map ship_map);
void Initialize_GameMap(Game_Map game_map);
void Initialize_GameMap_IF_WALL_IS_ERASED(Game_Map game_map);
void Initialize_Status_Board(Status_Board status_board);