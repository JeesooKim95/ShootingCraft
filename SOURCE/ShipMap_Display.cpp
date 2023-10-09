/**
\file        ShipMap_Display.cpp
\author      jeesoo.kim
\brief
<<<<<<< .mine
                This file will check the ship_map's each elements and printing in the console screen.

                (18.11.09 Revised) : Take professor David's feedback, change the space of each elements in display.

                copyright   All content ?2018 DigiPen (USA) Corporation, all rights reserved

*/

#include "ShipMap_Display.h"
#include "MapStatus.h"
#include "SetCursor_Position.h"
#include "windows.h"
#include "conio.h"
#include "Ship_Status.h"

void ShipMap_Display(Ship_Map ship_map)
{
    for (int i = 0; i < SHIP_LOW; i++)
    {
        for (int j = 0; j < SHIP_COL; j++)
        {
            if (ship_map[i][j] == AIR)
            {
                printf("    ");
            }
            else if (ship_map[i][j] == WALL)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                printf("   X");
            }
            else if (ship_map[i][j] == Ship_Map_Cursor)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                printf("   0");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            }
            else if (ship_map[i][j] == Head || ship_map[i][j] == Head - 1 || ship_map[i][j] == Head - 2)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                printf("   H");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            }
            else if (ship_map[i][j] == Body || ship_map[i][j] == Body - 1 || ship_map[i][j] == Body - 2)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                printf("   B");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            }
            else if (ship_map[i][j] == Weapon || ship_map[i][j] == Weapon - 1 || ship_map[i][j] == Weapon - 2)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
                printf("   W");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            }
            else
                printf("%4d", ship_map[i][j]);
        }
        printf("\n\n");
    }
}