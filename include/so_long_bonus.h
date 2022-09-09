/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:24:32 by skhali            #+#    #+#             */
/*   Updated: 2022/09/09 20:51:37 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

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
# define SPEED 3000

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
	void	*player_1;
	void	*player_2;
	void	*profil_a;
	void	*profil_a_1;
	void	*profil_a_2;
	void	*profil_b;
	void	*profil_b_1;
	void	*profil_b_2;
	void	*enemy;
	void	*enemy_1;
	void	*enemy_2;
	void	*back;
	void	*back_1;
	void	*back_2;
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
	int		anim;
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
void	exit_error_handler_map(char *str, t_map *map);
void	exit_error(char *str, t_map *map);

int		image_init(t_map *map);
int		player_moves(int keycode, t_map *map);
void	free_map(t_map *map, char **tab);
int		player_stat(int keycode, t_map *map);

int		animation(t_map *map);
void	load_images(t_image *image, t_map *map);
void	destroy_images(t_image *image, t_map *map, char *str, int i);
void	display_moves(t_map *map);
int		borders_check(t_map *map, int fd);
int		cross(t_map *map);
int		check_path_map(char **tab, t_map *map);
int		check_path(char **tab, int i, int j);
int		middle_line_check(char *line, t_map *map);
void	init_map(t_map *map);
void	free_map_p2(char **tab, int j);

#endif