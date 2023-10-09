/**
\file        Ship_Status.h
\author      sangmin.kim
\par         email: ryan95kr@gmail.com
\brief
This is the header file of Ship_Statue.cpp

copyright   All content ?2018 DigiPen (USA) Corporation, all rights reserved

*/

#pragma once

typedef enum Ship_Part {

    Head = 200,
    Body = 205,
    Weapon = 210,
    Bullet = 215,
    Bullet_Col = 220,

    Ship_Die1 = 231,
    Ship_Die2 = 232,
    Ship_Die3 = 233,
    Ship_Die4 = 234,
    Ship_Die5 = 235,
    Ship_Die_Manager = 236,

    Bomb_Particle1 = 237,
    Bomb_Particle2 = 238,
    Bomb_Particle3 = 239,
    Bomb_Particle4 = 240,

    Item = 241

}Ship_Part;

typedef enum Ship_Bomb {

    Bomb = 1200,
    Bomb_Ready = 1201,

    User_Bomb_Particle1 = 1202,
    User_Bomb_Particle2 = 1203,
    User_Bomb_Particle3 = 1204,
    User_Bomb_Particle4 = 1205,
    User_Bomb_Particle5 = 1206,
    User_Bomb_Particle6 = 1207,

    Bomb_Effect1 = 1208,
    Bomb_Effect2 = 1209,
    Bomb_Effect3 = 1210,
    Bomb_Effect4 = 1211,
    Bomb_Effect5 = 1212,

}Ship_Bomb;