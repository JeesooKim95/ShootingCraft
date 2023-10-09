
/**
\file        ShipMap_InsertWeapon.cpp
\author     jeesoo.kim
\brief
This will keep on asking the user to insert weapon until the weapon_power is smaller than 0.

copyright   All content ?2018 DigiPen (USA) Corporation, all rights reserved
*/

#include "MapStatus.h"
#include "Input.h"
#include "SetCursor_Position.h"
#include "ShipMap_Display.h"
#include "Ship_Status.h"
#include "ShipMap_InsertWeapon.h"
#include "Sound_Manager.h"
#include "ShipMap_InsertBody.h"

void ShipMap_InsertWeapon(Ship_Map ship_map, bool *insert_weapon, bool *insert_ship, int weapon_power)
{
    system("cls");

    int dir = 0;
    int cursor_x = 0, cursor_y = 0;
    bool only_one_cursor = true;
    do {
        gotoxy(1, 1);

        ShipMap_Display(ship_map);

        printf("Insert " ANSI_COLOR_MAGENTA "Weapon" ANSI_COLOR_RESET " where you want\n");
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

        Set_Weapon(ship_map, dir, cursor_x, cursor_y, &only_one_cursor, &weapon_power);


    } while (weapon_power > 0);

    *insert_weapon = false;
    *insert_ship = false;
}

void Set_Weapon(Ship_Map ship_map, int dir, int cursor_x, int cursor_y, bool *only_one_cursor, int *weapon_power)
{
    if (Check_Next(ship_map, cursor_x, cursor_y))
    {
        if (dir == SPACE)
        {
            ship_map[cursor_y][cursor_x] = Weapon;
            *only_one_cursor = true;
            *weapon_power -= 1;

            Sound::play(4);
            Sound::volume(4, 50);
        }
    }
}