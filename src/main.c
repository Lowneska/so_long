/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 19:42:26 by skhali            #+#    #+#             */
/*   Updated: 2022/09/09 17:11:03 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <stdio.h>
void	print(char *str, int i)
{
	ft_putstr_fd(str, 2);
	ft_putnbr_fd(i, 2);
	ft_putchar_fd('\n', 2);
}

int	cross(t_map *map)
{
	destroy_images(map->image, map, "", 13);
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	*map;
	char	**tab;

	map = malloc(sizeof(t_map));
	if (!map)
		return (1);
	init_map(map);
	if (argc != 2)
		return (ft_putstr_fd("Invalid number of arguments.\n", 2), 1);
	if (map_checker(argv[1], map))
		exit(1);
	map->tab = create_map(argv[1], map);
	if (!map->tab)
		return (1);
	tab = create_map(argv[1], map);
	if (!tab)
		return (1);
	check_path(tab, map->pos_y, map->pos_x);
	if (!check_path_map(tab, map))
		return (free_map(map, map->tab), free(map),
			ft_putstr_fd("Pas de chemin possible !\n", 2), 1);
	free_map(map, tab);
	if (image_init(map))
		exit (1);
	mlx_hook(map->image->mlx_win, 33, 0, cross, map);
	mlx_hook(map->image->mlx_win, KeyPress, KeyPressMask, player_moves, map);
	mlx_loop(map->image->mlx);
	destroy_images(map->image, map, "", 13);
	return (free_map(map, map->tab), free(map->image), free(map), 0);
}
