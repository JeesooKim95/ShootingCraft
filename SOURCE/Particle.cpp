/**
\file        Particle.cpp
\author      hyun.gang
\par         email: hangam131313@gmail.com
\brief
This will manage the particle effects in elements.

copyright   All content ?2018 DigiPen (USA) Corporation, all rights reserved

*/
#include "MapStatus.h"
#include "Ship_Status.h"
#include "Enemy_Part.h"
#include "Particle.h"

void Particle_Ship(Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status)
{
    int x, y;

    for (int i = 0; i < current_map_status.count_ship_particle; i++)
    {
        x = current_ship_xy.ship_particle_x[i];
        y = current_ship_xy.ship_particle_y[i];

        if (game_map[y][x] == Ship_Die1)
        {
            game_map[y][x] = Ship_Die2;

        }
        else if (game_map[y][x] == Ship_Die2)
        {
            game_map[y][x] = Ship_Die3;

        }
        else if (game_map[y][x] == Ship_Die3)
        {
            game_map[y][x] = Ship_Die4;

        }
        else if (game_map[y][x] == Ship_Die4)
        {
            game_map[y][x] = Ship_Die5;

        }
        else if (game_map[y][x] == Ship_Die5)
        {
            game_map[y][x] = AIR;

        }
    }


}

void Bomb_Particle(Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status)
{
    int x, y;
    int bomb_range = 1;
    for (int i = 0; i < current_map_status.count_bome_particle; i++)
    {
        x = current_ship_xy.bomb_particle_x[i];
        y = current_ship_xy.bomb_particle_y[i];

        if (game_map[y][x] == Bomb_Particle1)
        {
            for (int i = y - bomb_range; i <= y + bomb_range; i++)
            {
                for (int j = x - bomb_range; j <= x + bomb_range; j++)
                {
                    if (i == y && j == x)
                    {
                        game_map[i][j] = Bomb_Particle2;
                        continue;
                    }
                    if (game_map[i][j] <= Body && game_map[i][j] >= Body - 2)
                    {
                        game_map[i][j] -= 1;
                        if (game_map[i][j] < Body - 2)
                        {
                            game_map[i][j] = AIR;
                        }
                        continue;

                    }
                    if (game_map[i][j] <= Head && game_map[i][j] >= Head - 2)
                    {
                        game_map[i][j] -= 1;
                        if (game_map[i][j] < Head - 2)
                        {
                            game_map[i][j] = AIR;
                        }
                        continue;

                    }
                    if (game_map[i][j] <= Weapon && game_map[i][j] >= Weapon - 2)
                    {
                        game_map[i][j] -= 1;
                        if (game_map[i][j] < Weapon - 2)
                        {
                            game_map[i][j] = AIR;
                        }
                        continue;

                    }
                    if (game_map[i][j] != AIR)
                    {
                        continue;
                    }
                    game_map[i][j] = Ship_Die1;
                }

            }

        }
        else if (game_map[y][x] == Bomb_Particle2)
        {
            bomb_range = 2;
            for (int i = y - bomb_range; i <= y + bomb_range; i++)
            {
                for (int j = x - bomb_range; j <= x + bomb_range; j++)
                {
                    if (i == y && j == x)
                    {
                        game_map[i][j] = Bomb_Particle3;
                        continue;
                    }
                    if (game_map[i][j] <= Body && game_map[i][j] >= Body - 2)
                    {
                        game_map[i][j] -= 1;
                        if (game_map[i][j] < Body - 2)
                        {
                            game_map[i][j] = AIR;
                        }
                        continue;

                    }
                    if (game_map[i][j] <= Head && game_map[i][j] >= Head - 2)
                    {
                        game_map[i][j] -= 1;
                        if (game_map[i][j] < Head - 2)
                        {
                            game_map[i][j] = AIR;
                        }
                        continue;

                    }
                    if (game_map[i][j] <= Weapon && game_map[i][j] >= Weapon - 2)
                    {
                        game_map[i][j] -= 1;
                        if (game_map[i][j] < Weapon - 2)
                        {
                            game_map[i][j] = AIR;
                        }
                        continue;

                    }
                    if (game_map[i][j] != AIR)
                    {
                        continue;
                    }
                    game_map[i][j] = Ship_Die1;
                }

            }

        }
        else if (game_map[y][x] == Bomb_Particle3)
        {
            bomb_range = 3;
            for (int i = y - bomb_range; i <= y + bomb_range; i++)
            {
                for (int j = x - bomb_range; j <= x + bomb_range; j++)
                {
                    if (i == y && j == x)
                    {
                        game_map[i][j] = Bomb_Particle4;
                        continue;
                    }
                    if (game_map[i][j] <= Body && game_map[i][j] >= Body - 2)
                    {
                        game_map[i][j] -= 1;
                        if (game_map[i][j] < Body - 2)
                        {
                            game_map[i][j] = AIR;
                        }
                        continue;

                    }
                    if (game_map[i][j] <= Head && game_map[i][j] >= Head - 2)
                    {
                        game_map[i][j] -= 1;
                        if (game_map[i][j] < Head - 2)
                        {
                            game_map[i][j] = AIR;
                        }
                        continue;

                    }
                    if (game_map[i][j] <= Weapon && game_map[i][j] >= Weapon - 2)
                    {
                        game_map[i][j] -= 1;
                        if (game_map[i][j] < Weapon - 2)
                        {
                            game_map[i][j] = AIR;
                        }
                        continue;

                    }
                    if (game_map[i][j] != AIR)
                    {
                        continue;
                    }

                    game_map[i][j] = Ship_Die1;

                }

            }

        }
        else if (game_map[y][x] == Bomb_Particle4)
        {
            game_map[y][x] = AIR;
        }

    }

}