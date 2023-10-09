/**
\file        Apply_Two_Map.cpp
\author      sangmin.kim
\par         email: ryan95kr@gmail.com
\brief
        Since we have two different size of array(Ship_Map, Game_Map)
        After initializing the ship_map(ship), for apply to game_map, use this statement.

        copyright   All content ?2018 DigiPen (USA) Corporation, all rights reserved
*/

#include "Apply_Two_Map.h"
#include "windows.h"
#include "Ship_Status.h"
#include "MapStatus.h"

void ShipMap_To_GameMap(Ship_Map ship_map, Game_Map game_map)
{

    game_map[(LOW / 2) + FIRST_SHIP_INIT_BODY_Y][COL / 2] = Body;
    game_map[(LOW / 2) + FIRST_SHIP_INIT_HEAD_Y][COL / 2] = Head;
    game_map[(LOW / 2) + FIRST_SHIP_INIT_WEAPON_Y][COL / 2] = Weapon;
    system("cls");

}

void Hack_ShipMap_To_GameMap(Ship_Map ship_map, Game_Map game_map)
{
    game_map[(LOW / 2) + FIRST_SHIP_INIT_BODY_Y][COL / 2] = Body;
    game_map[(LOW / 2) + FIRST_SHIP_INIT_HEAD_Y][COL / 2] = Head;
    game_map[(LOW / 2) + FIRST_SHIP_INIT_WEAPON_Y][COL / 2] = Weapon;
    game_map[(LOW / 2) + HACK_SHIP_WEAPON_INIT_2][COL / 2] = Weapon;
    game_map[(LOW / 2) + HACK_SHIP_WEAPON_INIT_1][COL / 2 + 1] = Weapon;
    game_map[(LOW / 2) + HACK_SHIP_WEAPON_INIT_1][COL / 2 + 2] = Weapon;
    game_map[(LOW / 2) + HACK_SHIP_WEAPON_INIT_1][COL / 2 - 1] = Weapon;
    game_map[(LOW / 2) + HACK_SHIP_WEAPON_INIT_1][COL / 2 - 2] = Weapon;
    game_map[(LOW / 2) + HACK_SHIP_WEAPON_INIT_2][COL / 2 + 1] = Weapon;
    game_map[(LOW / 2) + HACK_SHIP_WEAPON_INIT_2][COL / 2 + 2] = Weapon;
    game_map[(LOW / 2) + HACK_SHIP_WEAPON_INIT_2][COL / 2 - 1] = Weapon;
    game_map[(LOW / 2) + HACK_SHIP_WEAPON_INIT_2][COL / 2 - 2] = Weapon;

    game_map[(LOW / 2) + HACK_SHIP_BODY_INIT_1][COL / 2 + 1] = Body;
    game_map[(LOW / 2) + HACK_SHIP_BODY_INIT_1][COL / 2 + 2] = Body;
    game_map[(LOW / 2) + HACK_SHIP_BODY_INIT_1][COL / 2 - 1] = Body;
    game_map[(LOW / 2) + HACK_SHIP_BODY_INIT_1][COL / 2 - 2] = Body;
    game_map[(LOW / 2) + HACK_SHIP_BODY_INIT_2][COL / 2] = Body;
    game_map[(LOW / 2) + HACK_SHIP_BODY_INIT_2][COL / 2 - 1] = Body;
    game_map[(LOW / 2) + HACK_SHIP_BODY_INIT_2][COL / 2 + 1] = Body;
    game_map[(LOW / 2) + HACK_SHIP_BODY_INIT_2][COL / 2 - 2] = Body;
    game_map[(LOW / 2) + HACK_SHIP_BODY_INIT_2][COL / 2 + 2] = Body;

    system("cls");

}
void Save_Position_Ship_in_Ship_Map(Ship_Map ship_map, Game_Map game_map, XY_Position_Ship *current_ship_xy, Map_Status_Count* current_map_status)
{
    int ship_int = 0;

    for (int i = 0; i < SHIP_LOW; i++)
    {
        for (int j = 0; j < SHIP_COL; j++)
        {
            if (ship_map[i][j] == Body || ship_map[i][j] == Body - 1 || ship_map[i][j] == Body - 2 ||
                ship_map[i][j] == Head || ship_map[i][j] == Head - 1 || ship_map[i][j] == Head - 2 ||
                ship_map[i][j] == Weapon || ship_map[i][j] == Weapon - 1 || ship_map[i][j] == Weapon - 2)
            {
                current_ship_xy->whole_ship_x_ship_map[ship_int] = j;
                current_ship_xy->whole_ship_y_ship_map[ship_int] = i;
                ship_int++;

            }

        }

    }
    current_map_status->count_whole_ship = ship_int;
}

