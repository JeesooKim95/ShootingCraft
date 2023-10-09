/*
   \file        Sound_Manager.h
   \project     Shooting Craft
   \author(s)   Chulseung Lee
   \copyright   All content ?2018 DigiPen (USA) Corporation, all rights reserved
*/

#define SOUND_NUM       20
#define CHANNEL_NUM     20

#include "fmod.hpp"
#include "fmod_errors.h"
#include "stdlib.h"

/* Declare variables and functions */
class Sound {
public:
    static FMOD_RESULT result;
    static FMOD_SYSTEM * f_system;
    static FMOD_SOUND * sound[SOUND_NUM];
    static FMOD_CHANNEL * channel[SOUND_NUM];

public:
    static void initialize(void);
    static void load(void);
    static void play(int Channel_Num);
    static void volume(int Channel_Num, float Volume);
};