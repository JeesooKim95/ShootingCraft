/**
\file        Game_State.cpp
\author      sangmin.kim
\par         email: ryan95kr@gmail.com
\brief
This file will managing the game by set of gameState.
                GameStatus_Manager : Using switch statement, check the current gameState, execute it.
                Create_gameState   : Using malloc, give the data to out gameState pointer.
                Set_GameStatus     : Set easily current gameState.

                copyright   All content ?2018 DigiPen (USA) Corporation, all rights reserved
*/
#include "Game_State.h"
#include "MapStatus.h"
#include "Apply_Two_Map.h"
#include "GameMap_Display.h"
#include "GameMap_Control.h"
#include "GameMap_Position.h"
#include "GameMap_Count.h"
#include "Create_Ship_XY.h"
#include "Free_Allocated_Data.h"
#include "Bullet_Move.h"
#include "stdlib.h"
#include "Timer.h"
#include "Enemy_Init.h"
#include "Ship_Shoot_Bullet.h"
#include "Collision_Control.h"
#include "Enemy_Move.h"
#include "Rid_Bullet_Col.h"
#include "Particle.h"
#include "windows.h"
#include "Enemy_Determine_Dir.h"
#include "Enemy_Init2.h"
#include "Overlapped_Control.h"
#include "Enemy_Init3.h"
#include "Enemy_Move_Phase_1_first.h"
#include "Enemy_Move_Phase_1_second.h"
#include "Enemy_Init4.h"
#include "Phase3_Enemy_Init.h"
#include "GameMap_Clear.h"
#include "Item_Move.h"
#include "Bomb.h"
#include "Sound_Manager.h"
#include "Boss_Init.h"
#include "Boss_Move.h"
#include "Boss_Shoot.h"
#include "Boss_Bullet_Move.h"
#include "Boss_Move_Phase2.h"
#include "Tutorial.h"
#include "Bef_Boss_Clean.h"
#include "Game_Control.h"
#include "GameClear.h"
#include "GameOver.h"

Ship_Map ship_map = { 0 };
Game_Map game_map = { 0 };

bool EASY = TRUE;
bool HARD = FALSE;
bool is_hack = false;
bool can_control = true;

