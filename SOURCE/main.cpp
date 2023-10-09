/**
\file        main.cpp
\author      sangmin.kim
\par         email: ryan95kr@gmail.com
\brief
This file is contains main function of game.

copyright   All content ?2018 DigiPen (USA) Corporation, all rights reserved
*/

#include "stdio.h"
#include "MapStatus.h"
#include "Console.h"
#include "Time.h"
#include "windows.h"
#include "SetCursor_Position.h"
#include "Game_State.h"
#include "Start_Screen.h"
#include "Sound_Manager.h"
#include "Game_Logo_Init.h"
#include "Timer.h"
#include "Game_Control.h"
#include "stdlib.h"
#include "Create_Ship_XY.h"

#define MODE_NUMBER 4

clock_t gameClock;

int main(void)
{

    Sound::initialize();
    Sound::load();
    int mode = 50000;
    adjustWindowSize(100, 45);
    changefont();
    Open_Logo();
    while (!(mode >= 0 && mode <= MODE_NUMBER))
    {
        mode = Print_Menu();
    }
    long current_time, prev_time, dt;
    current_time = gameClock;
    prev_time = gameClock;
    In_Game_Seconds* in_game_seconds = NULL;
    Map_Status_Count* current_map_status = NULL;
    XY_Position_Ship* current_ship_xy = NULL;
    Game_Control* game_control = NULL;
    Level_Control* level_control = NULL;
    bool should_run = true;
    GameState* gameState;
    current_map_status = (Map_Status_Count *)calloc(1, sizeof(Map_Status_Count));
    current_ship_xy = (XY_Position_Ship *)calloc(1, sizeof(XY_Position_Ship));
    in_game_seconds = (In_Game_Seconds *)calloc(1, sizeof(In_Game_Seconds));
    game_control = (Game_Control *)calloc(1, sizeof(Game_Control));
    level_control = (Level_Control *)calloc(1, sizeof(Level_Control));
    Alloc_xy_array(current_ship_xy);

    gameState = Create_gameState();


    if (mode == EASY_MODE)
    {
        gameState = Set_GameStatus(gameState, Initialize_Ship_Map);
    }
    if (mode == HARD_MODE)
    {
        gameState = Set_GameStatus(gameState, Initialize_Hard_Ship_Map);
    }
    if (mode == QUIT)
    {
        should_run = false;
    }
    if (mode == 0)
    {
        gameState = Set_GameStatus(gameState, Hack_Mode);

    }

    while (should_run)
    {
        gotoxy(1, 1);


        prev_time = current_time;
        current_time = clock();
        dt = current_time - prev_time;

        GameStatus_Manager(gameState, &should_run, dt, current_map_status, current_ship_xy, in_game_seconds, game_control, level_control);
    }
    free(current_map_status);
    free(current_ship_xy);
    free(in_game_seconds);
    free(game_control);
    free(level_control);


    return 0;
}