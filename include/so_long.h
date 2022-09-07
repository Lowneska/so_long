#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
#include "../libft/includes/libft.h"
#include "../libft/includes/get_next_line.h"
#include "../mlx_linux/mlx.h"
# include "/usr/include/X11/X.h"

# define UP 122
# define DOWN 115
# define LEFT 113
# define RIGHT 100
# define ESC 65307

typedef struct	s_image{
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
	int pos_x;
	int pos_y;
	int	v_len;
	int	h_len;
	int p_num;
	int i_num;
	int i_collected;
	int e_num;
	int moves;
	char	**tab;
	t_image	*image;
}				t_map;



//Gestion des erreurs
void    distroy_game(t_map *map);
int simple_error_handler(char* str, t_map *map);
int border_error_handler(char* str, char *line, t_map *map);
void exit_error_handler_map(char* str, t_map *map);

//Vérification de la structure de la map
int map_checker(char *str, t_map *map);
void    init_map(t_map *map);
char **create_map(char *str, t_map *map);
void exit_error_handler(char* str, t_map *map);
void exit_error(char* str, t_map *map);

int image_init(t_map* map);
int player_moves(int keycode, t_map *map);
void free_map(t_map *map);
void    display_moves(t_map *map);

void load_images(t_image *image, t_map *map);
void    destroy_images(t_image *image, t_map *map, char *str, int i);
int   borders_check(t_map *map, int fd);
int	check_path(char **tab, int i, int j);
#endif