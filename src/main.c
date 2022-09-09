/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 19:42:26 by skhali            #+#    #+#             */
/*   Updated: 2022/09/09 20:35:43 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	**create_map(char *str, t_map *map)
{
	char	**tab;
	int		fd;
	char	*line;
	int		i;

	i = 1;
	tab = create_map_p2(&fd, str, map, &line);
	tab[0] = ft_strdup(line);
	free(line);
	line = get_next_line(fd);
	while (line)
	{
		tab[i] = ft_strdup(line);
		free(line);
		if (!tab[i])
		{
			free_map_p2(tab, i);
			simple_exit_error_handler("Malloc error.\n", map);
		}
		line = get_next_line(fd);
		i++;
	}
	return (tab);
}

int	check_path_map(char **tab, t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < (map->v_len))
	{
		j = -1;
		while (++j < (map->h_len))
		{
			if ((tab[j][i] == 'I') || (tab[j][i] == 'E'))
				return (0);
		}
	}
	return (1);
}

void	print(char *str, int i)
{
	ft_putstr_fd(str, 2);
	ft_putnbr_fd(i, 2);
	ft_putchar_fd('\n', 2);
}

int	cross(t_map *map)
{
	destroy_images(map->image, map, "");
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
	tab = create_map(argv[1], map);
	check_path(tab, map->pos_y, map->pos_x);
	if (!check_path_map(tab, map))
		return (free_map(map, map->tab), free_map(map, tab), free(map),
			ft_putstr_fd("Pas de chemin possible !\n", 2), 1);
	free_map(map, tab);
	if (image_init(map))
		exit (1);
	mlx_hook(map->image->mlx_win, 33, 0, cross, map);
	mlx_hook(map->image->mlx_win, KeyPress, KeyPressMask, player_moves, map);
	mlx_loop(map->image->mlx);
	destroy_images(map->image, map, "");
	return (free_map(map, map->tab), free(map->image), free(map), 0);
}
