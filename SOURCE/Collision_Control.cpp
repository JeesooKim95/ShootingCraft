/**
\file        Collision_Control.cpp
\author      sangmin.kim
\par         email: ryan95kr@gmail.com
\brief
This file will manage when collision happened. Check each array's element.

copyright   All content ?2018 DigiPen (USA) Corporation, all rights reserved
*/

#define _CRT_SECURE_NO_WARNINGS

#include "Collision_Control.h"
#include "MapStatus.h"
#include "Ship_Status.h"
#include "Enemy_Part.h"
#include "Item.h"
#include "time.h"
#include "Windows.h"
#include "Game_State.h"
#include "Sound_Manager.h"
#include "GameOver.h"
#include "GameClear.h"


void Check_Collision(Game_Map game_map, XY_Position_Ship* current_ship_xy, Map_Status_Count current_map_status, int *score, int *power_up, GameState* gameState, bool* should_run, bool is_hack)
{
    int over_rap = 0;
    int x, y = 0;
    int temp = 0;
    int rand_item = 0;
    int item_move = 0;

    for (int i = 0; i < current_map_status.count_particle_manager; i++)
    {
        x = current_ship_xy->particle_manager_x[i];
        y = current_ship_xy->particle_manager_y[i];

        if (game_map[y + 1][x] == Bullet)
        {
            game_map[y][x] = Bomb_Particle1;
        }
        else if ((game_map[y + 1][x] <= Enemy_Body_Left && game_map[y + 1][x] >= Enemy_Body_Left - 2) ||
            (game_map[y + 1][x] <= Enemy_Body_Left2 && game_map[y + 1][x] >= Enemy_Body_Left2 - 2) ||
            (game_map[y + 1][x] <= Enemy_Body_Right && game_map[y + 1][x] >= Enemy_Body_Right - 2) ||
            (game_map[y + 1][x] <= Enemy_Body_Right2 && game_map[y + 1][x] >= Enemy_Body_Right2 - 2) ||
            (game_map[y + 1][x] <= Enemy_Head && game_map[y + 1][x] >= Enemy_Head - 2) ||
            (game_map[y + 1][x] <= Enemy_Head2 && game_map[y + 1][x] >= Enemy_Head2 - 2) ||
            (game_map[y + 1][x] <= Enemy_Weapon && game_map[y + 1][x] >= Enemy_Weapon - 2) ||
            (game_map[y + 1][x] <= Enemy_Weapon2 && game_map[y + 1][x] >= Enemy_Weapon2 - 2) ||
            (game_map[y + 1][x] <= Enemy_Body_Left3 && game_map[y + 1][x] >= Enemy_Body_Left3 - 2) ||
            (game_map[y + 1][x] <= Enemy_Body_Left4 && game_map[y + 1][x] >= Enemy_Body_Left4 - 2) ||
            (game_map[y + 1][x] <= Enemy_Body_Right3 && game_map[y + 1][x] >= Enemy_Body_Right3 - 2) ||
            (game_map[y + 1][x] <= Enemy_Body_Right4 && game_map[y + 1][x] >= Enemy_Body_Right4 - 2) ||
            (game_map[y + 1][x] <= Enemy_Head3 && game_map[y + 1][x] >= Enemy_Head3 - 2) ||
            (game_map[y + 1][x] <= Enemy_Head4 && game_map[y + 1][x] >= Enemy_Head4 - 2) ||
            (game_map[y + 1][x] <= Enemy_Weapon3 && game_map[y + 1][x] >= Enemy_Weapon3 - 2) ||
            (game_map[y + 1][x] <= Enemy_Weapon4 && game_map[y + 1][x] >= Enemy_Weapon4 - 2))
        {
            if (current_ship_xy->overlap_x[over_rap] != 0 && current_ship_xy->overlap_y[over_rap] != 0)
            {
                over_rap++;
                continue;
            }
            current_ship_xy->overlap_x[over_rap] = x;
            current_ship_xy->overlap_y[over_rap] = y + 1;
            current_ship_xy->overlap[over_rap] = game_map[y + 1][x];
            over_rap++;
            temp = game_map[y][x];
            game_map[y][x] = AIR;
            game_map[y + 1][x] = temp;

        }


    }
    for (int i = 0; i < current_map_status.user_bomb_count; i++)
    {
        x = current_ship_xy->user_bomb_x[i];
        y = current_ship_xy->user_bomb_y[i];

        if (game_map[y - 1][x] != AIR)
        {
            game_map[y - 1][x] = AIR;

        }
    }
    for (int i = 0; i < current_map_status.count_item; i++)
    {
        item_move = 0;
        x = current_ship_xy->power_up_x[i];
        y = current_ship_xy->power_up_y[i];

        if (game_map[y][x] == Item_Red || game_map[y][x] == Item_Yellow ||
            game_map[y][x] == Item_Puple || game_map[y][x] == Item_Cyan ||
            game_map[y][x] == Item_Blue || game_map[y][x] == Item_Green ||
            game_map[y][x] == Item_White)
        {

            if ((game_map[y + 1][x] <= Head && game_map[y + 1][x] >= Head - 2) ||
                (game_map[y + 1][x] <= Body && game_map[y + 1][x] >= Body - 2) ||
                (game_map[y + 1][x] <= Weapon && game_map[y + 1][x] >= Weapon - 2))
            {
                *power_up += 1;
                game_map[y][x] = AIR;

                Sound::play(7);
                Sound::volume(7, 30);
            }
            else if (game_map[y + 1][x] == Bullet)
            {
                temp = game_map[y][x];

                while (game_map[y + item_move][x] == Body || game_map[y + item_move][x] == Head || game_map[y + item_move][x] == Weapon)
                {
                    item_move++;

                    if (game_map[y + item_move][x] != Body || game_map[y + item_move][x] != Head || game_map[y + item_move][x] != Weapon)
                    {
                        game_map[y + item_move][x] = temp;
                        break;

                    }
                    else if (game_map[y + item_move][x] == Body || game_map[y + item_move][x] == Head || game_map[y + item_move][x] == Weapon)
                    {
                        *power_up += 1;
                        game_map[y][x] = AIR;

                        Sound::play(7);
                        Sound::volume(7, 30);

                    }
                }

            }


            else if (game_map[y + 1][x] != AIR)
            {
                temp = game_map[y][x];
                game_map[y][x] = AIR;
                game_map[y + 2][x] = temp;

            }
            else if (y == LOW - 3)
            {
                game_map[y][x] = AIR;
            }



        }


    }

    for (int i = 0; i < current_map_status.count_ship_bullet; i++)
    {
        x = current_ship_xy->bullet_x[i];
        y = current_ship_xy->bullet_y[i];

        if ((game_map[y - 1][x] <= Enemy_Body_Left && game_map[y - 1][x] >= Enemy_Body_Left - 2) ||
            (game_map[y - 1][x] <= Enemy_Body_Left2 && game_map[y - 1][x] >= Enemy_Body_Left2 - 2) ||
            (game_map[y - 1][x] <= Enemy_Body_Left3 && game_map[y - 1][x] >= Enemy_Body_Left3 - 2) ||
            (game_map[y - 1][x] <= Enemy_Body_Left4 && game_map[y - 1][x] >= Enemy_Body_Left4 - 2) ||
            (game_map[y - 1][x] <= Enemy_Body_Right && game_map[y - 1][x] >= Enemy_Body_Right - 2) ||
            (game_map[y - 1][x] <= Enemy_Body_Right2 && game_map[y - 1][x] >= Enemy_Body_Right2 - 2) ||
            (game_map[y - 1][x] <= Enemy_Body_Right3 && game_map[y - 1][x] >= Enemy_Body_Right3 - 2) ||
            (game_map[y - 1][x] <= Enemy_Body_Right4 && game_map[y - 1][x] >= Enemy_Body_Right4 - 2) ||
            (game_map[y - 1][x] <= Enemy_Head && game_map[y - 1][x] >= Enemy_Head - 2) ||
            (game_map[y - 1][x] <= Enemy_Head2 && game_map[y - 1][x] >= Enemy_Head2 - 2) ||
            (game_map[y - 1][x] <= Enemy_Head3 && game_map[y - 1][x] >= Enemy_Head3 - 2) ||
            (game_map[y - 1][x] <= Enemy_Head4 && game_map[y - 1][x] >= Enemy_Head4 - 2) ||
            (game_map[y - 1][x] <= Enemy_Weapon && game_map[y - 1][x] >= Enemy_Weapon - 2) ||
            (game_map[y - 1][x] <= Enemy_Weapon2 && game_map[y - 1][x] >= Enemy_Weapon2 - 2 ||
            (game_map[y - 1][x] <= Enemy_Weapon3 && game_map[y - 1][x] >= Enemy_Weapon3 - 2) ||
                (game_map[y - 1][x] <= Enemy_Weapon4 && game_map[y - 1][x] >= Enemy_Weapon4 - 2) ||
                (game_map[y - 1][x] == Enemy_Bullet || game_map[y - 1][x] == Enemy_Bullet2)))
        {
            game_map[y][x] = Bullet_Col;

            Sound::play(3);
            Sound::volume(3, 10);
        }
        else if ((game_map[y - 1][x] <= Boss_Body && game_map[y - 1][x] >= Boss_Body - 8) ||
            (game_map[y - 1][x] <= Boss_Weapon && game_map[y - 1][x] >= Boss_Weapon - 8) ||
            (game_map[y - 1][x] == Boss_Head_In_Body) || (game_map[y - 1][x] == Boss_Head) ||
            (game_map[y - 1][x] <= Boss_Weapon_2 && game_map[y - 1][x] >= Boss_Weapon_2 - 8) ||
            (game_map[y - 1][x] <= Boss_Weapon_3 && game_map[y - 1][x] >= Boss_Weapon_3 - 8))
        {
            game_map[y][x] = Bullet_Col;

        }
        else if (game_map[y - 1][x] == Boss_Core_Weapon_Unbreakable || game_map[y - 1][x] == Boss_Core_Body_Unbreakable)
        {
            game_map[y][x] = Bullet_Col;

        }
        else if (game_map[y - 1][x] == Boss_Bullet_2)
        {
            game_map[y][x] = Bullet_Col;
            game_map[y - 1][x] = Enemy_Bullet_Col;

        }
        else if (game_map[y - 1][x] == Body || game_map[y - 1][x] == Body - 1 || game_map[y - 1][x] == Body - 2 ||
            game_map[y - 1][x] == Head || game_map[y - 1][x] == Head - 1 || game_map[y - 1][x] == Head - 2 ||
            game_map[y - 1][x] == Weapon || game_map[y - 1][x] == Weapon - 1 || game_map[y - 1][x] == Weapon - 2)
        {
            game_map[y][x] = AIR;
            game_map[y - 2][x] = Bullet;

        }

        else if (game_map[y - 1][x] == Item_Red || game_map[y - 1][x] == Item_Yellow ||
            game_map[y - 1][x] == Item_Puple || game_map[y - 1][x] == Item_Cyan ||
            game_map[y - 1][x] == Item_Blue || game_map[y - 1][x] == Item_Green ||
            game_map[y - 1][x] == Item_White)
        {
            game_map[y][x] = AIR;
            game_map[y - 2][x] = Bullet;


        }
        else if (game_map[y - 1][x] == Ship_Die_Manager)
        {
            game_map[y - 2][x] = Bullet;
            game_map[y][x] = AIR;

        }
        else if (game_map[y - 1][x] == Bomb_Particle1 || game_map[y - 1][x] == Bomb_Particle2 ||
            game_map[y - 1][x] == Bomb_Particle3 || game_map[y - 1][x] == Bomb_Particle4)
        {
            game_map[y][x] = AIR;

        }
        else if (game_map[y - 1][x] >= 65 && game_map[y - 1][x] <= 127)
        {
            game_map[y][x] = AIR;

        }
        else if (y == 2)
        {
            game_map[y][x] = AIR;
        }

    }

    for (int i = 0; i < current_map_status.count_enemy_bullet; i++)
    {
        x = current_ship_xy->enemy_bullet_x[i];
        y = current_ship_xy->enemy_bullet_y[i];

        if (game_map[y + 1][x] <= Body && game_map[y + 1][x] >= Body - 2 ||
            game_map[y + 1][x] <= Weapon && game_map[y + 1][x] >= Weapon - 2 ||
            (game_map[y + 1][x] <= Head && game_map[y + 1][x] >= Head - 2) ||
            (game_map[y + 1][x] <= Enemy_Body_Left2 && game_map[y + 1][x] >= Enemy_Body_Left2 - 2) ||
            (game_map[y + 1][x] <= Enemy_Body_Right && game_map[y + 1][x] >= Enemy_Body_Right - 2) ||
            (game_map[y + 1][x] <= Enemy_Body_Right2 && game_map[y + 1][x] >= Enemy_Body_Right2 - 2) ||
            (game_map[y + 1][x] <= Enemy_Head && game_map[y + 1][x] >= Enemy_Head - 2) ||
            (game_map[y + 1][x] <= Enemy_Head2 && game_map[y + 1][x] >= Enemy_Head2 - 2) ||
            (game_map[y + 1][x] <= Enemy_Weapon && game_map[y + 1][x] >= Enemy_Weapon - 2) ||
            (game_map[y + 1][x] <= Enemy_Weapon2 && game_map[y + 1][x] >= Enemy_Weapon2 - 2) ||
            (game_map[y - 1][x] <= Enemy_Body_Left3 && game_map[y - 1][x] >= Enemy_Body_Left3 - 2) ||
            (game_map[y - 1][x] <= Enemy_Body_Left4 && game_map[y - 1][x] >= Enemy_Body_Left4 - 2) ||
            (game_map[y - 1][x] <= Enemy_Body_Right3 && game_map[y - 1][x] >= Enemy_Body_Right3 - 2) ||
            (game_map[y - 1][x] <= Enemy_Body_Right4 && game_map[y - 1][x] >= Enemy_Body_Right4 - 2) ||
            (game_map[y - 1][x] <= Enemy_Head3 && game_map[y - 1][x] >= Enemy_Head3 - 2) ||
            (game_map[y - 1][x] <= Enemy_Head4 && game_map[y - 1][x] >= Enemy_Head4 - 2) ||
            (game_map[y - 1][x] <= Enemy_Weapon3 && game_map[y - 1][x] >= Enemy_Weapon3 - 2) ||
            (game_map[y - 1][x] <= Enemy_Weapon4 && game_map[y - 1][x] >= Enemy_Weapon4 - 2) ||
            game_map[y + 1][x + 1] == WALL || game_map[y + 1][x - 1] == WALL ||
            game_map[y + 1][x] == Bullet_Col)
        {
            game_map[y][x] = Enemy_Bullet_Col;
            current_ship_xy->bullet_dir_x[i] = 0;
            current_ship_xy->bullet_dir_y[i] = 0;

        }
        //else if((game_map[y + 1][x] <= Enemy_Body_Left && game_map[y + 1][x] >= Enemy_Body_Left - 2) || )
        else if (y == LOW - 2)
        {
            game_map[y][x] = AIR;
            current_ship_xy->bullet_dir_x[i] = 0;
            current_ship_xy->bullet_dir_y[i] = 0;

        }

    }

    for (int i = 0; i < current_map_status.count_enemy_bullet2; i++)
    {
        x = current_ship_xy->enemy_bullet_x2[i];
        y = current_ship_xy->enemy_bullet_y2[i];

        if (game_map[y + 1][x] <= Body && game_map[y + 1][x] >= Body - 2 ||
            game_map[y + 1][x] <= Weapon && game_map[y + 1][x] >= Weapon - 2 ||
            (game_map[y + 1][x] <= Head && game_map[y + 1][x] >= Head - 2) ||
            game_map[y + 1][x + 1] == WALL || game_map[y + 1][x - 1] == WALL ||
            (game_map[y + 1][x] <= Enemy_Head && game_map[y + 1][x] >= Enemy_Head - 2) ||
            (game_map[y + 1][x] <= Enemy_Head2 && game_map[y + 1][x] >= Enemy_Head2 - 2) ||
            game_map[y + 1][x] == Bullet_Col)
        {
            game_map[y][x] = Enemy_Bullet_Col;


        }
        else if ((game_map[y + 1][x] <= Enemy_Body_Left && game_map[y + 1][x] >= Enemy_Body_Left - 2) ||
            (game_map[y + 1][x] <= Enemy_Body_Left2 && game_map[y + 1][x] >= Enemy_Body_Left2 - 2) ||
            (game_map[y + 1][x] <= Enemy_Body_Right && game_map[y + 1][x] >= Enemy_Body_Right - 2) ||
            (game_map[y + 1][x] <= Enemy_Body_Right2 && game_map[y + 1][x] >= Enemy_Body_Right2 - 2) ||
            (game_map[y + 1][x] <= Enemy_Head && game_map[y + 1][x] >= Enemy_Head - 2) ||
            (game_map[y + 1][x] <= Enemy_Head2 && game_map[y + 1][x] >= Enemy_Head2 - 2) ||
            (game_map[y + 1][x] <= Enemy_Weapon && game_map[y + 1][x] >= Enemy_Weapon - 2) ||
            (game_map[y + 1][x] <= Enemy_Weapon2 && game_map[y + 1][x] >= Enemy_Weapon2 - 2) ||
            (game_map[y + 1][x] <= Enemy_Body_Left3 && game_map[y + 1][x] >= Enemy_Body_Left3 - 2) ||
            (game_map[y + 1][x] <= Enemy_Body_Left4 && game_map[y + 1][x] >= Enemy_Body_Left4 - 2) ||
            (game_map[y + 1][x] <= Enemy_Body_Right3 && game_map[y + 1][x] >= Enemy_Body_Right3 - 2) ||
            (game_map[y + 1][x] <= Enemy_Body_Right4 && game_map[y + 1][x] >= Enemy_Body_Right4 - 2) ||
            (game_map[y + 1][x] <= Enemy_Head3 && game_map[y + 1][x] >= Enemy_Head3 - 2) ||
            (game_map[y + 1][x] <= Enemy_Head4 && game_map[y + 1][x] >= Enemy_Head4 - 2) ||
            (game_map[y + 1][x] <= Enemy_Weapon3 && game_map[y + 1][x] >= Enemy_Weapon3 - 2) ||
            (game_map[y + 1][x] <= Enemy_Weapon4 && game_map[y + 1][x] >= Enemy_Weapon4 - 2))
        {
            if (current_ship_xy->overlap_x[over_rap] != 0 && current_ship_xy->overlap_y[over_rap] != 0)
            {
                over_rap++;
                continue;
            }
            current_ship_xy->overlap_x[over_rap] = x;
            current_ship_xy->overlap_y[over_rap] = y + 1;
            current_ship_xy->overlap[over_rap] = game_map[y + 1][x];
            over_rap++;
            temp = game_map[y][x];
            game_map[y][x] = AIR;
            game_map[y + 1][x] = temp;

        }
        else if (game_map[y + 1][x] == Item_Red || game_map[y + 1][x] == Item_Blue ||
            game_map[y + 1][x] == Item_Green || game_map[y + 1][x] == Item_Cyan ||
            game_map[y + 1][x] == Item_White || game_map[y + 1][x] == Item_Puple ||
            game_map[y + 1][x] == Item_Yellow)
        {
            temp = game_map[y][x];
            game_map[y][x] = AIR;
            game_map[y + 2][x] = temp;

        }
        if (y == LOW - 2)
        {
            game_map[y][x] = AIR;


        }

    }
    for (int i = 0; i < current_map_status.count_boss_bullet_2; i++)
    {
        x = current_ship_xy->boss_bullet_2_x[i];
        y = current_ship_xy->boss_bullet_2_y[i];

        if (game_map[y][x] == Boss_Bullet_2)
        {
            if (game_map[y + 1][x] == Body || game_map[y + 1][x] == Body - 1 || game_map[y + 1][x] == Body - 2 ||
                game_map[y + 1][x] == Weapon || game_map[y + 1][x] == Weapon - 1 || game_map[y + 1][x] == Weapon - 2 ||
                game_map[y + 1][x] == Head || game_map[y + 1][x] == Head - 1 || game_map[y + 1][x] == Head - 2)
            {
                game_map[y][x] = Enemy_Bullet_Col;
            }

        }

    }

    if (!is_hack)
    {
        for (int i = 0; i < current_map_status.count_whole_ship; i++)
        {
            x = current_ship_xy->whole_ship_x[i];
            y = current_ship_xy->whole_ship_y[i];

            if (game_map[y][x] <= Head && game_map[y][x] >= Head - 2)
            {
                if (game_map[y - 1][x] == Enemy_Bullet_Col)
                {
                    game_map[y][x] -= 1;
                    game_map[y - 1][x] = AIR;

                    if (game_map[y][x] < Head - 2)
                    {
                        Set_GameStatus(gameState, End_Game);

                        Game_Over(should_run);
                    }
                }

            }
            else if (game_map[y][x] <= Body && game_map[y][x] >= Body - 2)
            {
                if (game_map[y - 1][x] == Enemy_Bullet_Col)
                {
                    game_map[y][x] -= 1;
                    game_map[y - 1][x] = AIR;

                    if (game_map[y][x] < Body - 2)
                    {
                        game_map[y][x] = Ship_Die1;
                        Sound::play(2);
                        Sound::volume(2, 1);
                    }


                }

            }
            else if (game_map[y][x] <= Weapon && game_map[y][x] >= Weapon - 2)
            {
                if (game_map[y - 1][x] == Enemy_Bullet_Col)
                {
                    game_map[y - 1][x] = AIR;
                    game_map[y][x] = Ship_Die1;


                }

            }


        }
    }
    for (int i = 0; i < current_map_status.count_boss_whole; i++)
    {
        x = current_ship_xy->boss_whole_x[i];
        y = current_ship_xy->boss_whole_y[i];

        if (game_map[y][x] <= Boss_Body && game_map[y][x] >= Boss_Body - 8)
        {
            if (game_map[y + 1][x] == Bullet_Col)
            {
                game_map[y][x] -= 1;
                game_map[y + 1][x] = AIR;

                if (game_map[y][x] < Boss_Body - 8)
                {
                    game_map[y][x] = Ship_Die1;
                }

            }
        }
        else if (game_map[y][x] <= Boss_Weapon && game_map[y][x] >= Boss_Weapon - 8)
        {
            if (game_map[y + 1][x] == Bullet_Col)
            {
                game_map[y][x] -= 1;
                game_map[y + 1][x] = AIR;

                if (game_map[y][x] < Boss_Weapon - 8)
                {
                    game_map[y][x] = Ship_Die1;
                }

            }
        }
        else if (game_map[y][x] <= Boss_Weapon_2 && game_map[y][x] >= Boss_Weapon_2 - 8)
        {
            if (game_map[y + 1][x] == Bullet_Col)
            {
                game_map[y][x] -= 1;
                game_map[y + 1][x] = AIR;

                if (game_map[y][x] < Boss_Weapon_2 - 8)
                {
                    game_map[y][x] = Ship_Die1;

                }
            }

        }

        else if (game_map[y][x] <= Boss_Weapon_3 && game_map[y][x] >= Boss_Weapon_3 - 8)
        {
            if (game_map[y + 1][x] == Bullet_Col)
            {
                game_map[y][x] -= 1;
                game_map[y + 1][x] = AIR;

                if (game_map[y][x] < Boss_Weapon_3 - 8)
                {
                    game_map[y][x] = Ship_Die1;

                }
            }

        }
        else if (game_map[y][x] == Boss_Head_In_Body)
        {
            if (game_map[y + 1][x] == Bullet_Col)
            {
                for (int i = y - 3; i <= y + 6; i++)
                {
                    for (int j = x - 3; j <= x + 3; j++)
                    {
                        game_map[i][j] = Ship_Die1;
                    }

                }

            }


        }
        else if (game_map[y][x] == Boss_Head)
        {
            if (game_map[y + 1][x] == Bullet_Col)
            {
                Set_GameStatus(gameState, Clear_Game);
                //Game_Clear();
            }

        }
    }

    for (int i = 0; i < current_map_status.count_all_enemy; i++)
    {
        x = current_ship_xy->all_enemy_x[i];
        y = current_ship_xy->all_enemy_y[i];

        if (game_map[y][x] <= Enemy_Head && game_map[y][x] >= Enemy_Head - 2)
        {
            if (game_map[y + 1][x] == Bullet_Col)
            {
                game_map[y][x] = AIR;
                game_map[y + 1][x] = AIR;

                if (game_map[y][x] < Enemy_Head - 2)
                {
                    for (int i = y; i <= y + 1; i++)
                    {
                        for (int j = x - 1; j <= x + 1; j++)
                        {
                            if ((game_map[i][j] <= Enemy_Body_Left && game_map[i][j] >= Enemy_Body_Left - 2) ||
                                (game_map[i][j] <= Enemy_Body_Right && game_map[i][j] >= Enemy_Body_Right - 2) ||
                                (game_map[i][j] <= Enemy_Weapon && game_map[i][j] >= Enemy_Weapon - 2) ||
                                (game_map[i][j] <= Enemy_Head && game_map[i][j] >= Enemy_Head - 2))
                                game_map[i][j] = Ship_Die1;
                            Sound::play(2);
                            Sound::volume(2, 1);
                        }

                    }
                    *score += 1;

                }

            }
            else if (game_map[y + 1][x + 1] == WALL || game_map[y][x + 1] == WALL || game_map[y][x - 1] == WALL)
            {
                game_map[y][x] = AIR;
            }

        }
        else if ((game_map[y][x] <= Enemy_Head2 && game_map[y][x] >= Enemy_Head2 - 2))
        {
            if (game_map[y + 1][x] == Bullet_Col)
            {
                game_map[y][x] = AIR;
                game_map[y + 1][x] = AIR;

                if (game_map[y][x] < Enemy_Head2 - 2)
                {
                    for (int i = y; i <= y + 1; i++)
                    {
                        for (int j = x - 1; j <= x + 1; j++)
                        {
                            if ((game_map[i][j] <= Enemy_Body_Left2 && game_map[i][j] >= Enemy_Body_Left2 - 2) ||
                                (game_map[i][j] <= Enemy_Body_Right2 && game_map[i][j] >= Enemy_Body_Right2 - 2) ||
                                (game_map[i][j] <= Enemy_Weapon2 && game_map[i][j] >= Enemy_Weapon2 - 2) ||
                                (game_map[i][j] <= Enemy_Head2 && game_map[i][j] >= Enemy_Head2 - 2))
                                game_map[i][j] = Ship_Die1;
                            Sound::play(2);
                            Sound::volume(2, 1);
                        }

                    }
                    *score += 1;
                }
            }
            else if (game_map[y + 1][x - 1] == WALL || game_map[y][x - 1] == WALL)
            {
                game_map[y][x] = AIR;
            }

        }
        else if ((game_map[y][x] <= Enemy_Head3 && game_map[y][x] >= Enemy_Head3 - 2))
        {
            if (game_map[y + 1][x] == Bullet_Col)
            {
                game_map[y][x] = AIR;
                game_map[y + 1][x] = AIR;

                if (game_map[y][x] < Enemy_Head3 - 2)
                {
                    for (int i = y; i <= y + 1; i++)
                    {
                        for (int j = x - 1; j <= x + 1; j++)
                        {
                            if ((game_map[i][j] <= Enemy_Body_Left3 && game_map[i][j] >= Enemy_Body_Left3 - 2) ||
                                (game_map[i][j] <= Enemy_Body_Right3 && game_map[i][j] >= Enemy_Body_Right3 - 2) ||
                                (game_map[i][j] <= Enemy_Weapon3 && game_map[i][j] >= Enemy_Weapon3 - 2) ||
                                (game_map[i][j] <= Enemy_Head3 && game_map[i][j] >= Enemy_Head3 - 2))
                                game_map[i][j] = Ship_Die1;
                            Sound::play(2);
                            Sound::volume(2, 1);
                        }

                    }
                    *score += 1;
                }
            }
            else if (game_map[y][x + 1] == WALL)
            {
                game_map[y][x] = AIR;
            }

        }
        else if ((game_map[y][x] <= Enemy_Head4 && game_map[y][x] >= Enemy_Head4 - 2))
        {
            if (game_map[y + 1][x] == Bullet_Col)
            {
                game_map[y][x] = AIR;
                game_map[y + 1][x] = AIR;

                if (game_map[y][x] < Enemy_Head4 - 2)
                {
                    for (int i = y; i <= y + 1; i++)
                    {
                        for (int j = x - 1; j <= x + 1; j++)
                        {
                            if ((game_map[i][j] <= Enemy_Body_Left4 && game_map[i][j] >= Enemy_Body_Left4 - 2) ||
                                (game_map[i][j] <= Enemy_Body_Right4 && game_map[i][j] >= Enemy_Body_Right4 - 2) ||
                                (game_map[i][j] <= Enemy_Weapon4 && game_map[i][j] >= Enemy_Weapon4 - 2) ||
                                (game_map[i][j] <= Enemy_Head4 && game_map[i][j] >= Enemy_Head4 - 2))
                                game_map[i][j] = Ship_Die1;
                            Sound::play(2);
                            Sound::volume(2, 1);
                        }

                    }
                    *score += 1;
                }
            }
            else if (game_map[y][x - 1] == WALL)
            {
                game_map[y][x] = AIR;
            }

        }
        else if ((game_map[y][x] <= Enemy_Body_Left && game_map[y][x] >= Enemy_Body_Left - 2))
        {
            if (game_map[y + 1][x] == Bullet_Col)
            {

                game_map[y][x] -= 1;
                game_map[y + 1][x] = AIR;

                if (game_map[y][x] < Enemy_Body_Left - 2)
                {
                    for (int i = y; i <= y + 1; i++)
                    {
                        for (int j = x; j <= x + 2; j++)
                        {
                            if ((game_map[i][j] <= Enemy_Body_Left && game_map[i][j] >= Enemy_Body_Left - 3) ||
                                (game_map[i][j] <= Enemy_Body_Right && game_map[i][j] >= Enemy_Body_Right - 2) ||
                                (game_map[i][j] <= Enemy_Weapon && game_map[i][j] >= Enemy_Weapon - 2) ||
                                (game_map[i][j] <= Enemy_Head && game_map[i][j] >= Enemy_Head - 2))
                                game_map[i][j] = Ship_Die1;
                            Sound::play(2);
                            Sound::volume(2, 1);
                        }

                    }
                    rand_item = rand() % 4;

                    if (rand_item == 1)
                    {
                        game_map[y][x] = Item_Red;

                    }

                    *score += 1;
                }
            }
            else if (game_map[y + 1][x + 1] == WALL || game_map[y][x + 1] == WALL || game_map[y][x - 1] == WALL)
            {
                game_map[y][x] = AIR;
            }

        }
        else if ((game_map[y][x] <= Enemy_Body_Left2 && game_map[y][x] >= Enemy_Body_Left2 - 2))
        {
            if (game_map[y + 1][x] == Bullet_Col)
            {

                game_map[y][x] -= 1;
                game_map[y + 1][x] = AIR;

                if (game_map[y][x] < Enemy_Body_Left2 - 2)
                {

                    for (int i = y; i <= y + 1; i++)
                    {
                        for (int j = x; j <= x + 2; j++)
                        {
                            if ((game_map[i][j] <= Enemy_Body_Left2 && game_map[i][j] >= Enemy_Body_Left2 - 3) ||
                                (game_map[i][j] <= Enemy_Body_Right2 && game_map[i][j] >= Enemy_Body_Right2 - 2) ||
                                (game_map[i][j] <= Enemy_Weapon2 && game_map[i][j] >= Enemy_Weapon2 - 2) ||
                                (game_map[i][j] <= Enemy_Head2 && game_map[i][j] >= Enemy_Head2 - 2))
                                game_map[i][j] = Ship_Die1;
                            Sound::play(2);
                            Sound::volume(2, 1);
                        }

                    }
                    rand_item = rand() % 4;

                    if (rand_item == 1)
                    {
                        game_map[y][x] = Item_Red;

                    }
                    *score += 1;
                }

            }
            else if (game_map[y + 1][x - 1] == WALL || game_map[y][x - 1] == WALL)
            {
                game_map[y][x] = AIR;
            }
        }
        else if ((game_map[y][x] <= Enemy_Body_Left3 && game_map[y][x] >= Enemy_Body_Left3 - 2))
        {
            if (game_map[y + 1][x] == Bullet_Col)
            {

                game_map[y][x] -= 1;
                game_map[y + 1][x] = AIR;

                if (game_map[y][x] < Enemy_Body_Left3 - 2)
                {
                    for (int i = y; i <= y + 1; i++)
                    {
                        for (int j = x; j <= x + 2; j++)
                        {
                            if ((game_map[i][j] <= Enemy_Body_Left3 && game_map[i][j] >= Enemy_Body_Left3 - 3) ||
                                (game_map[i][j] <= Enemy_Body_Right3 && game_map[i][j] >= Enemy_Body_Right3 - 2) ||
                                (game_map[i][j] <= Enemy_Weapon3 && game_map[i][j] >= Enemy_Weapon3 - 2) ||
                                (game_map[i][j] <= Enemy_Head3 && game_map[i][j] >= Enemy_Head3 - 2))
                                game_map[i][j] = Ship_Die1;
                            Sound::play(2);
                            Sound::volume(2, 1);
                        }

                    }
                    rand_item = rand() % 4;

                    if (rand_item == 1)
                    {
                        game_map[y][x] = Item_Red;

                    }
                    *score += 1;
                }


            }
            else if (game_map[y][x + 1] == WALL)
            {
                game_map[y][x] = AIR;
            }
        }
        else if ((game_map[y][x] <= Enemy_Body_Left4 && game_map[y][x] >= Enemy_Body_Left4 - 2))
        {
            if (game_map[y + 1][x] == Bullet_Col)
            {

                game_map[y][x] -= 1;
                game_map[y + 1][x] = AIR;


                if (game_map[y][x] < Enemy_Body_Left4 - 2)
                {
                    for (int i = y; i <= y + 1; i++)
                    {

                        for (int j = x; j <= x + 2; j++)
                        {
                            if ((game_map[i][j] <= Enemy_Body_Left4 && game_map[i][j] >= Enemy_Body_Left4 - 3) ||
                                (game_map[i][j] <= Enemy_Body_Right4 && game_map[i][j] >= Enemy_Body_Right4 - 2) ||
                                (game_map[i][j] <= Enemy_Weapon4 && game_map[i][j] >= Enemy_Weapon4 - 2) ||
                                (game_map[i][j] <= Enemy_Head4 && game_map[i][j] >= Enemy_Head4 - 2))
                                game_map[i][j] = Ship_Die1;
                            Sound::play(2);
                            Sound::volume(2, 1);
                        }



                    }
                    rand_item = rand() % 4;

                    if (rand_item == 1)
                    {
                        game_map[y][x] = Item_Red;

                    }
                    *score += 1;
                }

            }
            else if (game_map[y][x - 1] == WALL)
            {
                game_map[y][x] = AIR;
            }
        }
        else if ((game_map[y][x] <= Enemy_Body_Right && game_map[y][x] >= Enemy_Body_Right - 2))
        {
            if (game_map[y + 1][x] == Bullet_Col)
            {

                game_map[y][x] -= 1;
                game_map[y + 1][x] = AIR;

                if (game_map[y][x] < Enemy_Body_Right - 2)
                {
                    for (int i = y; i <= y + 1; i++)
                    {
                        for (int j = x; j >= x - 2; j--)
                        {
                            if ((game_map[i][j] <= Enemy_Body_Left && game_map[i][j] >= Enemy_Body_Left - 2) ||
                                (game_map[i][j] <= Enemy_Body_Right && game_map[i][j] >= Enemy_Body_Right - 3) ||
                                (game_map[i][j] <= Enemy_Weapon && game_map[i][j] >= Enemy_Weapon - 2) ||
                                (game_map[i][j] <= Enemy_Head && game_map[i][j] >= Enemy_Head - 2))
                                game_map[i][j] = Ship_Die1;
                            Sound::play(2);
                            Sound::volume(2, 1);
                        }

                    }
                    rand_item = rand() % 4;

                    if (rand_item == 1)
                    {
                        game_map[y][x] = Item_Red;

                    }
                    *score += 1;

                }
            }
            else if (game_map[y + 1][x + 1] == WALL || game_map[y][x + 1] == WALL || game_map[y][x - 1] == WALL)
            {
                game_map[y][x] = AIR;
            }
        }
        else if ((game_map[y][x] <= Enemy_Body_Right2 && game_map[y][x] >= Enemy_Body_Right2 - 2))
        {
            if (game_map[y + 1][x] == Bullet_Col)
            {

                game_map[y][x] -= 1;
                game_map[y + 1][x] = AIR;

                if (game_map[y][x] < Enemy_Body_Right2 - 2)
                {
                    for (int i = y; i <= y + 1; i++)
                    {
                        for (int j = x; j >= x - 2; j--)
                        {
                            if ((game_map[i][j] <= Enemy_Body_Left2 && game_map[i][j] >= Enemy_Body_Left2 - 2) ||
                                (game_map[i][j] <= Enemy_Body_Right2 && game_map[i][j] >= Enemy_Body_Right2 - 3) ||
                                (game_map[i][j] <= Enemy_Weapon2 && game_map[i][j] >= Enemy_Weapon2 - 2) ||
                                (game_map[i][j] <= Enemy_Head2 && game_map[i][j] >= Enemy_Head2 - 2))
                                game_map[i][j] = Ship_Die1;
                            Sound::play(2);
                            Sound::volume(2, 1);
                        }

                    }
                    rand_item = rand() % 4;

                    if (rand_item == 1)
                    {
                        game_map[y][x] = Item_Red;

                    }
                    *score += 1;

                }
            }
            else if (game_map[y + 1][x - 1] == WALL || game_map[y][x - 1] == WALL)
            {
                game_map[y][x] = AIR;
            }
        }
        else if ((game_map[y][x] <= Enemy_Body_Right3 && game_map[y][x] >= Enemy_Body_Right3 - 2))
        {
            if (game_map[y + 1][x] == Bullet_Col)
            {

                game_map[y][x] -= 1;
                game_map[y + 1][x] = AIR;

                if (game_map[y][x] < Enemy_Body_Right3 - 2)
                {
                    for (int i = y; i <= y + 1; i++)
                    {
                        for (int j = x; j >= x - 2; j--)
                        {
                            if ((game_map[i][j] <= Enemy_Body_Left3 && game_map[i][j] >= Enemy_Body_Left3 - 2) ||
                                (game_map[i][j] <= Enemy_Body_Right3 && game_map[i][j] >= Enemy_Body_Right3 - 3) ||
                                (game_map[i][j] <= Enemy_Weapon3 && game_map[i][j] >= Enemy_Weapon3 - 2) ||
                                (game_map[i][j] <= Enemy_Head3 && game_map[i][j] >= Enemy_Head3 - 2))
                                game_map[i][j] = Ship_Die1;
                            Sound::play(2);
                            Sound::volume(2, 1);
                        }

                    }
                    rand_item = rand() % 4;

                    if (rand_item == 1)
                    {
                        game_map[y][x] = Item_Red;

                    }
                    *score += 1;
                }
            }
            else if (game_map[y][x + 1] == WALL)
            {
                game_map[y][x] = AIR;
            }
        }
        else if ((game_map[y][x] <= Enemy_Body_Right4 && game_map[y][x] >= Enemy_Body_Right4 - 2))
        {
            if (game_map[y + 1][x] == Bullet_Col)
            {

                game_map[y][x] -= 1;
                game_map[y + 1][x] = AIR;

                if (game_map[y][x] < Enemy_Body_Right4 - 2)
                {
                    for (int i = y; i <= y + 1; i++)
                    {
                        for (int j = x; j >= x - 2; j--)
                        {
                            if ((game_map[i][j] <= Enemy_Body_Left4 && game_map[i][j] >= Enemy_Body_Left4 - 2) ||
                                (game_map[i][j] <= Enemy_Body_Right4 && game_map[i][j] >= Enemy_Body_Right4 - 3) ||
                                (game_map[i][j] <= Enemy_Weapon4 && game_map[i][j] >= Enemy_Weapon4 - 2) ||
                                (game_map[i][j] <= Enemy_Head4 && game_map[i][j] >= Enemy_Head4 - 2))
                                game_map[i][j] = Ship_Die1;
                            Sound::play(2);
                            Sound::volume(2, 1);
                        }

                    }
                    rand_item = rand() % 4;

                    if (rand_item == 1)
                    {
                        game_map[y][x] = Item_Red;

                    }
                    *score += 1;

                }
            }
            else if (game_map[y][x - 1] == WALL)
            {
                game_map[y][x] = AIR;
            }
        }
        else if ((game_map[y][x] <= Enemy_Weapon && game_map[y][x] >= Enemy_Weapon - 2))
        {
            if (game_map[y + 1][x] == Bullet_Col)
            {
                game_map[y][x] -= 1;
                game_map[y + 1][x] = AIR;

                if (game_map[y][x] < Enemy_Weapon - 2)
                {
                    for (int i = y - 1; i <= y; i++)
                    {
                        for (int j = x - 1; j <= x + 1; j++)
                        {
                            if ((game_map[i][j] <= Enemy_Body_Left && game_map[i][j] >= Enemy_Body_Left - 2) ||
                                (game_map[i][j] <= Enemy_Body_Right && game_map[i][j] >= Enemy_Body_Right - 2) ||
                                (game_map[i][j] <= Enemy_Weapon && game_map[i][j] >= Enemy_Weapon - 3) ||
                                (game_map[i][j] <= Enemy_Head && game_map[i][j] >= Enemy_Head - 2))
                                game_map[i][j] = Ship_Die1;
                            Sound::play(2);
                            Sound::volume(2, 1);
                        }

                    }
                    rand_item = rand() % 4;

                    if (rand_item == 1)
                    {
                        game_map[y][x] = Item_Red;

                    }
                    *score += 1;
                }

            }
            else if (game_map[y + 1][x + 1] == WALL || game_map[y][x + 1] == WALL || game_map[y][x - 1] == WALL)
            {
                game_map[y][x] = AIR;
            }

        }
        else if ((game_map[y][x] <= Enemy_Weapon2 && game_map[y][x] >= Enemy_Weapon2 - 2))
        {
            if (game_map[y + 1][x] == Bullet_Col)
            {
                game_map[y][x] -= 1;
                game_map[y + 1][x] = AIR;

                if (game_map[y][x] < Enemy_Weapon2 - 2)
                {
                    for (int i = y - 1; i <= y; i++)
                    {
                        for (int j = x - 1; j <= x + 1; j++)
                        {
                            if ((game_map[i][j] <= Enemy_Body_Left2 && game_map[i][j] >= Enemy_Body_Left2 - 2) ||
                                (game_map[i][j] <= Enemy_Body_Right2 && game_map[i][j] >= Enemy_Body_Right2 - 2) ||
                                (game_map[i][j] <= Enemy_Weapon2 && game_map[i][j] >= Enemy_Weapon2 - 3) ||
                                (game_map[i][j] <= Enemy_Head2 && game_map[i][j] >= Enemy_Head2 - 2))
                                game_map[i][j] = Ship_Die1;
                            Sound::play(2);
                            Sound::volume(2, 1);
                        }

                    }
                    rand_item = rand() % 4;

                    if (rand_item == 1)
                    {
                        game_map[y][x] = Item_Red;

                    }
                    *score += 1;
                }

            }
            else if (game_map[y + 1][x - 1] == WALL || game_map[y][x - 1] == WALL)
            {
                game_map[y][x] = AIR;
            }

        }
        else if ((game_map[y][x] <= Enemy_Weapon3 && game_map[y][x] >= Enemy_Weapon3 - 2))
        {
            if (game_map[y + 1][x] == Bullet_Col)
            {
                game_map[y][x] -= 1;
                game_map[y + 1][x] = AIR;

                if (game_map[y][x] < Enemy_Weapon3 - 2)
                {
                    for (int i = y - 1; i <= y; i++)
                    {
                        for (int j = x - 1; j <= x + 1; j++)
                        {
                            if ((game_map[i][j] <= Enemy_Body_Left3 && game_map[i][j] >= Enemy_Body_Left3 - 2) ||
                                (game_map[i][j] <= Enemy_Body_Right3 && game_map[i][j] >= Enemy_Body_Right3 - 2) ||
                                (game_map[i][j] <= Enemy_Weapon3 && game_map[i][j] >= Enemy_Weapon3 - 3) ||
                                (game_map[i][j] <= Enemy_Head3 && game_map[i][j] >= Enemy_Head3 - 2))
                                game_map[i][j] = Ship_Die1;
                            Sound::play(2);
                            Sound::volume(2, 1);
                        }

                    }
                    rand_item = rand() % 4;

                    if (rand_item == 1)
                    {
                        game_map[y][x] = Item_Red;

                    }
                    *score += 1;
                }

            }
            else if (game_map[y][x + 1] == WALL)
            {
                game_map[y][x] = AIR;
            }

        }
        else if ((game_map[y][x] <= Enemy_Weapon4 && game_map[y][x] >= Enemy_Weapon4 - 2))
        {
            if (game_map[y + 1][x] == Bullet_Col)
            {
                game_map[y][x] -= 1;
                game_map[y + 1][x] = AIR;

                if (game_map[y][x] < Enemy_Weapon4 - 2)
                {
                    for (int i = y - 1; i <= y; i++)
                    {
                        for (int j = x - 1; j <= x + 1; j++)
                        {
                            if ((game_map[i][j] <= Enemy_Body_Left4 && game_map[i][j] >= Enemy_Body_Left4 - 2) ||
                                (game_map[i][j] <= Enemy_Body_Right4 && game_map[i][j] >= Enemy_Body_Right4 - 2) ||
                                (game_map[i][j] <= Enemy_Weapon4 && game_map[i][j] >= Enemy_Weapon4 - 3) ||
                                (game_map[i][j] <= Enemy_Head4 && game_map[i][j] >= Enemy_Head4 - 2))
                                game_map[i][j] = Ship_Die1;
                            Sound::play(2);
                            Sound::volume(2, 1);
                        }

                    }
                    rand_item = rand() % 4;

                    if (rand_item == 1)
                    {
                        game_map[y][x] = Item_Red;

                    }
                    *score += 1;
                }
            }
            else if (game_map[y][x - 1] == WALL)
            {
                game_map[y][x] = AIR;
            }
        }
    }
}