/**
\file        Boss_Bullet_Move.cpp
\author      jeesoo.kim
\brief
This file moves the bullet shot by the boss character.

copyright   All content ?2018 DigiPen (USA) Corporation, all rights reserved
*/

#include "Boss_Bullet_Move.h"
#include "MapStatus.h"
#include "Enemy_Part.h"
#include "Ship_Status.h"

void Boss_Bullet_2_Move(Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status)
{
    int x = 0, y = 0, temp = 0;

    for (int i = 0; i < current_map_status.count_boss_bullet_2; i++)
    {
        x = current_ship_xy.boss_bullet_2_x[i];
        y = current_ship_xy.boss_bullet_2_y[i];

        if (y == BOSS_BULLET_SECOND_MOVE_ENOUGH)
        {
            game_map[y][x] = AIR;

        }
        temp = game_map[y][x];
        game_map[y][x] = AIR;
        game_map[y + 1][x] = temp;
    }
}

void Boss_phase_2_bullet_move(Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status)
{
    int x = 0, y = 0;
    int temp = 0;

    for (int i = 0; i < current_map_status.count_particle_manager; i++)
    {
        x = current_ship_xy.particle_manager_x[i];
        y = current_ship_xy.particle_manager_y[i];

        if (game_map[y][x] == Ship_Die_Manager)
        {
            if (y == BOSS_PHASE_2_BULLET_MOVE_ENOUGH)
            {
                game_map[y][x] = Bomb_Particle1;
            }
            temp = game_map[y][x];
            game_map[y][x] = Ship_Die1;
            game_map[y + 1][x] = temp;
        }

    }

}