#include "../include/so_long.h"

static void     put_walls(int j, int i, int a, int b, t_image *image, t_map *map)
{
    if ((j == 0))
        mlx_put_image_to_window(image->mlx, image->mlx_win, image->wall_up, a, b);
    else if (( i != 0) && (i != (map->v_len - 1)) && (j == (map->h_len - 1)))
        mlx_put_image_to_window(image->mlx, image->mlx_win, image->wall_down, a, b);
    else if ((i == 0) && (j != 0) && (j != (map->h_len - 1)))
        mlx_put_image_to_window(image->mlx, image->mlx_win, image->wall_left, a, b);
    else if ((i == (map->v_len - 1)) && (j != (map->h_len - 1)))
        mlx_put_image_to_window(image->mlx, image->mlx_win, image->wall_right, a, b);
    else if (((i == 0) && (j == (map->h_len - 1))))
        mlx_put_image_to_window(image->mlx, image->mlx_win, image->wall_aright, a, b);
    else if ((i == (map->v_len - 1)) && (j == (map->h_len - 1)))
        mlx_put_image_to_window(image->mlx, image->mlx_win, image->wall_bright, a, b);
    else
        mlx_put_image_to_window(image->mlx, image->mlx_win, image->wall, a, b);
}
static void    put_images(t_image *image, t_map *map)
{
    int i;
    int j;
    int a;
    int b;

    i = 0;
    while (i < (map->v_len))
    {
        a = i * 64;
        j = 0;
        while (j < (map->h_len))
        {
            b = j * 64;
            if (map->tab[j][i] == '1')
                put_walls(j, i, a, b, image, map);
		    else if (map->tab[j][i] == '0')
			    mlx_put_image_to_window(image->mlx, image->mlx_win, image->ground, a, b);
            else if (map->tab[j][i] == 'I')
                mlx_put_image_to_window(image->mlx, image->mlx_win, image->item, a, b);
            else if (map->tab[j][i] == 'E')
                mlx_put_image_to_window(image->mlx, image->mlx_win, image->exit, a, b);
            else
                mlx_put_image_to_window(image->mlx, image->mlx_win, image->player, a, b);
            j++;
        }
        i++;
    }
}

int image_init(t_map* map)
{
    t_image *image;

    image = malloc(sizeof(t_image));
    map->image = image;
	image->mlx = mlx_init();
    if(!image->mlx)
        return (simple_error_handler("Error in the initialisation of the mlx.\n", map));
    image->mlx_win = mlx_new_window(image->mlx, map->v_len * 64, map->h_len *64, " So_long ");
    if(!image->mlx_win)
    {
        mlx_destroy_display(image->mlx);
        return(simple_error_handler("Error in the creation of the window.\n", map));
    }
    load_images(image, map);
    put_images(image, map);
    return (0);
}