/**
\file		 Enemy_Determine_Dir
\author      jeesoo.kim
\brief
This file manages the enemies' bullet direction.

copyright   All content ?2018 DigiPen (USA) Corporation, all rights reserved
*/

#include "Enemy_Determine_Dir.h"
#include "MapStatus.h"
#include "Game_State.h"
#include "Ship_Status.h"


void Determine_Enemy_Bullet_Dir(Game_Map game_map, Map_Status_Count current_map_status, XY_Position_Ship* current_ship_xy)
{
    int x, y;
    int head_x = current_ship_xy->head_ship_x[0];
    int head_y = current_ship_xy->head_ship_y[0];

    for (int i = 0; i < current_map_status.count_all_enemy_weapon; i++)
    {
        x = current_ship_xy->all_enemy_weapon_x[i];
        y = current_ship_xy->all_enemy_weapon_y[i];


        if (current_ship_xy->bullet_dir_x[i] == 0 && current_ship_xy->bullet_dir_y[i] == 0)
        {
            current_ship_xy->bullet_dir_x[i] = x - head_x;
            current_ship_xy->bullet_dir_y[i] = y - head_y;
        }
    }
}
