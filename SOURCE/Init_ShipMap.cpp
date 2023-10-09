/**
\file        Init_ShipMap.cpp
\author      Chulseung Lee
\brief
        This file will initialize the player's own ship to ship_world.

        Initialize_ShipWorld : with while looping, the user will insert the head, body, weapon to ship_map.
                                                        whole looping = insert_ship.(will ask until user set whole ship)
                                                        insert_head   = will ask until user set head in ship_map.
                                                        insert_body   = will ask until user set body in ship_map.
                                                        insert_weapon = will ask until user set weapon in ship_map.

        copyright   All content ?2018 DigiPen (USA) Corporation, all rights reserved

*/
#include "Init_ShipMap.h"
#include "MapStatus.h"
#include "ShipMap_InsertHead.h"
#include "ShipMap_InsertBody.h"
#include "ShipMap_InsertWeapon.h"

void Initialize_ShipWorld(Ship_Map ship_map, int body_power, int weapon_power)
{
    bool insert_ship = true;
    bool insert_head = true;
    bool insert_body = false;
    bool insert_weapon = false;

    while (insert_ship)
    {
        while (insert_head)
        {
            ShipMap_InsertHead(ship_map, &insert_head, &insert_body);
        }

        while (insert_body)
        {
            ShipMap_InsertBody(ship_map, &insert_body, &insert_weapon, body_power);
        }

        while (insert_weapon)
        {
            ShipMap_InsertWeapon(ship_map, &insert_weapon, &insert_ship, weapon_power);
        }

    }

}

void Initialize_ShipWorld_During(Ship_Map ship_map, int body_power, int weapon_power)
{
    bool insert_ship = true;
    bool insert_body = true;
    bool insert_weapon = false;

    if (body_power == 0 && weapon_power == 1)
    {
        insert_body = false;
        insert_weapon = true;
    }
    while (insert_ship)
    {
        while (insert_body)
        {
            ShipMap_InsertBody(ship_map, &insert_body, &insert_weapon, body_power);
        }

        while (insert_weapon)
        {
            ShipMap_InsertWeapon(ship_map, &insert_weapon, &insert_ship, weapon_power);
        }
    }
}