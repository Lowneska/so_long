#include "../include/so_long_bonus.h"

void    display_moves(t_map *map)
{
    char    *moves;
    moves = NULL;
    moves = ft_itoa(map->moves);
    mlx_string_put(map->image->mlx, map->image->mlx_win, map->h_len * 64 - 10, map->h_len * 64 - 20, 0xFFFFFF, "moves :");
    mlx_string_put(map->image->mlx, map->image->mlx_win, map->h_len * 64, map->h_len * 64, 0xFFFFFF, moves);
	free(moves);
}

int check_case(int i, int j, t_map *map)
{
    if (map->tab[i][j] == '1')
        return 0;;
    if (map->tab[i][j] == 'E' && map->i_collected != map->i_num)
        return (0);
    return (1);
}
void    put_vue(int vue, t_map *map, int a, int b)
{
    if (vue == 1)
        mlx_put_image_to_window(map->image->mlx, map->image->mlx_win, map->image->back, b, a);
    if (vue == 2)
        mlx_put_image_to_window(map->image->mlx, map->image->mlx_win, map->image->player, b, a);
    if (vue == 3)
        mlx_put_image_to_window(map->image->mlx, map->image->mlx_win, map->image->profil_b, b, a);
    if (vue == 4)
        mlx_put_image_to_window(map->image->mlx, map->image->mlx_win, map->image->profil_a, b, a);
}
int case_action(int i, int j, t_map *map, int vue)
{
    int a;
    int b;

    a = i * 64;
    b = j * 64;
    (void)vue;
    if (map->tab[i][j] == 'I')
        map->i_collected++;
    if (map->tab[i][j] == 'E' && map->i_collected == map->i_num)
        return (2);
    map->tab[i][j] = 'P';
    map->tab[map->pos_y][map->pos_x] = '0';
    put_vue(vue, map, a, b);
    mlx_put_image_to_window(map->image->mlx, map->image->mlx_win, map->image->ground, map->pos_x * 64, map->pos_y * 64);
    map->pos_x = j;
    map->pos_y = i;
    map->moves++;
    return (1);
}

int player_moves(int keycode, t_map *map)
{
    int status;

    status = 0;
    if (keycode == UP)
        if (check_case(map->pos_y - 1, map->pos_x, map))
            status = case_action(map->pos_y - 1, map->pos_x, map, 1);
    if (keycode == DOWN)
        if (check_case(map->pos_y + 1, map->pos_x, map))
            status = case_action(map->pos_y + 1, map->pos_x, map, 2);
    if (keycode == LEFT)
        if (check_case(map->pos_y, map->pos_x - 1, map))
            status = case_action(map->pos_y, map->pos_x - 1, map, 3);
    if (keycode == RIGHT)
        if (check_case(map->pos_y, map->pos_x + 1, map))
            status = case_action(map->pos_y, map->pos_x + 1, map, 4);
    if (keycode == ESC || status == 2 )
    {
        destroy_images(map->image,map, "", 23);
        exit(0);
    }
    mlx_put_image_to_window(map->image->mlx, map->image->mlx_win, map->image->wall_down, map->h_len* 64, (map->h_len - 1) * 64);
    display_moves(map);
    return (0);
}