void ShipMap_To_GameMap2(Ship_Map ship_map, Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status)
{

    int leftest_x = current_ship_xy.whole_ship_x[0];
    int rightest_x = current_ship_xy.whole_ship_x[0];
    int upest_y = current_ship_xy.whole_ship_y[0];

    int leftest_x_ship_world = current_ship_xy.whole_ship_x_ship_map[0];
    int rightest_x_ship_world = current_ship_xy.whole_ship_x_ship_map[0];
    int upest_y_ship_world = current_ship_xy.whole_ship_y_ship_map[0];
    int downest_y_ship_world = current_ship_xy.whole_ship_y_ship_map[0];

    for (int i = 0; i < current_map_status.count_whole_ship; i++)
    {
        if (leftest_x >= current_ship_xy.whole_ship_x[i] && current_ship_xy.whole_ship_x[i] != 0)
        {
            leftest_x = current_ship_xy.whole_ship_x[i];
        }
        if (rightest_x <= current_ship_xy.whole_ship_x[i] && current_ship_xy.whole_ship_x[i] != 0)
        {
            rightest_x = current_ship_xy.whole_ship_x[i];
        }

        if (upest_y >= current_ship_xy.whole_ship_y[i] && current_ship_xy.whole_ship_y[i] != 0)
        {
            upest_y = current_ship_xy.whole_ship_y[i];
        }
        if (leftest_x_ship_world > current_ship_xy.whole_ship_x_ship_map[i])
        {
            leftest_x_ship_world = current_ship_xy.whole_ship_x_ship_map[i];
        }
        if (rightest_x_ship_world < current_ship_xy.whole_ship_x_ship_map[i])
        {
            rightest_x_ship_world = current_ship_xy.whole_ship_x_ship_map[i];
        }
        if (upest_y_ship_world > current_ship_xy.whole_ship_y_ship_map[i])
        {
            upest_y_ship_world = current_ship_xy.whole_ship_y_ship_map[i];
        }
        if (downest_y_ship_world < current_ship_xy.whole_ship_y_ship_map[i])
        {
            downest_y_ship_world = current_ship_xy.whole_ship_y_ship_map[i];
        }

    }
    if (rightest_x == COL - 2)
    {
        leftest_x -= 1;
    }

    int remain_x_ship_world = SHIP_COL - leftest_x_ship_world;
    int remain_y_ship_world = SHIP_LOW - upest_y_ship_world;

    for (int i = upest_y_ship_world, a = upest_y; i <= downest_y_ship_world && a <= upest_y + downest_y_ship_world; i++, a++)
    {
        for (int j = leftest_x_ship_world, b = leftest_x; j <= rightest_x_ship_world && b <= leftest_x + rightest_x_ship_world; j++, b++)
        {
            game_map[a][b] = ship_map[i][j];

        }

    }
}

void Save_GameMap(Game_Map game_map, Game_Map save_map)
{
    for (int i = 0; i < LOW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            save_map[i][j] = game_map[i][j];
        }
    }
}

void Save_Ship_To_Game_Map(Game_Map game_map, Game_Map save_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status)
{
    for (int i = 0; i < LOW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if (game_map[i][j] == Head || game_map[i][j] == Head - 1 || game_map[i][j] == Head - 2 ||
                game_map[i][j] == Body || game_map[i][j] == Body - 1 || game_map[i][j] == Body - 2 ||
                game_map[i][j] == Weapon || game_map[i][j] == Weapon - 1 || game_map[i][j] == Weapon - 2)
            {
                save_map[i][j] = game_map[i][j];
            }
        }
    }
}

void Save_Ship_To_Ship_Map(Game_Map game_map, Ship_Map ship_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status)
{
    int x = 0, y = 0;

    int head_x = 0, head_y = 0;
    int leftest_x = current_ship_xy.whole_ship_x[0];
    int upest_y = current_ship_xy.whole_ship_y[0];
    int downest_y = current_ship_xy.whole_ship_y[0];
    int rightest_x = current_ship_xy.whole_ship_x[0];
    int center_x = 0, center_y = 0;

    head_x = current_ship_xy.head_ship_x[0];
    head_y = current_ship_xy.head_ship_y[0];

    for (int i = 0; i < current_map_status.count_whole_ship; i++)
    {
        if (leftest_x >= current_ship_xy.whole_ship_x[i])
        {

            leftest_x = current_ship_xy.whole_ship_x[i];
        }
        if (rightest_x <= current_ship_xy.whole_ship_x[i])
        {

            rightest_x = current_ship_xy.whole_ship_x[i];
        }
        if (upest_y >= current_ship_xy.whole_ship_y[i])
        {

            upest_y = current_ship_xy.whole_ship_y[i];
        }
        if (downest_y <= current_ship_xy.whole_ship_y[i])
        {

            downest_y = current_ship_xy.whole_ship_y[i];
        }


    }
    center_y = (upest_y + downest_y) / 2;
    center_x = (rightest_x + leftest_x) / 2;

    for (int i = 0; i < current_map_status.count_whole_ship; i++)
    {
        x = current_ship_xy.whole_ship_x[i];
        y = current_ship_xy.whole_ship_y[i];

        for (int i = (SHIP_LOW) / 2 - 4, a = center_y - 4; i < (SHIP_LOW) / 2 + 4 && a < center_y + 4; i++, a++)
        {
            for (int j = (SHIP_COL) / 2 - 4, b = center_x - 4; j < (SHIP_COL) / 2 + 4 && b < center_x + 4; j++, b++)
            {
                if (game_map[a][b] == Head || game_map[a][b] == Head - 1 || game_map[a][b] == Head - 2
                    || game_map[a][b] == Body || game_map[a][b] == Body - 1 || game_map[a][b] == Body - 2 ||
                    game_map[a][b] == Weapon || game_map[a][b] == Weapon - 1 || game_map[a][b] == Weapon - 2)
                    ship_map[i][j] = game_map[a][b];

            }
        }
    }



}
void Erase_Ship(Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status)
{
    int x = 0, y = 0;

    for (int i = 0; i < current_map_status.count_whole_ship; i++)
    {
        x = current_ship_xy.whole_ship_x[i];
        y = current_ship_xy.whole_ship_y[i];

        game_map[y][x] = AIR;

    }

}
