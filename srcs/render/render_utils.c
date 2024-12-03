/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 23:06:31 by nsakanou          #+#    #+#             */
/*   Updated: 2024/12/03 17:57:50 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_hit_wall(t_game *game, t_ray *ray)
{
	char	**map;

	map = game->mapinfo.map;
	if (ray->map_x < 0 || ray->map_x >= game->mapinfo.map_width
		|| ray->map_y < 0 || ray->map_y >= game->mapinfo.map_height)
		return (false);
	if (map[ray->map_y][ray->map_x] == WALL_C)
		return (true);
	return (false);
}
