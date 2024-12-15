/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:43:56 by nsakanou          #+#    #+#             */
/*   Updated: 2024/12/15 20:11:29 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_forward(t_player *player)
{
	player->map_x = player->map_x + player->x_vec_dir * MOVE_SPEED;
	player->map_y = player->map_y + player->y_vec_dir * MOVE_SPEED;
}

void	move_backward(t_player *player)
{
	player->map_x = player->map_x - player->x_vec_dir * MOVE_SPEED;
	player->map_y = player->map_y - player->y_vec_dir * MOVE_SPEED;
}

void	move_left(t_player *player)
{
	player->map_x = player->map_x + player->y_vec_dir * MOVE_SPEED;
	player->map_y = player->map_y - player->x_vec_dir * MOVE_SPEED;
}

void	move_right(t_player *player)
{
	player->map_x = player->map_x - player->y_vec_dir * MOVE_SPEED;
	player->map_y = player->map_y + player->x_vec_dir * MOVE_SPEED;
}
