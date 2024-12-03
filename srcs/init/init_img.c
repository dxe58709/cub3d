/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:47:34 by nsakanou          #+#    #+#             */
/*   Updated: 2024/12/03 17:54:17 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * Get MLX pixel image data into the t_img structure
 * Editing is possible in units of one pixel by rewriting
 * addr as well as t_img image data.
 */
void	init_img(t_game *game, t_img *image, int width, int height)
{
	initialize_img(image);
	image->img = mlx_new_image(game->mlx, width, height);
	if (image->img == NULL)
		free_exit(game, err_msg("mlx_new_image() error.", ERROR));
	image->addr = (int *)mlx_get_data_addr(image->img, &image->pixel_bits,
			&image->size_line, &image->endian);
	if (image->addr == NULL)
		free_exit(game, err_msg("mlx_get_data_addr() error.", ERROR));
}

/**
 * Get MLX XPM data into the t_img structure
 * Editing is possible in units of one pixel by rewriting
 * addr as well as t_img image data.
 */
void	init_xpm_img(t_game *game, t_img *image, char *path)
{
	initialize_img(image);
	image->img = mlx_xpm_file_to_image(game->mlx, path, &game->texinfo.size,
			&game->texinfo.size);
	if (image->img == NULL)
		free_exit(game, err_msg("mlx_xpm_file_to_image() error.", ERROR));
	image->addr = (int *)mlx_get_data_addr(image->img, &image->pixel_bits,
			&image->size_line, &image->endian);
	if (image->addr == NULL)
		free_exit(game, err_msg("mlx_get_data_addr() error.", ERROR));
}

void	initialize_img(t_img *image)
{
	image->img = NULL;
	image->addr = NULL;
	image->pixel_bits = 0;
	image->size_line = 0;
	image->endian = 0;
}
