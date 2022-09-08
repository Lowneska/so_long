/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 22:42:38 by skhali            #+#    #+#             */
/*   Updated: 2022/09/08 05:34:37 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	init_map(map);
	if (argc != 2)
		simple_error_handler("Invalid number of arguments.\n", map);
	if (map_checker(argv[1], map))
		exit(1);
	map->tab = create_map(argv[1], map);
	if (image_init(map))
		exit (1);
	mlx_loop_hook(map->image->mlx, animation, map);
	mlx_hook(map->image->mlx_win, 33, 0, cross, map);
	mlx_hook(map->image->mlx_win, 3, (1L << 1), player_stat, map);
	mlx_hook(map->image->mlx_win, KeyPress, KeyPressMask, player_moves, map);
	mlx_loop(map->image->mlx);
	destroy_images(map->image, map, "", 23);
	return (0);
}
