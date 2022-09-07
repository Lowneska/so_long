#include "../include/so_long.h"

static int    extension_check(char *str, t_map *map)
{
    int i;
    i = ft_strlen(str) - 4;
    if (ft_strncmp(str + i, ".ber", 4))
        return (simple_error_handler("Invalid file extension.\n", map));
    else
        return (0);
}

void    init_map(t_map *map)
{
    map->e_num = 0;
    map->i_num = 0;
    map->p_num = 0;
    map->h_len = 0;
    map->v_len = 0;
    map->i_collected = 0;
    map->moves = 0;
}
int map_checker(char *str, t_map *map)
{
    int fd;

    if (access(str, F_OK))
        return (simple_error_handler("File do not exist.\n", map));
    fd = open(str, O_RDONLY);
    if (!fd)
        return (simple_error_handler("Error when opening the file.\n", map));
    if (extension_check(str, map))
        return (1);
    if (borders_check(map, fd))
        return (1);
    if (map->v_len < 3 || map->h_len < 3)
        return (simple_error_handler("Error on the borders.\n", map));
    if (map->p_num != 1)
        return (simple_error_handler("Invalid number of players.\n", map));
    if (map->i_num < 1)
        return (simple_error_handler("No items.\n", map));
    if (map->e_num < 1)
        return (simple_error_handler("No exit.\n", map));
    return (0);
}

int check_path(char **tab, int i, int j)
{
    if ((tab[i][j + 1] != '1' && tab[i][j + 1] != 'X') && (tab[i][j - 1] != '1' 
        && tab[i][j - 1] != 'X') && (tab[i + 1][j] != '1' && tab[i + 1][j] != 'X') 
        && (tab[i - 1][j] != '1' && tab[i - 1][j] != 'X'))
        return (0);
    if (tab[i + 1][j] && tab[i + 1][j] != '1' && tab[i + 1][j] != 'X')
    {
        tab[i + 1][j] = 'X';
         check_path(tab, i + 1, j);
    }
    if (tab[i - 1][j] != '1' && tab[i - 1][j] != 'X')
    {
        tab[i - 1][j] = 'X';
         check_path(tab, i - 1, j);
    }
    if (tab[i][j + 1] != '1' && tab[i][j + 1] != 'X')
    {
        tab[i][j + 1] = 'X';
         check_path(tab, i, j + 1);
    }
    if (tab[i][j - 1] && tab[i][j - 1] != '1' && tab[i][j - 1] != 'X')
    {
        tab[i][j - 1] = 'X';
        check_path(tab, i, j - 1);
    }
    return 0;
}  

char **create_map(char *str, t_map *map)
{
    int fd;
    char *line;
    char **tab;
    int i;

    i = 1;
    tab = malloc(sizeof(char*)*map->h_len);
    fd = open(str, O_RDONLY);
    if (!fd)
        exit_error_handler("Error when opening the file.\n", map);
    line = get_next_line(fd);
    tab[0] = ft_strdup(line);
    free(line);
    line = get_next_line(fd);
    while (line)
    {
        tab[i] = ft_strdup(line);
        free(line);
        line = get_next_line(fd);
        i++;
    }
    return (tab);
}