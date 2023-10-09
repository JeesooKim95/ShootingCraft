
/*
        \file        Start_Screen.h
        \project	 Shooting Craft
        \author(s)   Hyun Kang & Jeesoo Kim
		\par         email: hangam131313@gmail.com

        \copyright   All content ?2018 DigiPen (USA) Corporation, all rights reserved
*/
#pragma once

#include <stdio.h>
#include "windows.h"
#include "Console.h"
#include "HowToPlay.h"

#define EASY_MODE 1
#define HARD_MODE 2
#define QUIT 3
#define HACK_MODE 0

#define TRANSITION_COUNT 25

#define LOGO_SIZE 16
#define LINE_SIZE 295
#define GAME_LOGO_SIZE 25

int Print_Menu();
void Play_Menu(int* choice);
void Credits();
void Transition();
void Wait(long waitTime);
void Print_DigipenLogo();