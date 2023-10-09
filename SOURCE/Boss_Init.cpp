/**
\file        Boss_Init.cpp
\author      hyun.gang
\par         email: hangam131313@gmail.com
\brief
This file will initialize the boss in the array.

copyright   All content ?2018 DigiPen (USA) Corporation, all rights reserved
*/
#include "MapStatus.h"
#include "Boss_Init.h"
#include "Enemy_Part.h"
#include "Ship_Status.h"
#include "Sound_Manager.h"
#include "windows.h"

Boss enemy_boss;

void Boss_Init(Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status, bool *is_boss_exist)
{
    for (int i = enemy_boss.boss_spawn_position_y, a = 0; i < enemy_boss.boss_spawn_position_y + NINE && a < NINE; i++, a++)
    {
        for (int j = enemy_boss.boss_spawn_position_x, b = 0; j < enemy_boss.boss_spawn_position_x + SIPO && b < SIPO; j++, b++)
        {
            game_map[i][j] = enemy_boss.boss_arr[a][b];

        }

    }
    *is_boss_exist = true;

}
void Boss_Init2(Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status)
{
    enemy_boss.boss_part_1_spawn_position_x = 1;

    for (int i = enemy_boss.boss_part_1_spawn_position_y, a = 0; i < enemy_boss.boss_part_1_spawn_position_y + 7 && a < SEVEN; i++, a++)
    {
        for (int j = enemy_boss.boss_part_1_spawn_position_x, b = 0; j < enemy_boss.boss_part_1_spawn_position_x + 7 && b < SEVEN; j++, b++)
        {
            game_map[i][j] = enemy_boss.combine_1[a][b];

        }
    }
    for (int i = enemy_boss.boss_part_2_spawn_position_y, a = 0; i < enemy_boss.boss_part_2_spawn_position_y + 7 && a < SEVEN; i++, a++)
    {
        for (int j = enemy_boss.boss_part_2_spawn_position_x, b = 0; j < enemy_boss.boss_part_2_spawn_position_x + 7 && b < SEVEN; j++, b++)
        {
            game_map[i][j] = enemy_boss.combine_2[a][b];

        }
    }


}

void Boss_Combine(Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status, bool *is_combined)
{

    if (enemy_boss.boss_part_1_spawn_position_x < 8 && enemy_boss.boss_part_2_spawn_position_x >(COL / 2) + 2)
    {
        for (int i = enemy_boss.boss_part_1_spawn_position_y, a = 0; i < enemy_boss.boss_part_1_spawn_position_y + 7 && a < SEVEN; i++, a++)
        {
            for (int j = enemy_boss.boss_part_1_spawn_position_x, b = 0; j < enemy_boss.boss_part_1_spawn_position_x + 7 && b < SEVEN; j++, b++)
            {
                game_map[i][j] = AIR;

            }
        }
        for (int i = enemy_boss.boss_part_2_spawn_position_y, a = 0; i < enemy_boss.boss_part_2_spawn_position_y + 7 && a < SEVEN; i++, a++)
        {
            for (int j = enemy_boss.boss_part_2_spawn_position_x, b = 0; j < enemy_boss.boss_part_2_spawn_position_x + 7 && b < SEVEN; j++, b++)
            {
                game_map[i][j] = AIR;

            }
        }

        enemy_boss.boss_part_1_spawn_position_x += 1;
        enemy_boss.boss_part_2_spawn_position_x -= 1;

        for (int i = enemy_boss.boss_part_1_spawn_position_y, a = 0; i < enemy_boss.boss_part_1_spawn_position_y + 7 && a < SEVEN; i++, a++)
        {
            for (int j = enemy_boss.boss_part_1_spawn_position_x, b = 0; j < enemy_boss.boss_part_1_spawn_position_x + 7 && b < SEVEN; j++, b++)
            {
                game_map[i][j] = enemy_boss.combine_1[a][b];

            }
        }
        for (int i = enemy_boss.boss_part_2_spawn_position_y, a = 0; i < enemy_boss.boss_part_2_spawn_position_y + 7 && a < SEVEN; i++, a++)
        {
            for (int j = enemy_boss.boss_part_2_spawn_position_x, b = 0; j < enemy_boss.boss_part_2_spawn_position_x + 7 && b < SEVEN; j++, b++)
            {
                game_map[i][j] = enemy_boss.combine_2[a][b];

            }
        }
    }
    else
    {
        *is_combined = true;

    }
}

