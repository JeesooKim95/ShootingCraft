/**
\file        GameMap_Move.cpp
\author      jeesoo.kim
\brief
This file will moves the player's ship by the player's input.

copyright   All content ?2018 DigiPen (USA) Corporation, all rights reserved
*/

#include "GameMap_Move.h"
#include "Input.h"
#include "Ship_Status.h"
#include "Item.h"
#include "Enemy_Part.h"
#include "Sound_Manager.h"

void Move_Ship_Left(Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status, int *power_up)
{
    int temp = 0;
    int x = 0, y = 0;
    int proper_bullet_pos = 0;

    for (int i = 0; i < current_map_status.count_whole_ship; i++)
    {
        x = current_ship_xy.whole_ship_x[i];
        y = current_ship_xy.whole_ship_y[i];

        if (game_map[y][x - 1] == Bullet)
        {
            //game_map[y][x - 1] = AIR;
            while (game_map[y - proper_bullet_pos][x] != AIR)
            {
                proper_bullet_pos++;
                if (game_map[y - proper_bullet_pos][x] == AIR)
                {

                    break;
                }
                game_map[y - proper_bullet_pos][x] = Bullet;
            }
        }
        if (game_map[y][x - 1] == Item_Blue || game_map[y][x - 1] == Item_Cyan || game_map[y][x - 1] == Item_Green || game_map[y][x - 1] == Item_White ||
            game_map[y][x - 1] == Item_Puple || game_map[y][x - 1] == Item_Red || game_map[y][x - 1] == Item_Yellow)
        {
            game_map[y][x - 1] = AIR;
            *power_up += 1;

            Sound::play(7);
            Sound::volume(7, 30);
        }
        else if (game_map[y][x - 1] == Enemy_Bullet || game_map[y][x - 1] == Enemy_Bullet2)
        {
            game_map[y][x - 1] = AIR;
            game_map[y][x] -= 1;

        }
        else if (game_map[y][x - 1] == Boss_Bullet_2)
        {
            game_map[y][x] -= 1;
            game_map[y][x - 1] = AIR;
        }

        temp = game_map[y][x];
        game_map[y][x] = AIR;
        game_map[y][x - 1] = temp;
    }

}
void Move_Ship_Right(Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status, int *power_up)
{
    int temp = 0;
    int x = 0, y = 0;
    int proper_bullet_pos = 0;

    for (int i = current_map_status.count_whole_ship - 1; i >= 0; i--)
    {
        x = current_ship_xy.whole_ship_x[i];
        y = current_ship_xy.whole_ship_y[i];

        temp = game_map[y][x];

        if (game_map[y][x + 1] == Bullet)
        {
            while (game_map[y - proper_bullet_pos][x] != AIR)
            {
                proper_bullet_pos++;
                if (game_map[y - proper_bullet_pos][x] == AIR)
                {

                    break;
                }
                game_map[y - proper_bullet_pos][x] = Bullet;
            }
        }
        if (game_map[y][x + 1] == Item_Blue || game_map[y][x + 1] == Item_Cyan || game_map[y][x + 1] == Item_Green || game_map[y][x + 1] == Item_White ||
            game_map[y][x + 1] == Item_Puple || game_map[y][x + 1] == Item_Red || game_map[y][x + 1] == Item_Yellow)
        {
            game_map[y][x + 1] = AIR;
            *power_up += 1;

            Sound::play(7);
            Sound::volume(7, 30);
        }
        else if (game_map[y][x + 1] == Enemy_Bullet || game_map[y][x + 1] == Enemy_Bullet2)
        {
            game_map[y][x] -= 1;
            game_map[y][x + 1] = AIR;
        }
        else if (game_map[y][x + 1] == Boss_Bullet_2)
        {
            game_map[y][x] -= 1;
            game_map[y][x + 1] = AIR;
        }

        game_map[y][x] = AIR;
        game_map[y][x + 1] = temp;
    }

}
void Move_Ship_Up(Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status, int *power_up)
{
    int temp = 0;
    int x = 0, y = 0;

    for (int i = 0; i < current_map_status.count_whole_ship; i++)
    {
        x = current_ship_xy.whole_ship_x[i];
        y = current_ship_xy.whole_ship_y[i];

        temp = game_map[y][x];

        if (game_map[y - 1][x] == Bullet)
        {
            game_map[y - 1][x] = AIR;
        }
        if (game_map[y - 1][x] == Item_Blue || game_map[y - 1][x] == Item_Cyan || game_map[y - 1][x] == Item_Green || game_map[y - 1][x] == Item_White ||
            game_map[y - 1][x] == Item_Puple || game_map[y - 1][x] == Item_Red || game_map[y - 1][x] == Item_Yellow)
        {
            game_map[y - 1][x] = AIR;
            *power_up += 1;

            Sound::play(7);
            Sound::volume(7, 30);
        }
        else if (game_map[y - 1][x] == Enemy_Bullet || game_map[y - 1][x] == Enemy_Bullet2)
        {
            game_map[y][x] -= 1;
            game_map[y - 1][x] = AIR;
        }
        else if (game_map[y - 1][x] == Boss_Bullet_2)
        {
            game_map[y][x] -= 1;
            game_map[y - 1][x] = AIR;
        }

        game_map[y][x] = AIR;
        game_map[y - 1][x] = temp;
    }

}
void Move_Ship_Down(Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status, int *power_up)
{
    int temp = 0;
    int x = 0, y = 0;

    for (int i = current_map_status.count_whole_ship - 1; i >= 0; i--)
    {
        x = current_ship_xy.whole_ship_x[i];
        y = current_ship_xy.whole_ship_y[i];

        temp = game_map[y][x];
        if (game_map[y + 1][x] == Bullet)
        {
            game_map[y + 1][x] = AIR;
        }
        if (game_map[y + 1][x] == Item_Blue || game_map[y + 1][x] == Item_Cyan || game_map[y + 1][x] == Item_Green || game_map[y + 1][x] == Item_White ||
            game_map[y + 1][x] == Item_Puple || game_map[y + 1][x] == Item_Red || game_map[y + 1][x] == Item_Yellow)
        {
            game_map[y + 1][x] = AIR;
            *power_up += 1;

            Sound::play(7);
            Sound::volume(7, 30);
        }
        else if (game_map[y + 1][x] == Enemy_Bullet || game_map[y + 1][x] == Enemy_Bullet2)
        {
            game_map[y][x] -= 1;
            game_map[y + 1][x] = AIR;
        }
        else if (game_map[y + 1][x] == Boss_Bullet_2)
        {
            game_map[y][x] -= 1;
            game_map[y + 1][x] = AIR;
        }

        game_map[y][x] = AIR;
        game_map[y + 1][x] = temp;
    }

}