void GameStatus_Manager(GameState* gameState, bool* should_run, long dt, Map_Status_Count* current_map_status, XY_Position_Ship* current_ship_xy, In_Game_Seconds* in_game_seconds, Game_Control* game_control, Level_Control* level_control)
{
    srand((unsigned)time(NULL));


    CONSOLE_CURSOR_INFO cursorInfo = { 0, };
    cursorInfo.dwSize = 1;
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);


    switch (*gameState)
    {
    case Initialize_Ship_Map:
        EASY = TRUE;
        HARD = FALSE;
        Init_Control(current_ship_xy, current_map_status, in_game_seconds, game_control, level_control);
        Initialize_ShipMap(ship_map);
        Set_GameStatus(gameState, Initialize_Game_Map);
        break;

    case Initialize_Hard_Ship_Map:
        EASY = FALSE;
        HARD = TRUE;
        Init_Hard_Control(current_ship_xy, current_map_status, in_game_seconds, game_control, level_control);
        Initialize_ShipMap(ship_map);
        Set_GameStatus(gameState, Initialize_Game_Map);
        break;

    case Hack_Mode:
        is_hack = true;
        EASY = TRUE;
        HARD = FALSE;
        Init_Control(current_ship_xy, current_map_status, in_game_seconds, game_control, level_control);
        Initialize_ShipMap(ship_map);
        Set_GameStatus(gameState, Initialize_Game_Map);
        break;
    case Boss_Hack:
        game_control->enemy_arr_1 = false;
        game_control->enemy_arr_2 = false;

        game_control->init_enemy = false;
        game_control->init_enemy2 = false;
        game_control->init_enemy3 = false;

        

        game_control->phase_1 = false;
        game_control->phase_2 = false;
        game_control->phase_3 = false;
        game_control->bef_boss_init = true;

        Set_GameStatus(gameState, Update_Game_Map);
        break;
    case Initialize_Ship:
        Set_GameStatus(gameState, Initialize_Game_Map);
        break;

    case Initialize_Game_Map:
        Initialize_GameMap(game_map);
        Set_GameStatus(gameState, Paste_ShipMap_To_GameMap);
        break;

    case Paste_ShipMap_To_GameMap:
        if (!is_hack)
        {
            ShipMap_To_GameMap(ship_map, game_map);
        }
        if (is_hack)
        {
            Hack_ShipMap_To_GameMap(ship_map, game_map);

        }
        Set_GameStatus(gameState, Tutorial);
        break;

    case Tutorial:
        GameMap_Display(game_map, level_control->score, level_control->power_up_tutorial);
        if (game_control->tutorial_enemy_is_exist)
        {
            Init_Tutorial_Enemy(game_map, *current_ship_xy, *current_map_status);
            game_control->tutorial_enemy_is_exist = false;
        }
        Get_Count_Game_Map(game_map, current_map_status);
        Get_XY_Game_Map(game_map, current_ship_xy);
        GameMap_ControlShip_Tutorial(game_map, current_ship_xy, current_map_status, ship_map, gameState, &level_control->power_up_tutorial, &level_control->player_bullet_move_limitation, gameState);
        Check_Collision(game_map, current_ship_xy, *current_map_status, &level_control->score, &level_control->power_up, gameState, should_run, is_hack);
        Introduction(game_map);
        if (in_game_seconds->bullet_move < 0)
        {
            Move_Bullet(game_map, *current_map_status, *current_ship_xy);
            in_game_seconds->bullet_move = PLAYER_BULLET_MOVE + level_control->player_bullet_move_limitation;
        }

        if (in_game_seconds->particle_effext < 0)
        {
            Rid_Bullet_Col(game_map, *current_ship_xy, *current_map_status);
            Particle_Ship(game_map, *current_ship_xy, *current_map_status);
            Bomb_Particle(game_map, *current_ship_xy, *current_map_status);

            in_game_seconds->particle_effext = PARTICLE_EFFECT;
        }
        if (current_map_status->count_enemy_whole_ship == 0)
        {
            game_control->tutorial_enemy_is_exist = true;
        }
        if (in_game_seconds->twinkle_letters < 0)
        {
            Item_Twinkle(game_map, *current_ship_xy, *current_map_status);
            in_game_seconds->twinkle_letters = TWINKLE_LETTERS;
        }


        in_game_seconds->bullet_move -= dt;
        in_game_seconds->particle_effext -= dt;
        in_game_seconds->twinkle_letters -= dt;
        game_control->bef_phase_1 = true;
        break;

    case Tutorial_end:
        Initialize_GameMap(game_map);

        Set_GameStatus(gameState, Update_Game_Map);
        if (!is_hack)
        {
            ShipMap_To_GameMap(ship_map, game_map);
            level_control->score = 0;
            level_control->power_up = 1;
            level_control->player_bullet_move_limitation = 30;
        }
        if (is_hack)
        {
            Hack_ShipMap_To_GameMap(ship_map, game_map);
            level_control->score = 0;
            level_control->power_up = 50;
            level_control->player_bullet_move_limitation = 0;
        }
    case Update_Game_Map:
        GameMap_Display(game_map, level_control->score, level_control->power_up);
        Get_Count_Game_Map(game_map, current_map_status);
        Get_XY_Game_Map(game_map, current_ship_xy);
        if (can_control)
        {
            GameMap_ControlShip(game_map, current_ship_xy, current_map_status, ship_map, gameState, &level_control->power_up, &level_control->player_bullet_move_limitation);
        }
        Determine_Enemy_Bullet_Dir(game_map, *current_map_status, current_ship_xy);
        Check_Collision(game_map, current_ship_xy, *current_map_status, &level_control->score, &level_control->power_up, gameState, should_run, is_hack);
        GameMap_Clear_Trash(game_map, *current_ship_xy, *current_map_status);
        Initialize_GameMap_IF_WALL_IS_ERASED(game_map);
        Set_Bomb(game_map, *current_ship_xy, *current_map_status);
        Decrease_Time(in_game_seconds, dt, game_control->boss_phase_2, game_control->bef_phase_1, game_control->bef_boss_init, game_control);
        if (in_game_seconds->bullet_move < 0)
        {
            Move_Bullet(game_map, *current_map_status, *current_ship_xy);
            in_game_seconds->bullet_move = PLAYER_BULLET_MOVE + level_control->player_bullet_move_limitation;
        }
        if (game_control->phase_1 && !game_control->enemy_arr_1 && game_control->once)
        {
            game_control->enemy_arr_1 = true;
            game_control->once = false;
        }
        if (in_game_seconds->bef_phase_1 < 0 && game_control->bef_phase_1)
        {
            game_control->phase_1 = true;
            game_control->bef_phase_1 = false;

        }
        if (game_control->phase_1)
        {

            if (game_control->enemy_arr_1)
            {
                if (in_game_seconds->enemy_1_init < 0)
                {
                    Control_Enemy_Init3(level_control->enemy_arr1_control_x_up);
                    Initialize_Enemy_Ship3(game_map, &level_control->control_enemy_num);
                    Control_Enemy_Init3(level_control->enemy_arr1_control_x_down);
                    Initialize_Enemy_Ship3(game_map, &level_control->control_enemy_num);

                    if (level_control->enemy_arr1_control_x_up <= LOW - 4 && level_control->enemy_arr1_control_x_down >= 4)
                    {
                        level_control->enemy_arr1_control_x_up += 4;
                        level_control->enemy_arr1_control_x_down -= 4;
                    }
                    else
                    {
                        game_control->enemy_arr_1 = false;

                        level_control->enemy_arr1_control_x_down = (COL / 2) - 1;
                        level_control->enemy_arr1_control_x_up = (COL / 2) + 1;
                    }
                    in_game_seconds->enemy_1_init = ENEMY_1_INIT;
                }
            }
            if (game_control->enemy_arr_2)
            {
                if (in_game_seconds->enemy_2_init < 0)
                {
                    Control_Enemy_Init4(level_control->enemy_arr1_control_x_up);
                    Initialize_Enemy_Ship4(game_map, &level_control->control_enemy_num);
                    Control_Enemy_Init4(level_control->enemy_arr1_control_x_down);
                    Initialize_Enemy_Ship4(game_map, &level_control->control_enemy_num);

                    if (level_control->enemy_arr1_control_x_up <= LOW - 6 && level_control->enemy_arr1_control_x_down >= 6)
                    {
                        level_control->enemy_arr1_control_x_up += 3;
                        level_control->enemy_arr1_control_x_down -= 3;
                    }
                    else
                    {
                        game_control->enemy_arr_2 = false;
                        game_control->change_phase_1_to_2 = true;

                    }
                    in_game_seconds->enemy_2_init = ENEMY_2_INIT;
                }
            }

            if (in_game_seconds->enemy_1_move < 0)
            {
                Enemy_Move3(game_map, current_ship_xy, *current_map_status, game_control->enemy_arr_2);

                in_game_seconds->enemy_1_move = ENEMY_1_MOVE;
            }
            if (in_game_seconds->enemy_1_shoot < 0)
            {
                Enemy_Shoot_Bullet3(game_map, *current_ship_xy, *current_map_status);
                in_game_seconds->enemy_1_shoot = ENEMY_1_SHOOT;
            }
            if (in_game_seconds->enemy_2_move < 0)
            {
                Enemy_Move4(game_map, current_ship_xy, *current_map_status, game_control->phase_2);
                in_game_seconds->enemy_2_move = ENEMY_2_MOVE;
            }
            if (in_game_seconds->enemy_2_shoot < 0)
            {
                Enemy_Shoot_Bullet4(game_map, *current_ship_xy, *current_map_status);
                in_game_seconds->enemy_2_shoot = ENEMY_2_SHOOT;
            }
            if (in_game_seconds->phase_1_enemy_bullet_move < 0)
            {
                Move_Enemy_Bullet2(game_map, *current_ship_xy, *current_map_status);
                in_game_seconds->phase_1_enemy_bullet_move = PHASE_1_ENEMY_BULLET_MOVE;

            }

        }

        if (game_control->phase_2)
        {
            int ENEMY_MOVE_UPGRADE = 0;

            if (in_game_seconds->phase_2_enemy_1_move < 0)
            {
                Enemy_Move(game_map, current_ship_xy, *current_map_status);
                Check_Overlapped(game_map, current_ship_xy, *current_map_status);
                in_game_seconds->phase_2_enemy_1_move = PHASE_2_ENEMY_1_MOVE - ENEMY_MOVE_UPGRADE;
            }
            if (in_game_seconds->phase_2_enemy_2_move < 0)
            {
                Enemy_Move2(game_map, current_ship_xy, *current_map_status);
                Check_Overlapped(game_map, current_ship_xy, *current_map_status);
                in_game_seconds->phase_2_enemy_2_move = PHASE_2_ENEMY_2_MOVE - ENEMY_MOVE_UPGRADE;
            }

            if (game_control->init_enemy)
            {
                level_control->enemy_type = rand() % 2;
                game_control->init_enemy = false;
            }
            if (game_control->init_enemy2)
            {
                level_control->enemy_type2 = rand() % 2;
                game_control->init_enemy2 = false;
            }

            if (!game_control->init_enemy)
            {
                if (in_game_seconds->phase_2_enemy_1_init < 0)
                {
                    Control_Enemy_Init(level_control->enemy_type);
                    Initialize_Enemy_Ship(game_map, &level_control->control_enemy_num);
                    in_game_seconds->phase_2_enemy_1_init = PHASE_2_ENEMY_1_INIT;
                }
                if (level_control->control_enemy_num > 1)
                {
                    game_control->init_enemy = true;
                    level_control->control_enemy_num = 0;
                }
            }
            if (!game_control->init_enemy2)
            {
                if (in_game_seconds->phase_2_enemy_2_init < 0)
                {
                    Control_Enemy_Init2(level_control->enemy_type2);
                    Initialize_Enemy_Ship2(game_map, &level_control->control_enemy_num2);
                    in_game_seconds->phase_2_enemy_2_init = PHASE_2_ENEMY_2_INIT;
                }
                if (level_control->control_enemy_num2 > 1)
                {
                    game_control->init_enemy2 = true;
                    level_control->control_enemy_num2 = 0;
                }

            }
            if (in_game_seconds->phase_2_enemy_1_shoot < 0)
            {
                Enemy_Shoot_Bullet(game_map, *current_ship_xy, *current_map_status);
                in_game_seconds->phase_2_enemy_1_shoot = PHASE_2_ENEMY_1_SHOOT;

            }
            if (in_game_seconds->phase_2_enemy_2_shoot < 0)
            {
                Enemy_Shoot_Bullet2(game_map, *current_ship_xy, *current_map_status);
                in_game_seconds->phase_2_enemy_2_shoot = PHASE_2_ENEMY_2_SHOOT;
            }
            if (in_game_seconds->phase_2_enemy_1_bullet_move < 0)
            {
                Move_Enemy_Bullet(game_map, *current_ship_xy, *current_map_status);
                in_game_seconds->phase_2_enemy_1_bullet_move = PHASE_2_ENEMY_1_BULLET_MOVE;
            }
            if (in_game_seconds->phase_2_enemy_2_bullet_move < 0)
            {
                Move_Enemy_Bullet2(game_map, *current_ship_xy, *current_map_status);
                in_game_seconds->phase_2_enemy_2_bullet_move = PHASE_2_ENEMY_2_BULLET_MOVE;
            }

        }

        if (game_control->phase_3)
        {

            if (in_game_seconds->phase_3_enemy_1_move < 0)
            {
                Enemy_Move(game_map, current_ship_xy, *current_map_status);
                Check_Overlapped(game_map, current_ship_xy, *current_map_status);
                in_game_seconds->phase_3_enemy_1_move = PHASE_3_ENEMY_1_MOVE - level_control->PHASE3_ENEMY1_MOVE_UPGRADE;
            }
            if (in_game_seconds->phase_3_enemy_2_move < 0)
            {
                Phase3_Enemy_Move(game_map, current_ship_xy, *current_map_status, current_ship_xy->head_ship_y[0]);

                in_game_seconds->phase_3_enemy_2_move = PHASE_3_ENEMY_2_MOVE - level_control->PHASE3_ENEMY2_MOVE_UPGRADE;
            }

            if (game_control->init_enemy)
            {
                level_control->enemy_type = rand() % 2;
                game_control->init_enemy = false;
            }
            if (game_control->init_enemy2)
            {
                level_control->enemy_type2 = rand() % 2;
                game_control->init_enemy2 = false;
            }

            if (!game_control->init_enemy)
            {
                if (in_game_seconds->phase_3_enemy_1_init < 0)
                {
                    Control_Enemy_Init(level_control->enemy_type);
                    Initialize_Enemy_Ship(game_map, &level_control->control_enemy_num);
                    in_game_seconds->phase_3_enemy_1_init = PHASE_3_ENEMY_1_INIT - level_control->PHASE3_ENEMY1_INIT_UPGRADE;
                }
                if (level_control->control_enemy_num > 1)
                {
                    game_control->init_enemy = true;
                    level_control->control_enemy_num = 0;
                }
            }

            if (!game_control->init_enemy2)
            {
                if (in_game_seconds->phase_3_enemy_2_init < 0)
                {
                    Phase3_Control_Enemy_Init(level_control->enemy_type2, current_ship_xy->head_ship_x[0] - 1);
                    Phase3_Initialize_Enemy_Ship(game_map, &level_control->control_enemy_num2);
                    in_game_seconds->phase_3_enemy_2_init = PHASE_3_ENEMY_2_INIT - level_control->PHASE3_ENEMY2_INIT_UPGRADE;
                }
                if (level_control->control_enemy_num2 > 1)
                {
                    game_control->init_enemy2 = true;
                    level_control->control_enemy_num2 = 0;
                }

            }
            if (in_game_seconds->phase_3_enemy_1_shoot < 0)
            {
                Enemy_Shoot_Bullet(game_map, *current_ship_xy, *current_map_status);
                in_game_seconds->phase_3_enemy_1_shoot = PHASE_3_ENEMY_1_SHOOT - level_control->PHASE3_ENEMY1_SHOOT_UPGRADE;
            }
            if (in_game_seconds->phase_3_enemy_2_shoot < 0)
            {
                Enemy_Shoot_Bullet2(game_map, *current_ship_xy, *current_map_status);
                in_game_seconds->phase_3_enemy_2_shoot = PHASE_3_ENEMY_2_SHOOT - level_control->PHASE3_ENEMY2_SHOOT_UPGRADE;
            }
            if (in_game_seconds->phase_3_enemy_1_bullet_move < 0)
            {

                Move_Enemy_Bullet(game_map, *current_ship_xy, *current_map_status);
                in_game_seconds->phase_3_enemy_1_bullet_move = PHASE_3_ENEMY_1_BULLET_MOVE - level_control->PHASE3_ENEMY1_BULLET_MOVE_UPGRADE;
            }
            if (in_game_seconds->phase_3_enemy_2_bullet_move < 0)
            {
                Move_Enemy_Bullet2(game_map, *current_ship_xy, *current_map_status);
                in_game_seconds->phase_3_enemy_2_bullet_move = PHASE_3_ENEMY_2_BULLET_MOVE - level_control->PHASE3_ENEMY2_BULLET_MOVE_UPGRADE;
            }

            if (EASY == TRUE && HARD == FALSE)
            {
                if (level_control->score % 2 == 0 && game_control->level_up_once)
                {
                    if (in_game_seconds->phase_3_enemy_1_move > PHASE_3_ENEMY_1_MOVE_LIMIT)
                    {
                        level_control->PHASE3_ENEMY1_MOVE_UPGRADE += UPGRADE_MOVE_30;
                    }
                    if (in_game_seconds->phase_3_enemy_2_move > PHASE_3_ENEMY_2_MOVE_LIMIT)
                    {
                        level_control->PHASE3_ENEMY2_MOVE_UPGRADE += UPGRADE_MOVE_10;
                    }
                    if (in_game_seconds->phase_3_enemy_1_bullet_move > PHASE_3_ENEMY_1_BULLET_MOVE_LIMIT)
                    {
                        level_control->PHASE3_ENEMY1_BULLET_MOVE_UPGRADE += UPGRADE_BULLET_MOVE_3;
                    }
                    if (in_game_seconds->phase_3_enemy_2_bullet_move > PHASE_3_ENEMY_2_BULLET_MOVE_LIMIT)
                    {
                        level_control->PHASE3_ENEMY2_BULLET_MOVE_UPGRADE += UPGRADE_BULLET_MOVE_1;
                    }
                    if (in_game_seconds->phase_3_enemy_1_init > PHASE_3_ENEMY_1_INIT_LIMIT)
                    {
                        level_control->PHASE3_ENEMY1_INIT_UPGRADE += UPGRADE_INIT_50;
                    }
                    if (in_game_seconds->phase_3_enemy_2_init > PHASE_3_ENEMY_2_INIT_LIMIT)
                    {
                        level_control->PHASE3_ENEMY2_INIT_UPGRADE += UPGRADE_INIT_20;
                    }
                    level_control->PHASE3_ENEMY1_SHOOT_UPGRADE += UPGRADE_SHOOT_50;
                    level_control->PHASE3_ENEMY2_SHOOT_UPGRADE += UPGRADE_SHOOT_35;
                }
            }
            if (EASY == FALSE && HARD == TRUE)
            {
                if (level_control->score % 2 == 0 && game_control->level_up_once)
                {

                    if (in_game_seconds->phase_3_enemy_1_move > PHASE_3_ENEMY_1_MOVE_LIMIT)
                    {
                        level_control->PHASE3_ENEMY1_MOVE_UPGRADE += UPGRADE_HARD_MOVE_30;
                    }
                    if (in_game_seconds->phase_3_enemy_2_move > PHASE_3_ENEMY_2_MOVE_LIMIT)
                    {
                        level_control->PHASE3_ENEMY2_MOVE_UPGRADE += UPGRADE_HARD_MOVE_10;
                    }
                    if (in_game_seconds->phase_3_enemy_1_bullet_move > PHASE_3_ENEMY_1_BULLET_MOVE_LIMIT)
                    {
                        level_control->PHASE3_ENEMY1_BULLET_MOVE_UPGRADE += UPGRADE_HARD_BULLET_MOVE_3;
                    }
                    if (in_game_seconds->phase_3_enemy_2_bullet_move > PHASE_3_ENEMY_2_BULLET_MOVE_LIMIT)
                    {
                        level_control->PHASE3_ENEMY2_BULLET_MOVE_UPGRADE += UPGRADE_HARD_BULLET_MOVE_1;
                    }
                    if (in_game_seconds->phase_3_enemy_1_init > PHASE_3_ENEMY_1_INIT_LIMIT)
                    {
                        level_control->PHASE3_ENEMY1_INIT_UPGRADE += UPGRADE_HARD_INIT_50;
                    }
                    if (in_game_seconds->phase_3_enemy_2_init > PHASE_3_ENEMY_2_INIT_LIMIT)
                    {
                        level_control->PHASE3_ENEMY2_INIT_UPGRADE += UPGRADE_HARD_INIT_20;
                    }
                    level_control->PHASE3_ENEMY1_SHOOT_UPGRADE += UPGRADE_HARD_SHOOT_50;
                    level_control->PHASE3_ENEMY2_SHOOT_UPGRADE += UPGRADE_HARD_SHOOT_35;
                }
            }
        }


        if (game_control->phase_boss)
        {
            if (game_control->boss_phase_1)
            {
                if (game_control->init_boss)
                {
                    Make_Boss();
                    Boss_Init(game_map, *current_ship_xy, *current_map_status, &game_control->is_boss_exist);
                    game_control->init_boss = false;
                }
                if (in_game_seconds->boss_move < 0)
                {
                    Move_Boss(game_map, *current_ship_xy, *current_map_status);
                    in_game_seconds->boss_move = BOSS_MOVE;
                }
                if (in_game_seconds->boss_shoot < 0)
                {
                    Boss_Shoot(game_map, *current_ship_xy, *current_map_status);
                    in_game_seconds->boss_shoot = BOSS_SHOOT;
                }
                if (in_game_seconds->boss_shoot_unbreakable_weapon < 0)
                {
                    Boss_Shoot_Unbreakable_weapon(game_map, *current_ship_xy, *current_map_status, &game_control->boss_phase_2, &game_control->boss_phase_1);
                    in_game_seconds->boss_shoot_unbreakable_weapon = BOSS_SHOOT_UNBREAKABLE_WEAPON;
                }
                if (in_game_seconds->boss_bullet_move_2 < 0)
                {
                    Boss_Bullet_2_Move(game_map, *current_ship_xy, *current_map_status);
                    in_game_seconds->boss_bullet_move_2 = BOSS_BULLET_MOVE_2;
                }


            }
            if (game_control->boss_phase_2)
            {
                if (!game_control->boss_move_enough)
                {
                    if (in_game_seconds->boss_phase_2_move_back < 0)
                    {
                        Move_Boss_Phase_2_Back(game_map, *current_ship_xy, *current_map_status, &game_control->boss_move_enough, &game_control->init_boss_phase_2);
                        in_game_seconds->boss_phase_2_move_back = BOSS_PHASE_2_MOVE_BACK;
                    }
                }
                if (in_game_seconds->boss_bullet_move_2 < 0)
                {
                    Boss_Bullet_2_Move(game_map, *current_ship_xy, *current_map_status);
                    in_game_seconds->boss_bullet_move_2 = BOSS_BULLET_MOVE_2;
                }
                if (game_control->boss_move_enough)
                {
                    if (game_control->init_boss_phase_2)
                    {

                        Boss_Init2(game_map, *current_ship_xy, *current_map_status);
                        game_control->init_boss_phase_2 = false;
                    }
                    if (in_game_seconds->wait_boss_combine < 0)
                    {
                        Boss_Combine(game_map, *current_ship_xy, *current_map_status, &game_control->is_combined);
                        in_game_seconds->wait_boss_combine = WAIT_SEC_COMBINE;

                    }

                }
                if (game_control->is_combined)
                {
                    if (in_game_seconds->boss_move < 0)
                    {
                        Move_Boss(game_map, *current_ship_xy, *current_map_status);
                        in_game_seconds->boss_move = BOSS_MOVE;
                    }
                    if (in_game_seconds->boss_shoot_unbreakable_weapon < 0)
                    {
                        Boss_Shoot_Unbreakable_weapon(game_map, *current_ship_xy, *current_map_status, &game_control->boss_phase_2, &game_control->boss_phase_1);
                        in_game_seconds->boss_shoot_unbreakable_weapon = BOSS_SHOOT_UNBREAKABLE_WEAPON;
                    }
                    if (in_game_seconds->boss_shoot_weapon_2 < 0)
                    {

                        Boss_Shoot_Weapon_2(game_map, *current_ship_xy, *current_map_status);
                        in_game_seconds->boss_shoot_weapon_2 = BOSS_SHOOT_PHASE_2_WEAPON;
                    }
                    if (in_game_seconds->boss_phase_2_bullet_move < 0)
                    {
                        Boss_phase_2_bullet_move(game_map, *current_ship_xy, *current_map_status);
                        in_game_seconds->boss_phase_2_bullet_move = BOSS_BULLET_PHASE_2_MOVE;
                    }
                    if (in_game_seconds->boss_phase_2_shoot_weapon2 < 0)
                    {
                        Boss_Shoot_Phase_Weapon2(game_map, *current_ship_xy, *current_map_status, game_control);

                        in_game_seconds->boss_phase_2_shoot_weapon2 = BOSS_SHOOT_PHASE_2_WEAPON2;
                    }
                }
            }
            if (game_control->boss_phase_3)
            {
                if (in_game_seconds->boss_move_fast_enouth < 0)
                {
                    game_control->boss_move_fast = false;
                }
                if (game_control->boss_move_fast)
                {
                    if (in_game_seconds->boss_move_phase_3_fast < 0)
                    {
                        Move_Boss_Phase_3_Fast(game_map, *current_ship_xy, *current_map_status);
                        in_game_seconds->boss_move_phase_3_fast = BOSS_MOVE_PHASE_3_MOVE_FAST;
                    }

                    if (in_game_seconds->boss_shoot_phase_3_weapon2_fast < 0)
                    {
                        Boss_Shoot_Weapon_2(game_map, *current_ship_xy, *current_map_status);
                        in_game_seconds->boss_shoot_phase_3_weapon2_fast = BOSS_SHOOT_PHASE_3_WEAPON2_FAST;
                    }

                    if (in_game_seconds->boss_shoot_phase_3_weapon3_fast < 0)
                    {
                        Boss_Shoot_Phase3_Weapon2(game_map, *current_ship_xy, *current_map_status, game_control);
                        in_game_seconds->boss_shoot_phase_3_weapon3_fast = BOSS_SHOOT_PHASE_3_WEAPON3_FAST;
                    }

                }
                if (!game_control->boss_move_fast)
                {
                    if (in_game_seconds->boss_move_phase_3_normal < 0)
                    {
                        Move_Boss(game_map, *current_ship_xy, *current_map_status);
                        in_game_seconds->boss_move_phase_3_normal = BOSS_MOVE_PHASE_3_MOVE_NORMAL;
                    }

                    if (in_game_seconds->boss_shoot_phase_3_weapon2_normal < 0)
                    {
                        Boss_Shoot_Weapon_2(game_map, *current_ship_xy, *current_map_status);
                        in_game_seconds->boss_shoot_phase_3_weapon2_normal = BOSS_SHOOT_PHASE_3_WEAPON2_NORMAL;
                    }

                    if (in_game_seconds->boss_shoot_phase_3_weapon3_normal < 0)
                    {
                        Boss_Shoot_Phase3_Weapon2(game_map, *current_ship_xy, *current_map_status, game_control);
                        in_game_seconds->boss_shoot_phase_3_weapon3_normal = BOSS_SHOOT_PHASE_3_WEAPON3_NORMAL;
                    }
                }
                if (in_game_seconds->boss_phase_2_bullet_move < 0)
                {
                    Boss_phase_2_bullet_move(game_map, *current_ship_xy, *current_map_status);
                    in_game_seconds->boss_phase_2_bullet_move = BOSS_BULLET_PHASE_2_MOVE;
                }
                if (in_game_seconds->boss_bullet_move_2 < 0)
                {
                    Boss_Bullet_2_Move(game_map, *current_ship_xy, *current_map_status);
                    in_game_seconds->boss_bullet_move_2 = BOSS_BULLET_MOVE_2;
                }
            }
        }

        if (in_game_seconds->particle_effext < 0)
        {
            Rid_Bullet_Col(game_map, *current_ship_xy, *current_map_status);
            Particle_Ship(game_map, *current_ship_xy, *current_map_status);
            Bomb_Particle(game_map, *current_ship_xy, *current_map_status);

            in_game_seconds->particle_effext = PARTICLE_EFFECT;
        }
        if (level_control->score == 3 && game_control->second)
        {
            game_control->second = false;
            game_control->enemy_arr_1 = false;
            game_control->enemy_arr_2 = true;
        }
        if (in_game_seconds->item_move < 0)
        {
            Item_Move(game_map, *current_ship_xy, *current_map_status);
            in_game_seconds->item_move = ITEM_MOVE;
        }
        if (in_game_seconds->bef_boss_phase < 0)
        {
            game_control->bef_boss_init = false;
            game_control->let_boss_init = true;
        }
        if (!can_control)
        {
            if (in_game_seconds->change_player_pos < 0)
            {
                Bef_Boss_Change_Player_Pos(game_map, *current_ship_xy, *current_map_status, &can_control);
                in_game_seconds->change_player_pos = CHANGE_PLAYER_POS;
            }
        }
        if (in_game_seconds->clear_enemy < 0)
        {
            Bef_Boss_Clear_Screen(game_map, *current_ship_xy, *current_map_status);
            Move_Enemy_Bullet2(game_map, *current_ship_xy, *current_map_status);
            Move_Enemy_Bullet(game_map, *current_ship_xy, *current_map_status);
            in_game_seconds->clear_enemy = CLEAR_ENEMY;
        }
        if (game_control->let_boss_init == true)
        {
            game_control->phase_boss = true;
            game_control->let_boss_init = false;
        }
        if (level_control->score > ENEMY_INIT)
        {
            game_control->phase_1 = false;
            game_control->phase_2 = true;

        }
        if (level_control->score % 2 == 0 && game_control->level_up_once)
        {


            game_control->level_up_once = false;
            level_control->temp_score = level_control->score;

        }
        if (!(game_control->level_up_once) && level_control->temp_score != level_control->score)
        {
            game_control->level_up_once = true;

        }
        if (EASY)
        {
            if (level_control->score > FIRST_EASY_PHASE)
            {
                game_control->phase_2 = false;
                game_control->phase_3 = true;
            }
        }
        if (HARD)
        {
            if (level_control->score > FIRST_HARD_PHASE)
            {
                game_control->phase_2 = false;
                game_control->phase_3 = true;
            }
        }
        if (EASY)
        {
            if (level_control->score > SECOND_EASY_PHASE)
            {
                game_control->phase_3 = false;
                if (game_control->bef_boss_init)
                {
                    can_control = false;
                }
                game_control->bef_boss_init = true;
            }
        }
        if (HARD)
        {
            if (level_control->score > SECOND_HARD_PHASE)
            {
                game_control->phase_3 = false;
                if (game_control->bef_boss_init)
                {
                    can_control = false;
                }
                game_control->bef_boss_init = true;
            }
        }
        if (current_map_status->count_ship_head == 0)
        {
            Set_GameStatus(gameState, End_Game);
        }

        break;
    case Free_Allocated_Data:
        Free_Allocated(current_ship_xy);
        break;
    case Count_Ship_Game_Map:
        Get_Count_Game_Map(game_map, current_map_status);
        break;
    case Malloc_ship_XY:
        Create_Ship_XY(current_ship_xy, *current_map_status);
        break;
    case Position_Ship_Game_Map:
        Get_XY_Game_Map(game_map, current_ship_xy);
        break;
    case Restart:
        system("cls");
        Set_GameStatus(gameState, Initialize_Ship_Map);

        game_control->once = true;
        break;
    case Quit:
        *should_run = false;
        break;
    case End_Game:
        system("cls");
        Set_GameStatus(gameState, Initialize_Ship_Map);
        game_control->once = true;
        Game_Over(should_run);
        break;
    case Clear_Game:
        Game_Clear(should_run);
    }

}


GameState* Set_GameStatus(GameState* currentState, GameState nextState)
{
    *currentState = nextState;

    return currentState;
}

GameState* Create_gameState()
{
    GameState* gameState = NULL;

    gameState = (GameState*)malloc(sizeof(GameState));

    return gameState;
}
