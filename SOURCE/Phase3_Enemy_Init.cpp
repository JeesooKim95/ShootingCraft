/**
\file		Phase3_Enemy_Init.cpp
\author     jeesoo.kim
\brief
This file initializes the special enemy type when in phase 3.

copyright   All content ?2018 DigiPen (USA) Corporation, all rights reserved

*/


#include "Phase3_Enemy_Init.h"
#include "time.h"
#include "stdlib.h"
#include "MapStatus.h"
#include "Enemy_Part.h"
#include "Particle.h"

int type_phase3;
Enemy_Type enemy_phase3;
int player_pos_x;

void Phase3_Control_Enemy_Init(int enemy_type, int player_pos)
{
    enemy_phase3.enemy_type = enemy_type;
    player_pos_x = player_pos;
    Phase3_Make_Ship();
}


void Phase3_Make_Ship()
{
    switch (enemy_phase3.enemy_type)
    {
    case 0:
        enemy_phase3.spawn_position_x = player_pos_x;
        enemy_phase3.spawn_position_y = SIXTH_ENEMY_INIT_Y;
        enemy_phase3.enemy_ship[0][0] = AIR;
        enemy_phase3.enemy_ship[0][1] = AIR;
        enemy_phase3.enemy_ship[0][2] = AIR;
        enemy_phase3.enemy_ship[1][0] = AIR;
        enemy_phase3.enemy_ship[1][1] = Enemy_Head3;
        enemy_phase3.enemy_ship[1][2] = AIR;
        enemy_phase3.enemy_ship[2][0] = AIR;
        enemy_phase3.enemy_ship[2][1] = Enemy_Weapon3;
        enemy_phase3.enemy_ship[2][2] = AIR;

        break;
    case 1:
        enemy_phase3.spawn_position_x = player_pos_x;
        enemy_phase3.spawn_position_y = SIXTH_ENEMY_INIT_Y;
        enemy_phase3.enemy_ship[0][0] = AIR;
        enemy_phase3.enemy_ship[0][1] = AIR;
        enemy_phase3.enemy_ship[0][2] = AIR;
        enemy_phase3.enemy_ship[1][0] = AIR;
        enemy_phase3.enemy_ship[1][1] = Ship_Die_Manager;
        enemy_phase3.enemy_ship[1][2] = AIR;
        enemy_phase3.enemy_ship[2][0] = AIR;
        enemy_phase3.enemy_ship[2][1] = AIR;
        enemy_phase3.enemy_ship[2][2] = AIR;
        break;
    }
}

bool Phase3_Check_Enemy_Spawnposition(Game_Map game_map)
{
    for (int i = enemy_phase3.spawn_position_y; i < enemy_phase3.spawn_position_y + 3; i++)
    {
        for (int j = enemy_phase3.spawn_position_x; j < enemy_phase3.spawn_position_x + 3; j++)
        {
            if (game_map[i][j] != AIR)
            {
                return false;
            }

        }

    }
    return true;
}

void Phase3_Initialize_Enemy_Ship(Game_Map game_map, int* control_enemy_num)
{
    if (Phase3_Check_Enemy_Spawnposition(game_map))
    {
        for (int i = enemy_phase3.spawn_position_y, a = 0; i < enemy_phase3.spawn_position_y + 3 && a < 3; i++, a++)
        {
            for (int j = enemy_phase3.spawn_position_x, b = 0; j < enemy_phase3.spawn_position_x + 3 && b < 3; j++, b++)
            {
                game_map[i][j] = enemy_phase3.enemy_ship[a][b];
            }
        }

        *control_enemy_num += 1;
    }
}