#include "../include/so_long.h"

static int middle_line_check(char *line, t_map *map)
{
    int length;
    length = 0;

    length = ft_strlen(line) - 1;
    if ((length == map->v_len) && (line[0] == '1') && (line[length - 1] == '1') && (line[length] == '\n'))
        return (2);
    else if ((length == map->v_len - 1) && (line[0] == '1') && (line[length] == '1'))
        return (1);
    else
        return (0);
}
static int up_line_check(char *line)
{
    int i;
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
static int down_line_check(char *line)
{
    int i;
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

static void objects(char *str, t_map *map)
{
    int i;
    i = 0;

    while(str[i])
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
        i++;
    }
}
int   borders_check(t_map *map, int fd)
{
    char *line;
    int status;

    line = get_next_line(fd);
    map->v_len = up_line_check(line);
    free(line);
    if (!map->v_len)
        exit_error_handler("Error on the borders.\n",map);
    line = get_next_line(fd);
    while (line)
    {
        map->h_len += 1;
        status = middle_line_check(line, map);
        if (!status)
            return (border_error_handler("Error on the borders.\n", line, map));
        objects(line, map);
        if (status == 1)
            break;
        free(line);
        line = get_next_line(fd);
    }
    if (down_line_check(line) != map->v_len)
        return (border_error_handler("Error on the borders.\n", line, map));
    map->h_len += 1;
    free(line);
    return (0);
}