/**
\file        GameMap_Control.cpp
\author      Chulseung Lee
\brief
This file will manage the player's input and event.

copyright   All content ?2018 DigiPen (USA) Corporation, all rights reserved

*/

#include "Game_State.h"
#include "GameMap_Control.h"
#include "Input.h"
#include "GameMap_Move.h"
#include "Ship_Shoot_Bullet.h"
#include "Apply_Two_Map.h"
#include "Init_ShipMap.h"
#include "windows.h"
#include "User_Choice.h"
#include "Sound_Manager.h"

int esc_counter = 0;
Game_Map save_map;
bool esc_once = false;

int bullet_limit = 4;
int bullet_limit_tutorial = 4;
bool space_limit = false;

void GameMap_ControlShip(Game_Map game_map, XY_Position_Ship* current_ship_xy, Map_Status_Count* current_map_status, Ship_Map ship_map, GameState* gameState, int *power_up, int *player_bullet_speed_limitation)
{
    int dir = 0;
    int user_choice = 0;
    dir = User_Input();
    bool is_exit = false;

    Move_Game_Map_Ship(game_map, dir, *current_ship_xy, *current_map_status, power_up);

    if (dir == SPACE)
    {
        space_limit = true;

    }

    if (dir == ESC && !esc_once && *power_up > 0)
    {
        esc_counter++;
        esc_once = true;

        Sound::play(11);
        Sound::volume(11, 30);
    }
    if (esc_counter != 0 && esc_once)
    {
        esc_once = false;
        Save_GameMap(game_map, save_map);
        Initialize_ShipMap(ship_map);
        Save_Ship_To_Ship_Map(game_map, ship_map, *current_ship_xy, *current_map_status);
        while (*power_up > 0)
        {
            Erase_Ship(game_map, *current_ship_xy, *current_map_status);
            system("cls");
            user_choice = User_Ask_2(*power_up, &is_exit);
            if (is_exit)
                break;

            if (user_choice == Want_Body)
            {
                Sound::play(11);
                Sound::volume(11, 30);
                Initialize_ShipWorld_During(ship_map, 1, 0);
                Sound::play(4);
                Sound::volume(4, 50);
            }
            else if (user_choice == Want_Weapon)
            {
                Sound::play(11);
                Sound::volume(11, 30);
                Initialize_ShipWorld_During(ship_map, 0, 1);
                Sound::play(4);
                Sound::volume(4, 50);
            }
            else if (user_choice == Want_Shoot_More)
            {
                bullet_limit += 4;
                Sound::play(15);
                Sound::volume(15, 30);
            }
            else if (user_choice == Want_Shoot_Speed)
            {
                *player_bullet_speed_limitation -= 10;
                Sound::play(15);
                Sound::volume(15, 30);
            }
            else if (user_choice == Want_Quit)
            {
                Sound::play(12);
                Sound::volume(12, 30);

                Sleep(1500);
                Set_GameStatus(gameState, Quit);
            }
            else if (user_choice == Want_Restart)
            {
                Sound::play(11);
                Sound::volume(11, 20);
                Set_GameStatus(gameState, Restart);
            }

            *power_up -= 1;
        }
        Save_Position_Ship_in_Ship_Map(ship_map, game_map, current_ship_xy, current_map_status);
        ShipMap_To_GameMap2(ship_map, game_map, *current_ship_xy, *current_map_status);
        system("cls");
    }
    if (dir == QUIT_)
    {
        Set_GameStatus(gameState, Quit);

    }
    if (dir == RESTART_)
    {
        Set_GameStatus(gameState, Restart);
    }
    if (dir == BOSS_)
    {
        Set_GameStatus(gameState, Boss_Hack);
    }

    if (dir == SPACE && current_map_status->count_ship_bullet < bullet_limit && space_limit)
    {
        Shoot_Bullet(game_map, *current_ship_xy, *current_map_status);
        Sound::play(1);
        Sound::volume(1, 15);
    }
    space_limit = false;
}

void GameMap_ControlShip_Tutorial(Game_Map game_map, XY_Position_Ship* current_ship_xy, Map_Status_Count* current_map_status, Ship_Map ship_map, GameState* gameState, int *power_up, int *player_bullet_speed_limitation, GameState* game_state)
{
    int dir = 0;
    int user_choice = 0;
    dir = User_Input();
    bool is_exit = false;

    Move_Game_Map_Ship(game_map, dir, *current_ship_xy, *current_map_status, power_up);

    if (dir == ESC && !esc_once && *power_up > 0)
    {
        esc_counter++;
        esc_once = true;

    }
    if (esc_counter != 0 && esc_once && *power_up > 0)
    {

        esc_once = false;
        Save_GameMap(game_map, save_map);
        Initialize_ShipMap(ship_map);
        Save_Ship_To_Ship_Map(game_map, ship_map, *current_ship_xy, *current_map_status);
        while (*power_up > 0)
        {
            Erase_Ship(game_map, *current_ship_xy, *current_map_status);
            system("cls");
            user_choice = User_Ask_2(*power_up, &is_exit);
            if (is_exit)
                break;

            if (user_choice == Want_Body)
            {
                Initialize_ShipWorld_During(ship_map, 1, 0);
            }
            else if (user_choice == Want_Weapon)
            {
                Initialize_ShipWorld_During(ship_map, 0, 1);

            }
            else if (user_choice == Want_Shoot_More)
            {
                bullet_limit_tutorial += BULLET_LEVEL_UP;
            }
            else if (user_choice == Want_Shoot_Speed)
            {
                *player_bullet_speed_limitation -= SHOOT_SPEED_UP;
            }
            else if (user_choice == Want_Quit)
            {
                Set_GameStatus(gameState, Quit);
            }
            else if (user_choice == Want_Restart)
            {
                Set_GameStatus(gameState, Restart);

            }

            *power_up -= 1;
        }
        Save_Position_Ship_in_Ship_Map(ship_map, game_map, current_ship_xy, current_map_status);
        ShipMap_To_GameMap2(ship_map, game_map, *current_ship_xy, *current_map_status);
        system("cls");
    }

    if (dir == E)
    {
        Set_GameStatus(gameState, Tutorial_end);
        Sound::play(11);
        Sound::volume(11, 3);

    }

    if (dir == SPACE && current_map_status->count_ship_bullet < bullet_limit_tutorial)
    {
        Shoot_Bullet(game_map, *current_ship_xy, *current_map_status);
    }
}
