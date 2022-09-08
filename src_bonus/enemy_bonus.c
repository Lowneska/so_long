#include "../include/so_long_bonus.h"

int	print_player_down(t_map *map)
{
	static int	i;

	if (i > 0 && i < SPEED)
	{
		mlx_put_image_to_window(map->image->mlx, map->image->mlx_win,
			map->image->enemy, map->pos_x * 64, map->pos_y * 64);
    }
	if (i >= SPEED && i < (SPEED * 4))
	{
		mlx_put_image_to_window(map->image->mlx, map->image->mlx_win,
			map->image->enemy_1, map->pos_x * 64, map->pos_y * 64);
	}
	if (i >= (SPEED * 4) && i < (SPEED * 8))
	{
		mlx_put_image_to_window(map->image->mlx, map->image->mlx_win,
			map->image->enemy_2, map->pos_x * 64, map->pos_y * 64);
	}
	if (i == (SPEED * 8))
		i = 0;
	i++;
	return (0);
}
