/**
\file        SetCursor_Position.h
\author      Chulseung Lee
\brief
        This is the header file of SetCursor_Position.cpp

        copyright   All content © 2018 DigiPen (USA) Corporation, all rights reserved
*/

#pragma once

void gotoxy(int x, int y);
#include "MapStatus.h"

typedef enum Cursor {

    Ship_Map_Cursor = -1

}Cursor;

void Initialize_Ship_Map_Cursor(Ship_Map ship_map);
void Move_Ship_Map_Cursor(Ship_Map ship_map, int dir, int cursor_x, int cursor_y);
void Get_Cursor_Position_Ship_Map(int *cursor_x, int *cursor_y, Ship_Map ship_map);
bool Check_Cursor_Position_Is_Good(int cursor_x, int cursor_y, int dir, Ship_Map ship_map);