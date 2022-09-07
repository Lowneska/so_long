#include "../include/so_long_bonus.h"

static void load_exit_item(t_image *image, t_map *map, int width, int height)
{
    image->item= mlx_xpm_file_to_image(image->mlx, "sprites/flower.xpm", &width, &height);
    if (!image->item)
        destroy_images(image, map, "Mauvais chargement des images.\n", 8);
    image->exit= mlx_xpm_file_to_image(image->mlx, "sprites/exit.xpm", &width, &height);
    if (!image->exit)
        destroy_images(image, map, "Mauvais chargement des images.\n", 9);
}
static void load_base(t_image *image, t_map *map, int width, int height)
{
    image->wall = mlx_xpm_file_to_image(image->mlx, "sprites/wall.xpm", &width, &height);
    if (!image->wall)
        destroy_images(image, map, "Mauvais chargement des images.\n", 1);
    image->ground = mlx_xpm_file_to_image(image->mlx, "sprites/ground.xpm", &width, &height);
    if (!image->ground)
        destroy_images(image, map, "Mauvais chargement des images.\n", 2);
    image->player = mlx_xpm_file_to_image(image->mlx, "sprites/boy.xpm", &width, &height);
    if (!image->player)
        destroy_images(image, map, "Mauvais chargement des images.\n", 3);
    image->wall_down= mlx_xpm_file_to_image(image->mlx, "sprites/wall_down.xpm", &width, &height);
    if (!image->wall_down)
        destroy_images(image, map, "Mauvais chargement des images.\n", 4);
    image->wall_up= mlx_xpm_file_to_image(image->mlx, "sprites/wall_up.xpm", &width, &height);
    if (!image->wall_up)
        destroy_images(image, map, "Mauvais chargement des images.\n", 5);
    image->wall_left= mlx_xpm_file_to_image(image->mlx, "sprites/wall_left.xpm", &width, &height);
    if (!image->wall_left)
        destroy_images(image, map, "Mauvais chargement des images.\n", 6);
    image->wall_right= mlx_xpm_file_to_image(image->mlx, "sprites/wall_right.xpm", &width, &height);
    if (!image->wall_right)
        destroy_images(image, map, "Mauvais chargement des images.\n", 7);
}

static void load_wall_face(t_image *image, t_map *map, int width, int height)
{
    image->wall_bright= mlx_xpm_file_to_image(image->mlx, "sprites/wall_b_down_right.xpm", &width, &height);
    if (!image->wall_bright)
        destroy_images(image, map, "Mauvais chargement des images.\n", 10);
    image->wall_aright= mlx_xpm_file_to_image(image->mlx, "sprites/wall_b_down_leftt.xpm", &width, &height);
    if (!image->wall_aright)
        destroy_images(image, map, "Mauvais chargement des images.\n", 11);
    image->player_1= mlx_xpm_file_to_image(image->mlx, "sprites/player_1.xpm", &width, &height);
    if (!image->player_1)
        destroy_images(image, map, "Mauvais chargement des images.\n", 12);
    image->player_2= mlx_xpm_file_to_image(image->mlx, "sprites/player_2.xpm", &width, &height);
    if (!image->player_2)
        destroy_images(image, map, "Mauvais chargement des images.\n", 13);
}
static void load_profil_a_b(t_image *image, t_map *map, int width, int height)
{
    image->profil_a= mlx_xpm_file_to_image(image->mlx, "sprites/profil_a.xpm", &width, &height);
    if (!image->profil_a)
        destroy_images(image, map, "Mauvais chargement des images.\n", 14);
    image->profil_a_1= mlx_xpm_file_to_image(image->mlx, "sprites/profil_a_1.xpm", &width, &height);
    if (!image->profil_a_1)
        destroy_images(image, map, "Mauvais chargement des images.\n", 15);
    image->profil_a_2 = mlx_xpm_file_to_image(image->mlx, "sprites/profil_a_2.xpm", &width, &height);
    if (!image->profil_a_2)
        destroy_images(image, map, "Mauvais chargement des images.\n", 16);
    image->profil_b= mlx_xpm_file_to_image(image->mlx, "sprites/profil_b.xpm", &width, &height);
    if (!image->profil_b)
        destroy_images(image, map, "Mauvais chargement des images.\n", 17);
    image->profil_b_1= mlx_xpm_file_to_image(image->mlx, "sprites/profil_b_1.xpm", &width, &height);
    if (!image->profil_b_1)
        destroy_images(image, map, "Mauvais chargement des images.\n", 18);
    image->profil_b_2 = mlx_xpm_file_to_image(image->mlx, "sprites/profil_b_2.xpm", &width, &height);
    if (!image->profil_b_2)
        destroy_images(image, map, "Mauvais chargement des images.\n", 19);
}
void load_images(t_image *image, t_map *map)
{
    int height;
    int width;

    load_exit_item(image, map, width, height);
    load_base(image, map, width, height);
    load_wall_face(image, map, width, height);
    load_profil_a_b(image, map, width, height);
    image->back = mlx_xpm_file_to_image(image->mlx, "sprites/back.xpm", &width, &height);
    if (!image->back)
        destroy_images(image, map, "Mauvais chargement des images.\n", 20);
    image->back_1 = mlx_xpm_file_to_image(image->mlx, "sprites/back_1.xpm", &width, &height);
    if (!image->back_1)
        destroy_images(image, map, "Mauvais chargement des images.\n", 21);
    image->back_2 = mlx_xpm_file_to_image(image->mlx, "sprites/back_2.xpm", &width, &height);
    if (!image->back_2)
        destroy_images(image, map, "Mauvais chargement des images.\n", 22);
}
