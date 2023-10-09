/**
\file        User_Choice.h
\author      hyun.gang
\par         email: hangam131313@gmail.com
\brief
This is the header file of User_Choice.cpp

copyright   All content ?2018 DigiPen (USA) Corporation, all rights reserved
*/

#define BOARD_LOW 20
#define BOARD_COL 50


#define CURSOR_POS_Y_BOTTOM 11
#define CURSOR_POS_Y_UP 3
#define CURSOR_POS_Y_TOP 2

#define USER_WANT_BODY 2
#define USER_WANT_WEAPON 5
#define USER_WANT_SHOOT_SPEED 8
#define USER_WANT_SHOOT_MORE 11

#pragma once
int User_Choice_Ask(int power_up);
int User_Ask_2(int power_up, bool *is_exit);
void Print_Ask();

typedef enum Choice {

    Want_Body = 1000,
    Want_Weapon = 1001,
    Want_Shoot_Speed = 1002,
    Want_Shoot_More = 1003,
    Want_Restart = 1004,
    Want_Quit = 1005

}Choice;