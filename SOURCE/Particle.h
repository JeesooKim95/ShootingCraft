/**
\file        Particle.h
\author      hyun.gang
\par         email: hangam131313@gmail.com
\brief
This is the header file of Particle.cpp

copyright   All content ?2018 DigiPen (USA) Corporation, all rights reserved
*/
#pragma once

#include "MapStatus.h"
#include "Ship_Status.h"
#include "Enemy_Part.h"


void Particle_Ship(Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status);
void Bomb_Particle(Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status);