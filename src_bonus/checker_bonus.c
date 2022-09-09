/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 21:54:57 by skhali            #+#    #+#             */
/*   Updated: 2022/09/09 17:52:58 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

static int	middle_line_check(char *line, t_map *map)
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

static int	up_line_check(char *line)
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

static int	down_line_check(char *line)
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

static void	objects(char *str, t_map *map)
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
