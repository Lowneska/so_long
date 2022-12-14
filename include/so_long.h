/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:24:46 by skhali            #+#    #+#             */
/*   Updated: 2022/09/09 20:39:22 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../libft/gnl/get_next_line.h"
# include "../mlx_linux/mlx.h"
# include "/usr/include/X11/X.h"

# define UP 119
# define DOWN 115
# define LEFT 97
# define RIGHT 100
# define ESC 65307

typedef struct s_image{
	void	*mlx;
	void	*mlx_win;
	void	*wall;
	void	*wall_up;
	void	*wall_down;
	void	*wall_left;
	void	*wall_right;
	void	*wall_aright;
	void	*wall_bright;
	void	*ground;
	void	*player;
	void	*exit;
	void	*item;
}				t_image;

typedef struct s_map
{
	int		pos_x;
	int		pos_y;
	int		v_len;
	int		h_len;
	int		p_num;
	int		i_num;
	int		i_collected;
	int		e_num;
	int		moves;
	int		other;
	char	**tab;
	t_image	*image;
}				t_map;

//Gestion des erreurs
int		simple_error_handler(char *str, t_map *map);
int		border_error_handler(char *str, char *line, t_map *map);
void	exit_error_handler_map(char *str, t_map *map);
void	exit_error_handler(char *str, t_map *map);
void	simple_exit_error_handler(char *str, t_map *map);

//Vérification de la structure de la map
int		map_checker(char *str, t_map *map);
void	init_map(t_map *map);
char	**create_map(char *str, t_map *map);
void	exit_error(char *str, t_map *map);

int		image_init(t_map *map);
int		player_moves(int keycode, t_map *map);
void	free_map(t_map *map, char **tab);
void	display_moves(t_map *map);

void	load_images(t_image *image, t_map *map);
void	destroy_images(t_image *image, t_map *map, char *str);
int		borders_check(t_map *map, int fd);
int		check_path_map(char **tab, t_map *map);
int		check_path(char **tab, int i, int j);
void	print(char *str, int i);
char	**create_map_p2(int *fd, char *str, t_map *map, char **line);
void	free_map_p2(char **tab, int j);
int		borders_check_bis(t_map *map, int fd, char **line);
void	objects(char *str, t_map *map);
int		down_line_check(char *line);
int		up_line_check(char *line);
int		middle_line_check(char *line, t_map *map);

#endif