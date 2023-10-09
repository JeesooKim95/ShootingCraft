/**
\file        Bomb.cpp
\author      sangmin.kim
\par         email: ryan95kr@gmail.com
\brief
This will manage the player's bomb.

copyright   All content © 2018 DigiPen (USA) Corporation, all rights reserved
*/


#include "Bomb.h"
#include "Ship_Status.h"
#include "MapStatus.h"
#include "Sound_Manager.h"

int range = 10;

void Bomb_Move(Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status)
{
    int x, y;
    int temp;

    for (int i = 0; i < current_map_status.user_bomb_count; i++)
    {
        x = current_ship_xy.user_bomb_x[i];
        y = current_ship_xy.user_bomb_y[i];

        if (game_map[y][x] == Bomb)
        {
            if (range != 0)
            {
                temp = game_map[y][x];
                game_map[y][x] = AIR;
                game_map[y - 1][x] = temp;

                range--;
            }
            else if (range == 0)
            {
                game_map[y][x] = User_Bomb_Particle1;
                range = 10;

            }
        }
    }

}

void User_Particle_Bomb(Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status)
{
    int x, y;

    for (int i = 0; i < current_map_status.user_bomb_particle_count; i++)
    {
        x = current_ship_xy.user_bomb_particle_x[i];
        y = current_ship_xy.user_bomb_particle_y[i];

        if (game_map[y][x] == Bomb_Effect1)
        {
            game_map[y][x] = Bomb_Effect2;

        }
        else if (game_map[y][x] == Bomb_Effect2)
        {
            game_map[y][x] = Bomb_Effect3;

        }
        else if (game_map[y][x] == Bomb_Effect3)
        {
            game_map[y][x] = Bomb_Effect4;

        }
        else if (game_map[y][x] == Bomb_Effect4)
        {
            game_map[y][x] = Bomb_Effect5;

        }
        else if (game_map[y][x] == Bomb_Effect5)
        {
            game_map[y][x] = AIR;

        }
    }


}
void Set_Bomb(Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status)
{
    int x, y;

    for (int i = 0; i < current_map_status.bomb_ready_count; i++)
    {
        x = current_ship_xy.bomb_ready_x[i];
        y = current_ship_xy.bomb_ready_y[i];

        if (game_map[y][x] == Bomb_Ready)
        {
            game_map[y][x] = User_Bomb_Particle1;
        }

    }

}


void Shoot_Bomb(Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status)
{
    int x, y;
    int a = 0;
    x = current_ship_xy.head_ship_x[0];
    y = current_ship_xy.head_ship_y[0];

    //game_map[y - 1][x] = Bomb;
    if (game_map[y - a][x] == Head || game_map[y - a][x] == Body || game_map[y - a][x] == Weapon)
    {
        //while (game_map[y - a][x] != Head || game_map[y - a][x] != Body || game_map[y - a][x] != Weapon)
        while (game_map[y - a][x] != AIR)
        {
            a++;
            if (game_map[y - a][x] == AIR)
                break;
        }
        game_map[y - a][x] = Bomb;
    }

    Sound::play(5);
}

void User_Bomb_Particle(Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status)
{
    int x, y;
    int range = 1;
    for (int i = 0; i < current_map_status.user_bomb_particle_count; i++)
    {
        x = current_ship_xy.user_bomb_particle_x[i];
        y = current_ship_xy.user_bomb_particle_y[i];



        if (game_map[y][x] == User_Bomb_Particle1)
        {
            for (int i = y - range; i <= y + range; i++)
            {
                for (int j = x - range; j <= x + range; j++)
                {
                    if (i == y && j == x)
                    {
                        game_map[i][j] = User_Bomb_Particle2;
                        continue;
                    }

                    game_map[i][j] = Bomb_Effect1;

                }

            }

        }
        else if (game_map[y][x] == User_Bomb_Particle2)
        {
            range = 2;
            for (int i = y - range; i <= y + range; i++)
            {
                for (int j = x - range; j <= x + range; j++)
                {
                    if (i == y && j == x)
                    {
                        game_map[i][j] = User_Bomb_Particle3;
                        continue;
                    }

                    game_map[i][j] = Bomb_Effect1;

                }

            }

        }
        else if (game_map[y][x] == User_Bomb_Particle3)
        {
            range = 3;
            for (int i = y - range; i <= y + range; i++)
            {
                for (int j = x - range; j <= x + range; j++)
                {
                    if (i == y && j == x)
                    {
                        game_map[i][j] = User_Bomb_Particle4;
                        continue;
                    }

                    game_map[i][j] = Bomb_Effect1;

                }

            }

        }
        else if (game_map[y][x] == User_Bomb_Particle4)
        {
            range = 4;
            for (int i = y - range; i <= y + range; i++)
            {
                for (int j = x - range; j <= x + range; j++)
                {
                    if (i == y && j == x)
                    {
                        game_map[i][j] = User_Bomb_Particle5;
                        continue;
                    }

                    game_map[i][j] = Bomb_Effect1;

                }

            }

        }
        else if (game_map[y][x] == User_Bomb_Particle5)
        {
            range = 5;
            for (int i = y - range; i <= y + range; i++)
            {
                for (int j = x - range; j <= x + range; j++)
                {
                    if (i == y && j == x)
                    {
                        game_map[i][j] = User_Bomb_Particle6;
                        continue;
                    }

                    game_map[i][j] = Bomb_Effect1;

                }

            }

        }
        else if (game_map[y][x] == User_Bomb_Particle6)
        {
            game_map[y][x] = AIR;
        }

    }

}