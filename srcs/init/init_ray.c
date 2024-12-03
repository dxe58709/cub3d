/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:47:34 by nsakanou          #+#    #+#             */
/*   Updated: 2024/12/03 17:54:35 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 *
 */
static void	init_ray_dda(t_ray *ray, t_player *player)
{
	if (ray->vec_dir_x < 0)
	{
		ray->step_x = -1;
		ray->sidedist_x = (player->map_x - ray->map_x) * ray->deltadist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->sidedist_x = (ray->map_x + 1.0 - player->map_x) * ray->deltadist_x;
	}
	if (ray->vec_dir_y < 0)
	{
		ray->step_y = -1;
		ray->sidedist_y = (player->map_y - ray->map_y) * ray->deltadist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->sidedist_y = (ray->map_y + 1.0 - player->map_y) * ray->deltadist_y;
	}
}

/**
 * 
 */
void	init_ray(t_ray *ray, t_player *player, int x)
{
	initialize_ray(ray);
	ray->camera_x = 2 * x / (double)WIN_WIDTH - 1;
	ray->vec_dir_x = player->vec_dir_x + player->vec_plane_x * ray->camera_x;
	ray->vec_dir_y = player->vec_dir_y + player->vec_plane_y * ray->camera_x;
	ray->map_x = (int)player->map_x;
	ray->map_y = (int)player->map_y;
	ray->deltadist_x = fabs(1 / ray->vec_dir_x);
	ray->deltadist_y = fabs(1 / ray->vec_dir_y);
	init_ray_dda(ray, player);
}

/**
 * 
 */
void	initialize_ray(t_ray *ray)
{
	ray->camera_x = 0.0;
	ray->side = 0;
	ray->map_x = 0;
	ray->map_y = 0;
	ray->vec_dir_x = 0.0;
	ray->vec_dir_y = 0.0;
	ray->sidedist_x = 0.0;
	ray->sidedist_y = 0.0;
	ray->deltadist_x = 0.0;
	ray->deltadist_y = 0.0;
	ray->wall_height = 0;
	ray->wall_dist = 0.0;
	ray->wall_start_y = 0;
	ray->wall_end_y = 0;
	ray->wall_x = 0.0;
}
