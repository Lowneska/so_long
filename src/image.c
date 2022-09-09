/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:30:06 by skhali            #+#    #+#             */
/*   Updated: 2022/09/09 20:36:55 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	put_walls(int j, int i, t_map *map)
{
	if (j == 0)
		mlx_put_image_to_window(map->image->mlx, map->image->mlx_win,
			map->image->wall_up, i * 64, j * 64);
	else if ((i != 0) && (i != (map->v_len - 1)) && (j == (map->h_len - 1)))
		mlx_put_image_to_window(map->image->mlx, map->image->mlx_win,
			map->image->wall_down, i * 64, j * 64);
	else if ((i == 0) && (j != 0) && (j != (map->h_len - 1)))
		mlx_put_image_to_window(map->image->mlx, map->image->mlx_win,
			map->image->wall_left, i * 64, j * 64);
	else if ((i == (map->v_len - 1)) && (j != (map->h_len - 1)))
		mlx_put_image_to_window(map->image->mlx, map->image->mlx_win,
			map->image->wall_right, i * 64, j * 64);
	else if (((i == 0) && (j == (map->h_len - 1))))
		mlx_put_image_to_window(map->image->mlx, map->image->mlx_win,
			map->image->wall_aright, i * 64, j * 64);
	else if ((i == (map->v_len - 1)) && (j == (map->h_len - 1)))
		mlx_put_image_to_window(map->image->mlx, map->image->mlx_win,
			map->image->wall_bright, i * 64, j * 64);
	else
		mlx_put_image_to_window(map->image->mlx, map->image->mlx_win,
			map->image->wall, i * 64, j * 64);
}

static void	put_images(t_image *image, t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < (map->v_len))
	{
		j = -1;
		while (++j < (map->h_len))
		{
			if (map->tab[j][i] == '1')
				put_walls(j, i, map);
			else if (map->tab[j][i] == '0')
				mlx_put_image_to_window(image->mlx, image->mlx_win,
					image->ground, i * 64, j * 64);
			else if (map->tab[j][i] == 'I')
				mlx_put_image_to_window(image->mlx, image->mlx_win,
					image->item, i * 64, j * 64);
			else if (map->tab[j][i] == 'E')
				mlx_put_image_to_window(image->mlx, image->mlx_win,
					image->exit, i * 64, j * 64);
			else
				mlx_put_image_to_window(image->mlx, image->mlx_win,
					image->player, i * 64, j * 64);
		}
	}
}

int	image_init(t_map *map)
{
	t_image	*image;

	image = malloc(sizeof(t_image));
	if (!image)
		return (simple_error_handler("Error in the initialisation of the mlx.\n",
				map));
	map->image = image;
	image->mlx = mlx_init();
	if (!image->mlx)
		return (simple_error_handler("Error in the initialisation of the mlx.\n",
				map));
	image->mlx_win = mlx_new_window(image->mlx, map->v_len * 64,
			map->h_len * 64, " So_long ");
	if (!image->mlx_win)
	{
		mlx_destroy_display(image->mlx);
		return (simple_error_handler("Error in the creation of the window.\n",
				map));
	}
	load_images(image, map);
	put_images(image, map);
	return (0);
}

int	border_error_handler(char *str, char *line, t_map *map)
{
	free(map);
	free(line);
	line = NULL;
	ft_putstr_fd(str, 2);
	return (1);
}

int	borders_check(t_map *map, int fd)
{
	char	*line;
	int		status;

	line = NULL;
	if (borders_check_bis(map, fd, &line))
		return (1);
	while (line)
	{
		map->h_len += 1;
		status = middle_line_check(line, map);
		if (!status)
			return (border_error_handler("Error.\n", line, map));
		objects(line, map);
		if (status == 1)
			break ;
		free(line);
		line = get_next_line(fd);
		if (!line)
			return (free(map), 1);
	}
	if (down_line_check(line) != map->v_len)
		return (border_error_handler("Error on the borders.\n", line, map));
	return (map->h_len += 1, free(line), 0);
}
