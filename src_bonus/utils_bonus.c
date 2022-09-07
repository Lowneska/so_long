#include "../include/so_long_bonus.h"

int player_stat(int keycode, t_map *map)
{
    if (keycode == UP)
        {
            mlx_put_image_to_window(map->image->mlx, map->image->mlx_win, map->image->back, map->pos_x * 64, map->pos_y * 64);
            map->anim =1;
        }
    if (keycode == DOWN)
        {
            mlx_put_image_to_window(map->image->mlx, map->image->mlx_win, map->image->player, map->pos_x * 64, map->pos_y * 64);
            map->anim = 2;
        }
    if (keycode == LEFT)
    {
            mlx_put_image_to_window(map->image->mlx, map->image->mlx_win, map->image->profil_b, map->pos_x * 64, map->pos_y * 64);
            map->anim = 3;
    }
    if (keycode == RIGHT)
    {
            mlx_put_image_to_window(map->image->mlx, map->image->mlx_win, map->image->profil_a, map->pos_x * 64, map->pos_y * 64);
            map->anim = 4;
    }
    return (0);
}

int cross(t_map *map)
{
    destroy_images(map->image, map, "", 23);
    exit(0);
    return (0);
}
