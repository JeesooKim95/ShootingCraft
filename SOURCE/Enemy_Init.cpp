/**
\file        Enemy_Init.cpp
\author      jeesoo.kim
\brief
This file initializes the first type of enemies.

copyright   All content ?2018 DigiPen (USA) Corporation, all rights reserved

*/

#include "Enemy_Init.h"
#include "time.h"
#include "stdlib.h"
#include "MapStatus.h"
#include "Enemy_Part.h"

int type2;
int enemy_position_x2;
int enemy_position_y2;
Enemy_Type enemy2;

void Control_Enemy_Init(int enemy_type)
{
    enemy2.enemy_type = enemy_type;

    Make_Ship();
}


void Make_Ship()
{
    switch (enemy2.enemy_type)
    {
    case 0:
        enemy2.spawn_position_x = FIRST_ENEMY_INIT_X;
        enemy2.spawn_position_y = FIRST_ENEMY_INIT_Y;
        enemy2.enemy_ship[0][0] = AIR;
        enemy2.enemy_ship[0][1] = AIR;
        enemy2.enemy_ship[0][2] = AIR;
        enemy2.enemy_ship[1][0] = Enemy_Body_Left;
        enemy2.enemy_ship[1][1] = Enemy_Head;
        enemy2.enemy_ship[1][2] = Enemy_Body_Right;
        enemy2.enemy_ship[2][0] = AIR;
        enemy2.enemy_ship[2][1] = Enemy_Weapon;
        enemy2.enemy_ship[2][2] = AIR;
        break;

    case 1:
        enemy2.spawn_position_x = SECOND_ENEMY_INIT_X;
        enemy2.spawn_position_y = SECOND_ENEMY_INIT_Y;
        enemy2.enemy_ship[0][0] = AIR;
        enemy2.enemy_ship[0][1] = AIR;
        enemy2.enemy_ship[0][2] = AIR;
        enemy2.enemy_ship[1][0] = Enemy_Body_Left2;
        enemy2.enemy_ship[1][1] = Enemy_Head2;
        enemy2.enemy_ship[1][2] = Enemy_Body_Right2;
        enemy2.enemy_ship[2][0] = AIR;
        enemy2.enemy_ship[2][1] = Enemy_Weapon2;
        enemy2.enemy_ship[2][2] = AIR;
        break;
    }
}

bool Check_Enemy_Spawnposition(Game_Map game_map)
{
    for (int i = enemy2.spawn_position_y; i < enemy2.spawn_position_y + 3; i++)
    {
        for (int j = enemy2.spawn_position_x; j < enemy2.spawn_position_x + 3; j++)
        {
            if (game_map[i][j] != AIR)
            {
                return false;
            }
        }
    }
    return true;
}

void Initialize_Enemy_Ship(Game_Map game_map, int* control_enemy_num)
{
    if (Check_Enemy_Spawnposition(game_map))
    {
        for (int i = enemy2.spawn_position_y, a = 0; i < enemy2.spawn_position_y + 3 && a < 3; i++, a++)
        {
            for (int j = enemy2.spawn_position_x, b = 0; j < enemy2.spawn_position_x + 3 && b < 3; j++, b++)
            {
                game_map[i][j] = enemy2.enemy_ship[a][b];
            }
        }
        *control_enemy_num += 1;
    }
}