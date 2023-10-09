/**
\file        ShipMap_InsertHead.h
\author      jeesoo.kim
\brief
This is the header file of ShipMap_InsertHead.cpp

copyright   All content ?2018 DigiPen (USA) Corporation, all rights reserved
*/

#pragma once
#include "MapStatus.h"

void ShipMap_InsertHead(Ship_Map ship_map, bool *insert_head, bool *insert_body);
void Set_Head(Ship_Map ship_map, int dir, int cursor_x, int cursor_y, bool *only_one_cursor, bool *only_one_head);