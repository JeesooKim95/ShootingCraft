/*
   \file        Sound_Manager.cpp
   \project     Shooting Craft
   \author(s)   Chulseung Lee
   \copyright   All content � 2018 DigiPen (USA) Corporation, all rights reserved
*/

#include "Sound_Manager.h"

FMOD_RESULT Sound::result;
FMOD_SYSTEM * Sound::f_system;
FMOD_SOUND * Sound::sound[SOUND_NUM];
FMOD_CHANNEL * Sound::channel[CHANNEL_NUM];

/* Initializing Sounds */
void Sound::initialize(void)
{
    result = FMOD_System_Create(&f_system);
    result = FMOD_System_Init(f_system, 20, FMOD_INIT_NORMAL, 0);
    result = FMOD::Memory_Initialize(malloc(4 * 100000000), 4 * 100000000, 0, 0, 0);
}

/* Loading Sound files */
void Sound::load(void)
{
    result = FMOD_System_CreateStream(f_system, "Sound Asset//GameBGM.mp3", FMOD_LOOP_NORMAL, 0, &sound[0]);
    result = FMOD_System_CreateSound(f_system, "Sound Asset//GunShot.mp3", FMOD_DEFAULT, 0, &sound[1]);
    result = FMOD_System_CreateSound(f_system, "Sound Asset//Explosion.mp3", FMOD_DEFAULT, 0, &sound[2]);
    result = FMOD_System_CreateSound(f_system, "Sound Asset//BulletCollision.mp3", FMOD_DEFAULT, 0, &sound[3]);
    result = FMOD_System_CreateSound(f_system, "Sound Asset//Equipment.mp3", FMOD_DEFAULT, 0, &sound[4]);
    result = FMOD_System_CreateSound(f_system, "Sound Asset//Warning.mp3", FMOD_DEFAULT, 0, &sound[5]);
    result = FMOD_System_CreateSound(f_system, "Sound Asset//Loading.mp3", FMOD_DEFAULT, 0, &sound[6]);
    result = FMOD_System_CreateSound(f_system, "Sound Asset//PowerUp.mp3", FMOD_DEFAULT, 0, &sound[7]);
    result = FMOD_System_CreateSound(f_system, "Sound Asset//TeamDoubleCheck.mp3", FMOD_DEFAULT, 0, &sound[8]);
    result = FMOD_System_CreateSound(f_system, "Sound Asset//DouDouDouDoubleCheck.mp3", FMOD_DEFAULT, 0, &sound[9]);
    result = FMOD_System_CreateSound(f_system, "Sound Asset//PageTurning.mp3", FMOD_DEFAULT, 0, &sound[10]);
    result = FMOD_System_CreateSound(f_system, "Sound Asset//Click.mp3", FMOD_DEFAULT, 0, &sound[11]);
    result = FMOD_System_CreateSound(f_system, "Sound Asset//Quit.mp3", FMOD_DEFAULT, 0, &sound[12]);
    result = FMOD_System_CreateSound(f_system, "Sound Asset//Ting.mp3", FMOD_DEFAULT, 0, &sound[13]);
    result = FMOD_System_CreateStream(f_system, "Sound Asset//BossBGM.mp3", FMOD_LOOP_NORMAL, 0, &sound[14]);
    result = FMOD_System_CreateSound(f_system, "Sound Asset//Upgrade.mp3", FMOD_DEFAULT, 0, &sound[15]);
}

/* Playing specific sound */
void Sound::play(int Channel_Num)
{
    if (Channel_Num == 0 || Channel_Num == 14)
    {
        if (result != FMOD_OK)
        {
            return;
        }
        result = FMOD_System_PlaySound(f_system, sound[Channel_Num], 0, 0, &channel[Channel_Num]);
    }
    else if (Channel_Num == 1 || Channel_Num == 3 || Channel_Num == 7)
    {
        if (result != FMOD_OK)
        {
            return;
        }
        result = FMOD_System_PlaySound(f_system, sound[Channel_Num], 0, 0, &channel[Channel_Num]);
    }
    else
    {
        if (result != FMOD_OK)
        {
            return;
        }
        result = FMOD_System_PlaySound(f_system, sound[Channel_Num], 0, 0, &channel[Channel_Num]);

        if (result != FMOD_OK)
        {
            return;
        }
        result = FMOD_System_Update(f_system);
    }
}

/* Set Volume in specific channel */
void Sound::volume(int Channel_Num, float Volume)
{
    if (result != FMOD_OK)
    {
        return;
    }
    result = FMOD_Channel_SetVolume(channel[Channel_Num], Volume);
}