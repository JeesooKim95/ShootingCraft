/**
\file        Enemy_Init3.cpp
\author      Chulseung Lee
\brief
This will initialize the enemy's type third.

copyright   All content ?2018 DigiPen (USA) Corporation, all rights reserved

*/

#include "Enemy_Init3.h"
#include "time.h"
#include "stdlib.h"
#include "MapStatus.h"
#include "Enemy_Part.h"

int type3;
int enemy_position_x3;
int enemy_position_y3;
Enemy_Type enemy3;

void Initialize_Enemy_Ship3(Game_Map game_map, int* control_enemy_num)
{
    for (int i = enemy3.spawn_position_y, a = 0; i < enemy3.spawn_position_y + 3 && a < 3; i++, a++)
    {
        for (int j = enemy3.spawn_position_x, b = 0; j < enemy3.spawn_position_x + 3 && b < 3; j++, b++)
        {
            game_map[i][j] = enemy3.enemy_ship[a][b];
        }
    }
    *control_enemy_num += 1;
}
void Control_Enemy_Init3(int enemy_type)
{
    enemy3.enemy_type = enemy_type;

    Make_Ship3();

}
void Make_Ship3()
{
    enemy3.spawn_position_y = FIFTH_ENEMY_INIT_Y;
    enemy3.spawn_position_x = enemy3.enemy_type;
    enemy3.enemy_ship[0][0] = AIR;
    enemy3.enemy_ship[0][1] = AIR;
    enemy3.enemy_ship[0][2] = AIR;
    enemy3.enemy_ship[1][0] = Enemy_Body_Left;
    enemy3.enemy_ship[1][1] = Enemy_Head;
    enemy3.enemy_ship[1][2] = Enemy_Body_Right;
    enemy3.enemy_ship[2][0] = AIR;
    enemy3.enemy_ship[2][1] = Enemy_Weapon;
    enemy3.enemy_ship[2][2] = AIR;
}
