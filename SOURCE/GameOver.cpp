/*
   \file        GameOver.cpp
   \project    Shooting Craft
   \author(s)	hyun gang
   \par         email: hangam131313@gmail.com

   \copyright   All content © 2018 DigiPen (USA) Corporation, all rights reserved

   this file display game over screen when the player die.
*/

#include "Start_Screen.h"
#include "Sound_Manager.h"
#include "GameOver.h"
#include "Console.h"


#define GAME_LINE 9

static const char *GameOver[] =
{
"                                                                                                       ",
"         d8888b          d8888 888b     d888 8888888888   d88888b   888     888 8888888888 8888888b     ",
"      d88P  Y88b       d88888 8888b   d8888 888        d88P   Y88b 888     888 888        888   Y88b   ",
"     888    888      d88P888 88888b d88888 888        888     888 888     888 888        888    888   ",
"    888            d88P 888 888Y88888P888 8888888    888     888 Y88b   d88P 8888888    888   d88P   ",
"   888  88888    d88P  888 888 Y888P 888 888        888     888  Y88b d88P  888        8888888P     ",
"  888    888   d88P   888 888  Y8P  888 888        888     888   Y88o88P   888        888 T88b     ",
" Y88b  d88P  d8888888888 888       888 888        Y88b   d88P    Y888P    888        888  T88b          ",
"  Y8888P88 d88P     888 888       888 8888888888   Y88888P       Y8P     8888888888 888   T88b  ",

};

/*this function print game over and go menu.*/
void Game_Over(bool* should_run)
{
    Sound::volume(0, 0);
    Sound::volume(16, 0);
    adjustWindowSize(100, 110);

    system("cls");
    printf("\n\n\n\n\n");

    Print_Game_Over();

    Sleep(3000);
    *should_run = false;
}

/*this function can print logo */
void Print_Game_Over()
{
    for (int i = 0; i < GAME_LINE; i++)
    {
        printf("%s\n", GameOver[i]);

    }
}