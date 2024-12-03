/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:43:56 by nsakanou          #+#    #+#             */
/*   Updated: 2024/12/03 17:44:00 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_forward(t_player *player)
{
	player->map_x = player->map_x + player->vec_dir_x * MOVESPEED;
	player->map_y = player->map_y + player->vec_dir_y * MOVESPEED;
}

void	move_backward(t_player *player)
{
	player->map_x = player->map_x - player->vec_dir_x * MOVESPEED;
	player->map_y = player->map_y - player->vec_dir_y * MOVESPEED;
}

void	move_left(t_player *player)
{
	player->map_x = player->map_x + player->vec_dir_y * MOVESPEED;
	player->map_y = player->map_y - player->vec_dir_x * MOVESPEED;
}

void	move_right(t_player *player)
{
	player->map_x = player->map_x - player->vec_dir_y * MOVESPEED;
	player->map_y = player->map_y + player->vec_dir_x * MOVESPEED;
}
