/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:47:34 by nsakanou          #+#    #+#             */
/*   Updated: 2024/12/16 14:51:30 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	initialize_ray(t_ray *ray)
{
	ray->camera_x = 0.0;
	ray->side = 0;
	ray->map_x = 0;
	ray->map_y = 0;
	ray->x_vec_dir = 0.0;
	ray->y_vec_dir = 0.0;
	ray->distance_x = 0.0;
	ray->distance_y = 0.0;
	ray->x_cell_dist = 0.0;
	ray->y_cell_dist = 0.0;
	ray->wall_height = 0;
	ray->wall_dist = 0.0;
	ray->wall_start_y = 0;
	ray->wall_end_y = 0;
	ray->wall_x = 0.0;
}

static int	calculate_next_x_direction(t_ray *ray, t_player *player)
{
printf("\nray->map_x: %d, player->map_x; %f,\n x_cell_dist; %f, distance_x: %.2f\n\n", ray->map_x, player->map_x, ray->x_cell_dist, ray->distance_x);
	if (ray->x_vec_dir < 0)
	{
		ray->distance_x = (player->map_x - ray->map_x)
			* ray->x_cell_dist;
		return (-1);
	}
	ray->distance_x = (ray->map_x + 1.0
			- player->map_x) * ray->x_cell_dist;

	return (1);
}

static int	calculate_next_y_direction(t_ray *ray, t_player *player)
{
	if (ray->y_vec_dir < 0)
	{
		ray->distance_y = (player->map_y - ray->map_y)
			* ray->y_cell_dist;
		return (-1);
	}
	ray->distance_y = (ray->map_y + 1.0
			- player->map_y) * ray->y_cell_dist;
	return (1);
}

void	init_ray(t_ray *ray, t_player *player, int x)
{
	initialize_ray(ray);
	ray->camera_x = 2 * x / (double)WIN_WIDTH - 1;
	ray->x_vec_dir = player->x_vec_dir + player->vec_plane_x * ray->camera_x;
	ray->y_vec_dir = player->y_vec_dir + player->vec_plane_y * ray->camera_x;
	ray->map_x = (int)player->map_x;
	ray->map_y = (int)player->map_y;
	ray->x_cell_dist = fabs(1 / ray->x_vec_dir);
	ray->y_cell_dist = fabs(1 / ray->y_vec_dir);
	ray->next_x = calculate_next_x_direction(ray, player);
	ray->next_y = calculate_next_y_direction(ray, player);
}
