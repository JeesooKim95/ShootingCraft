/**
\file        SetCursor_Move.cpp
\author      sangmin.kim
\par         email: ryan95kr@gmail.com
\brief
		This will change cursor's x,y position in console screen.
		
*/


#include "SetCursor_Move.h"
#include "MapStatus.h"

void Move_Cursor_Left(int cursor_x, int cursor_y, Ship_Map ship_map)
{
	int temp;
	temp = ship_map[cursor_y][cursor_x];
	ship_map[cursor_y][cursor_x] = AIR;
	ship_map[cursor_y][cursor_x - 1] = temp;


}
void Move_Cursor_Right(int cursor_x, int cursor_y, Ship_Map ship_map)
{
	int temp;
	temp = ship_map[cursor_y][cursor_x];
	ship_map[cursor_y][cursor_x] = AIR;
	ship_map[cursor_y][cursor_x + 1] = temp;

}
void Move_Cursor_Up(int cursor_x, int cursor_y, Ship_Map ship_map)
{
	int temp;
	temp = ship_map[cursor_y][cursor_x];
	ship_map[cursor_y][cursor_x] = AIR;
	ship_map[cursor_y - 1][cursor_x] = temp;

}
void Move_Cursor_Down(int cursor_x, int cursor_y, Ship_Map ship_map)
{
	int temp;
	temp = ship_map[cursor_y][cursor_x];
	ship_map[cursor_y][cursor_x] = AIR;
	ship_map[cursor_y + 1][cursor_x] = temp;

}