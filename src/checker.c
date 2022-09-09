/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:25:10 by skhali            #+#    #+#             */
/*   Updated: 2022/09/09 20:39:09 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	middle_line_check(char *line, t_map *map)
{
	int	length;

	length = ft_strlen(line) - 1;
	if ((length == map->v_len) && (line[0] == '1') && (line[length - 1] == '1')
		&& (line[length] == '\n'))
		return (2);
	else if ((length == map->v_len - 1) && (line[0] == '1')
		&& (line[length] == '1'))
		return (1);
	else
		return (0);
}

int	up_line_check(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\n')
	{
		if (line[i] != '1')
		{
			return (0);
		}
		i++;
	}
	return (i);
}

int	down_line_check(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '1')
		{
			return (0);
		}
		i++;
	}
	return (i);
}

void	objects(char *str, t_map *map)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'P')
		{
			map->p_num++;
			map->pos_y = map->h_len;
			map->pos_x = i;
		}
		else if (str[i] == 'I')
			map->i_num++;
		else if (str[i] == 'E')
			map->e_num++;
		else if ((str[i] != '1') && (str[i] != '0') && (str[i] != 'E')
			&& (str[i] != 'I') && (str[i] != 'P') && (str[i] != '\n'))
			map->other++;
		i++;
	}
}

int	borders_check_bis(t_map *map, int fd, char **line)
{
	*line = get_next_line(fd);
	if (!*line)
		return (free(map), 1);
	map->v_len = up_line_check(*line);
	free(*line);
	if (!map->v_len)
	{
		free(map);
		ft_putstr_fd("Error on the borders.\n", 2);
		exit (1);
	}
	*line = get_next_line(fd);
	if (!*line)
		return (free(map), 1);
	return (0);
}