void Make_Boss()
{
    Sound::volume(0, 0);

    Sound::play(5);
    Sound::volume(5, 10);
    Sleep(3000);

    Sound::play(14);
    Sound::volume(14, 10);

    for (int i = 0; i < SIPO; i++)
    {
        enemy_boss.boss_arr[0][i] = AIR;
    }

    for (int i = 0; i < SIPO; i++)
    {
        if (i == 5 || i == 9 || i == 0 || i == 14)
            enemy_boss.boss_arr[1][i] = AIR;
        else
            enemy_boss.boss_arr[1][i] = Boss_Core_Body_Unbreakable;
    }

    enemy_boss.boss_spawn_position_x = 5;
    enemy_boss.boss_spawn_position_y = 5;
    enemy_boss.boss_part_1_spawn_position_x = 1;
    enemy_boss.boss_part_1_spawn_position_y = 5;

    enemy_boss.boss_part_2_spawn_position_x = (COL / 2) + 5;
    enemy_boss.boss_part_2_spawn_position_y = 5;

    enemy_boss.boss_arr[1][6] = Boss_Core_Body_Unbreakable;
    enemy_boss.boss_arr[1][7] = Boss_Core_Body_Unbreakable;
    enemy_boss.boss_arr[1][8] = Boss_Core_Body_Unbreakable;


    enemy_boss.boss_arr[2][0] = Boss_Core_Body_Unbreakable;
    enemy_boss.boss_arr[2][1] = AIR;
    enemy_boss.boss_arr[2][2] = AIR;
    enemy_boss.boss_arr[2][3] = AIR;
    enemy_boss.boss_arr[2][4] = Boss_Body;
    enemy_boss.boss_arr[2][5] = Boss_Core_Body_Unbreakable;
    enemy_boss.boss_arr[2][6] = Boss_Core_Body_Unbreakable;
    enemy_boss.boss_arr[2][7] = Boss_Head;
    enemy_boss.boss_arr[2][8] = Boss_Core_Body_Unbreakable;
    enemy_boss.boss_arr[2][9] = Boss_Core_Body_Unbreakable;
    enemy_boss.boss_arr[2][10] = AIR;
    enemy_boss.boss_arr[2][11] = AIR;
    enemy_boss.boss_arr[2][12] = AIR;
    enemy_boss.boss_arr[2][13] = AIR;
    enemy_boss.boss_arr[2][14] = Boss_Core_Body_Unbreakable;

    enemy_boss.boss_arr[3][0] = Boss_Core_Body_Unbreakable;
    enemy_boss.boss_arr[3][1] = AIR;
    enemy_boss.boss_arr[3][2] = Boss_Head_In_Body;
    enemy_boss.boss_arr[3][3] = AIR;
    enemy_boss.boss_arr[3][4] = Boss_Body;
    enemy_boss.boss_arr[3][5] = AIR;
    enemy_boss.boss_arr[3][6] = Boss_Core_Weapon_Unbreakable;
    enemy_boss.boss_arr[3][7] = Boss_Core_Weapon_Unbreakable;
    enemy_boss.boss_arr[3][8] = Boss_Core_Weapon_Unbreakable;
    enemy_boss.boss_arr[3][9] = AIR;
    enemy_boss.boss_arr[3][10] = Boss_Body;
    enemy_boss.boss_arr[3][11] = AIR;
    enemy_boss.boss_arr[3][12] = Boss_Head_In_Body;
    enemy_boss.boss_arr[3][13] = AIR;
    enemy_boss.boss_arr[3][14] = Boss_Core_Body_Unbreakable;

    enemy_boss.boss_arr[4][0] = Boss_Core_Body_Unbreakable;
    enemy_boss.boss_arr[4][1] = Boss_Body;
    enemy_boss.boss_arr[4][2] = Boss_Weapon;
    enemy_boss.boss_arr[4][3] = Boss_Body;
    enemy_boss.boss_arr[4][4] = Boss_Weapon;
    enemy_boss.boss_arr[4][5] = AIR;
    enemy_boss.boss_arr[4][6] = AIR;
    enemy_boss.boss_arr[4][7] = AIR;
    enemy_boss.boss_arr[4][8] = AIR;
    enemy_boss.boss_arr[4][9] = AIR;
    enemy_boss.boss_arr[4][10] = Boss_Weapon;
    enemy_boss.boss_arr[4][11] = Boss_Body;
    enemy_boss.boss_arr[4][12] = Boss_Weapon;
    enemy_boss.boss_arr[4][13] = Boss_Body;
    enemy_boss.boss_arr[4][14] = Boss_Core_Body_Unbreakable;


    enemy_boss.boss_arr[5][0] = Boss_Core_Body_Unbreakable;
    enemy_boss.boss_arr[5][1] = Boss_Weapon;
    enemy_boss.boss_arr[5][2] = Boss_Body;
    enemy_boss.boss_arr[5][3] = Boss_Body;
    enemy_boss.boss_arr[5][4] = Boss_Body;
    enemy_boss.boss_arr[5][5] = AIR;
    enemy_boss.boss_arr[5][6] = AIR;
    enemy_boss.boss_arr[5][7] = AIR;
    enemy_boss.boss_arr[5][8] = AIR;
    enemy_boss.boss_arr[5][9] = AIR;
    enemy_boss.boss_arr[5][10] = Boss_Body;
    enemy_boss.boss_arr[5][11] = Boss_Body;
    enemy_boss.boss_arr[5][12] = Boss_Body;
    enemy_boss.boss_arr[5][13] = Boss_Weapon;
    enemy_boss.boss_arr[5][14] = Boss_Core_Body_Unbreakable;

    enemy_boss.boss_arr[6][0] = Boss_Core_Body_Unbreakable;
    enemy_boss.boss_arr[6][1] = Boss_Weapon;
    enemy_boss.boss_arr[6][2] = Boss_Weapon;
    enemy_boss.boss_arr[6][3] = AIR;
    enemy_boss.boss_arr[6][4] = AIR;
    enemy_boss.boss_arr[6][5] = AIR;
    enemy_boss.boss_arr[6][6] = AIR;
    enemy_boss.boss_arr[6][7] = AIR;
    enemy_boss.boss_arr[6][8] = AIR;
    enemy_boss.boss_arr[6][9] = AIR;
    enemy_boss.boss_arr[6][10] = AIR;
    enemy_boss.boss_arr[6][11] = AIR;
    enemy_boss.boss_arr[6][12] = Boss_Weapon;
    enemy_boss.boss_arr[6][13] = Boss_Weapon;
    enemy_boss.boss_arr[6][14] = Boss_Core_Body_Unbreakable;

    enemy_boss.boss_arr[7][0] = Boss_Core_Body_Unbreakable;
    enemy_boss.boss_arr[7][1] = Boss_Weapon;
    enemy_boss.boss_arr[7][2] = Boss_Body;
    enemy_boss.boss_arr[7][3] = AIR;
    enemy_boss.boss_arr[7][4] = AIR;
    enemy_boss.boss_arr[7][5] = AIR;
    enemy_boss.boss_arr[7][6] = AIR;
    enemy_boss.boss_arr[7][7] = AIR;
    enemy_boss.boss_arr[7][8] = AIR;
    enemy_boss.boss_arr[7][9] = AIR;
    enemy_boss.boss_arr[7][10] = AIR;
    enemy_boss.boss_arr[7][11] = AIR;
    enemy_boss.boss_arr[7][12] = Boss_Body;
    enemy_boss.boss_arr[7][13] = Boss_Weapon;
    enemy_boss.boss_arr[7][14] = Boss_Core_Body_Unbreakable;

    enemy_boss.boss_arr[8][0] = Boss_Weapon;
    enemy_boss.boss_arr[8][1] = Boss_Body;
    enemy_boss.boss_arr[8][2] = Boss_Weapon;
    enemy_boss.boss_arr[8][3] = AIR;
    enemy_boss.boss_arr[8][4] = AIR;
    enemy_boss.boss_arr[8][5] = AIR;
    enemy_boss.boss_arr[8][6] = AIR;
    enemy_boss.boss_arr[8][7] = AIR;
    enemy_boss.boss_arr[8][8] = AIR;
    enemy_boss.boss_arr[8][9] = AIR;
    enemy_boss.boss_arr[8][10] = AIR;
    enemy_boss.boss_arr[8][11] = AIR;
    enemy_boss.boss_arr[8][12] = Boss_Weapon;
    enemy_boss.boss_arr[8][13] = Boss_Body;
    enemy_boss.boss_arr[8][14] = Boss_Weapon;

    for (int i = 0; i < SEVEN; i++)
    {
        enemy_boss.combine_1[1][i] = Boss_Core_Body_Unbreakable;
        enemy_boss.combine_2[1][i] = Boss_Core_Body_Unbreakable;


    }
    for (int i = 0; i < SEVEN; i++)
    {

        enemy_boss.combine_1[i][0] = Boss_Core_Body_Unbreakable;
        enemy_boss.combine_1[i][1] = Boss_Body;
        enemy_boss.combine_1[i][2] = Boss_Body;
        enemy_boss.combine_1[i][3] = Boss_Body;
        enemy_boss.combine_1[i][4] = Boss_Body;
        enemy_boss.combine_1[i][5] = Boss_Core_Body_Unbreakable;
        enemy_boss.combine_1[i][6] = AIR;

        enemy_boss.combine_2[i][0] = AIR;
        enemy_boss.combine_2[i][1] = Boss_Core_Body_Unbreakable;
        enemy_boss.combine_2[i][2] = Boss_Body;
        enemy_boss.combine_2[i][3] = Boss_Body;
        enemy_boss.combine_2[i][4] = Boss_Body;
        enemy_boss.combine_2[i][5] = Boss_Body;
        enemy_boss.combine_2[i][6] = Boss_Core_Body_Unbreakable;
    }

    enemy_boss.combine_1[2][6] = Boss_Body;
    enemy_boss.combine_2[2][0] = Boss_Body;

    enemy_boss.combine_1[0][0] = AIR;
    enemy_boss.combine_2[0][6] = AIR;

    enemy_boss.combine_1[3][0] = AIR;
    enemy_boss.combine_1[4][0] = AIR;
    enemy_boss.combine_1[5][0] = AIR;
    enemy_boss.combine_1[6][0] = AIR;
    enemy_boss.combine_1[4][1] = AIR;
    enemy_boss.combine_1[5][1] = AIR;
    enemy_boss.combine_1[6][1] = AIR;
    enemy_boss.combine_1[6][2] = AIR;
    enemy_boss.combine_1[6][5] = AIR;
    enemy_boss.combine_1[1][1] = AIR;
    enemy_boss.combine_1[1][2] = AIR;
    enemy_boss.combine_1[1][3] = AIR;
    enemy_boss.combine_1[1][4] = AIR;
    enemy_boss.combine_1[2][2] = AIR;
    enemy_boss.combine_1[2][3] = AIR;
    enemy_boss.combine_1[2][4] = AIR;
    enemy_boss.combine_1[3][3] = Boss_Head_In_Body;


    enemy_boss.combine_2[3][6] = AIR;
    enemy_boss.combine_2[4][5] = AIR;
    enemy_boss.combine_2[4][6] = AIR;
    enemy_boss.combine_2[5][6] = AIR;
    enemy_boss.combine_2[5][5] = AIR;
    enemy_boss.combine_2[6][6] = AIR;
    enemy_boss.combine_2[6][5] = AIR;
    enemy_boss.combine_2[6][4] = AIR;
    enemy_boss.combine_2[6][1] = AIR;
    enemy_boss.combine_2[1][2] = AIR;
    enemy_boss.combine_2[1][3] = AIR;
    enemy_boss.combine_2[1][4] = AIR;
    enemy_boss.combine_2[1][5] = AIR;
    enemy_boss.combine_2[2][2] = AIR;
    enemy_boss.combine_2[2][3] = AIR;
    enemy_boss.combine_2[2][4] = AIR;
    enemy_boss.combine_2[3][3] = Boss_Head_In_Body;

    enemy_boss.combine_1[3][4] = Boss_Body;
    enemy_boss.combine_2[3][2] = Boss_Body;

    enemy_boss.combine_2[2][6] = Boss_Weapon_2;
    enemy_boss.combine_1[2][0] = Boss_Weapon_2;

    enemy_boss.combine_1[4][3] = Boss_Weapon_3;
    enemy_boss.combine_1[5][3] = Boss_Weapon_3;
    enemy_boss.combine_1[6][3] = Boss_Weapon_3;
    enemy_boss.combine_1[4][2] = Boss_Weapon_2;
    enemy_boss.combine_1[5][2] = Boss_Weapon_2;
    enemy_boss.combine_1[6][2] = Boss_Weapon_2;

    enemy_boss.combine_2[4][3] = Boss_Weapon_3;
    enemy_boss.combine_2[5][3] = Boss_Weapon_3;
    enemy_boss.combine_2[6][3] = Boss_Weapon_3;
    enemy_boss.combine_2[4][4] = Boss_Weapon_2;
    enemy_boss.combine_2[5][4] = Boss_Weapon_2;
    enemy_boss.combine_2[6][4] = Boss_Weapon_2;

}