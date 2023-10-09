/**
\file        ShipMap_InsertHead.cpp
\author     jeesoo.kim
\brief
This file keeps on asking the user to insert the head of the ship.

copyright   All content ?2018 DigiPen (USA) Corporation, all rights reserved
*/

#include "MapStatus.h"
#include "Input.h"
#include "SetCursor_Position.h"
#include "ShipMap_Display.h"
#include "Ship_Status.h"
#include "ShipMap_InsertHead.h"
#include "Sound_Manager.h"

void ShipMap_InsertHead(Ship_Map ship_map, bool *insert_head, bool *insert_body)
{
    system("cls");

    int dir = 0;
    int cursor_x = 0, cursor_y = 0;
    bool only_one_cursor = true;
    bool only_one_head = true;

    do {
        gotoxy(1, 1);

        ShipMap_Display(ship_map);

        printf("Insert " ANSI_COLOR_RED "Head" ANSI_COLOR_RESET " where you want\n");
        printf("Press ");
        printf(ANSI_COLOR_CYAN "SPACE" ANSI_COLOR_RESET);

        dir = User_Input();

        if (only_one_cursor)
        {
            Initialize_Ship_Map_Cursor(ship_map);
            only_one_cursor = false;
        }
        Get_Cursor_Position_Ship_Map(&cursor_x, &cursor_y, ship_map);

        Move_Ship_Map_Cursor(ship_map, dir, cursor_x, cursor_y);

        Set_Head(ship_map, dir, cursor_x, cursor_y, &only_one_cursor, &only_one_head);

        if (only_one_head == false)
        {
            *insert_head = false;
            *insert_body = true;
        }

    } while (only_one_head);
}

void Set_Head(Ship_Map ship_map, int dir, int cursor_x, int cursor_y, bool *only_one_cursor, bool *only_one_head)
{

    if (dir == CTR)
    {
        ship_map[cursor_y][cursor_x] = Head;
        *only_one_cursor = true;
        *only_one_head = false;

        Sound::play(4);
        Sound::volume(4, 50);
    }
}