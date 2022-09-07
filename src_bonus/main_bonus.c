#include "../include/so_long_bonus.h"

int main(int argc, char** argv)
{
    t_map *map;
    map = malloc(sizeof(t_map));
    int i = 0;

    init_map(map);
    if (argc != 2)
        simple_error_handler("Invalid number of arguments.\n", map);
    if (map_checker(argv[1], map))
        exit(1);
    map->tab = create_map(argv[1], map);
    while (i < map->h_len)
        printf("%s", map->tab[i++]);
    printf("\n");
    if(image_init(map))
        exit (1);
    mlx_loop_hook(map->image->mlx, animation, map);
    mlx_hook(map->image->mlx_win, 33, 0, cross, map);
    mlx_hook(map->image->mlx_win, 3, (1L << 1), player_stat, map);
    mlx_hook(map->image->mlx_win, KeyPress, KeyPressMask, player_moves, map);
    mlx_loop(map->image->mlx);
    return (0);
}
