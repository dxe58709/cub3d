/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 23:06:31 by nsakanou          #+#    #+#             */
/*   Updated: 2024/12/16 17:40:10 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	calculate_wall(t_ray *ray, t_game *game, t_player *player)
{
	if (ray->side == 0)
		ray->wall_dist = (ray->distance_x - ray->x_cell_dist);
	else
		ray->wall_dist = (ray->distance_y - ray->y_cell_dist);
	ray->wall_height = (int)(game->win_height / ray->wall_dist);
	ray->wall_start_y = -(ray->wall_height) / 2 + game->win_height / 2;
	if (ray->wall_start_y < 0)
		ray->wall_start_y = 0;
	ray->wall_end_y = ray->wall_height / 2 + game->win_height / 2;
	if (ray->wall_end_y >= game->win_height)
		ray->wall_end_y = game->win_height - 1;
	if (ray->side == 0)
		ray->wall_x = player->map_y + ray->wall_dist * ray->y_vec_dir;
	else
		ray->wall_x = player->map_x + ray->wall_dist * ray->x_vec_dir;
	ray->wall_x -= floor(ray->wall_x);
}

static bool	is_hit_wall(t_game *game, t_ray *ray)
{
	char	**map;

	map = game->mapinfo.map;
	if (ray->map_x < 0 || ray->map_x >= game->mapinfo.map_width
		|| ray->map_y < 0 || ray->map_y >= game->mapinfo.map_height)
		return (false);
	if (map[ray->map_y][ray->map_x] == '1')
	{
		printf("map[%d][%d] = %c\n", ray->map_y, ray->map_x, map[ray->map_y][ray->map_x]);
		return (true);
	}
	return (false);
}

/**
 * Use ray to texture vertical axis.
 */
static void	set_ray_pixels(t_game *game, t_ray *ray, int x)
{
	t_tex_ray	tex_ray;
	int			y;
	int			**wall_tex;

	y = -1;
	wall_tex = get_wall_texture(game, ray);
	init_tex_ray(game, ray, &tex_ray);
	while (++y < game->win_height)
	{
		if (y < ray->wall_start_y)
			game->view_pixels[y][x] = get_ceiling_color(game);
		else if (y > ray->wall_end_y)
			game->view_pixels[y][x] = get_floor_color(game);
		else
			game->view_pixels[y][x] = get_wall_color(game, wall_tex, &tex_ray);
	}
}

/**
 * DDA algorithm.
 * Get distance to wall.
 * ray.sideist_yx Distance to the wall
 * ray.side Which wall in the x or y axis was hit If side=0,
	the wall in the x axis
 */

static void	run_dda(t_game *game, t_ray *ray)
{
	int	tmp;

	while (1)
	{
		if (ray->distance_x < ray->distance_y)
		{
			tmp = ray->map_x + ray->next_x;
			if (tmp < 0 || tmp >= game->mapinfo.map_width)
				return ;
			ray->distance_x += ray->x_cell_dist;
			ray->map_x += ray->next_x;
			ray->side = 0;
		}
		else
		{
			tmp = ray->map_y + ray->next_y;
			if (tmp < 0 || tmp >= game->mapinfo.map_height)
				return ;
			ray->distance_y += ray->y_cell_dist;
			ray->map_y += ray->next_y;
			ray->side = 1;
		}
		if (is_hit_wall(game, ray))
			break ;
	}
}

void	raycasting(t_game *game)
{
	t_ray	ray;
	int		x;

	x = 0;
	while (x < game->win_width)
	{
		init_ray(&ray, &game->player, x);
		run_dda(game, &ray);
		calculate_wall(&ray, game, &game->player);
		set_ray_pixels(game, &ray, x);
		x++;
	}
}
