#include "MapStatus.h"
#include "Collision_Check.h"
#include "Enemy_Part.h"

void aa(Game_Map game_map, XY_Position_Ship current_ship_xy, Map_Status_Count current_map_status)
{
	int x, y;
	int collision_arr[3];

	for (int i = 0; i < current_map_status.count_all_enemy; i++)
	{
		x = current_ship_xy.all_enemy_x[i];
		y = current_ship_xy.all_enemy_y[i];



	}


}