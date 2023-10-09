/**
\file        User_Choice.cpp
\author      hyun.gang
\par         email: hangam131313@gmail.com
\brief
This file will print the array of when user power_up.

copyright   All content ?2018 DigiPen (USA) Corporation, all rights reserved
*/

#define _CRT_SECURE_NO_WARNINGS

#include "User_Choice.h"
#include "stdio.h"
#include "string.h"
#include <stdio.h>
#include "MapStatus.h"
#include "Input.h"
#include "SetCursor_Position.h"
#include "windows.h"

char board[BOARD_LOW][BOARD_COL] =
{
        ANSI_COLOR_YELLOW"                      < POWER UP >",ANSI_COLOR_RESET
        "                                   ",
        ANSI_COLOR_YELLOW"                        ( BODY )  ",ANSI_COLOR_RESET
        ANSI_COLOR_WHITE"                    INCLUDE MORE BODY",ANSI_COLOR_RESET
        "                                 ",
        ANSI_COLOR_YELLOW"                        ( WEAPON )",ANSI_COLOR_RESET
        ANSI_COLOR_WHITE"                    INCLUDE MORE WEAPON",ANSI_COLOR_RESET
        "                                      ",
        ANSI_COLOR_YELLOW"                      ( SHOOT SPEED )",ANSI_COLOR_RESET
        ANSI_COLOR_WHITE"                    UPGRADE SHOOT SPEED",ANSI_COLOR_RESET
        "                                    ",
        ANSI_COLOR_YELLOW"                        ( BULLET )",ANSI_COLOR_RESET
        ANSI_COLOR_WHITE"                    UPGRADE BULLET",ANSI_COLOR_RESET
		"      "
};

int cursor_pos_y = 2;


int User_Choice_Ask(int power_up)
{
    char user_num[BOARD_COL];



    printf("	More Body Parts		 : Press ");
    printf(ANSI_COLOR_GREEN "(B)\n\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_WHITE "\tInclude one more body parts in your ship\n\n\n");
    printf("	More Weapon Parts	 : Press ");
    printf(ANSI_COLOR_GREEN "(W)\n\n" ANSI_COLOR_RESET);
    printf("\tInclude one more weapon parts in your ship\n\n\n");
    printf("	More Shoot speed	 : Press ");
    printf(ANSI_COLOR_GREEN "(S)\n\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_WHITE "\tYour bullets will move fast!!\n\n\n");
    printf("	More Bullet		 : Press ");
    printf(ANSI_COLOR_GREEN "(A)\n\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_WHITE "\tYour can shoot more bullets!!!\n\n\n");
    printf(ANSI_COLOR_WHITE "\tType what you want and press " ANSI_COLOR_RED "'Enter'\n\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_YELLOW "Power_Up : %d\n\n" ANSI_COLOR_RESET, power_up);
    while (true)
    {
        scanf("%s", user_num);

        if ((strcmp(user_num, "s") == 0) || strcmp(user_num, "S") == 0 || strcmp(user_num, "B") == 0 || strcmp(user_num, "b") == 0 ||
            strcmp(user_num, "W") == 0 || strcmp(user_num, "w") == 0 || strcmp(user_num, "A") == 0 || strcmp(user_num, "a") == 0)
        {
            break;
        }
        else
        {
            printf("invalid input \n");
        }


    }

    if ((strcmp(user_num, "B") == 0) || strcmp(user_num, "b") == 0)
    {
        for (int i = 0; i < BOARD_COL; i++)
        {
            user_num[i] = 0;
        }
        return Want_Body;
    }
    else if ((strcmp(user_num, "W") == 0) || strcmp(user_num, "w") == 0)
        return Want_Weapon;
    else if ((strcmp(user_num, "s") == 0) || strcmp(user_num, "S") == 0)
        return Want_Shoot_Speed;
    else if ((strcmp(user_num, "a") == 0) || strcmp(user_num, "A") == 0)
        return Want_Shoot_More;

    else
        return 0;
}

int User_Ask_2(int power_up, bool *is_exit)
{

    int dir = 0;
    board[cursor_pos_y][CURSOR_POS_Y_UP] = Ship_Map_Cursor;
    while (dir != SPACE)
    {

        gotoxy(1, 1);
        dir = User_Input();
        Print_Ask();

        if (dir == ESC)
        {
            *is_exit = true;
            break;
        }

        switch (dir)
        {
        case UP:
            if (cursor_pos_y != CURSOR_POS_Y_TOP)
            {
                board[cursor_pos_y][CURSOR_POS_Y_UP] = AIR;
                cursor_pos_y -= CURSOR_POS_Y_UP;
                board[cursor_pos_y][CURSOR_POS_Y_UP] = Ship_Map_Cursor;

            }
            break;
        case DOWN:
            if (cursor_pos_y != CURSOR_POS_Y_BOTTOM)
            {
                board[cursor_pos_y][CURSOR_POS_Y_UP] = AIR;
                cursor_pos_y += CURSOR_POS_Y_UP;
                board[cursor_pos_y][CURSOR_POS_Y_UP] = Ship_Map_Cursor;

            }
            break;
        case SPACE:
            if (cursor_pos_y == USER_WANT_BODY)
            {
                return Want_Body;
            }
            else if (cursor_pos_y == USER_WANT_WEAPON)
            {
                return Want_Weapon;
            }
            else if (cursor_pos_y == USER_WANT_SHOOT_SPEED)
            {
                return Want_Shoot_Speed;
            }
            else if (cursor_pos_y == USER_WANT_SHOOT_MORE)
            {
                return Want_Shoot_More;
            }
            break;

        }

    }
    return 0;
}

void Print_Ask()
{

    for (int i = 0; i < BOARD_LOW; i++)
    {
        for (int j = 0; j < BOARD_COL; j++)
        {
            if (board[i][j] != 0)
            {
                printf("%c", board[i][j]);
            }
            else if (board[i][j] == AIR)
            {
                printf(" ");
            }
            else if (board[i][j] == Ship_Map_Cursor)
            {
                printf("O");

            }
        }
        printf("\n");
    }
}