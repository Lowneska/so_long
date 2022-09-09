/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 18:02:00 by skhali            #+#    #+#             */
/*   Updated: 2022/09/09 18:46:29 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	extension_check(char *str, t_map *map)
{
	int	i;

	i = ft_strlen(str) - 4;
	if (ft_strncmp(str + i, ".ber", 4) || (!ft_strncmp(str + i, "/.ber", 5)))
		return (simple_error_handler("Invalid file extension.\n", map));
	else
		return (0);
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
}

int	map_checker(char *str, t_map *map)
{
	int	fd;

	if (access(str, F_OK))
		return (simple_error_handler("File do not exist.\n", map));
	fd = open(str, O_RDONLY);
	if (!fd)
		return (simple_error_handler("Error when opening the file.\n", map));
	if (extension_check(str, map))
		return (close(fd), 1);
	if (borders_check(map, fd))
		return (close(fd), 1);
	if (map->v_len < 3 || map->h_len < 3)
		return (simple_error_handler("Not rectangular.\n", map));
	if (map->p_num != 1)
		return (simple_error_handler("Invalid number of players.\n", map));
	if (map->other > 0)
		return (simple_error_handler("Invalid object on map.\n", map));
	if (map->i_num < 1)
		return (simple_error_handler("No items.\n", map));
	if (map->e_num != 1)
		return (simple_error_handler("No exit.\n", map));
	return (0);
}
void	free_map_p2(char **tab, int j)
{
	int	i;

	i = 0;
	while (i <= j)
		free(tab[i++]);
	free(tab);
}
char **create_map_p2(int *fd, char *str, t_map *map, char **line)
{
	char	**tab;
	
	tab = malloc(sizeof (char *) * map->h_len);
	if (!tab)
		simple_exit_error_handler("Malloc error.\n", map);
	*fd = open(str, O_RDONLY);
	if (*fd < 0)
	{
		free(tab);
		simple_exit_error_handler("Error while opening the file.\n", map);
	}
	*line = get_next_line(*fd);
	return (tab);
}

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
