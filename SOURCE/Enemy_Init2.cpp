/**
\file        Enemy_Init2.cpp
\author      jeesoo.kim
\brief
This file initializes the sceond type of enemies.

copyright   All content ?2018 DigiPen (USA) Corporation, all rights reserved

*/

#include "Enemy_Init2.h"
#include "time.h"
#include "stdlib.h"
#include "MapStatus.h"
#include "Enemy_Part.h"

int type;
int enemy_position_x;
int enemy_position_y;
Enemy_Type enemy;

void Control_Enemy_Init2(int enemy_type)
{
    enemy.enemy_type = enemy_type;

    Make_Ship2();
}

void Make_Ship2()
{
    switch (enemy.enemy_type)
    {
    case 0:
        enemy.spawn_position_x = THIRD_ENEMY_INIT_X;
        enemy.spawn_position_y = THIRD_ENEMY_INIT_Y;
        enemy.enemy_ship[0][0] = AIR;
        enemy.enemy_ship[0][1] = AIR;
        enemy.enemy_ship[0][2] = AIR;
        enemy.enemy_ship[1][0] = Enemy_Body_Left3;
        enemy.enemy_ship[1][1] = Enemy_Head3;
        enemy.enemy_ship[1][2] = Enemy_Body_Right3;
        enemy.enemy_ship[2][0] = AIR;
        enemy.enemy_ship[2][1] = Enemy_Weapon3;
        enemy.enemy_ship[2][2] = AIR;
        break;
    case 1:
        enemy.spawn_position_x = FOURTH_ENEMY_INIT_X;
        enemy.spawn_position_y = FOURTH_ENEMY_INIT_Y;
        enemy.enemy_ship[0][0] = AIR;
        enemy.enemy_ship[0][1] = AIR;
        enemy.enemy_ship[0][2] = AIR;
        enemy.enemy_ship[1][0] = Enemy_Body_Left4;
        enemy.enemy_ship[1][1] = Enemy_Head4;
        enemy.enemy_ship[1][2] = Enemy_Body_Right4;
        enemy.enemy_ship[2][0] = AIR;
        enemy.enemy_ship[2][1] = Enemy_Weapon4;
        enemy.enemy_ship[2][2] = AIR;
        break;
    }
}

bool Check_Enemy_Spawnposition2(Game_Map game_map)
{
    for (int i = enemy.spawn_position_y; i < enemy.spawn_position_y + 3; i++)
    {
        for (int j = enemy.spawn_position_x; j < enemy.spawn_position_x + 3; j++)
        {
            if (game_map[i][j] != AIR)
            {
                return false;
            }
        }
    }
    return true;
}

void Initialize_Enemy_Ship2(Game_Map game_map, int* control_enemy_num)
{
    if (Check_Enemy_Spawnposition2(game_map))
    {
        for (int i = enemy.spawn_position_y, a = 0; i < enemy.spawn_position_y + 3 && a < 3; i++, a++)
        {
            for (int j = enemy.spawn_position_x, b = 0; j < enemy.spawn_position_x + 3 && b < 3; j++, b++)
            {
                game_map[i][j] = enemy.enemy_ship[a][b];
            }
        }
        *control_enemy_num += 1;
    }
}