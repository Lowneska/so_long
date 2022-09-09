/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 21:48:46 by skhali            #+#    #+#             */
/*   Updated: 2022/09/09 20:45:19 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

static int	print_player_down(t_map *map)
{
	static int	i;

	if (i > 0 && i < SPEED)
	{
		mlx_put_image_to_window(map->image->mlx, map->image->mlx_win,
			map->image->player, map->pos_x * 64, map->pos_y * 64);
	}
	if (i >= SPEED && i < (SPEED * 4))
	{
		mlx_put_image_to_window(map->image->mlx, map->image->mlx_win,
			map->image->player_1, map->pos_x * 64, map->pos_y * 64);
	}
	if (i >= (SPEED * 4) && i < (SPEED * 8))
	{
		mlx_put_image_to_window(map->image->mlx, map->image->mlx_win,
			map->image->player_2, map->pos_x * 64, map->pos_y * 64);
	}
	if (i == (SPEED * 8))
		i = 0;
	i++;
	return (0);
}

static int	print_player_up(t_map *map)
{
	static int	i;

	if (i > 0 && i < SPEED)
	{
		mlx_put_image_to_window(map->image->mlx, map->image->mlx_win,
			map->image->back, map->pos_x * 64, map->pos_y * 64);
	}
	if (i >= SPEED && i < (SPEED * 4))
	{
		mlx_put_image_to_window(map->image->mlx, map->image->mlx_win,
			map->image->back_1, map->pos_x * 64, map->pos_y * 64);
	}
	if (i >= (SPEED * 4) && i < (SPEED * 8))
	{
		mlx_put_image_to_window(map->image->mlx, map->image->mlx_win,
			map->image->back_2, map->pos_x * 64, map->pos_y * 64);
	}
	if (i == (SPEED * 8))
		i = 0;
	i++;
	return (0);
}

static int	print_player_right(t_map *map)
{
	static int	i;

	if (i > 0 && i < SPEED)
	{
		mlx_put_image_to_window(map->image->mlx, map->image->mlx_win,
			map->image->profil_a, map->pos_x * 64, map->pos_y * 64);
	}
	if (i >= SPEED && i < (SPEED * 4))
	{
		mlx_put_image_to_window(map->image->mlx, map->image->mlx_win,
			map->image->profil_a_1, map->pos_x * 64, map->pos_y * 64);
	}
	if (i >= (SPEED * 4) && i < (SPEED * 8))
	{
		mlx_put_image_to_window(map->image->mlx, map->image->mlx_win,
			map->image->profil_a_2, map->pos_x * 64, map->pos_y * 64);
	}
	if (i == (SPEED * 8))
		i = 0;
	i++;
	return (0);
}

static int	print_player_left(t_map *map)
{
	static int	i;

	if (i > 0 && i < SPEED)
	{
		mlx_put_image_to_window(map->image->mlx, map->image->mlx_win,
			map->image->profil_b, map->pos_x * 64, map->pos_y * 64);
	}
	if (i >= SPEED && i < (SPEED * 4))
	{
		mlx_put_image_to_window(map->image->mlx, map->image->mlx_win,
			map->image->profil_b_1, map->pos_x * 64, map->pos_y * 64);
	}
	if (i >= (SPEED * 4) && i < (SPEED * 8))
	{
		mlx_put_image_to_window(map->image->mlx, map->image->mlx_win,
			map->image->profil_b_2, map->pos_x * 64, map->pos_y * 64);
	}
	if (i == (SPEED * 8))
		i = 0;
	i++;
	return (0);
}

int	animation(t_map *map)
{
	if (map->anim == 1)
		print_player_up(map);
	if (map->anim == 2)
		print_player_down(map);
	if (map->anim == 3)
		print_player_left(map);
	if (map->anim == 4)
		print_player_right(map);
	else
		return (0);
	return (0);
}
