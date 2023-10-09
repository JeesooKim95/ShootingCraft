/*
   \file        Game_Logo_Init.h
   \project    Shooting Craft
   \author(s)	hyun gang
   \par         email: hangam131313@gmail.com

   \copyright   All content © 2018 DigiPen (USA) Corporation, all rights reserved
*/
#define _CRT_SECURE_NO_WARNINGS

#include "Game_Logo_Init.h"
#include "Start_Screen.h"
#include "Sound_Manager.h"

#define FMOD_SIZE 13

static const char* Fmod_Logo[] =
{
"          .;oxkOOOOk:                                                                  ;xkkk:       ",
"        .dKWMMMMMMMWo                                                                  oWMMWo       ",
"       ;0WMMWXOkkkkk;                                                                  oWMMWo       ",
"      .OMMMNd'          .'''.            ..''..              ..'''..            .',,'..oWMMWo       ",
"  ,oooONMMM0'.cxko'  .lOXNNNKk:.       'o0XNNNKx;         .lkKNNWNX0d:.      'lOKNWWNX0XMMMWo       ",
"  oWMMMMMMMO'cNMMMx.,0WMMMMMMMWx.     :KMMMMMMMMNo'.    .lKWMMMMMMMMMWO;   .dXMMMMMMMMMMMMMWo       ",
"  c000XWMMMO'.oO0x,.kMMMNxlOWMMNo    'OMMMXdoKMMMX0c   .dWMMWKo::lkNMMMX: .kWMMW0oc:cxKWMMWK:       ",
"   ...:XMMMO.      cNMMMk. ;KMMMK,   oWMMWd. :XMMMWO.  ;XMMM0,     lNMMMk.cNMMMk.     .;lo:.        ",
"      ;XMMMO.     'OMMMX:  .dWMMWx. ;KMMM0,  .xWMMMNl  ;XMMMO'     cXMMMk'lNMMWx.     ;k0Ol.        ",
"      ;KMMMO.   .;xWMMWx.   '0MMMNo:OWMMNl    ;KMMMMKl',kWMMWOc,';dXMMMNc '0MMMNk:,,:xNMMMK, ...    ",
"      ;KMMMO.  .kWMMMM0,     :XMMMWWMMMWx.     lNMMMMWXl'xNMMMMWWWMMMMKc.  ,OWMMMWWWMMMMW0:.' R '.  ",
"      ;KMMMO.  .OMMNKo.       ,xXWMMWN0l.      .:kKXWMWl  ;d0NWMMMWXOl.     .:xKNWMMMNKkc. .'...' ",
"      .;ccc,    ,c:,.           .,::;'.           ..;::.    .';:c:,.           .';:::,.        ",

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
" 88.     88.   .88'   .88'.oooooo.  oooo                          oooo",
" '88.    'o  .88'   .88' d8P'  `Y8b  888                           888",
"  '88    ' .88'   .88'  888          888.oo.    .ooooo.   .ooooo.  888  oooo",
"   88.   .888'  .88'    888          888P'Y88b d88' `88b d88' `'Y8 888 .8P'",
"   '88 .88 88 .88'      888          888   888 888ooo888 888       888888.",
"    '888   '888'        `88b    ooo  888   888 888.  888 .o8   888 88b.'88",
"     88'    88'          `Y8bood8P' o888o o888o`Y8bod8P'  Y8bod8P'o888o o888o",
};

void Print_Fmod_Logo()
{
    for (int j = 0; j < FMOD_SIZE; j++)
    {
        printf("%s\n", Fmod_Logo[j]);
    }
}

void Print_DigipenLogo()
{
    FILE *fp = NULL;
    int c;

    fp = fopen("DigiPenLogo (Unofficial).txt", "r");
    while ((c = fgetc(fp)) != EOF)
    {
        putchar(c);
    }

    fclose(fp);

}

void Open_Logo()
{

    printf("\n\n\n\n\n\n\n");
    Print_DigipenLogo();

    Sleep(1800);

    system("cls");
    printf("\n\n\n\n\n\n\n");
    Print_Fmod_Logo();
    Sleep(1800);

    system("cls");
    printf("\n\n\n\n\n\n\n");
    for (int j = 0; j < LOGO_SIZE; j++)
    {
        printf("%s\n", Team_Logo[j]);
    }

    Sound::play(8);
    Sound::volume(8, 5);
    Sleep(1600);

    Sound::play(0);
    Sound::volume(0, 25);

}