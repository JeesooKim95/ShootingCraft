/**
\file        GameMap_Position.h
\author      sangmin.kim
\par         email: ryan95kr@gmail.com
\brief
This file will get current x,y position of each elements.

copyright   All content ?2018 DigiPen (USA) Corporation, all rights reserved
*/
#include "GameMap_Position.h"
#include "MapStatus.h"
#include "Ship_Status.h"
#include "Enemy_Part.h"
#include "SetCursor_Position.h"
#include "Item.h"

void Get_XY_Game_Map(Game_Map game_map, XY_Position_Ship *current_ship_xy)
{
    int body_int = 0;
    int weapon_int = 0;
    int head_int = 0;
    int whole_int = 0;
    int bullet_int = 0;

    int body_int_enemy = 0;
    int weapon_int_enemy = 0;
    int head_int_enemy = 0;
    int whole_int_enemy = 0;
    int bullet_int_enemy = 0;
    int bullet_int_enemy2 = 0;

    int body_int_enemy2 = 0;
    int weapon_int_enemy2 = 0;
    int head_int_enemy2 = 0;
    int whole_int_enemy2 = 0;

    int body_int_enemy3 = 0;
    int weapon_int_enemy3 = 0;
    int head_int_enemy3 = 0;
    int whole_int_enemy3 = 0;

    int body_int_enemy4 = 0;
    int weapon_int_enemy4 = 0;
    int head_int_enemy4 = 0;
    int whole_int_enemy4 = 0;

    int boss_whole_int = 0;
    int boss_body_int = 0;
    int boss_weapon_int = 0;
    int boss_core_body_int = 0;
    int boss_core_weapon_int = 0;
    int boss_head_int = 0;
    int boss_head_in_body_int = 0;
    int boss_bullet_2_int = 0;
    int boss_body_unbreakalbe_int = 0;
    int boss_weapon_unbreakable_int = 0;
    int boss_weapon_2_int = 0;
    int boss_weapon_3_int = 0;

    int bullet_col_int = 0;
    int bullet_col_enemy_int = 0;

    int all_int_enemy = 0;
    int all_int_enemy_weapon = 0;
    int all_int_enemy_weapon2 = 0;
    int particle_int_ship = 0;
    int particle_manager_int = 0;
    int bomb_particle_int = 0;
    int user_bomb_particle_int = 0;
    int enemy_bomb_int = 0;

    int item_int = 0;
    int user_bomb_int = 0;
    int bomb_ready_int = 0;

    for (int i = 0; i < LOW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if (game_map[i][j] <= Body && game_map[i][j] >= Body - 2)
            {
                current_ship_xy->body_ship_x[body_int] = j;
                current_ship_xy->body_ship_y[body_int] = i;
                current_ship_xy->whole_ship_x[whole_int] = j;
                current_ship_xy->whole_ship_y[whole_int] = i;

                body_int++;
                whole_int++;
            }

            else if (game_map[i][j] <= Weapon && game_map[i][j] >= Weapon - 2)
            {
                current_ship_xy->weapon_ship_x[weapon_int] = j;
                current_ship_xy->weapon_ship_y[weapon_int] = i;
                current_ship_xy->whole_ship_x[whole_int] = j;
                current_ship_xy->whole_ship_y[whole_int] = i;

                weapon_int++;
                whole_int++;
            }
            else if (game_map[i][j] <= Head && game_map[i][j] >= Head - 2)
            {
                current_ship_xy->head_ship_x[head_int] = j;
                current_ship_xy->head_ship_y[head_int] = i;
                current_ship_xy->whole_ship_x[whole_int] = j;
                current_ship_xy->whole_ship_y[whole_int] = i;

                head_int++;
                whole_int++;
            }
            else if (game_map[i][j] == Bullet)
            {
                current_ship_xy->bullet_x[bullet_int] = j;
                current_ship_xy->bullet_y[bullet_int] = i;

                bullet_int++;

            }
            else if ((game_map[i][j] <= Enemy_Body_Left && game_map[i][j] >= Enemy_Body_Left - 2) ||
                (game_map[i][j] <= Enemy_Body_Right && game_map[i][j] >= Enemy_Body_Right - 2))
            {
                current_ship_xy->enemy_body_x[body_int_enemy] = j;
                current_ship_xy->enemy_body_y[body_int_enemy] = i;
                current_ship_xy->whole_enemy_x[whole_int_enemy] = j;
                current_ship_xy->whole_enemy_y[whole_int_enemy] = i;
                current_ship_xy->all_enemy_x[all_int_enemy] = j;
                current_ship_xy->all_enemy_y[all_int_enemy] = i;

                body_int_enemy++;
                whole_int_enemy++;
                all_int_enemy++;
            }
            else if (game_map[i][j] <= Enemy_Head && game_map[i][j] >= Enemy_Head - 2)
            {
                current_ship_xy->enemy_head_x[head_int_enemy] = j;
                current_ship_xy->enemy_head_y[head_int_enemy] = i;
                current_ship_xy->whole_enemy_x[whole_int_enemy] = j;
                current_ship_xy->whole_enemy_y[whole_int_enemy] = i;
                current_ship_xy->all_enemy_x[all_int_enemy] = j;
                current_ship_xy->all_enemy_y[all_int_enemy] = i;

                head_int_enemy++;
                whole_int_enemy++;
                all_int_enemy++;
            }
            else if (game_map[i][j] <= Enemy_Weapon && game_map[i][j] >= Enemy_Weapon - 2)
            {
                current_ship_xy->enemy_weapon_x[weapon_int_enemy] = j;
                current_ship_xy->enemy_weapon_y[weapon_int_enemy] = i;
                current_ship_xy->whole_enemy_x[whole_int_enemy] = j;
                current_ship_xy->whole_enemy_y[whole_int_enemy] = i;
                current_ship_xy->all_enemy_y[all_int_enemy] = i;
                current_ship_xy->all_enemy_x[all_int_enemy] = j;
                current_ship_xy->all_enemy_weapon_x[all_int_enemy_weapon] = j;
                current_ship_xy->all_enemy_weapon_y[all_int_enemy_weapon] = i;

                all_int_enemy++;
                weapon_int_enemy++;
                whole_int_enemy++;
                all_int_enemy_weapon++;

            }
            else if (game_map[i][j] == Enemy_Bullet)
            {
                current_ship_xy->enemy_bullet_x[bullet_int_enemy] = j;
                current_ship_xy->enemy_bullet_y[bullet_int_enemy] = i;

                bullet_int_enemy++;

            }
            else if (game_map[i][j] == Enemy_Bullet2)
            {
                current_ship_xy->enemy_bullet_x2[bullet_int_enemy2] = j;
                current_ship_xy->enemy_bullet_y2[bullet_int_enemy2] = i;

                bullet_int_enemy2++;

            }

            else if ((game_map[i][j] <= Enemy_Body_Left2 && game_map[i][j] >= Enemy_Body_Left2 - 2) ||
                (game_map[i][j] <= Enemy_Body_Right2 && game_map[i][j] >= Enemy_Body_Right2 - 2))
            {
                current_ship_xy->enemy_body_x2[body_int_enemy2] = j;
                current_ship_xy->enemy_body_y2[body_int_enemy2] = i;
                current_ship_xy->whole_enemy_x2[whole_int_enemy2] = j;
                current_ship_xy->whole_enemy_y2[whole_int_enemy2] = i;
                current_ship_xy->all_enemy_y[all_int_enemy] = i;
                current_ship_xy->all_enemy_x[all_int_enemy] = j;

                all_int_enemy++;
                body_int_enemy2++;
                whole_int_enemy2++;
            }
            else if (game_map[i][j] <= Enemy_Head2 && game_map[i][j] >= Enemy_Head2 - 2)
            {
                current_ship_xy->enemy_head_x2[head_int_enemy2] = j;
                current_ship_xy->enemy_head_y2[head_int_enemy2] = i;
                current_ship_xy->whole_enemy_x2[whole_int_enemy2] = j;
                current_ship_xy->whole_enemy_y2[whole_int_enemy2] = i;
                current_ship_xy->all_enemy_y[all_int_enemy] = i;
                current_ship_xy->all_enemy_x[all_int_enemy] = j;

                all_int_enemy++;
                head_int_enemy2++;
                whole_int_enemy2++;
            }
            else if (game_map[i][j] <= Enemy_Weapon2 && game_map[i][j] >= Enemy_Weapon2 - 2)
            {
                current_ship_xy->enemy_weapon_x2[weapon_int_enemy2] = j;
                current_ship_xy->enemy_weapon_y2[weapon_int_enemy2] = i;
                current_ship_xy->whole_enemy_x2[whole_int_enemy2] = j;
                current_ship_xy->whole_enemy_y2[whole_int_enemy2] = i;
                current_ship_xy->all_enemy_y[all_int_enemy] = i;
                current_ship_xy->all_enemy_x[all_int_enemy] = j;
                current_ship_xy->all_enemy_weapon_x[all_int_enemy_weapon] = j;
                current_ship_xy->all_enemy_weapon_y[all_int_enemy_weapon] = i;

                all_int_enemy++;
                weapon_int_enemy2++;
                whole_int_enemy2++;
                all_int_enemy_weapon++;
            }
            else if ((game_map[i][j] <= Enemy_Body_Left3 && game_map[i][j] >= Enemy_Body_Left3 - 2) ||
                (game_map[i][j] <= Enemy_Body_Right3 && game_map[i][j] >= Enemy_Body_Right3 - 2))
            {
                current_ship_xy->enemy_body_x3[body_int_enemy3] = j;
                current_ship_xy->enemy_body_y3[body_int_enemy3] = i;
                current_ship_xy->whole_enemy_x3[whole_int_enemy3] = j;
                current_ship_xy->whole_enemy_y3[whole_int_enemy3] = i;
                current_ship_xy->all_enemy_y[all_int_enemy] = i;
                current_ship_xy->all_enemy_x[all_int_enemy] = j;

                all_int_enemy++;
                body_int_enemy3++;
                whole_int_enemy3++;
            }
            else if (game_map[i][j] <= Enemy_Head3 && game_map[i][j] >= Enemy_Head3 - 2)
            {
                current_ship_xy->enemy_head_x3[head_int_enemy3] = j;
                current_ship_xy->enemy_head_y3[head_int_enemy3] = i;
                current_ship_xy->whole_enemy_x3[whole_int_enemy3] = j;
                current_ship_xy->whole_enemy_y3[whole_int_enemy3] = i;
                current_ship_xy->all_enemy_y[all_int_enemy] = i;
                current_ship_xy->all_enemy_x[all_int_enemy] = j;

                all_int_enemy++;
                head_int_enemy3++;
                whole_int_enemy3++;
            }
            else if (game_map[i][j] <= Enemy_Weapon3 && game_map[i][j] >= Enemy_Weapon3 - 2)
            {
                current_ship_xy->enemy_weapon_x3[weapon_int_enemy3] = j;
                current_ship_xy->enemy_weapon_y3[weapon_int_enemy3] = i;
                current_ship_xy->whole_enemy_x3[whole_int_enemy3] = j;
                current_ship_xy->whole_enemy_y3[whole_int_enemy3] = i;
                current_ship_xy->all_enemy_y[all_int_enemy] = i;
                current_ship_xy->all_enemy_x[all_int_enemy] = j;
                current_ship_xy->all_enemy_weapon_x2[all_int_enemy_weapon2] = j;
                current_ship_xy->all_enemy_weapon_y2[all_int_enemy_weapon2] = i;

                all_int_enemy++;
                weapon_int_enemy3++;
                whole_int_enemy3++;
                all_int_enemy_weapon2++;
            }
            else if ((game_map[i][j] <= Enemy_Body_Left4 && game_map[i][j] >= Enemy_Body_Left4 - 2) ||
                (game_map[i][j] <= Enemy_Body_Right4 && game_map[i][j] >= Enemy_Body_Right4 - 2))
            {
                current_ship_xy->enemy_body_x4[body_int_enemy4] = j;
                current_ship_xy->enemy_body_y4[body_int_enemy4] = i;
                current_ship_xy->whole_enemy_x4[whole_int_enemy4] = j;
                current_ship_xy->whole_enemy_y4[whole_int_enemy4] = i;
                current_ship_xy->all_enemy_y[all_int_enemy] = i;
                current_ship_xy->all_enemy_x[all_int_enemy] = j;

                all_int_enemy++;
                body_int_enemy4++;
                whole_int_enemy4++;
            }
            else if (game_map[i][j] <= Enemy_Head4 && game_map[i][j] >= Enemy_Head4 - 2)
            {
                current_ship_xy->enemy_head_x4[head_int_enemy4] = j;
                current_ship_xy->enemy_head_y4[head_int_enemy4] = i;
                current_ship_xy->whole_enemy_x4[whole_int_enemy4] = j;
                current_ship_xy->whole_enemy_y4[whole_int_enemy4] = i;
                current_ship_xy->all_enemy_y[all_int_enemy] = i;
                current_ship_xy->all_enemy_x[all_int_enemy] = j;

                all_int_enemy++;
                head_int_enemy4++;
                whole_int_enemy4++;
            }
            else if (game_map[i][j] <= Enemy_Weapon4 && game_map[i][j] >= Enemy_Weapon4 - 2)
            {
                current_ship_xy->enemy_weapon_x4[weapon_int_enemy4] = j;
                current_ship_xy->enemy_weapon_y4[weapon_int_enemy4] = i;
                current_ship_xy->whole_enemy_x4[whole_int_enemy4] = j;
                current_ship_xy->whole_enemy_y4[whole_int_enemy4] = i;
                current_ship_xy->all_enemy_y[all_int_enemy] = i;
                current_ship_xy->all_enemy_x[all_int_enemy] = j;
                current_ship_xy->all_enemy_weapon_x2[all_int_enemy_weapon2] = j;
                current_ship_xy->all_enemy_weapon_y2[all_int_enemy_weapon2] = i;

                all_int_enemy++;
                weapon_int_enemy4++;
                whole_int_enemy4++;
                all_int_enemy_weapon2++;
            }
            else if (game_map[i][j] <= Boss_Body && game_map[i][j] >= Boss_Body - 8)
            {
                current_ship_xy->boss_body_x[boss_body_int] = j;
                current_ship_xy->boss_body_y[boss_body_int] = i;
                current_ship_xy->boss_whole_x[boss_whole_int] = j;
                current_ship_xy->boss_whole_y[boss_whole_int] = i;

                boss_body_int++;
                boss_whole_int++;
            }
            else if (game_map[i][j] <= Boss_Weapon && game_map[i][j] >= Boss_Weapon - 8)
            {
                current_ship_xy->boss_weapon_x[boss_weapon_int] = j;
                current_ship_xy->boss_weapon_y[boss_weapon_int] = i;
                current_ship_xy->boss_whole_x[boss_whole_int] = j;
                current_ship_xy->boss_whole_y[boss_whole_int] = i;

                boss_weapon_int++;
                boss_whole_int++;
            }
            else if (game_map[i][j] <= Boss_Weapon_2 && game_map[i][j] >= Boss_Weapon_2 - 8)
            {
                current_ship_xy->boss_whole_x[boss_whole_int] = j;
                current_ship_xy->boss_whole_y[boss_whole_int] = i;
                current_ship_xy->boss_weapon_2_x[boss_weapon_2_int] = j;
                current_ship_xy->boss_weapon_2_y[boss_weapon_2_int] = i;

                boss_whole_int++;
                boss_weapon_2_int++;

            }

            else if (game_map[i][j] <= Boss_Weapon_3 && game_map[i][j] >= Boss_Weapon_3 - 8)
            {
                current_ship_xy->boss_whole_x[boss_whole_int] = j;
                current_ship_xy->boss_whole_y[boss_whole_int] = i;
                current_ship_xy->boss_weapon_3_x[boss_weapon_3_int] = j;
                current_ship_xy->boss_weapon_3_y[boss_weapon_3_int] = i;

                boss_whole_int++;
                boss_weapon_3_int++;

            }

            else if (game_map[i][j] == Boss_Head)
            {
                current_ship_xy->boss_head_x[boss_head_int] = j;
                current_ship_xy->boss_head_y[boss_head_int] = i;
                current_ship_xy->boss_whole_x[boss_whole_int] = j;
                current_ship_xy->boss_whole_y[boss_whole_int] = i;

                boss_head_int++;
                boss_whole_int++;
            }
            else if (game_map[i][j] == Boss_Head_In_Body)
            {
                current_ship_xy->boss_head_in_body_x[boss_head_in_body_int] = j;
                current_ship_xy->boss_head_in_body_y[boss_head_in_body_int] = i;
                current_ship_xy->boss_whole_x[boss_whole_int] = j;
                current_ship_xy->boss_whole_y[boss_whole_int] = i;

                boss_head_in_body_int++;
                boss_whole_int++;
            }

            else if (game_map[i][j] <= Boss_Core_Body && game_map[i][j] >= Boss_Core_Body - 8)
            {
                current_ship_xy->boss_body_core_x[boss_core_body_int] = j;
                current_ship_xy->boss_body_core_y[boss_core_body_int] = i;
                current_ship_xy->boss_whole_x[boss_whole_int] = j;
                current_ship_xy->boss_whole_y[boss_whole_int] = i;

                boss_core_body_int++;
                boss_whole_int++;
            }
            else if (game_map[i][j] <= Boss_Core_Weapon && game_map[i][j] >= Boss_Core_Weapon - 8)
            {
                current_ship_xy->boss_weapon_core_x[boss_core_weapon_int] = j;
                current_ship_xy->boss_weapon_core_y[boss_core_weapon_int] = i;
                current_ship_xy->boss_whole_x[boss_whole_int] = j;
                current_ship_xy->boss_whole_y[boss_whole_int] = i;

                boss_core_weapon_int++;
                boss_whole_int++;
            }
            else if (game_map[i][j] == Boss_Bullet_2)
            {
                current_ship_xy->boss_bullet_2_x[boss_bullet_2_int] = j;
                current_ship_xy->boss_bullet_2_y[boss_bullet_2_int] = i;
                boss_bullet_2_int++;

            }
            else if (game_map[i][j] == Boss_Core_Body_Unbreakable)
            {
                current_ship_xy->boss_body_unbreakable_x[boss_body_unbreakalbe_int] = j;
                current_ship_xy->boss_body_unbreakable_y[boss_body_unbreakalbe_int] = i;
                current_ship_xy->boss_whole_x[boss_whole_int] = j;
                current_ship_xy->boss_whole_y[boss_whole_int] = i;
                boss_body_unbreakalbe_int++;
                boss_whole_int++;
            }
            else if (game_map[i][j] == Boss_Core_Weapon_Unbreakable)
            {
                current_ship_xy->boss_weapon_unbreakable_x[boss_weapon_unbreakable_int] = j;
                current_ship_xy->boss_weapon_unbreakable_y[boss_weapon_unbreakable_int] = i;
                current_ship_xy->boss_whole_x[boss_whole_int] = j;
                current_ship_xy->boss_whole_y[boss_whole_int] = i;
                boss_weapon_unbreakable_int++;
                boss_whole_int++;
            }


            else if (game_map[i][j] == Bullet_Col)
            {
                current_ship_xy->bullet_col_x[bullet_col_int] = j;
                current_ship_xy->bullet_col_y[bullet_col_int] = i;
                bullet_col_int++;
            }
            else if (game_map[i][j] == Enemy_Bullet_Col)
            {
                current_ship_xy->bullet_col_enemy_x[bullet_col_enemy_int] = j;
                current_ship_xy->bullet_col_enemy_y[bullet_col_enemy_int] = i;
                bullet_col_enemy_int++;
            }
            else if (game_map[i][j] == Ship_Die1 || game_map[i][j] == Ship_Die2 ||
                game_map[i][j] == Ship_Die3 || game_map[i][j] == Ship_Die4 ||
                game_map[i][j] == Ship_Die5)
            {
                current_ship_xy->ship_particle_x[particle_int_ship] = j;
                current_ship_xy->ship_particle_y[particle_int_ship] = i;

                particle_int_ship++;

            }
            else if (game_map[i][j] == Bomb_Effect1 || game_map[i][j] == Bomb_Effect2 ||
                game_map[i][j] == Bomb_Effect3 || game_map[i][j] == Bomb_Effect4 ||
                game_map[i][j] == Bomb_Effect5)
            {
                current_ship_xy->user_bomb_particle_x[user_bomb_particle_int] = j;
                current_ship_xy->user_bomb_particle_y[user_bomb_particle_int] = i;

                user_bomb_particle_int++;
            }
            else if (game_map[i][j] == User_Bomb_Particle1 || game_map[i][j] == User_Bomb_Particle2 ||
                game_map[i][j] == User_Bomb_Particle3 || game_map[i][j] == User_Bomb_Particle4
                || game_map[i][j] == User_Bomb_Particle5 || game_map[i][j] == User_Bomb_Particle6)
            {
                current_ship_xy->user_bomb_particle_x[bomb_particle_int] = j;
                current_ship_xy->user_bomb_particle_y[bomb_particle_int] = i;

                bomb_particle_int++;
            }
            else if (game_map[i][j] == Bomb_Particle1 || game_map[i][j] == Bomb_Particle2 ||
                game_map[i][j] == Bomb_Particle3 || game_map[i][j] == Bomb_Particle4)
            {
                current_ship_xy->bomb_particle_x[enemy_bomb_int] = j;
                current_ship_xy->bomb_particle_y[enemy_bomb_int] = i;

                enemy_bomb_int++;

            }
            else if (game_map[i][j] == Ship_Die_Manager)
            {
                current_ship_xy->particle_manager_x[particle_manager_int] = j;
                current_ship_xy->particle_manager_y[particle_manager_int] = i;

                particle_manager_int++;

            }
            else if (game_map[i][j] == Item_Red || game_map[i][j] == Item_Yellow ||
                game_map[i][j] == Item_Puple || game_map[i][j] == Item_Cyan ||
                game_map[i][j] == Item_Blue || game_map[i][j] == Item_Green ||
                game_map[i][j] == Item_White)
            {
                current_ship_xy->power_up_x[item_int] = j;
                current_ship_xy->power_up_y[item_int] = i;

                item_int++;
            }

            else if (game_map[i][j] == Bomb)
            {

                current_ship_xy->user_bomb_x[user_bomb_int] = j;
                current_ship_xy->user_bomb_y[user_bomb_int] = i;

                user_bomb_int++;
            }
            else if (game_map[i][j] == Bomb_Ready)
            {
                current_ship_xy->bomb_ready_x[bomb_ready_int] = j;
                current_ship_xy->bomb_ready_y[bomb_ready_int] = i;

                bomb_ready_int++;

            }
            else if (game_map[i][j] == Ship_Map_Cursor)
            {
                game_map[i][j] = AIR;
            }
        }
    }
}