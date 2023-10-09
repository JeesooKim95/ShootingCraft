/**
\file        Enemy_Init4.cpp
\author      Chulseung Lee
\brief
This will initialize the enemy's type fourth.

copyright   All content ?2018 DigiPen (USA) Corporation, all rights reserved

*/

#include "Enemy_Init4.h"
#include "time.h"
#include "stdlib.h"
#include "MapStatus.h"
#include "Enemy_Part.h"

int type4;
int enemy_position_x4;
int enemy_position_y4;
Enemy_Type enemy4;

void Initialize_Enemy_Ship4(Game_Map game_map, int* control_enemy_num)
{

    for (int i = enemy4.spawn_position_y, a = 0; i < enemy4.spawn_position_y + 3 && a < 3; i++, a++)
    {
        for (int j = enemy4.spawn_position_x, b = 0; j < enemy4.spawn_position_x + 3 && b < 3; j++, b++)
        {
            game_map[i][j] = enemy4.enemy_ship[a][b];
        }
    }

    *control_enemy_num += 1;


}
void Control_Enemy_Init4(int enemy_type)
{
    enemy4.enemy_type = enemy_type;

    Make_Ship4();

}
void Make_Ship4()
{
    enemy4.spawn_position_y = SIXTH_ENEMY_INIT_Y;
    enemy4.spawn_position_x = enemy4.enemy_type;
    enemy4.enemy_ship[0][0] = AIR;
    enemy4.enemy_ship[0][1] = AIR;
    enemy4.enemy_ship[0][2] = AIR;
    enemy4.enemy_ship[1][0] = Enemy_Body_Left2;
    enemy4.enemy_ship[1][1] = Enemy_Head2;
    enemy4.enemy_ship[1][2] = Enemy_Body_Right2;
    enemy4.enemy_ship[2][0] = AIR;
    enemy4.enemy_ship[2][1] = Enemy_Weapon2;
    enemy4.enemy_ship[2][2] = AIR;
}
