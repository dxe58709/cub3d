/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 23:00:39 by nsakanou          #+#    #+#             */
/*   Updated: 2024/12/03 17:59:30 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	**get_wall_texture(t_game *game, t_ray *ray)
{
	(void)game;
	if (ray->side == 1)
	{
		if (ray->vec_dir_y < 0)
			return (game->texinfo.tex_north);
		else
			return (game->texinfo.tex_south);
	}
	else
	{
		if (ray->vec_dir_x < 0)
			return (game->texinfo.tex_west);
		else
			return (game->texinfo.tex_east);
	}
}

int	get_wall_color(t_game *game, int **wall_tex, t_tex_ray *tex_ray)
{
	tex_ray->y = (int)tex_ray->pos & (game->texinfo.size - 1);
	tex_ray->pos += tex_ray->step;
	return (wall_tex[tex_ray->y][tex_ray->x]);
}
