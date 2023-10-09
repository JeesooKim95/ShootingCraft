/*
        \file        Start_Screen.cpp
        \project	 Shooting Craft
        \author(s)   Hyun Gang & Jeesoo Kim
                \par         email: hangam131313@gmail.com

        \copyright   All content ?2018 DigiPen (USA) Corporation, all rights reserved
*/

#define _CRT_SECURE_NO_WARNINGS

#include "Start_Screen.h"
#include "Sound_Manager.h"
#include "HowToPlay.h"
#include "GameOver.h"
#include <time.h>


static const char *GameLogo[] =
{
"                                       *                                       '                  *    ",
" '     .d8888b.  888    888.  d88888b.   .d88888b.88888888888 8888888 888b   888 .d8888b.              ",
"     d88P  Y88b 888    888 d88P' 'Y88b d88P' 'Y88b   888     888   8888b   888 d88P  Y88b        .        ",
"    Y88b.      888    888 888  '  888 888     888   888     888   88888b  888 888    888     *           ",
"    'Y888b.   8888888888 888     888 888     888  888  .  888   888Y88b 888 888                       "  ,
"      'Y88b. 888    888 888     888 888     888  888     888   888 Y88b888 888  88888              *   "     ,
"   '   '888 888    888 888     888 888     888  888    888   888   Y88888 888    888        .              "     ,
" Y88b  d88P888    888 Y88b..d88P  Y88b..d88P  888    888   888     Y8888 Y88b  d88P                           ",
"  'Y8888P'888    888  'Y88888P'   'Y88888P'  888  8888888 888     Y888   Y8888P88             .         "  ,
"   *               .                    .                          '                                    .  ",
"                        .d8888b.  8888888b.   '     d8888 8888888888 88888888888         '     ",
"            *         d88P  Y88b 888   Y88b       d88888 888           888                  ",
"   '                 888    888 888    888      d88P888 888     '     888       .      ",
"               .    888        888   d88P     d88P 888 8888888       888             ",
"       .           888        8888888P'     d88P  888 888  '        888        .       ",
"                  888    888 888 T88b     d88P   888 888           888           ' ",
" .          *    :88b  d88P 888  T88b   d8888888888 888     .     888     *          ",
"      .          'Y8888P'  888   T88b d88P     888 888           888             .",
"                .             .           '               '                   .      ",
"			 ______     _ __                         __",
"			(  //      ( /  )     o     .      /)   ( /        .            /           . ",
"			  //_  _    /--<_  _,, _ _      __//     /    _ _,  _  _ _   __/     *  ",
"			_// /_(/_  /___(/(_)(_// /_    (_//_   (/___/(/(_)_(/_/ / /_(_/_              ",
"			                   /|           /)              /|                 *      ",
"			                  (/      .    (/              (/          .              ",
};

static const char *Team_Logo[] =
{
"                                                                        ",
"                               .88    ..88                                 ",
"                             .88'   ..88oooooooooo.                     .o8      oooo",
"                           .88'   ..88' 888'    Y8b                     888       888 ",
"                         .88'   .o88'   888      888 ooooo.oooo          888oooo.  888  .ooooo.",
"                       .88'   .88'      888      888 d88' `88b 888  `888 d88' `88b 888 d88' `88b ",
"                     .88'   .88'        888      888 888   888 888   888 888   888 888 888ooo888",
"                   .88'   .88'          888     d88 '888   888 888   888 888   888 888 888    .o ",
"                 .88'   .88'           o888bood8P'   `Y8bod8P' `V88V'V8' 'Y8bod8P'o888o`Y8bod8P'",
" 88.    88.    .88'   .88'.oooooo.  oooo                          oooo",
" '88.   '8o  .88'   .88' d8P'  `Y8b  888                           888",
"  '88    ' .88'   .88'  888          888.oo.    .ooooo.   .ooooo.  888  oooo",
"   88.   .888'  .88'    888          888P'Y88b d88' `88b d88' `'Y8 888 .8P'",
"   '88 .88 88 .88'      888          888   888 888ooo888 888       888888.",
"    '888   '888'        `88b    ooo  888   888 888.  888 .o8   888 88b.'88",
"     88'    88'          `Y8bood8P' o888o o888o`Y8bod8P'  Y8bod8P'o888o o888o",
};


/*Prints the Main menu. Gets input from the user and executes the expected act.*/
int Print_Menu()
{

    char user_choice[50];
    int still_run = true;
    int user_playmode_choice;

    while (still_run)
    {
        system("cls");

        for (int i = 0; i < GAME_LOGO_SIZE; i++)
        {
            printf("%s\n", GameLogo[i]);
        }

        printf("\n");
        printf("   *        1. Play                             *            \n");
        printf("            2. How To Play             .                            \n");
        printf("     .      3. Quit                             .            \n");
        printf("            4. Credits          *                               \n");
        printf("\n");
        printf("'       .   Enter A Number : ");

        scanf("%s", user_choice);

        /*Escapes the while loop when the input matches 1 to 4.*/
        if (strcmp(user_choice, "1") == 0 || strcmp(user_choice, "2") == 0 || strcmp(user_choice, "3") == 0 || strcmp(user_choice, "4") == 0 || strcmp(user_choice, "0") == 0)
        {
            still_run = false;
        }
        else
        {
            printf("Wrong Command! Try again\n");
            Sleep(500);
        }
    }

    if (strcmp(user_choice, "1") == 0)
    {
        Sound::play(11);
        Sound::volume(11, 3);
        Play_Menu(&user_playmode_choice);
        if (user_playmode_choice == EASY_MODE)
        {
            Sound::play(11);
            Sound::volume(11, 3);
            return EASY_MODE;
        }
        else if (user_playmode_choice == HARD_MODE)
        {
            Sound::play(11);
            Sound::volume(11, 3);
            return HARD_MODE;
        }

    }

    else if (strcmp(user_choice, "2") == 0)
    {
        Sound::play(11);
        Sound::volume(11, 3);
        How_To_Play();
    }
    else if (strcmp(user_choice, "3") == 0)
    {
        Sound::play(12);
        Sound::volume(12, 3);
        Sound::volume(0, 0);

        system("cls");
        printf("Bye!\n");

        Sleep(1800);
        return QUIT;
    }
    else if (strcmp(user_choice, "0") == 0)
    {
        Sound::play(11);
        Sound::volume(11, 3);
        return HACK_MODE;
    }
    else if (strcmp(user_choice, "4") == 0)
    {
        Sound::play(11);
        Sound::volume(11, 3);
        Credits();

        return 10;
    }


}

