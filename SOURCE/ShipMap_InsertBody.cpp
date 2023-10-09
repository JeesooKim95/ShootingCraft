/**
\file        ShipMap_InsertBody.cpp
\author      jeesoo.kim
\brief
This file asks the user to insert the body of the ship until the body_power is smaller than 0.

copyright   All content ?2018 DigiPen (USA) Corporation, all rights reserved
*/

#include "MapStatus.h"
#include "Input.h"
#include "SetCursor_Position.h"
#include "ShipMap_Display.h"
#include "Ship_Status.h"
#include "ShipMap_InsertBody.h"
#include "Sound_Manager.h"

void ShipMap_InsertBody(Ship_Map ship_map, bool *insert_body, bool *insert_weapon, int body_power)
{
    system("cls");

    int dir = 0;
    int cursor_x = 0, cursor_y = 0;
    bool only_one_cursor = true;

    do {
        gotoxy(1, 1);

        ShipMap_Display(ship_map);

        printf("Insert " ANSI_COLOR_GREEN "Body" ANSI_COLOR_RESET " where you want\n");
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

        Set_Body(ship_map, dir, cursor_x, cursor_y, &only_one_cursor, &body_power);


    } while (body_power > 0);

    *insert_body = false;
    *insert_weapon = true;
}

void Set_Body(Ship_Map ship_map, int dir, int cursor_x, int cursor_y, bool *only_one_cursor, int *body_power)
{
    if (Check_Next(ship_map, cursor_x, cursor_y))
    {
        if (dir == SPACE)
        {
            ship_map[cursor_y][cursor_x] = Body;
            *only_one_cursor = true;
            *body_power -= 1;
            Sound::play(4);
            Sound::volume(4, 50);
        }
    }
}

bool Check_Next(Ship_Map ship_map, int cursor_x, int cursor_y)
{
    for (int i = cursor_y - 1; i <= cursor_y + 1; i++)
    {
        for (int j = cursor_x - 1; j <= cursor_x + 1; j++)
        {
            if ((ship_map[i][j] <= Head && ship_map[i][j] >= Head - 2) ||
                (ship_map[i][j] <= Body && ship_map[i][j] >= Body - 2) ||
                (ship_map[i][j] <= Weapon && ship_map[i][j] >= Weapon - 2))
            {
                return true;
            }
        }
    }
    return false;
}