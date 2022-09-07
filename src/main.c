#include "../include/so_long.h"

void    distroy_game(t_map *map)
{
    mlx_destroy_image(map->image->mlx, map->image->wall_aright);
    mlx_destroy_image(map->image->mlx, map->image->wall_bright);
    mlx_destroy_image(map->image->mlx, map->image->exit);
    mlx_destroy_image(map->image->mlx, map->image->item);
    mlx_destroy_image(map->image->mlx, map->image->wall_right);
    mlx_destroy_image(map->image->mlx, map->image->wall_left);
    mlx_destroy_image(map->image->mlx, map->image->wall_up);
    mlx_destroy_image(map->image->mlx, map->image->wall_down);
    mlx_destroy_image(map->image->mlx, map->image->player);
    mlx_destroy_image(map->image->mlx, map->image->ground);
    mlx_destroy_image(map->image->mlx, map->image->wall);
    mlx_destroy_window(map->image->mlx, map->image->mlx_win);
    mlx_destroy_display(map->image->mlx);
    free(map->image->mlx);
    free(map->image);
    free_map(map);
}

void free_map(t_map *map)
{
    int i;

    i = 0;
    while (i < map->h_len)
        free(map->tab[i++]);
    free(map->tab);
    free(map);
}

int simple_error_handler(char* str, t_map *map)
{
    free(map);
    ft_putstr_fd(str, 2);
    return (1);
}

void exit_error_handler(char* str, t_map *map)
{
    free_map(map);
    ft_putstr_fd(str, 2);
    exit (2);
}

void exit_error_handler_map(char* str, t_map *map)
{
    free(map->image);
    free_map(map);
    ft_putstr_fd(str, 2);
    exit (2);
}

int border_error_handler(char* str, char *line, t_map *map)
{
    free(map);
    free(line);
    ft_putstr_fd(str, 2);
    return (1);
}

int cross(t_map *map)
{
    distroy_game(map);
    exit(0);
    return (0);
}

int main(int argc, char** argv)
{
    t_map *map;
    char **tab;
    map = malloc(sizeof(t_map));
    int i = 0;

    init_map(map);
    if (argc != 2)
        simple_error_handler("Invalid number of arguments.\n", map);
    if (map_checker(argv[1], map))
        exit(1);
    map->tab = create_map(argv[1], map);
    tab = create_map(argv[1], map);
    while (i < map->h_len)
        printf("%s", map->tab[i++]);
    printf("\n");
    printf("x : %d  y : %d\n", map->pos_x, map->pos_y);
    check_path(tab, map->pos_y, map->pos_x);
    //vérifier si il reste des 0
    //free tab
    i = 0;
    while (i < map->h_len)
        printf("%s", map->tab[i++]);
    printf("\n");
    if(image_init(map))
        exit (1);
    mlx_hook(map->image->mlx_win, 33, 0, cross, map);
    mlx_hook(map->image->mlx_win, KeyPress, KeyPressMask, player_moves, map);
    mlx_loop(map->image->mlx);
    return (0);
}
