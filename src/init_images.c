/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:54:21 by skhali            #+#    #+#             */
/*   Updated: 2022/09/08 23:33:36 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	destroy_images_p1(t_image *image, int i)
{
	(void)i;
	// if (i > 11)
	// 	mlx_destroy_image(image->mlx, image->wall_aright);
	// if (i > 10)
	// 	mlx_destroy_image(image->mlx, image->wall_bright);
	// if (i > 9)
	// 	mlx_destroy_image(image->mlx, image->exit);
	// if (i > 8)
	// 	mlx_destroy_image(image->mlx, image->item);
	// if (i > 7)
	// 	mlx_destroy_image(image->mlx, image->wall_right);
	// if (i > 6)
	// 	mlx_destroy_image(image->mlx, image->wall_left);
	// if (i > 5)
	// 	mlx_destroy_image(image->mlx, image->wall_up);
	// if (i > 4)
	// 	mlx_destroy_image(image->mlx, image->wall_down);
	// if (i > 3)
	// 	mlx_destroy_image(image->mlx, image->player);
	// if (i > 2)
	// 	mlx_destroy_image(image->mlx, image->ground);
	// if (i > 1)
	// 	mlx_destroy_image(image->mlx, image->wall);
	if (image->mlx)
	{
		if (image->wall_aright)
			mlx_destroy_image(image->mlx, image->wall_aright);
		if (image->wall_bright)
			mlx_destroy_image(image->mlx, image->wall_bright);
		if (image->exit)
			mlx_destroy_image(image->mlx, image->exit);
		if (image->item)
			mlx_destroy_image(image->mlx, image->item);
		if (image->wall_right)
			mlx_destroy_image(image->mlx, image->wall_right);
		if (image->wall_left)
			mlx_destroy_image(image->mlx, image->wall_left);
		if (image->wall_up)
			mlx_destroy_image(image->mlx, image->wall_up);
		if (image->wall_down)
			mlx_destroy_image(image->mlx, image->wall_down);
		if (image->player)
			mlx_destroy_image(image->mlx, image->player);
		if (image->ground)
			mlx_destroy_image(image->mlx, image->ground);
		if (image->wall)
			mlx_destroy_image(image->mlx, image->wall);
	}
}

void	destroy_images(t_image *image, t_map *map, char *str, int i)
{
	if (map)
		exit_error_handler_map(str, map);
	if (image->mlx)
	{
		mlx_destroy_window(image->mlx, image->mlx_win);
		destroy_images_p1(image, i);
		mlx_destroy_display(image->mlx);
		free(image->mlx);
		exit(0);
	}
}

static void	load_exit_item(t_image *image, t_map *map, int width, int height)
{
	image->wall_left = mlx_xpm_file_to_image(image->mlx,
			"sprites/wall_left.xpm", &width, &height);
	if (!image->wall_left)
		destroy_images(image, map, "Mauvais chargement des images.\n", 6);
	image->wall_right = mlx_xpm_file_to_image(image->mlx,
			"sprites/wall_right.xpm", &width, &height);
	if (!image->wall_right)
		destroy_images(image, map, "Mauvais chargement des images.\n", 7);
	image->item = mlx_xpm_file_to_image(image->mlx, "sprites/flower.xpm",
			&width, &height);
	if (!image->item)
		destroy_images(image, map, "Mauvais chargement des images.\n", 8);
	image->exit = mlx_xpm_file_to_image(image->mlx, "sprites/exit.xpm",
			&width, &height);
	if (!image->exit)
		destroy_images(image, map, "Mauvais chargement des images.\n", 9);
	image->wall_bright = mlx_xpm_file_to_image(image->mlx,
			"sprites/wall_b_down_right.xpm", &width, &height);
	if (!image->wall_bright)
		destroy_images(image, map, "Mauvais chargement des images.\n", 10);
	image->wall_aright = mlx_xpm_file_to_image(image->mlx,
			"sprites/wall_b_down_leftt.xpm", &width, &height);
	if (!image->wall_aright)
		destroy_images(image, map, "Mauvais chargement des images.\n", 11);
}

static void	load_base(t_image *image, t_map *map, int width, int height)
{
	image->wall = mlx_xpm_file_to_image(image->mlx, "sprites/wall.xpm",
			&width, &height);
	if (!image->wall)
		destroy_images(image, map, "Mauvais chargement des images.\n", 1);
	image->ground = mlx_xpm_file_to_image(image->mlx, "sprites/ground.xpm",
			&width, &height);
	if (!image->ground)
		destroy_images(image, map, "Mauvais chargement des images.\n", 2);
	image->player = mlx_xpm_file_to_image(image->mlx, "sprites/boy.xpm",
			&width, &height);
	if (!image->player)
		destroy_images(image, map, "Mauvais chargement des images.\n", 3);
	image->wall_down = mlx_xpm_file_to_image(image->mlx,
			"sprites/wall_down.xpm", &width, &height);
	if (!image->wall_down)
		destroy_images(image, map, "Mauvais chargement des images.\n", 4);
	image->wall_up = mlx_xpm_file_to_image(image->mlx, "sprites/wall_up.xpm",
			&width, &height);
	if (!image->wall_up)
		destroy_images(image, map, "Mauvais chargement des images.\n", 5);
}

void	load_images(t_image *image, t_map *map)
{
	int	height;
	int	width;

	height = 0;
	width = 0;
	load_exit_item(image, map, width, height);
	load_base(image, map, width, height);
}
