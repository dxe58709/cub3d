/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 23:00:39 by nsakanou          #+#    #+#             */
/*   Updated: 2024/12/15 22:52:17 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_ceiling_color(t_game *game)
{
	int	color;

	color = game->mapinfo.ceiling_rgb[0] * 256 * 256
		+ game->mapinfo.ceiling_rgb[1] * 256 + game->mapinfo.ceiling_rgb[2];
	return (color);
}

int	get_floor_color(t_game *game)
{
	int	color;

	color = game->mapinfo.floor_rgb[0] * 256 * 256 + game->mapinfo.floor_rgb[1]
		* 256 + game->mapinfo.floor_rgb[2];
	return (color);
}
