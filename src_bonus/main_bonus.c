/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 22:42:38 by skhali            #+#    #+#             */
/*   Updated: 2022/09/09 20:51:27 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	border_error_handler(char *str, char *line, t_map *map)
{
	free(map);
	free(line);
	line = NULL;
	ft_putstr_fd(str, 2);
	return (1);
}

void	free_map_p2(char **tab, int j)
{
	int	i;

	i = 0;
	while (i <= j)
		free(tab[i++]);
	free(tab);
}

void	init_map(t_map *map)
{
	map->e_num = 0;
	map->i_num = 0;
	map->p_num = 0;
	map->h_len = 0;
	map->v_len = 0;
	map->i_collected = 0;
	map->moves = 0;
	map->other = 0;
	map->anim = 0;
}

int	main(int argc, char **argv)
{
	t_map	*map;
	char	**tab;

	map = malloc(sizeof(t_map));
	init_map(map);
	if (argc != 2)
		return (ft_putstr_fd("Invalid number of arguments.\n", 2), 1);
	if (map_checker(argv[1], map))
		exit(1);
	map->tab = create_map(argv[1], map);
	tab = create_map(argv[1], map);
	check_path(tab, map->pos_y, map->pos_x);
	if (!check_path_map(tab, map))
		return (free_map(map, map->tab), free_map(map, tab), free(map),
			ft_putstr_fd("Pas de chemin possible !\n", 2), 1);
	free_map(map, tab);
	if (image_init(map))
		exit (1);
	mlx_loop_hook(map->image->mlx, animation, map);
	mlx_hook(map->image->mlx_win, 33, 0, cross, map);
	mlx_hook(map->image->mlx_win, 3, (1L << 1), player_stat, map);
	mlx_hook(map->image->mlx_win, KeyPress, KeyPressMask, player_moves, map);
	mlx_loop(map->image->mlx);
	destroy_images(map->image, map, "", 23);
	return (free_map(map, map->tab), free(map->image), free(map), 0);
}
