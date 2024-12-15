/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:47:34 by nsakanou          #+#    #+#             */
/*   Updated: 2024/12/15 22:41:18 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	initialize_texinfo(t_texinfo *texinfo)
{
	texinfo->tex_north = NULL;
	texinfo->tex_south = NULL;
	texinfo->tex_west = NULL;
	texinfo->tex_east = NULL;
	texinfo->size = TEX_SIZE;
}

static int	**init_wall_texture(t_game *game, t_texinfo *texinfo, char *path)
{
	t_img	image;
	int		**texture;
	int		y;
	int		x;

	init_xpm_img(game, &image, path);
	texture = (int **)ft_calloc(sizeof(int *), texinfo->size + 1);
	if (!texture)
		free_exit(game, err_msg(ERR_MALLOC, ERROR));
	y = 0;
	while (y < game->texinfo.size)
	{
		texture[y] = (int *)ft_calloc(sizeof(int), texinfo->size + 1);
		if (!texture[y])
			free_exit(game, err_msg(ERR_MALLOC, ERROR));
		x = 0;
		while (x < game->texinfo.size)
		{
			texture[y][x] = image.addr[y * game->texinfo.size + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(game->mlx, image.img);
	return (texture);
}

void	init_texinfo(t_game *game, t_texinfo *texinfo)
{
	texinfo->tex_north = init_wall_texture(game, texinfo,
			game->mapinfo.no_path);
	texinfo->tex_south = init_wall_texture(game, texinfo,
			game->mapinfo.so_path);
	texinfo->tex_west = init_wall_texture(game, texinfo, game->mapinfo.we_path);
	texinfo->tex_east = init_wall_texture(game, texinfo, game->mapinfo.ea_path);
}
