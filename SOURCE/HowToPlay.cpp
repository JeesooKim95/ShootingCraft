/*
   \file        HowToPlay.cpp
   \project    Shooting Craft
   \author(s)	hyun gang
   \par         email: hangam131313@gmail.com

   \copyright   All content © 2018 DigiPen (USA) Corporation, all rights reserved

   this file can help the player can understand easily.
*/

#include "Start_Screen.h"
#include "Sound_Manager.h"
#include "HowToPlay.h"

#define HOW_LOGO 17

static const char *HowToPlay[] =
{
"	       888    888                         88888888888                .",
"	 *    888    888          *                  888                        .",
"	     888    888               .        *    888           .           ",
"	    8888888888  .d88b.  888  888  888      888   .d88b.         .                ",
"	   888    888 d88''88b 888  888  888      888  d88''88b                 *",
"	  888    888 888  888 888  888  888      888  888  888       *",
"	 888    888 Y88..88P Y88b 888 d88P  .   888  Y88..88P                .",
"	888    888  'Y88P'   'Y8888888P'       888   'Y88P'       .",
" ",
"          *       8888888b.  888             d8888 Y88b   d88P       *",
"                 888   Y88b 888       .    d88888  Y88b d88P                 .",
"     .          888    888 888           d88P888   Y88o88P           *",
"               888   d88P 888    *     d88P 888    Y888P           .              .",
"     *        8888888P'  888         d88P  888     888     .                   *"  ,
"             888    .   888        d88P   888     888          *",
"            888   *    888       d8888888888     888               *",
"      .    888        88888888 d88P     888     888        .",
};

/*this function can print logo */
void Print_How_To_Play()
{
    for (int i = 0; i < HOW_LOGO; i++)
    {
        printf("%s\n", HowToPlay[i]);
    }
}

/*this function explain how to play our game. */
void How_To_Play()
{
    system("cls");

    Print_How_To_Play();

    printf("\n\n\n\n	INTRO\n");
    printf("\n	Shooting Craft - The Begin of Legend is a top-down space shooting game. \n");
    printf("\n	Defeat the enemies! Shoot them down.\n\n\n");


    system("pause");
    system("cls");
    Sound::play(10);
    Sound::volume(10, 30);

    Print_How_To_Play();

    printf("\n\n\n\n	BECOME STRONGER\n");
    printf("\n	Build your initial ship!\n");
    printf("\n	Earn POWER items to upgrade!\n");
    printf("\n	Press the ESC button to go to upgrade screen!\n\n\n");
    
    system("pause");
    system("cls");
    Sound::play(10);
    Sound::volume(10, 30);

    Print_How_To_Play();

    printf("\n\n\n\n	COMMANDS\n");
    printf("\n	Use the arrow keys to move.\n");
    printf("\n	                  /\\             \n");
    printf("	                <=  =>          \n");
    printf("	                  \\/             \n");
    printf("\n	Use SPACEBAR to shoot.\n");
    printf("\n	               [ space ]         \n\n\n");

    system("pause");
    system("cls");
    Sound::play(10);
    Sound::volume(10, 30);

    Print_How_To_Play();

    printf("\n\n\n\n	!!!WARNING!!!\n");

    Sound::play(13);
    Sound::volume(13, 15);
    Sleep(700);

    printf("\n	There is a BOSS at the end!\n");

    Sound::play(13);
    Sound::volume(13, 15);
    Sleep(700);

    printf("\n	Stay focused until you defeat the BOSS!\n\n\n");

    Sound::play(13);
    Sound::volume(13, 15);
    Sleep(700);
    system("pause");

    Sound::play(11);
    Sound::volume(11, 10);

    Print_Menu();
}