/**
\file        SetCursor_Move.h
\author      Chulseung Lee
\brief
This is the header file of SetCursor_Move.cpp

copyright   All content © 2018 DigiPen (USA) Corporation, all rights reserved
*/


#pragma once
#include "MapStatus.h"

void Move_Cursor_Left(int cursor_x,int cursor_y, Ship_Map ship_map);
void Move_Cursor_Right(int cursor_x, int cursor_y, Ship_Map ship_map);
void Move_Cursor_Up(int cursor_x, int cursor_y, Ship_Map ship_map);
void Move_Cursor_Down(int cursor_x, int cursor_y, Ship_Map ship_map);