void Move_Game_Map_Ship(Game_Map game_map, int dir, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status, int *power_up)
{
    switch (dir)
    {
    case LEFT:
        if (Check_Ship_Position_Is_Good(current_ship_xy, current_map_status, dir, game_map))
            Move_Ship_Left(game_map, current_ship_xy, current_map_status, power_up);
        break;
    case RIGHT:
        if (Check_Ship_Position_Is_Good(current_ship_xy, current_map_status, dir, game_map))
            Move_Ship_Right(game_map, current_ship_xy, current_map_status, power_up);
        break;
    case UP:
        if (Check_Ship_Position_Is_Good(current_ship_xy, current_map_status, dir, game_map))
            Move_Ship_Up(game_map, current_ship_xy, current_map_status, power_up);
        break;
    case DOWN:
        if (Check_Ship_Position_Is_Good(current_ship_xy, current_map_status, dir, game_map))
            Move_Ship_Down(game_map, current_ship_xy, current_map_status, power_up);
        break;
    }
}

bool Check_Ship_Position_Is_Good(XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status, int dir, Game_Map game_map)
{

    int leftest_x = current_ship_xy.whole_ship_x[0];
    int rightest_x = current_ship_xy.whole_ship_x[0];
    int upest_y = current_ship_xy.whole_ship_y[0];
    int downest_y = current_ship_xy.whole_ship_y[0];

    int leftest_y = current_ship_xy.whole_ship_y[0];
    int rightest_y = current_ship_xy.whole_ship_y[0];
    int upest_x = current_ship_xy.whole_ship_x[0];
    int downest_x = current_ship_xy.whole_ship_x[0];

    int x = 0, y = 0;

    for (int i = 0; i < current_map_status.count_whole_ship; i++)
    {
        if (leftest_x > current_ship_xy.whole_ship_x[i])
        {
            leftest_x = current_ship_xy.whole_ship_x[i];
            leftest_y = current_ship_xy.whole_ship_y[i];
        }
        if (rightest_x < current_ship_xy.whole_ship_x[i])
        {
            rightest_x = current_ship_xy.whole_ship_x[i];
            rightest_y = current_ship_xy.whole_ship_y[i];
        }
        if (downest_y < current_ship_xy.whole_ship_y[i])
        {
            downest_y = current_ship_xy.whole_ship_y[i];
            downest_x = current_ship_xy.whole_ship_x[i];
        }
        if (upest_y > current_ship_xy.whole_ship_y[i])
        {
            upest_y = current_ship_xy.whole_ship_y[i];
            upest_x = current_ship_xy.whole_ship_x[i];
        }
    }

    if (game_map[leftest_y][leftest_x - 1] != AIR && dir == LEFT)
    {
        return false;
    }
    if (game_map[rightest_y][rightest_x + 1] != AIR && dir == RIGHT)
    {
        return false;
    }
    if (game_map[upest_y - 1][upest_x] != AIR && dir == UP)
    {
        return false;
    }
    if (game_map[downest_y + 1][downest_x] != AIR && dir == DOWN)
    {
        return false;
    }
    for (int i = 0; i < current_map_status.count_whole_ship; i++)
    {
        x = current_ship_xy.whole_ship_x[i];
        y = current_ship_xy.whole_ship_y[i];

        if ((game_map[y][x + 1] == Enemy_Bullet || game_map[y][x + 1] == Enemy_Bullet2 ||
            game_map[y][x + 1] == Enemy_Bullet3 || game_map[y][x + 1] == Boss_Bullet_2)
            && dir == RIGHT)
        {
            return false;
        }
        if ((game_map[y][x - 1] == Enemy_Bullet || game_map[y][x - 1] == Enemy_Bullet2 ||
            game_map[y][x - 1] == Enemy_Bullet3 || game_map[y][x - 1] == Boss_Bullet_2)
            && dir == LEFT)
        {
            return false;
        }
        if ((game_map[y + 1][x] == Enemy_Bullet || game_map[y + 1][x] == Enemy_Bullet2 ||
            game_map[y + 1][x] == Enemy_Bullet3 || game_map[y + 1][x] == Boss_Bullet_2)
            && dir == DOWN)
        {
            return false;
        }
        if ((game_map[y - 1][x] == Enemy_Bullet || game_map[y - 1][x] == Enemy_Bullet2 ||
            game_map[y - 1][x] == Enemy_Bullet3 || game_map[y - 1][x] == Boss_Bullet_2)
            && dir == UP)
        {
            return false;
        }

    }
    return true;

}