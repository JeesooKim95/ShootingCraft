/**
\file        Bullet_Move.cpp
\author      hyun.gang
\par         email: hangam131313@gmail.com
\brief
This will manage the player's bullet.

copyright   All content ?2018 DigiPen (USA) Corporation, all rights reserved
*/

#include "Bullet_Move.h"
#include "Determine_Dir.h"
#include "Enemy_Determine_Dir.h"
#include "Enemy_Part.h"

void Move_Bullet(Game_Map game_map, Map_Status_Count current_map_status, XY_Position_Ship current_ship_xy)
{
    int x, y;
    int temp;

    for (int i = 0; i < current_map_status.count_ship_bullet; i++)
    {
        x = current_ship_xy.bullet_x[i];
        y = current_ship_xy.bullet_y[i];

        if (y <= 4)
        {
            game_map[y][x] = AIR;

        }
        if (game_map[y - 1][x] == Head || game_map[y - 1][x] == Head - 1 || game_map[y - 1][x] == Head - 2 ||
            game_map[y - 1][x] == Body || game_map[y - 1][x] == Body - 1 || game_map[y - 1][x] == Body - 2 ||
            game_map[y - 1][x] == Weapon || game_map[y - 1][x] == Weapon - 1 || game_map[y - 1][x] == Weapon - 2)
        {
            game_map[y - 2][x] = Bullet;
            game_map[y][x] = AIR;
        }

        if (game_map[y][x] == Bullet)
        {
            temp = game_map[y][x];
            game_map[y][x] = AIR;
            game_map[y - 1][x] = temp;


        }

    }


}


void Move_Enemy_Bullet(Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status)
{
    int x, y;
    int temp;


    int bullet_x, bullet_y;


    for (int i = 0; i < current_map_status.count_enemy_bullet; i++)
    {
        x = current_ship_xy.bullet_dir_x[i];
        y = current_ship_xy.bullet_dir_y[i];

        bullet_x = current_ship_xy.enemy_bullet_x[i];
        bullet_y = current_ship_xy.enemy_bullet_y[i];

        if (x == 0 && y == 0)
        {
            if (game_map[bullet_y + 1][bullet_x] != AIR)
            {
                game_map[bullet_y][bullet_x] = Enemy_Bullet_Col;
                continue;
            }

            temp = game_map[bullet_y][bullet_x];
            game_map[bullet_y][bullet_x] = AIR;
            game_map[bullet_y + 1][bullet_x] = temp;
        }
        else if (x <= 0 && y <= 0)
        {
            if (game_map[bullet_y + 1][bullet_x + 1] != AIR)
            {
                game_map[bullet_y][bullet_x] = Enemy_Bullet_Col;
                continue;
            }

            temp = game_map[bullet_y][bullet_x];
            game_map[bullet_y][bullet_x] = AIR;
            game_map[bullet_y + 1][bullet_x + 1] = temp;

        }
        else if (x >= 0 && y <= 0)
        {
            if (game_map[bullet_y + 1][bullet_x - 1] != AIR)
            {
                game_map[bullet_y][bullet_x] = Enemy_Bullet_Col;
                continue;
            }

            temp = game_map[bullet_y][bullet_x];
            game_map[bullet_y][bullet_x] = AIR;
            game_map[bullet_y + 1][bullet_x - 1] = temp;

        }
        else if (x == 0 && y <= 0)
        {
            if (game_map[bullet_y + 1][bullet_x] != AIR)
            {
                game_map[bullet_y][bullet_x] = Enemy_Bullet_Col;
                continue;
            }

            temp = game_map[bullet_y][bullet_x];
            game_map[bullet_y][bullet_x] = AIR;
            game_map[bullet_y + 1][bullet_x] = temp;

        }
        else if (x >= 0 && y == 0)
        {

            if (game_map[bullet_y][bullet_x - 1] != AIR)
            {
                game_map[bullet_y][bullet_x] = Enemy_Bullet_Col;
                continue;
            }
            temp = game_map[bullet_y][bullet_x];
            game_map[bullet_y][bullet_x] = AIR;
            game_map[bullet_y][bullet_x - 1] = temp;

        }
        else if (x <= 0 && y == 0)
        {
            if (game_map[bullet_y][bullet_x + 1] != AIR)
            {
                game_map[bullet_y][bullet_x] = Enemy_Bullet_Col;
                continue;
            }

            temp = game_map[bullet_y][bullet_x];
            game_map[bullet_y][bullet_x] = AIR;
            game_map[bullet_y][bullet_x + 1] = temp;

        }
        else if (y >= 0)
        {
            if (game_map[bullet_y + 1][bullet_x] != AIR)
            {
                game_map[bullet_y][bullet_x] = Enemy_Bullet_Col;
                continue;
            }
            temp = game_map[bullet_y][bullet_x];
            game_map[bullet_y][bullet_x] = AIR;
            game_map[bullet_y + 1][bullet_x] = temp;
        }
    }
}
void Move_Enemy_Bullet2(Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status)
{
    int bullet_x, bullet_y;
    int temp;

    for (int i = 0; i < current_map_status.count_enemy_bullet2; i++)
    {
        bullet_x = current_ship_xy.enemy_bullet_x2[i];
        bullet_y = current_ship_xy.enemy_bullet_y2[i];

        if (game_map[bullet_y][bullet_x] == Enemy_Bullet2 && game_map[bullet_y + 1][bullet_x] == AIR)
        {
            temp = game_map[bullet_y][bullet_x];
            game_map[bullet_y][bullet_x] = AIR;
            game_map[bullet_y + 1][bullet_x] = temp;
        }
    }
}
