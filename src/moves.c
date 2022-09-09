/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:02:10 by skhali            #+#    #+#             */
/*   Updated: 2022/09/09 18:33:47 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_case(int i, int j, t_map *map)
{
	if (map->tab[i][j] == '1')
		return (0);
	if (map->tab[i][j] == 'E' && map->i_collected != map->i_num)
		return (0);
	return (1);
}

int	case_action(int i, int j, t_map *map)
{
	int	a;
	int	b;

	a = i * 64;
	b = j * 64;
	if (map->tab[i][j] == 'I')
		map->i_collected++;
	if (map->tab[i][j] == 'E' && map->i_collected == map->i_num)
		return (2);
	map->tab[i][j] = 'P';
	map->tab[map->pos_y][map->pos_x] = '0';
	mlx_put_image_to_window(map->image->mlx, map->image->mlx_win,
		map->image->player, b, a);
	mlx_put_image_to_window(map->image->mlx, map->image->mlx_win,
		map->image->ground, map->pos_x * 64, map->pos_y * 64);
	map->pos_x = j;
	map->pos_y = i;
	map->moves++;
	return (1);
}

int	player_moves(int keycode, t_map *map)
{
	int	status;

	status = 0;
	if (keycode == UP)
		if (check_case(map->pos_y - 1, map->pos_x, map))
			status = case_action(map->pos_y - 1, map->pos_x, map);
	if (keycode == DOWN)
		if (check_case(map->pos_y + 1, map->pos_x, map))
			status = case_action(map->pos_y + 1, map->pos_x, map);
	if (keycode == LEFT)
		if (check_case(map->pos_y, map->pos_x - 1, map))
			status = case_action(map->pos_y, map->pos_x - 1, map);
	if (keycode == RIGHT)
		if (check_case(map->pos_y, map->pos_x + 1, map))
			status = case_action(map->pos_y, map->pos_x + 1, map);
	if (keycode == ESC || status == 2)
	{
		destroy_images(map->image, map, "", 12);
		exit(0);
	}
	if (status != 0)
		print("Nombre de mouvements :", map->moves);
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