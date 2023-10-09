/*
   \file        GameClear.cpp
   \project    Shooting Craft
   \author(s)	hyun gang
   \par         email: hangam131313@gmail.com

   \copyright   All content © 2018 DigiPen (USA) Corporation, all rights reserved


   this file display clear logo when player clear our game.
*/

#include "Start_Screen.h"
#include "Sound_Manager.h"
#include "GameClear.h"
#include "Console.h"


static const char * Game_Clear_Logo[] =
{
"   ",
"       .d8888b.         d8888 888b     d888 8888888888  ",
"      d88P  Y88b       d88888 8888b   d8888 888          ",
"      888    888      d88P888 88888b.d88888 888         ",
"      888            d88P 888 888Y88888P888 8888888     ",
"      888  88888    d88P  888 888 Y888P 888 888          ",
"      888    888   d88P   888 888  Y8P  888 888         ",
"      Y88b  d88P  d8888888888 888       888 888        ",
"        Y8888P88 d88P     888 888       888 8888888888",
"  ",
" .d8888b.  888      8888888888        d8888 8888888b.  888 888 ",
"d88P  Y88b 888      888              d88888 888   Y88b 888 888 ",
"888    888 888      888             d88P888 888    888 888 888 ",
"888        888      8888888        d88P 888 888   d88P 888 888 ",
"888        888      888           d88P  888 8888888P   888 888 ",
"888    888 888      888          d88P   888 888 T88b   Y8P Y8P ",
"Y88b  d88P 888      888         d8888888888 888  T88b          ",
"  Y8888P   88888888 8888888888 d88P     888 888   T88b 888 888 ",

};

/*this function printf game clear */
void Game_Clear(bool *should_run)
{
    Sound::volume(0, 0);
    Sound::volume(16, 0);

    system("cls");
    printf("\n\n\n\n\n\n");
    for (int i = 0; i < CLEAR_LOGO; i++)
    {
        printf("%s\n", Game_Clear_Logo[i]);

    }
    printf("Press the any key!!\n");
    Sleep(3000);
    Sound::play(6);
    Sound::volume(6, 20);

    Transition();

    *should_run = false;
}
