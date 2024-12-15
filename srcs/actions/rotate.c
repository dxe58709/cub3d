/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:44:23 by nsakanou          #+#    #+#             */
/*   Updated: 2024/12/15 20:11:04 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * Rotate viewpoint.
 * https://ja.wikipedia.org/wiki/%E5%9B%9E%E8%BB%A2%E8%A1%8C%E5%88%97
 * newX = x * cos(θ) - y * sin(θ)
 * newY = y * sin(θ) + y * cos(θ)
 */
static void	rotate(t_player *player, double rotspeed)
{
	double	tmp_x;

	tmp_x = player->x_vec_dir;
	player->x_vec_dir = player->x_vec_dir * cos(rotspeed) - player->y_vec_dir
		* sin(rotspeed);
	player->y_vec_dir = tmp_x * sin(rotspeed) + player->y_vec_dir
		* cos(rotspeed);
	tmp_x = player->vec_plane_x;
	player->vec_plane_x = player->vec_plane_x * cos(rotspeed)
		- player->vec_plane_y * sin(rotspeed);
	player->vec_plane_y = tmp_x * sin(rotspeed) + player->vec_plane_y
		* cos(rotspeed);
}

void	rotate_left(t_player *player)
{
	rotate(player, -ROT_SPEED);
}

void	rotate_right(t_player *player)
{
	rotate(player, ROT_SPEED);
}
