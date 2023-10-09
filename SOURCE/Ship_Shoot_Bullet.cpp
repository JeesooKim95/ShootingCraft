/**
\file        Ship_Shoot_Bullet.cpp
\author      hyun.gang
\par         email: hangam131313@gmail.com
\brief
This file will make bullet in the array by user's input.

copyright   All content ?2018 DigiPen (USA) Corporation, all rights reserved
*/

#include "Ship_Shoot_Bullet.h"
#include "Enemy_Part.h"

void Shoot_Bullet(Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status)
{
    int x = 0, y = 0;
    int bullet_init_pos = 0;
    int highest_y = current_ship_xy.whole_ship_y[0];

    for (int i = 0; i < current_map_status.count_whole_ship; i++)
    {
        if (highest_y > current_ship_xy.whole_ship_y[i])
        {
            highest_y = current_ship_xy.whole_ship_y[i];

        }
    }
    if (current_map_status.count_ship_weapon == 0)
    {
        x = current_ship_xy.head_ship_x[0];
        y = current_ship_xy.head_ship_y[0];

        game_map[highest_y - 1][x] = Bullet;
    }

    if (current_map_status.count_ship_weapon != 0)
    {
        for (int i = 0; i < current_map_status.count_ship_weapon; i++)
        {
            x = current_ship_xy.weapon_ship_x[i];
            y = current_ship_xy.weapon_ship_y[i];

            if (game_map[highest_y - 1][x] == AIR)
            {
                game_map[highest_y - 1][x] = Bullet;
            }
            else if (game_map[y - 1][x] == Body || game_map[y - 1][x] == Head || game_map[y - 1][x] == Weapon
                || game_map[y - 1][x] == Body - 1 || game_map[y - 1][x] == Head - 1 || game_map[y - 1][x] == Weapon - 1
                || game_map[y - 1][x] == Body - 2 || game_map[y - 1][x] == Head - 2 || game_map[y - 1][x] == Weapon - 2)
            {


                while (game_map[highest_y - bullet_init_pos - 1][x] != AIR)
                {
                    bullet_init_pos++;

                    if (game_map[highest_y - bullet_init_pos - 1][x] == AIR)
                    {
                        break;
                    }
                }
                game_map[highest_y - bullet_init_pos - 1][x] = Bullet;

            }
        }
    }

}

void Enemy_Shoot_Bullet(Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_statue)
{
    int x, y;


    for (int i = 0; i < current_map_statue.count_enemy_weapon; i++)
    {
        x = current_ship_xy.enemy_weapon_x[i];
        y = current_ship_xy.enemy_weapon_y[i];
        if (game_map[y + 1][x] == AIR && game_map[y + 2][x] == AIR)
        {
            game_map[y + 2][x] = Enemy_Bullet;
        }
    }
    /*for (int i = 0; i < current_map_statue.count_enemy_weapon2; i++)
    {
            x = current_ship_xy.enemy_weapon_x2[i];
            y = current_ship_xy.enemy_weapon_y2[i];

            if (game_map[y + 1][x] == AIR && game_map[y + 2][x] == AIR)
            {
                    game_map[y + 2][x] = Enemy_Bullet;
            }
    }*/


}

void Enemy_Shoot_Bullet2(Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_statue)
{

    int x, y;


    for (int i = 0; i < current_map_statue.count_all_enemy_weapon2; i++)
    {
        x = current_ship_xy.all_enemy_weapon_x2[i];
        y = current_ship_xy.all_enemy_weapon_y2[i];

        if (game_map[y + 1][x] == AIR && game_map[y + 2][x] == AIR)
        {
            game_map[y + 2][x] = Enemy_Bullet2;
        }

    }
}

void Enemy_Shoot_Bullet3(Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_statue)
{
    int x, y;


    for (int i = 0; i < current_map_statue.count_enemy_weapon; i++)
    {
        x = current_ship_xy.enemy_weapon_x[i];
        y = current_ship_xy.enemy_weapon_y[i];
        if (game_map[y + 1][x] == AIR && game_map[y + 2][x] == AIR && y == Enemy_Arr1_Shoot_Range)
        {
            game_map[y + 2][x] = Enemy_Bullet2;
        }
    }

}

void Enemy_Shoot_Bullet4(Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_statue)
{
    int x, y;


    for (int i = 0; i < current_map_statue.count_enemy_weapon2; i++)
    {
        x = current_ship_xy.enemy_weapon_x2[i];
        y = current_ship_xy.enemy_weapon_y2[i];
        if (game_map[y + 1][x] == AIR && game_map[y + 2][x] == AIR && y == Enemy_Arr1_Shoot_Range - 5)
        {
            game_map[y + 2][x] = Enemy_Bullet2;
        }
    }

}