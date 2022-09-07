#include "../include/so_long_bonus.h"

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

void exit_error_handler_map(char* str, t_map *map)
{
    free_map(map);
    ft_putstr_fd(str, 2);
    exit (2);
}

void exit_error(char* str, t_map *map)
{
    free(map);
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