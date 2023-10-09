/**
\file        Enemy_Part.h
\author      sangmin.kim
\par         email: ryan95kr@gmail.com
\brief
This is the header file Enemy parts.

copyright   All content © 2018 DigiPen (USA) Corporation, all rights reserved
*/
#pragma once

#define SIPO 15
#define NINE 9
#define SEVEN 7


typedef enum Enemy_Part {

    Enemy_Body_Right = 250,
    Enemy_Body_Left = 260,
    Enemy_Weapon = 270,
    Enemy_Head = 280,
    Enemy_Bullet = 290,

    Enemy_Body_Right2 = 300,
    Enemy_Body_Left2 = 310,
    Enemy_Head2 = 320,
    Enemy_Weapon2 = 330,

    Enemy_Body_Right3 = 350,
    Enemy_Body_Left3 = 355,
    Enemy_Head3 = 360,
    Enemy_Weapon3 = 365,

    Enemy_Body_Right4 = 370,
    Enemy_Body_Left4 = 375,
    Enemy_Head4 = 380,
    Enemy_Weapon4 = 385,

    Boss_Body = 4500,
    Boss_Weapon = 4600,
    Boss_Head = 4700,
    Boss_Head_In_Body = 4800,
    Boss_Bullet_2 = 4900,

    Boss_Weapon_3 = 5500,
    Boss_Core_Body_Unbreakable = 5400,
    Boss_Core_Weapon_Unbreakable = 5100,
    Boss_Weapon_2 = 5200,
    Boss_Core_Body = 440,
    Boss_Core_Weapon = 450,

    Enemy_Bullet_Col = 340,
    Enemy_Bullet2 = 395,
    Enemy_Bullet3 = 397

}Enemy_Part;

typedef struct Enemy_Type {

    int enemy_ship[3][3];
    int spawn_position_x;
    int spawn_position_y;
    int enemy_type;


}Enemy_Type;

typedef struct Enemy_Arr1 {

    int enemy_arr[20][30];

}Enemy_Arr1;

typedef struct Boss {

    int boss_arr[NINE][SIPO];
    int combine_1[SEVEN][SEVEN];
    int combine_2[SEVEN][SEVEN];
    int boss_part_1_spawn_position_x;
    int boss_part_1_spawn_position_y;
    int boss_part_2_spawn_position_x;
    int boss_part_2_spawn_position_y;
    int boss_spawn_position_x;
    int boss_spawn_position_y;

}Boss;

