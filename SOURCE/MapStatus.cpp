/**
\file        MapStatus.cpp
\author     Chulseung Lee
\brief
                This will initialize both ship_map, game_map basic.
                Initialize_ShipMap : set ship_map's each side with decimal value. else fill with air.
                Initialize_GameMap : set game_map's each side with WALL, else fill with air.

                copyright   All content ?2018 DigiPen (USA) Corporation, all rights reserved
*/


#include "stdio.h"
#include "stdlib.h"
#include "MapStatus.h"

void Initialize_ShipMap(Ship_Map ship_map)
{
    for (int i = 0; i < SHIP_LOW; i++)
    {
        for (int j = 0; j < SHIP_COL; j++)
        {
            if (i == 0)
            {
                ship_map[i][j] = WALL;
            }
            else if (i == SHIP_LOW - 1)
            {
                ship_map[i][j] = WALL;
            }
            else if (j == 0)
            {
                ship_map[i][j] = WALL;
            }
            else if (j == SHIP_COL - 1)
            {
                ship_map[i][j] = WALL;
            }
            else
                ship_map[i][j] = AIR;
        }
    }
}

void Initialize_GameMap(Game_Map game_map)
{
    for (int i = 0; i < LOW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if (j == 0)
            {
                game_map[i][j] = WALL;
            }
            else if (j == COL - 1)
            {
                game_map[i][j] = WALL;
            }
            else if (i == LOW - 2)
            {
                game_map[i][j] = WALL;

            }
            else
                game_map[i][j] = AIR;

        }

    }

}

void Initialize_GameMap_IF_WALL_IS_ERASED(Game_Map game_map)
{
    for (int i = 0; i < LOW; i++)
    {
        if (game_map[i][0] == AIR)
        {
            game_map[i][0] = WALL;
        }
        else if (game_map[i][COL - 1] == AIR)
        {
            game_map[i][COL - 1] = WALL;
        }
    }
    for (int j = 0; j < COL; j++)
    {
        if (game_map[LOW - 2][j] == AIR)
        {
            game_map[LOW - 2][j] = WALL;
        }

    }

}

void Initialize_Status_Board(Status_Board status_board)
{
    for (int i = 0; i < STATUS_BOARD_LOW; i++)
    {
        for (int j = 0; j < STATUS_BOARD_COL; j++)
        {
            if (i == 3)
            {
                status_board[i][j] = WALL;
            }
            else if (i == STATUS_BOARD_LOW - 1)
            {
                status_board[i][j] = WALL;
            }
            else if (j == 0)
            {
                status_board[i][j] = WALL;
            }
            else if (j == STATUS_BOARD_COL - 1)
            {
                status_board[i][j] = WALL;
            }
            else
                status_board[i][j] = AIR;

        }

    }

}