/**
\file        Free_Allocated_Data.cpp
\author      jeesoo.kim
\brief
This file frees the allocated memory.

copyright   All content ?2018 DigiPen (USA) Corporation, all rights reserved
*/

#include "Free_Allocated_Data.h"
#include "MapStatus.h"
#include "stdlib.h"

void Free_Allocated(XY_Position_Ship *current_ship_xy)
{
    free(current_ship_xy->head_ship_x);
    free(current_ship_xy->head_ship_y);
    free(current_ship_xy->body_ship_x);
    free(current_ship_xy->body_ship_y);
    free(current_ship_xy->weapon_ship_x);
    free(current_ship_xy->weapon_ship_y);
    free(current_ship_xy->bullet_x);
    free(current_ship_xy->bullet_y);
    free(current_ship_xy->whole_ship_x);
    free(current_ship_xy->whole_ship_y);

    free(current_ship_xy->enemy_body_x);
    free(current_ship_xy->enemy_body_y);
    free(current_ship_xy->enemy_weapon_x);
    free(current_ship_xy->enemy_weapon_y);
    free(current_ship_xy->enemy_head_x);
    free(current_ship_xy->enemy_head_y);
    free(current_ship_xy->whole_enemy_x);
    free(current_ship_xy->whole_enemy_y);
    free(current_ship_xy->enemy_bullet_y);
    free(current_ship_xy->enemy_bullet_x);

    free(current_ship_xy->enemy_body_x2);
    free(current_ship_xy->enemy_body_y2);
    free(current_ship_xy->enemy_weapon_x2);
    free(current_ship_xy->enemy_weapon_y2);
    free(current_ship_xy->enemy_head_x2);
    free(current_ship_xy->enemy_head_y2);
    free(current_ship_xy->whole_enemy_x2);
    free(current_ship_xy->whole_enemy_y2);

    free(current_ship_xy->all_enemy_x);
    free(current_ship_xy->all_enemy_y);
}