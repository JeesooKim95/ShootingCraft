/**
\file        GameMap_Count.cpp
\author      sangmin.kim
\par         email: ryan95kr@gmail.com
\brief
This file will count the current element's count in map array.

copyright   All content ?2018 DigiPen (USA) Corporation, all rights reserved
*/
#include "MapStatus.h"
#include "Ship_Status.h"
#include "GameMap_Count.h"
#include "Enemy_Part.h"
#include "Item.h"

void Get_Count_Game_Map(Game_Map game_map, Map_Status_Count* current_map_status)
{

    int ship_head_count = 0;
    int ship_weapon_count = 0;
    int ship_whole_count = 0;
    int ship_bullet_count = 0;
    int ship_body_count = 0;

    int enemy_whole_count = 0;
    int enemy_body_count = 0;
    int enemy_weapon_count = 0;
    int enemy_head_count = 0;
    int enemy_bullet_count = 0;
    int enemy_bullet_count2 = 0;

    int enemy_whole_count2 = 0;
    int enemy_body_count2 = 0;
    int enemy_weapon_count2 = 0;
    int enemy_head_count2 = 0;

    int enemy_whole_count3 = 0;
    int enemy_body_count3 = 0;
    int enemy_weapon_count3 = 0;
    int enemy_head_count3 = 0;

    int enemy_whole_count4 = 0;
    int enemy_body_count4 = 0;
    int enemy_weapon_count4 = 0;
    int enemy_head_count4 = 0;

    int boss_whole_count = 0;
    int boss_body_count = 0;
    int boss_weapon_count = 0;
    int boss_head_count_in_body = 0;
    int boss_core_body_count = 0;
    int boss_core_weapon_count = 0;
    int boss_head_count = 0;
    int boss_bullet_2_count = 0;
    int boss_body_unbreakable_count = 0;
    int boss_weapon_unbreakable_count = 0;
    int boss_weapon_2_count = 0;
    int boss_weapon_3_count = 0;

    int enemy_all_count = 0;
    int enemy_all_weapon_count = 0;
    int enemy_all_weapon_count2 = 0;
    int bullet_col_count = 0;
    int bullet_col_enemy_count = 0;

    int ship_particle_count = 0;
    int bomb_particle_count = 0;
    int user_bomb_particle_count = 0;
    int particle_manager_count = 0;
    int item_count = 0;

    int user_bomb_count2 = 0;
    int user_bomb_ready_count = 0;

    for (int i = 0; i < LOW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if (game_map[i][j] <= Body && game_map[i][j] >= Body - 2)
            {
                ship_body_count++;
                ship_whole_count++;
            }
            else if (game_map[i][j] <= Head && game_map[i][j] >= Head - 2)
            {
                ship_head_count++;
                ship_whole_count++;
            }
            else if (game_map[i][j] <= Weapon && game_map[i][j] >= Weapon - 2)
            {
                ship_weapon_count++;
                ship_whole_count++;
            }
            else if (game_map[i][j] == Bullet)
            {
                ship_bullet_count++;
            }
            else if ((game_map[i][j] <= Enemy_Body_Left && game_map[i][j] >= Enemy_Body_Left - 2) ||
                (game_map[i][j] <= Enemy_Body_Right && game_map[i][j] >= Enemy_Body_Right - 2))
            {
                enemy_whole_count++;
                enemy_body_count++;
                enemy_all_count++;
            }
            else if (game_map[i][j] <= Enemy_Head && game_map[i][j] >= Enemy_Head - 2)
            {
                enemy_whole_count++;
                enemy_head_count++;
                enemy_all_count++;
            }
            else if (game_map[i][j] <= Enemy_Weapon && game_map[i][j] >= Enemy_Weapon - 2)
            {
                enemy_whole_count++;
                enemy_weapon_count++;
                enemy_all_count++;
                enemy_all_weapon_count++;
            }
            else if (game_map[i][j] == Enemy_Bullet)
            {
                enemy_bullet_count++;
            }
            else if (game_map[i][j] == Enemy_Bullet2)
            {
                enemy_bullet_count2++;
            }
            else if ((game_map[i][j] <= Enemy_Body_Left2 && game_map[i][j] >= Enemy_Body_Left2 - 2) ||
                (game_map[i][j] <= Enemy_Body_Right2 && game_map[i][j] >= Enemy_Body_Right2 - 2))
            {
                enemy_whole_count2++;
                enemy_body_count2++;
                enemy_all_count++;
            }
            else if (game_map[i][j] <= Enemy_Head2 && game_map[i][j] >= Enemy_Head2 - 2)
            {
                enemy_whole_count2++;
                enemy_head_count2++;
                enemy_all_count++;
            }
            else if (game_map[i][j] <= Enemy_Weapon2 && game_map[i][j] >= Enemy_Weapon2 - 2)
            {
                enemy_whole_count2++;
                enemy_weapon_count2++;
                enemy_all_count++;
                enemy_all_weapon_count++;
            }
            else if ((game_map[i][j] <= Enemy_Body_Left3 && game_map[i][j] >= Enemy_Body_Left3 - 2) ||
                (game_map[i][j] <= Enemy_Body_Right3 && game_map[i][j] >= Enemy_Body_Right3 - 2))
            {
                enemy_whole_count3++;
                enemy_body_count3++;
                enemy_all_count++;
            }
            else if (game_map[i][j] <= Enemy_Head3 && game_map[i][j] >= Enemy_Head3 - 2)
            {
                enemy_whole_count3++;
                enemy_head_count3++;
                enemy_all_count++;
            }
            else if (game_map[i][j] <= Enemy_Weapon3 && game_map[i][j] >= Enemy_Weapon3 - 2)
            {
                enemy_whole_count3++;
                enemy_weapon_count3++;
                enemy_all_count++;
                enemy_all_weapon_count2++;
            }
            else if ((game_map[i][j] <= Enemy_Body_Left4 && game_map[i][j] >= Enemy_Body_Left4 - 2) ||
                (game_map[i][j] <= Enemy_Body_Right4 && game_map[i][j] >= Enemy_Body_Right4 - 2))
            {
                enemy_whole_count4++;
                enemy_body_count4++;
                enemy_all_count++;
            }
            else if (game_map[i][j] <= Enemy_Head4 && game_map[i][j] >= Enemy_Head4 - 2)
            {
                enemy_whole_count4++;
                enemy_head_count4++;
                enemy_all_count++;
            }
            else if (game_map[i][j] <= Enemy_Weapon4 && game_map[i][j] >= Enemy_Weapon4 - 2)
            {
                enemy_whole_count4++;
                enemy_weapon_count4++;
                enemy_all_count++;
                enemy_all_weapon_count2++;
            }
            else if (game_map[i][j] <= Boss_Body && game_map[i][j] >= Boss_Body - 8)
            {
                boss_body_count++;
                boss_whole_count++;
            }
            else if (game_map[i][j] <= Boss_Weapon && game_map[i][j] >= Boss_Weapon - 8)
            {
                boss_weapon_count++;
                boss_whole_count++;
            }
            else if (game_map[i][j] == Boss_Head)
            {
                boss_head_count++;
                boss_whole_count++;
            }
            else if (game_map[i][j] == Boss_Head_In_Body)
            {
                boss_head_count_in_body++;
                boss_whole_count++;
            }
            else if (game_map[i][j] <= Boss_Core_Body && game_map[i][j] >= Boss_Core_Body - 8)
            {
                boss_core_body_count++;
                boss_whole_count++;
            }
            else if (game_map[i][j] <= Boss_Core_Weapon && game_map[i][j] >= Boss_Core_Weapon - 8)
            {
                boss_core_weapon_count++;
                boss_whole_count++;
            }
            else if (game_map[i][j] == Boss_Core_Body_Unbreakable)
            {
                boss_body_unbreakable_count++;
                boss_whole_count++;
            }
            else if (game_map[i][j] == Boss_Core_Weapon_Unbreakable)
            {

                boss_weapon_unbreakable_count++;
                boss_whole_count++;
            }
            else if (game_map[i][j] == Boss_Bullet_2)
            {
                boss_bullet_2_count++;

            }
            else if (game_map[i][j] <= Boss_Weapon_2 && game_map[i][j] >= Boss_Weapon_2 - 8)
            {
                boss_whole_count++;
                boss_weapon_2_count++;

            }
            else if (game_map[i][j] <= Boss_Weapon_3 && game_map[i][j] >= Boss_Weapon_3 - 8)
            {
                boss_whole_count++;
                boss_weapon_3_count++;

            }

            else if (game_map[i][j] == Bullet_Col)
            {
                bullet_col_count++;

            }
            else if (game_map[i][j] == Enemy_Bullet_Col)
            {
                bullet_col_enemy_count++;

            }
            else if (game_map[i][j] == Ship_Die1 || game_map[i][j] == Ship_Die2 ||
                game_map[i][j] == Ship_Die3 || game_map[i][j] == Ship_Die4 ||
                game_map[i][j] == Ship_Die5)
            {
                ship_particle_count++;

            }
            else if (game_map[i][j] == Bomb_Effect1 || game_map[i][j] == Bomb_Effect2 ||
                game_map[i][j] == Bomb_Effect4 || game_map[i][j] == Bomb_Effect3 ||
                game_map[i][j] == Bomb_Effect5)
            {
                user_bomb_particle_count++;

            }
            else if (game_map[i][j] == Bomb_Particle1 || game_map[i][j] == Bomb_Particle2 ||
                game_map[i][j] == Bomb_Particle3 || game_map[i][j] == Bomb_Particle4)
            {
                bomb_particle_count++;

            }
            else if (game_map[i][j] == User_Bomb_Particle1 || game_map[i][j] == User_Bomb_Particle2 ||
                game_map[i][j] == User_Bomb_Particle3 || game_map[i][j] == User_Bomb_Particle4 ||
                game_map[i][j] == User_Bomb_Particle5 || game_map[i][j] == User_Bomb_Particle6)
            {
                user_bomb_particle_count++;
            }
            else if (game_map[i][j] == Ship_Die_Manager)
            {
                particle_manager_count++;

            }
            else if (game_map[i][j] == Item_Red || game_map[i][j] == Item_Yellow ||
                game_map[i][j] == Item_Puple || game_map[i][j] == Item_Cyan ||
                game_map[i][j] == Item_Blue || game_map[i][j] == Item_Green ||
                game_map[i][j] == Item_White)
            {
                item_count++;

            }
            else if (game_map[i][j] == Bomb)
            {
                user_bomb_count2++;

            }
            else if (game_map[i][j] == Bomb_Ready)
            {
                user_bomb_ready_count++;

            }



        }


    }

    current_map_status->count_ship_body = ship_body_count;
    current_map_status->count_ship_weapon = ship_weapon_count;
    current_map_status->count_ship_head = ship_head_count;
    current_map_status->count_whole_ship = ship_whole_count;
    current_map_status->count_ship_bullet = ship_bullet_count;

    current_map_status->count_enemy_body = enemy_body_count;
    current_map_status->count_enemy_weapon = enemy_weapon_count;
    current_map_status->count_enemy_head = enemy_head_count;
    current_map_status->count_enemy_whole_ship = enemy_whole_count;
    current_map_status->count_enemy_bullet = enemy_bullet_count;
    current_map_status->count_enemy_bullet2 = enemy_bullet_count2;

    current_map_status->count_enemy_body2 = enemy_body_count2;
    current_map_status->count_enemy_weapon2 = enemy_weapon_count2;
    current_map_status->count_enemy_head2 = enemy_head_count2;
    current_map_status->count_enemy_whole_ship2 = enemy_whole_count2;
    current_map_status->count_all_enemy_weapon = enemy_all_weapon_count;
    current_map_status->count_all_enemy_weapon2 = enemy_all_weapon_count2;

    current_map_status->count_enemy_body3 = enemy_body_count3;
    current_map_status->count_enemy_weapon3 = enemy_weapon_count3;
    current_map_status->count_enemy_head3 = enemy_head_count3;
    current_map_status->count_enemy_whole_ship3 = enemy_whole_count3;

    current_map_status->count_enemy_body4 = enemy_body_count4;
    current_map_status->count_enemy_weapon4 = enemy_weapon_count4;
    current_map_status->count_enemy_head4 = enemy_head_count4;
    current_map_status->count_enemy_whole_ship4 = enemy_whole_count4;

    current_map_status->count_boss_body = boss_body_count;
    current_map_status->count_boss_weapon = boss_weapon_count;
    current_map_status->count_boss_core_body = boss_core_body_count;
    current_map_status->count_boss_core_weapon = boss_core_weapon_count;
    current_map_status->count_boss_head = boss_head_count;
    current_map_status->count_boss_head_in_body = boss_head_count_in_body;
    current_map_status->count_boss_whole = boss_whole_count;
    current_map_status->count_boss_bullet_2 = boss_bullet_2_count;
    current_map_status->count_boss_body_unbreakable = boss_body_unbreakable_count;
    current_map_status->count_boss_weapon_unbreakable = boss_weapon_unbreakable_count;
    current_map_status->count_all_enemy = enemy_all_count;
    current_map_status->count_boss_weapon_2 = boss_weapon_2_count;
    current_map_status->count_boss_weapon_3 = boss_weapon_3_count;

    current_map_status->count_bullet_col = bullet_col_count;
    current_map_status->count_bullet_col_enemy = bullet_col_enemy_count;

    current_map_status->count_ship_particle = ship_particle_count;
    current_map_status->count_particle_manager = particle_manager_count;
    current_map_status->count_bome_particle = bomb_particle_count;
    current_map_status->user_bomb_particle_count = user_bomb_particle_count;
    current_map_status->count_item = item_count;
    current_map_status->user_bomb_count = user_bomb_count2;
    current_map_status->bomb_ready_count = user_bomb_ready_count;
}