/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:47:34 by nsakanou          #+#    #+#             */
/*   Updated: 2024/12/15 22:35:44 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	initialize_player(t_player *player)
{
	player->direction = '\0';
	player->map_x = 0.0;
	player->map_y = 0.0;
	player->x_vec_dir = 0.0;
	player->y_vec_dir = 0.0;
	player->vec_plane_x = 0.0;
	player->vec_plane_y = 0.0;
}

static void	init_player_vec_ns(t_player *player)
{
	if (player->direction == 'N')
	{
		player->x_vec_dir = 0;
		player->y_vec_dir = -1;
		player->vec_plane_x = FOV;
		player->vec_plane_y = 0;
	}
	if (player->direction == 'S')
	{
		player->x_vec_dir = 0;
		player->y_vec_dir = 1;
		player->vec_plane_x = -FOV;
		player->vec_plane_y = 0;
	}
}

static void	init_player_vec_ew(t_player *player)
{
	if (player->direction == 'E')
	{
		player->x_vec_dir = 1;
		player->y_vec_dir = 0;
		player->vec_plane_x = 0;
		player->vec_plane_y = FOV;
	}
	if (player->direction == 'W')
	{
		player->x_vec_dir = -1;
		player->y_vec_dir = 0;
		player->vec_plane_x = 0;
		player->vec_plane_y = -FOV;
	}
}

void	init_player_vec(t_player *player)
{
	init_player_vec_ns(player);
	init_player_vec_ew(player);
}
