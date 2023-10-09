/**
\file        Boss_Shoot.cpp
\author      jeesoo.kim
\brief
This file manages the shooting of boss.

copyright   All content ?2018 DigiPen (USA) Corporation, all rights 
*/
#include "Boss_Shoot.h"
#include "MapStatus.h"
#include "Enemy_Part.h"
#include "Ship_Status.h"
#include "Game_Control.h"

void Boss_Shoot(Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status)
{
	int x = 0, y = 0;
	int bullet_init_pos = 1;

	for(int i = 0 ; i < current_map_status.count_boss_weapon; i++)
	{
		x = current_ship_xy.boss_weapon_x[i];
		y = current_ship_xy.boss_weapon_y[i];
                bullet_init_pos = 0;
		if(game_map[y + 1][x] == AIR || game_map[y + 1][x] == Bullet)
		{
			game_map[y + 2][x] = Boss_Bullet_2;
		}
		else if((game_map[y + 1][x] <= Boss_Body && game_map[y + 1][x] >= Boss_Body - 8)
			|| (game_map[y + 1][x] <= Boss_Weapon && game_map[y + 1][x] >= Boss_Weapon - 8))
		{
			while(game_map[y + bullet_init_pos + 1][x] != AIR)
			{
                            bullet_init_pos++;
				if(game_map[y + bullet_init_pos + 1][x] == AIR)
				{
					break;
				}

			}
			game_map[y + bullet_init_pos + 1][x] = Boss_Bullet_2;

		}

	}


}
void Boss_Shoot_Weapon_2(Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status)
{
	int x = 0, y = 0;
	int bullet_init_pos = 0;

	for (int i = 0; i < current_map_status.count_boss_weapon_2; i++)
	{
		x = current_ship_xy.boss_weapon_2_x[i];
		y = current_ship_xy.boss_weapon_2_y[i];

		if (game_map[y + 1][x] == AIR)
		{
			game_map[y + 2][x] = Ship_Die_Manager;

		}
		else if ((game_map[y + 1][x] <= Boss_Body && game_map[y + 1][x] >= Boss_Body - 8)
			|| (game_map[y + 1][x] <= Boss_Weapon && game_map[y + 1][x] >= Boss_Weapon - 8))
		{
			while (game_map[y + bullet_init_pos + 1][x] != AIR)
			{
                            bullet_init_pos++;
				if (game_map[y + bullet_init_pos + 1][x] == AIR)
				{
					break;
				}

			}
			game_map[y + bullet_init_pos + 1][x] = Ship_Die_Manager;
		}
	}

}
void Boss_Shoot_Phase_Weapon2(Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status, Game_Control* game_control)
{
	int x = 0, y = 0;
	int bullet_init_pos = 1;

	for (int i = 0; i < current_map_status.count_boss_weapon_3; i++)
	{
		x = current_ship_xy.boss_weapon_3_x[i];
		y = current_ship_xy.boss_weapon_3_y[i];

                bullet_init_pos = 0;
		if (game_map[y + 1][x] == AIR || game_map[y + 1][x] == Bullet)
		{
			game_map[y + 2][x - 1] = Boss_Bullet_2;
			game_map[y + 2][x] = Boss_Bullet_2;
			game_map[y + 2][x + 1] = Boss_Bullet_2;
		}
		else if ((game_map[y + 1][x] <= Boss_Body && game_map[y + 1][x] >= Boss_Body - 8)
			|| (game_map[y + 1][x] <= Boss_Weapon && game_map[y + 1][x] >= Boss_Weapon - 8))
		{
			while (game_map[y + bullet_init_pos + 1][x] != AIR)
			{
                            bullet_init_pos++;
				if (game_map[y + bullet_init_pos + 1][x] == AIR)
				{
					break;
				}

			}
			game_map[y + bullet_init_pos + 1][x - 1] = Boss_Bullet_2;
			game_map[y + bullet_init_pos + 1][x] = Boss_Bullet_2;
			game_map[y + bullet_init_pos + 1][x + 1] = Boss_Bullet_2;
		}
		
		
	}
	if (current_map_status.count_boss_head_in_body == 0)
	{

		x = current_ship_xy.boss_weapon_unbreakable_x[1];
		y = current_ship_xy.boss_weapon_unbreakable_y[1];

		game_map[y][x] = Boss_Weapon_3;
		game_map[y][x - 1] = Boss_Weapon_2;
		game_map[y][x + 1] = Boss_Weapon_2;

		game_control->boss_phase_3 = true;
		game_control->boss_phase_2 = false;
		game_control->boss_move_fast = true;
	}

}
void Boss_Shoot_Phase3_Weapon2(Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status, Game_Control* game_control)
{
	int x = 0, y = 0;
	int bullet_init_pos = 1;


	for (int i = 0; i < current_map_status.count_boss_weapon_3; i++)
	{
		x = current_ship_xy.boss_weapon_3_x[i];
		y = current_ship_xy.boss_weapon_3_y[i];

                bullet_init_pos = 0;
		if (game_map[y + 1][x] == AIR || game_map[y + 1][x] == Bullet)
		{
			game_map[y + 2][x - 1] = Boss_Bullet_2;
			game_map[y + 2][x] = Boss_Bullet_2;
			game_map[y + 2][x + 1] = Boss_Bullet_2;
		}
		else if ((game_map[y + 1][x] <= Boss_Body && game_map[y + 1][x] >= Boss_Body - 8)
			|| (game_map[y + 1][x] <= Boss_Weapon && game_map[y + 1][x] >= Boss_Weapon - 8))
		{
			while (game_map[y + bullet_init_pos + 1][x] != AIR)
			{
                            bullet_init_pos++;
				if (game_map[y + bullet_init_pos + 1][x] == AIR)
				{
					break;
				}

			}
			game_map[y + bullet_init_pos + 1][x - 1] = Boss_Bullet_2;
			game_map[y + bullet_init_pos + 1][x] = Boss_Bullet_2;
			game_map[y + bullet_init_pos + 1][x + 1] = Boss_Bullet_2;
		}


	}


}

void Boss_Shoot_Unbreakable_weapon(Game_Map game_map, XY_Position_Ship current_ship_xy,Map_Status_Count current_map_status, bool *boss_phase_2, bool *boss_phase_1)
{
	int x = 0, y = 0;

	for(int i = 0 ; i < current_map_status.count_boss_weapon_unbreakable; i++)
	{
		x = current_ship_xy.boss_weapon_unbreakable_x[i];
		y = current_ship_xy.boss_weapon_unbreakable_y[i];

		if(game_map[y + 1][x] == AIR)
		{
			game_map[y + 2][x] = Boss_Bullet_2;

		}
		if(current_map_status.count_boss_head_in_body == 0)
		{
			*boss_phase_2 = true;
			*boss_phase_1 = false;
		}
	}


}