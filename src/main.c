/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 19:42:26 by skhali            #+#    #+#             */
/*   Updated: 2022/09/08 14:55:12 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
	init_map(map);
	if (argc != 2)
		simple_error_handler("Invalid number of arguments.\n", map);
	if (map_checker(argv[1], map))
		exit(1);
	map->tab = create_map(argv[1], map);
	tab = create_map(argv[1], map);
	check_path(tab, map->pos_y, map->pos_x);
	if (!check_path_map(tab, map))
	{	
		free_map(map, tab);
		exit_error_handler("Pas de chemin possible !\n", map);
	}
	free_map(map, tab);
	if (image_init(map))
		exit (1);
	mlx_hook(map->image->mlx_win, 33, 0, cross, map);
	mlx_hook(map->image->mlx_win, KeyPress, KeyPressMask, player_moves, map);
	mlx_loop(map->image->mlx);
	destroy_images(map->image, map, "", 13);
	free_map(map, map->tab);
	free(map->image);
	free(map);
	return (0);
}
