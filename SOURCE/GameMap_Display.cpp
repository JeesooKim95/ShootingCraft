/**
\file        GameMap_Display.cpp
\author      hyun.gang
\par         email: hangam131313@gmail.com
\brief
This file will check each elements of game_map.
Will display into console screen depends on state of elements.

copyright   All content © 2018 DigiPen (USA) Corporation, all rights reserved
*/

#include "MapStatus.h"
#include "windows.h"
#include "GameMap_Display.h"
#include "Ship_Status.h"
#include "Enemy_Part.h"
#include "stdio.h"
#include "Item.h"

void GameMap_Display(Game_Map game_map, int score, int power_up)
{
   for (int i = 3; i < LOW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if (game_map[i][j] == AIR || game_map[i][j] == 0)
            {
                printf("   ");
            }
            else if (game_map[i][j] == WALL)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                printf(" X ");
            }

            else if (game_map[i][j] <= Head && game_map[i][j] >= Head - 2)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                printf(" H ");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            }
            else if (game_map[i][j] == Body)
            {
                printf(ANSI_COLOR_GREEN " O " ANSI_COLOR_RESET);
            }
            else if (game_map[i][j] == Body - 1)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                printf(" O ");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            }
            else if (game_map[i][j] == Body - 2)
            {
                printf(ANSI_COLOR_RED " O " ANSI_COLOR_RESET);

            }
            else if (game_map[i][j] == Weapon)
            {
                printf(ANSI_COLOR_MAGENTA " ^ " ANSI_COLOR_RESET);

            }
            else if (game_map[i][j] == Weapon - 1)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
                printf(" ^ ");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            }
            else if (game_map[i][j] == Weapon - 2)
            {
                printf(ANSI_COLOR_RED " ^ " ANSI_COLOR_RESET);
	    }
	    else if (game_map[i][j] == Bullet)
	    {
	        printf(ANSI_COLOR_CYAN " ^ " ANSI_COLOR_RESET);
            }
            else if (game_map[i][j] == Enemy_Body_Left || game_map[i][j] == Enemy_Body_Left2 || game_map[i][j] == Enemy_Body_Left3 || game_map[i][j] == Enemy_Body_Left4)
            {
                printf(ANSI_COLOR_WHITE " [ " ANSI_COLOR_RESET);
            }
            else if (game_map[i][j] == Enemy_Body_Left - 1 || game_map[i][j] == Enemy_Body_Left2 - 1 || game_map[i][j] == Enemy_Body_Left3 - 1 || game_map[i][j] == Enemy_Body_Left4 - 1)
            {
                printf(ANSI_COLOR_GRAY " [ " ANSI_COLOR_RESET);

            }
            else if (game_map[i][j] == Enemy_Body_Left - 2 || game_map[i][j] == Enemy_Body_Left2 - 2 || game_map[i][j] == Enemy_Body_Left3 - 2 || game_map[i][j] == Enemy_Body_Left4 - 2)
            {
                printf(ANSI_COLOR_RED " [ " ANSI_COLOR_RESET);

            }
            else if (game_map[i][j] == Enemy_Body_Right || game_map[i][j] == Enemy_Body_Right2 || game_map[i][j] == Enemy_Body_Right3 || game_map[i][j] == Enemy_Body_Right4)
            {
                printf(ANSI_COLOR_WHITE " ] " ANSI_COLOR_RESET);
            }
            else if (game_map[i][j] == Enemy_Body_Right - 1 || game_map[i][j] == Enemy_Body_Right2 - 1 || game_map[i][j] == Enemy_Body_Right3 - 1 || game_map[i][j] == Enemy_Body_Right4 - 1)
            {
                printf(ANSI_COLOR_GRAY " ] " ANSI_COLOR_RESET);

            }
            else if (game_map[i][j] == Enemy_Body_Right - 2 || game_map[i][j] == Enemy_Body_Right2 - 2 || game_map[i][j] == Enemy_Body_Right3 - 2 || game_map[i][j] == Enemy_Body_Right4 - 2)
            {
                printf(ANSI_COLOR_RED " ] " ANSI_COLOR_RESET);

            }
            else if ((game_map[i][j] <= Enemy_Head && game_map[i][j] >= Enemy_Head - 2) ||
                (game_map[i][j] <= Enemy_Head2 && game_map[i][j] >= Enemy_Head2 - 2) ||
                (game_map[i][j] <= Enemy_Head3 && game_map[i][j] >= Enemy_Head3 - 2) ||
                (game_map[i][j] <= Enemy_Head4 && game_map[i][j] >= Enemy_Head4 - 2))
            {
                printf(" * ");

            }
            else if (game_map[i][j] == Enemy_Weapon || game_map[i][j] == Enemy_Weapon2 || game_map[i][j] == Enemy_Weapon3 || game_map[i][j] == Enemy_Weapon4)
            {
                printf(ANSI_COLOR_WHITE " T " ANSI_COLOR_RESET);

            }
            else if (game_map[i][j] == Enemy_Weapon - 1 || game_map[i][j] == Enemy_Weapon2 - 1 || game_map[i][j] == Enemy_Weapon3 - 1 || game_map[i][j] == Enemy_Weapon4 - 1)
            {
                printf(ANSI_COLOR_GRAY " T " ANSI_COLOR_RESET);

            }
            else if (game_map[i][j] == Enemy_Weapon - 2 || game_map[i][j] == Enemy_Weapon2 - 2 || game_map[i][j] == Enemy_Weapon3 - 2 || game_map[i][j] == Enemy_Weapon4 - 2)
            {
                printf(ANSI_COLOR_RED " T " ANSI_COLOR_RESET);

            }
            else if (game_map[i][j] <= Boss_Body && game_map[i][j] >= Boss_Body - 3)
            {
                printf(ANSI_COLOR_WHITE " O " ANSI_COLOR_RESET);
            }
            else if (game_map[i][j] < Boss_Body - 3 && game_map[i][j] >= Boss_Body - 6)
            {
                printf(ANSI_COLOR_GRAY " O " ANSI_COLOR_RESET);
            }
            else if (game_map[i][j] < Boss_Body - 6 && game_map[i][j] >= Boss_Body - 8)
            {
                printf(ANSI_COLOR_RED " O " ANSI_COLOR_RESET);
            }
            else if (game_map[i][j] <= Boss_Weapon && game_map[i][j] >= Boss_Weapon - 3)
            {
                printf(ANSI_COLOR_WHITE " T " ANSI_COLOR_RESET);
            }
            else if (game_map[i][j] < Boss_Weapon - 3 && game_map[i][j] >= Boss_Weapon - 6)
            {
                printf(ANSI_COLOR_GRAY " T " ANSI_COLOR_RESET);
            }
            else if (game_map[i][j] < Boss_Weapon - 6 && game_map[i][j] >= Boss_Weapon - 8)
            {
                printf(ANSI_COLOR_RED " T " ANSI_COLOR_RESET);
            }
            else if (game_map[i][j] <= Boss_Weapon_2 && game_map[i][j] >= Boss_Weapon_2 - 3)
            {
                printf(ANSI_COLOR_WHITE " T " ANSI_COLOR_RESET);
            }
            else if (game_map[i][j] < Boss_Weapon_2 - 3 && game_map[i][j] >= Boss_Weapon_2 - 6)
            {
                printf(ANSI_COLOR_GRAY " T " ANSI_COLOR_RESET);
            }
            else if (game_map[i][j] < Boss_Weapon_2 - 6 && game_map[i][j] >= Boss_Weapon_2 - 8)
            {
                printf(ANSI_COLOR_RED " T " ANSI_COLOR_RESET);
            }
            else if (game_map[i][j] <= Boss_Weapon_3 && game_map[i][j] >= Boss_Weapon_3 - 3)
            {
                printf(ANSI_COLOR_YELLOW " T " ANSI_COLOR_RESET);
            }
            else if (game_map[i][j] < Boss_Weapon_3 - 3 && game_map[i][j] >= Boss_Weapon_3 - 6)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                printf(" T ");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            }
            else if (game_map[i][j] < Boss_Weapon_3 - 6 && game_map[i][j] >= Boss_Weapon_3 - 8)
            {
                printf(ANSI_COLOR_RED " T " ANSI_COLOR_RESET);
            }
            else if (game_map[i][j] == Boss_Head)
            {
                printf(ANSI_COLOR_RED " H " ANSI_COLOR_RESET);

            }
            else if (game_map[i][j] == Boss_Core_Body_Unbreakable)
            {
                printf(ANSI_COLOR_YELLOW " O " ANSI_COLOR_RESET);

            }
            else if (game_map[i][j] == Boss_Core_Weapon_Unbreakable)
            {
                printf(ANSI_COLOR_YELLOW " T " ANSI_COLOR_RESET);
            }
            else if (game_map[i][j] == Boss_Head_In_Body)
            {
                printf(ANSI_COLOR_RED " H " ANSI_COLOR_RESET);

            }
            else if (game_map[i][j] == Boss_Bullet_2)
            {
                printf(ANSI_COLOR_RED " W " ANSI_COLOR_RESET);

            }
            else if (game_map[i][j] == Enemy_Bullet)
            {
                printf(ANSI_COLOR_RED " * " ANSI_COLOR_RESET);

            }
            else if (game_map[i][j] == Enemy_Bullet2)
            {
                printf(ANSI_COLOR_RED " W " ANSI_COLOR_RESET);

            }
            else if (game_map[i][j] == Enemy_Bullet3)
            {
                printf(ANSI_COLOR_RED " | " ANSI_COLOR_RESET);

            }
            else if (game_map[i][j] == Bullet_Col)
            {
                printf(ANSI_COLOR_CYAN " O " ANSI_COLOR_RESET);

            }
            else if (game_map[i][j] == Enemy_Bullet_Col)
            {
                printf(ANSI_COLOR_RED " O " ANSI_COLOR_RESET);

            }
            else if (game_map[i][j] == Ship_Die1 || game_map[i][j] == Ship_Die3 || game_map[i][j] == Ship_Die5)
            {
                printf(ANSI_COLOR_RED " O " ANSI_COLOR_RESET);

            }
            else if (game_map[i][j] == Ship_Die2 || game_map[i][j] == Ship_Die4)
            {
                printf(ANSI_COLOR_WHITE "   " ANSI_COLOR_RESET);

            }
            else if (game_map[i][j] == Bomb_Effect1 || game_map[i][j] == Bomb_Effect3 || game_map[i][j] == Bomb_Effect5)
            {
                printf(ANSI_COLOR_CYAN " O " ANSI_COLOR_RESET);
            }
            else if (game_map[i][j] == Bomb_Effect2 || game_map[i][j] == Bomb_Effect4)
            {
                printf("   ");

            }
            else if (game_map[i][j] == Ship_Die_Manager)
            {
                printf(" * ");

            }
            else if (game_map[i][j] == Item_Red)
            {
                printf(ANSI_COLOR_RED " P " ANSI_COLOR_RESET);

            }
            else if (game_map[i][j] == Item_Yellow)
            {
                printf(ANSI_COLOR_YELLOW " P " ANSI_COLOR_RESET);

            }
            else if (game_map[i][j] == Item_Puple)
            {
                printf(ANSI_COLOR_MAGENTA " P " ANSI_COLOR_RESET);

            }
            else if (game_map[i][j] == Item_Cyan)
            {
                printf(ANSI_COLOR_CYAN " P " ANSI_COLOR_RESET);

            }
            else if (game_map[i][j] == Item_Blue)
            {
                printf(ANSI_COLOR_BLUE " P " ANSI_COLOR_RESET);

            }
            else if (game_map[i][j] == Item_Green)
            {
                printf(ANSI_COLOR_GREEN " P " ANSI_COLOR_RESET);

            }
            else if (game_map[i][j] == Item_White)
            {
                printf(ANSI_COLOR_WHITE " P " ANSI_COLOR_RESET);

            }
            else if (game_map[i][j] == Bomb_Particle1 || game_map[i][j] == Bomb_Particle2 ||
                game_map[i][j] == Bomb_Particle3 || game_map[i][j] == Bomb_Particle4)
            {
                printf("   ");
            }
            else if (game_map[i][j] == Bomb)
            {
                printf(" B ");

            }
            else if (game_map[i][j] == User_Bomb_Particle1 || game_map[i][j] == User_Bomb_Particle2 ||
                game_map[i][j] == User_Bomb_Particle3 || game_map[i][j] == User_Bomb_Particle4 ||
                game_map[i][j] == User_Bomb_Particle5 || game_map[i][j] == User_Bomb_Particle6)
            {
                printf("   ");
            }
            else if (game_map[i][j] == Bomb_Ready)
            {
                printf("   ");

            }
            else
                printf(ANSI_COLOR_WHITE "%c" ANSI_COLOR_RESET, game_map[i][j]);
        }
        printf("\n");
    }
    printf("score		: %d", score);
    printf("	power up	: %d\n", power_up);
}