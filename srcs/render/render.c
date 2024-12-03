/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 23:06:31 by nsakanou          #+#    #+#             */
/*   Updated: 2024/12/03 17:57:33 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_view(t_game *game)
{
	t_img	image;
	int		y;
	int		x;

	init_img(game, &image, game->win_width, game->win_height);
	y = 0;
	while (y < game->win_height)
	{
		x = 0;
		while (x < game->win_width)
		{
			image.addr[y * (image.size_line / 4) + x] = game->view_pixels[y][x];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->mlx, game->win, image.img, 0, 0);
	mlx_destroy_image(game->mlx, image.img);
}

void	render_raycasting(t_game *game)
{
	init_view_pixels(game);
	raycasting(game);
	render_view(game);
}

int	render(t_game *game)
{
	render_raycasting(game);
	return (0);
}
