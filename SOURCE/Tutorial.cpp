/**
\file        Tutorial.cpp
\author      Chulseung Lee
\brief
This file will print the tutorial statement.

copyright   All content ?2018 DigiPen (USA) Corporation, all rights reserved
*/

#include "Tutorial.h"
#include "MapStatus.h"
#include "Ship_Status.h"
#include "Enemy_Part.h"
#include "string.h"
#include "Item.h"

void Init_Tutorial_Enemy(Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status)
{
    game_map[(LOW / 2)][(COL / 2)] = Enemy_Head;
    game_map[(LOW / 2)][(COL / 2) + 1] = Enemy_Body_Right;
    game_map[(LOW / 2)][(COL / 2) - 1] = Enemy_Body_Left;
    game_map[(LOW / 2) + 1][(COL / 2)] = Enemy_Weapon;
    game_map[(LOW / 2)][(COL / 2) - TUTORIAL_ITEM_POS] = Item_White;
}
void Introduction(Game_Map game_map)
{
    const char* introduction = { "Welcome to game!" };
    const char* intro_move = { "Move with <-, ->" };
    const char* intro_shoot = { "Shoot : spacebar" };
    const char* intro_power_up = { "Power Up : ESC" };
    const char* intro_next = { "End tutorial : E" };

    for (int i = 0, a = 3; i < strlen(introduction) && a < 3 + strlen(introduction); i++, a++)
    {
        game_map[TUTORIAL_INTRO_POS][a] = introduction[i];
    }
    for (int i = 0, a = 3; i < strlen(intro_move) && a < 3 + strlen(intro_move); i++, a++)
    {
        game_map[TUTORIAL_INTRO_MOVE_POS][a] = intro_move[i];
    }
    for (int i = 0, a = 3; i < strlen(intro_shoot) && a < 3 + strlen(intro_shoot); i++, a++)
    {
        game_map[TUTORIAL_INTRO_SHOOT_POS][a] = intro_shoot[i];
    }
    for (int i = 0, a = 3; i < strlen(intro_power_up) && a < 3 + strlen(intro_power_up); i++, a++)
    {
        game_map[TUTORIAL_INTRO_POWER_POS][a] = intro_power_up[i];
    }
    for (int i = 0, a = 3; i < strlen(intro_next) && a < 3 + strlen(intro_next); i++, a++)
    {
        game_map[TUTORIAL_INTRO_END_POS][a] = intro_next[i];
    }
}