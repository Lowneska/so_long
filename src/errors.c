/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 19:49:17 by skhali            #+#    #+#             */
/*   Updated: 2022/09/08 03:52:15 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_map(t_map *map, char **tab)
{
	int	i;

	i = 0;
	while (i < map->h_len)
		free(tab[i++]);
	free(tab);
}

int	simple_error_handler(char *str, t_map *map)
{
	free(map);
	ft_putstr_fd(str, 2);
	return (1);
}

void	exit_error_handler(char *str, t_map *map)
{
	free_map(map, map->tab);
	free(map);
	ft_putstr_fd(str, 2);
	exit (2);
}

void	exit_error_handler_map(char *str, t_map *map)
{
	free(map->image);
	free_map(map, map->tab);
	free(map);
	ft_putstr_fd(str, 2);
	exit (2);
}

int	border_error_handler(char *str, char *line, t_map *map)
{
	free(map);
	free(line);
	line = NULL;
	ft_putstr_fd(str, 2);
	return (1);
}
