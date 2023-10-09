/**
\file        Game_State.h
\author      sangmin.kim
\par         email: ryan95kr@gmail.com
\brief
This file is header file of Game_State.c

copyright   All content ?2018 DigiPen (USA) Corporation, all rights reserved
*/

#define ENEMY_INIT 5
#define FIRST_EASY_PHASE 40
#define SECOND_EASY_PHASE 65
#define FIRST_HARD_PHASE 20
#define SECOND_HARD_PHASE 85

#pragma once
#include "MapStatus.h"
#include "Timer.h"
#include "Game_Control.h"
typedef enum GameState {

    Initialize_Ship = 300,
    Initialize_Ship_Map = 301,
    Initialize_Game_Map = 302,
    Paste_ShipMap_To_GameMap = 303,
    Print_Game_Map = 304,
    Move_Game_Map = 305,
    Position_Ship_Game_Map = 306,
    Count_Ship_Game_Map = 307,
    Malloc_ship_XY = 308,
    Set_Of_Player_Ship = 309,
    Free_Allocated_Data = 310,
    Update_Game_Map = 311,
    Phase_1 = 312,
    Phase_2 = 313,
    End_Game = 314,
    Tutorial = 315,
    Tutorial_end = 316,
    Clear_Game = 317,
    Initialize_Hard_Ship_Map = 318,
    Hard_Mode = 318,
    Restart = 319,
    Quit = 320,
    Hack_Mode = 321,
	Boss_Hack = 322


}GameState;

void GameStatus_Manager(GameState* gameState, bool *should_run, long dt, Map_Status_Count* current_map_status, XY_Position_Ship* current_ship_xy, In_Game_Seconds* in_game_seconds, Game_Control* game_control, Level_Control* level_control);
GameState* Set_GameStatus(GameState* currentState, GameState nextState);
GameState* Create_gameState();