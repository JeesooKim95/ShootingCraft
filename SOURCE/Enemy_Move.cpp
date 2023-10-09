/**
\file        Enemy_Move.cpp
\author      jeesoo.kim
\brief
This file moves the enemy elements in to an array.

copyright   All content ?2018 DigiPen (USA) Corporation, all rights reserved

*/


#include "Enemy_Move.h"
#include "MapStatus.h"
#include "Ship_Status.h"
#include "Enemy_Part.h"
#include "stdlib.h"
#include "time.h"

void Enemy_Move(Game_Map game_map, XY_Position_Ship* current_ship_xy, Map_Status_Count current_map_status)
{
    int x = 0, y = 0;
    int end_x = 0, end_y = 0;
    int temp = 0;
    int rand_move = 0;
    int over_x = 0, over_y = 0;
    int over_temp = 0;

    rand_move = rand() % 2;

    for (int i = 0, a = current_map_status.count_all_enemy - 1; i < current_map_status.count_all_enemy && a >= 0; i++, a--)
    {
        x = current_ship_xy->all_enemy_x[i];
        y = current_ship_xy->all_enemy_y[i];

        end_x = current_ship_xy->all_enemy_x[a];
        end_y = current_ship_xy->all_enemy_y[a];

        over_x = current_ship_xy->overlap_x[i];
        over_y = current_ship_xy->overlap_y[i];

        over_temp = current_ship_xy->overlap[i];

        if (rand_move == 0)
        {
            if ((over_temp <= Enemy_Body_Left && over_temp >= Enemy_Body_Left - 2) ||
                (over_temp <= Enemy_Body_Right && over_temp >= Enemy_Body_Right - 2) ||
                (over_temp <= Enemy_Head && over_temp >= Enemy_Head - 2) ||
                (over_temp <= Enemy_Weapon && over_temp >= Enemy_Weapon - 2))
            {
                current_ship_xy->overlap_x[i] += 1;

            }
            if ((over_temp <= Enemy_Body_Left2 && over_temp >= Enemy_Body_Left2 - 2) ||
                (over_temp <= Enemy_Body_Right2 && over_temp >= Enemy_Body_Right2 - 2) ||
                (over_temp <= Enemy_Head2 && over_temp >= Enemy_Head2 - 2) ||
                (over_temp <= Enemy_Weapon2 && over_temp >= Enemy_Weapon2 - 2))
            {
                current_ship_xy->overlap_x[i] -= 1;

            }

            if ((game_map[end_y][end_x] <= Enemy_Body_Left && game_map[end_y][end_x] >= Enemy_Body_Left - 2)
                || (game_map[end_y][end_x] <= Enemy_Body_Right && game_map[end_y][end_x] >= Enemy_Body_Right - 2)
                || (game_map[end_y][end_x] <= Enemy_Head && game_map[end_y][end_x] >= Enemy_Head - 2)
                || (game_map[end_y][end_x] <= Enemy_Weapon && game_map[end_y][end_x] >= Enemy_Weapon - 2))
            {
                if ((game_map[end_y][end_x + 1] <= Head && game_map[end_y][end_x + 1] >= Head - 2) ||
                    (game_map[end_y][end_x + 1] <= Body && game_map[end_y][end_x + 1] >= Body - 2) ||
                    (game_map[end_y][end_x + 1] <= Weapon && game_map[end_y][end_x + 1] >= Weapon - 2))
                {
                    game_map[end_y][end_x + 1] -= 1;
                    game_map[end_y][end_x] = AIR;
                }
                temp = game_map[end_y][end_x];
                game_map[end_y][end_x] = AIR;
                game_map[end_y][end_x + 1] = temp;

            }


            if ((game_map[y][x] <= Enemy_Body_Left2 && game_map[y][x] >= Enemy_Body_Left2 - 2)
                || (game_map[y][x] <= Enemy_Body_Right2 && game_map[y][x] >= Enemy_Body_Right2 - 2)
                || (game_map[y][x] <= Enemy_Head2 && game_map[y][x] >= Enemy_Head2 - 2)
                || (game_map[y][x] <= Enemy_Weapon2 && game_map[y][x] >= Enemy_Weapon2 - 2))
            {
                if ((game_map[y][x - 1] <= Head && game_map[y][x - 1] >= Head - 2) ||
                    (game_map[y][x - 1] <= Body && game_map[y][x - 1] >= Body - 2) ||
                    (game_map[y][x - 1] <= Weapon && game_map[y][x - 1] >= Weapon - 2))
                {
                    game_map[y][x - 1] -= 1;
                    game_map[y][x] = AIR;
                }
                temp = game_map[y][x];
                game_map[y][x] = AIR;
                game_map[y][x - 1] = temp;

            }

        }
        else if (rand_move == 1)
        {
            if ((over_temp <= Enemy_Body_Left && over_temp >= Enemy_Body_Left - 2) ||
                (over_temp <= Enemy_Body_Right && over_temp >= Enemy_Body_Right - 2) ||
                (over_temp <= Enemy_Head && over_temp >= Enemy_Head - 2) ||
                (over_temp <= Enemy_Weapon && over_temp >= Enemy_Weapon - 2))
            {
                current_ship_xy->overlap_y[i] += 1;

            }
            if ((over_temp <= Enemy_Body_Left2 && over_temp >= Enemy_Body_Left2 - 2) ||
                (over_temp <= Enemy_Body_Right2 && over_temp >= Enemy_Body_Right2 - 2) ||
                (over_temp <= Enemy_Head2 && over_temp >= Enemy_Head2 - 2) ||
                (over_temp <= Enemy_Weapon2 && over_temp >= Enemy_Weapon2 - 2))
            {
                current_ship_xy->overlap_y[i] += 1;

            }

            if ((game_map[end_y][end_x] <= Enemy_Body_Left && game_map[end_y][end_x] >= Enemy_Body_Left - 2)
                || (game_map[end_y][end_x] <= Enemy_Body_Right && game_map[end_y][end_x] >= Enemy_Body_Right - 2)
                || (game_map[end_y][end_x] <= Enemy_Head && game_map[end_y][end_x] >= Enemy_Head - 2)
                || (game_map[end_y][end_x] <= Enemy_Weapon && game_map[end_y][end_x] >= Enemy_Weapon - 2))
            {

                if ((game_map[end_y + 1][end_x] <= Head && game_map[end_y + 1][end_x] >= Head - 2) ||
                    (game_map[end_y + 1][end_x] <= Body && game_map[end_y + 1][end_x] >= Body - 2) ||
                    (game_map[end_y + 1][end_x] <= Weapon && game_map[end_y + 1][end_x] >= Weapon - 2))
                {
                    game_map[end_y + 1][end_x] -= 1;
                    game_map[end_y][end_x] = AIR;
                }
                temp = game_map[end_y][end_x];
                game_map[end_y][end_x] = AIR;
                game_map[end_y + 1][end_x] = temp;

            }
            if ((game_map[end_y][end_x] <= Enemy_Body_Left2 && game_map[end_y][end_x] >= Enemy_Body_Left2 - 2)
                || (game_map[end_y][end_x] <= Enemy_Body_Right2 && game_map[end_y][end_x] >= Enemy_Body_Right2 - 2)
                || (game_map[end_y][end_x] <= Enemy_Head2 && game_map[end_y][end_x] >= Enemy_Head2 - 2)
                || (game_map[end_y][end_x] <= Enemy_Weapon2 && game_map[end_y][end_x] >= Enemy_Weapon2 - 2))
            {
                if ((game_map[end_y + 1][end_x] <= Head && game_map[end_y + 1][end_x] >= Head - 2) ||
                    (game_map[end_y + 1][end_x] <= Body && game_map[end_y + 1][end_x] >= Body - 2) ||
                    (game_map[end_y + 1][end_x] <= Weapon && game_map[end_y + 1][end_x] >= Weapon - 2))
                {
                    game_map[end_y + 1][end_x] -= 1;
                    game_map[end_y][end_x] = AIR;
                }
                temp = game_map[end_y][end_x];
                game_map[end_y][end_x] = AIR;
                game_map[end_y + 1][end_x] = temp;

            }

        }
    }
}
void Enemy_Move2(Game_Map game_map, XY_Position_Ship* current_ship_xy, Map_Status_Count current_map_status)
{
    int x = 0, y = 0;
    int temp = 0;
    int end_x = 0, end_y = 0;

    for (int i = 0, a = current_map_status.count_all_enemy - 1; i < current_map_status.count_all_enemy && a >= 0; i++, a--)
    {
        x = current_ship_xy->all_enemy_x[i];
        y = current_ship_xy->all_enemy_y[i];

        end_x = current_ship_xy->all_enemy_x[a];
        end_y = current_ship_xy->all_enemy_y[a];


        if ((game_map[end_y][end_x] <= Enemy_Body_Left3 && game_map[end_y][end_x] >= Enemy_Body_Left3 - 2)
            || (game_map[end_y][end_x] <= Enemy_Body_Right3 && game_map[end_y][end_x] >= Enemy_Body_Right3 - 2)
            || (game_map[end_y][end_x] <= Enemy_Head3 && game_map[end_y][end_x] >= Enemy_Head3 - 2)
            || (game_map[end_y][end_x] <= Enemy_Weapon3 && game_map[end_y][end_x] >= Enemy_Weapon3 - 2))
        {
            if ((game_map[end_y][end_x + 1] <= Head && game_map[end_y][end_x + 1] >= Head - 2) ||
                (game_map[end_y][end_x + 1] <= Body && game_map[end_y][end_x + 1] >= Body - 2) ||
                (game_map[end_y][end_x + 1] <= Weapon && game_map[end_y][end_x + 1] >= Weapon - 2))
            {
                game_map[end_y][end_x + 1] -= 1;
                game_map[end_y][end_x] = AIR;
            }
            temp = game_map[end_y][end_x];
            game_map[end_y][end_x] = AIR;
            game_map[end_y][end_x + 1] = temp;

        }
        if ((game_map[y][x] <= Enemy_Body_Left4 && game_map[y][x] >= Enemy_Body_Left4 - 2)
            || (game_map[y][x] <= Enemy_Body_Right4 && game_map[y][x] >= Enemy_Body_Right4 - 2)
            || (game_map[y][x] <= Enemy_Head4 && game_map[y][x] >= Enemy_Head4 - 2)
            || (game_map[y][x] <= Enemy_Weapon4 && game_map[y][x] >= Enemy_Weapon4 - 2))
        {
            if ((game_map[y][x - 1] <= Head && game_map[y][x - 1] >= Head - 2) ||
                (game_map[y][x - 1] <= Body && game_map[y][x - 1] >= Body - 2) ||
                (game_map[y][x - 1] <= Weapon && game_map[y][x - 1] >= Weapon - 2))
            {
                game_map[y][x - 1] -= 1;
                game_map[y][x] = AIR;
            }
            temp = game_map[y][x];
            game_map[y][x] = AIR;
            game_map[y][x - 1] = temp;

        }


    }

}