/*This is the play mode choide menu. User can either choose easy mode or hard mode.*/
void Play_Menu(int *choice)
{
    Sound::play(6);
    Sound::volume(6, 20);

    Transition();

    int run = true;
    char mode[50];

    while (run)
    {
        system("cls");
        printf("\n\n\n\n\n\n\n\n\n\n");
        printf("1. Easy Mode\n\n");
        printf("2. Hard Mode\n\n");
        printf("Enter A Number : ");

        scanf("%s", mode);

        /*Escapes the while loop when the input matches 1 to 2.*/
        if ((strcmp(mode, "1") == 0) || strcmp(mode, "2") == 0)
        {
            run = false;
        }
        else
        {
            printf("Wrong Command! Try again\n");
            Sleep(500);
        }
    }

    if (strcmp(mode, "1") == 0)
    {
        *choice = EASY_MODE;
        run = false;
    }
    if (strcmp(mode, "2") == 0)
    {
        *choice = HARD_MODE;
    }
}

/*This function prints out the credits of Shooint Craft.*/
void Credits()
{
    system("cls");
    adjustWindowSize(120, 35);

    Sound::play(9);
    Sound::volume(9, 10);

    for (int j = 0; j < LOGO_SIZE; j++)
    {
        printf("%s\n", Team_Logo[j]);
        Sleep(30);
    }


    printf("\n");
    const char line[LINE_SIZE] = "		President : Claude Comair\n\n		Instructor : David Ly		Made by : Double Check\n\n		Producer : JeeSoo Kim\n\n		Technical Manager : SangMin Kim\n\n		Sound Director : ChulSeung Lee\n\n		Designer : Hyun Kang\n\n		Test Manager : JunSeo Bae\n\n		 All content ?2018 DigiPen (USA) Corporation, all rights reserved\n";

    for (int i = 0; i < LINE_SIZE; i++)
    {
        Sleep(30);
        printf("%c", line[i]);
    }

    system("pause");
    Sound::play(11);
    Sound::volume(11, 3);
    adjustWindowSize(100, 45);
    //Print_Menu();

    return;
}

/*This function displays visual transition in the menu*/
void Transition()
{
    adjustWindowSize(90, 35);

    for (int i = 0; i < TRANSITION_COUNT; i++)
    {
        printf("       .                        .                         .             .         .  \n");
        printf("     *           .                                                           .    .  \n");
        printf("                                      .    *                     .     .           \n");
        printf("            *        .                                                              .\n");
        printf("       .                                                  .                       \n");
        printf("       .                        .                  .             .               .\n");
        printf("     *           .                                                                .     \n");
        printf("                                       .    *                     .     .              .\n");
        printf("                                         .                            .		  \n");
        printf("          *           .											  			  \n");
        int key = 1;
        printf("\n\n");
        switch (key)
        {
        case 1:
        {
            for (int j = 0; j < i; j++)
            {
                printf("   .");
            }
            printf("<[*]>=>");
            printf("\n");
        }
        case 2:
        {
            for (int j = 0; j < i; j++)
            {
                printf("    ");
            }
            printf(" (:=)");
            printf("\n");

        }
        case 3:
        {
            for (int j = 0; j < i; j++)
            {
                printf("   :");
            }
            printf("<[ H ]><=>=-");
            printf("\n");

        }
        case 4:
        {
            for (int j = 0; j < i; j++)
            {
                printf("    ");
            }
            printf(" (:=)");
            printf("\n");

        }
        case 5:
        {
            for (int j = 0; j < i; j++)
            {
                printf("   '");
            }
            printf("<[*]>=>");
            printf("\n");

        }
        printf("         .              .                  .                  *            \n");
        printf("                                                                           \n");
        printf("      .           .                     .       *                      .         \n");
        printf("                  *         .		    										   .\n");
        printf("       .                           .                           *			    \n");
        printf("       .                             .                  .             .			  \n");
        printf("     *           .														   \n");
        printf("                                                  .    *                  .     .	   \n");
        printf("            *        .		  											  .\n");
        printf("       .                                                          .				 \n");
        printf("       .                        .                  .		          	   .	 \n");
        printf("     *           .											    			 \n");

        }
        Wait(50);
        system("cls");

    }
    system("cls");
}

/*This function makes time difference and waits before the next line is executed.*/
void Wait(long waitTime)
{
    clock_t	wakeTime;
    wakeTime = waitTime + clock();
    while (wakeTime > clock())
    {

    }
}