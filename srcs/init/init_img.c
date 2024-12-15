/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:47:34 by nsakanou          #+#    #+#             */
/*   Updated: 2024/12/15 22:48:56 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	initialize_img(t_img *image)
{
	image->img = NULL;
	image->addr = NULL;
	image->bits_par_pixel = 0;
	image->bytes_line = 0;
	image->endian = 0;
}

void	init_img(t_game *game, t_img *image, int width, int height)
{
	initialize_img(image);
	image->img = mlx_new_image(game->mlx, width, height);
	if (image->img == NULL)
		free_exit(game, err_msg("Failed to create image", ERROR));
	image->addr = (int *)mlx_get_data_addr(image->img, &image->bits_par_pixel,
			&image->bytes_line, &image->endian);
	if (image->addr == NULL)
		free_exit(game, err_msg("Failed to addr data", ERROR));
}

void	init_xpm_img(t_game *game, t_img *image, char *path)
{
	initialize_img(image);
	image->img = mlx_xpm_file_to_image(game->mlx, path, &game->texinfo.size,
			&game->texinfo.size);
	if (image->img == NULL)
		free_exit(game, err_msg("Unable to load images", ERROR));
	image->addr = (int *)mlx_get_data_addr(image->img, &image->bits_par_pixel,
			&image->bytes_line, &image->endian);
	if (image->addr == NULL)
		free_exit(game, err_msg("Failed to addr data", ERROR));
}