void Phase3_Enemy_Move(Game_Map game_map, XY_Position_Ship* current_ship_xy, Map_Status_Count current_map_status, int player_pos)
{
    int x = 0, y = 0;
    int temp = 0;
    int end_x = 0, end_y = 0;
    int part_x = 0, part_y = 0;

    for (int i = 0, a = current_map_status.count_all_enemy - 1; i < current_map_status.count_all_enemy && a >= 0; i++, a--)
    {
        x = current_ship_xy->all_enemy_x[i];
        y = current_ship_xy->all_enemy_y[i];

        end_x = current_ship_xy->all_enemy_x[a];
        end_y = current_ship_xy->all_enemy_y[a];

        if ((game_map[end_y][end_x] <= Enemy_Body_Left3 && game_map[end_y][end_x] >= Enemy_Body_Left3 - 2)
            && (end_y < 6))
        {
            temp = game_map[end_y][end_x];
            game_map[end_y][end_x] = AIR;
            game_map[end_y + 1][end_x] = temp;

        }
        if ((game_map[end_y][end_x] <= Enemy_Body_Right3 && game_map[end_y][end_x] >= Enemy_Body_Right3 - 2)
            && (end_y < 6))
        {
            temp = game_map[end_y][end_x];
            game_map[end_y][end_x] = AIR;
            game_map[end_y + 1][end_x] = temp;

        }
        if ((game_map[end_y][end_x] <= Enemy_Head3 && game_map[end_y][end_x] >= Enemy_Head3 - 2)
            && (end_y < 6))
        {
            temp = game_map[end_y][end_x];
            game_map[end_y][end_x] = AIR;
            game_map[end_y + 1][end_x] = temp;

        }
        if ((game_map[end_y][end_x] <= Enemy_Weapon3 && game_map[end_y][end_x] >= Enemy_Weapon3 - 2)
            && (end_y < 7))
        {
            temp = game_map[end_y][end_x];
            game_map[end_y][end_x] = AIR;
            game_map[end_y + 1][end_x] = temp;

        }

    }
    for (int i = 0; i < current_map_status.count_particle_manager; i++)
    {
        part_x = current_ship_xy->particle_manager_x[i];
        part_y = current_ship_xy->particle_manager_y[i];

        if (game_map[part_y][part_x] == Ship_Die_Manager)
        {
            if (part_y == player_pos)
            {
                game_map[part_y][part_x] = Bomb_Particle1;
            }
            temp = game_map[part_y][part_x];
            game_map[part_y][part_x] = Ship_Die1;
            game_map[part_y + 1][part_x] = temp;

        }
    }

}
