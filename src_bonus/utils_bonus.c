/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 22:27:33 by skhali            #+#    #+#             */
/*   Updated: 2022/09/08 14:48:52 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	player_stat(int keycode, t_map *map)
{
	if (keycode == UP)
	{
		mlx_put_image_to_window(map->image->mlx, map->image->mlx_win,
			map->image->back, map->pos_x * 64, map->pos_y * 64);
		map->anim = 1;
	}
	if (keycode == DOWN)
	{
		mlx_put_image_to_window(map->image->mlx, map->image->mlx_win,
			map->image->player, map->pos_x * 64, map->pos_y * 64);
		map->anim = 2;
	}
	if (keycode == LEFT)
	{
		mlx_put_image_to_window(map->image->mlx, map->image->mlx_win,
			map->image->profil_b, map->pos_x * 64, map->pos_y * 64);
		map->anim = 3;
	}
	if (keycode == RIGHT)
	{
		mlx_put_image_to_window(map->image->mlx, map->image->mlx_win,
			map->image->profil_a, map->pos_x * 64, map->pos_y * 64);
		map->anim = 4;
	}
	return (0);
}

int	cross(t_map *map)
{
	destroy_images(map->image, map, "", 23);
	exit(0);
	return (0);
}

static int	check(char **tab, int i, int j)
{
	return ((tab[i][j + 1] != '1' && tab[i][j + 1] != 'X') &&
	(tab[i][j - 1] != '1' && tab[i][j - 1] != 'X') && (tab[i + 1][j] != '1'
				&& tab[i + 1][j] != 'X') && (tab[i - 1][j] != '1'
					&& tab[i - 1][j] != 'X'));
}

int	check_path(char **tab, int i, int j)
{
	if (check(tab, i, j))
		return (0);
	if (tab[i + 1][j] && tab[i + 1][j] != '1' && tab[i + 1][j] != 'X')
	{
		tab[i + 1][j] = 'X';
		check_path(tab, i + 1, j);
	}
	if (tab[i - 1][j] != '1' && tab[i - 1][j] != 'X')
	{
		tab[i - 1][j] = 'X';
		check_path(tab, i - 1, j);
	}
	if (tab[i][j + 1] != '1' && tab[i][j + 1] != 'X')
	{
		tab[i][j + 1] = 'X';
		check_path(tab, i, j + 1);
	}
	if (tab[i][j - 1] && tab[i][j - 1] != '1' && tab[i][j - 1] != 'X')
	{
		tab[i][j - 1] = 'X';
		check_path(tab, i, j - 1);
	}
	return (0);
}
