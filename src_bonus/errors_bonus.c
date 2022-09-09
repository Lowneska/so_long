/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 22:01:10 by skhali            #+#    #+#             */
/*   Updated: 2022/09/09 21:08:20 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

static void	destroy_images_p2(t_image *image, int i)
{
	if (i > 22)
		mlx_destroy_image(image->mlx, image->back_2);
	if (i > 21)
		mlx_destroy_image(image->mlx, image->back_1);
	if (i > 20)
		mlx_destroy_image(image->mlx, image->back);
	if (i > 19)
		mlx_destroy_image(image->mlx, image->profil_b_2);
	if (i > 18)
		mlx_destroy_image(image->mlx, image->profil_b_1);
	if (i > 17)
		mlx_destroy_image(image->mlx, image->profil_b);
	if (i > 16)
		mlx_destroy_image(image->mlx, image->profil_a_2);
	if (i > 15)
		mlx_destroy_image(image->mlx, image->profil_a_1);
	if (i > 14)
		mlx_destroy_image(image->mlx, image->profil_a);
	if (i > 13)
		mlx_destroy_image(image->mlx, image->player_2);
	if (i > 12)
		mlx_destroy_image(image->mlx, image->player_1);
}

static void	destroy_images_p1(t_image *image, int i)
{
	if (i > 11)
		mlx_destroy_image(image->mlx, image->wall_aright);
	if (i > 10)
		mlx_destroy_image(image->mlx, image->wall_bright);
	if (i > 9)
		mlx_destroy_image(image->mlx, image->exit);
	if (i > 8)
		mlx_destroy_image(image->mlx, image->item);
	if (i > 7)
		mlx_destroy_image(image->mlx, image->wall_right);
	if (i > 6)
		mlx_destroy_image(image->mlx, image->wall_left);
	if (i > 5)
		mlx_destroy_image(image->mlx, image->wall_up);
	if (i > 4)
		mlx_destroy_image(image->mlx, image->wall_down);
	if (i > 3)
		mlx_destroy_image(image->mlx, image->player);
	if (i > 2)
		mlx_destroy_image(image->mlx, image->ground);
	if (i > 1)
		mlx_destroy_image(image->mlx, image->wall);
}

void	destroy_images(t_image *image, t_map *map, char *str, int i)
{
	destroy_images_p1(image, i);
	destroy_images_p2(image, i);
	mlx_destroy_window(image->mlx, image->mlx_win);
	mlx_destroy_display(image->mlx);
	free(image->mlx);
	exit_error_handler_map(str, map);
}
