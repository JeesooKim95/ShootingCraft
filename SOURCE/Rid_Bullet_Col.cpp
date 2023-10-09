/**
\file        Rid_Bullet_Col.cpp
\author      hyun.gang
\par         email: hangam131313@gmail.com
\brief
This will rid the bullet_col(when enemy bullet and player's bullet meets)

copyright   All content ?2018 DigiPen (USA) Corporation, all rights reserved

*/
#include "Rid_Bullet_Col.h"
#include "MapStatus.h"
#include "Enemy_Part.h"
#include "Ship_Status.h"

void Rid_Bullet_Col(Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status)
{
    int x, y;

    for (int i = 0; i < current_map_status.count_bullet_col; i++)
    {
        x = current_ship_xy.bullet_col_x[i];
        y = current_ship_xy.bullet_col_y[i];

        if (game_map[y][x] == Bullet_Col)
        {
            game_map[y][x] = AIR;

        }

    }
    for (int i = 0; i < current_map_status.count_bullet_col_enemy; i++)
    {
        x = current_ship_xy.bullet_col_enemy_x[i];
        y = current_ship_xy.bullet_col_enemy_y[i];

        if (game_map[y][x] == Enemy_Bullet_Col)
        {
            game_map[y][x] = AIR;

        }

    }

}