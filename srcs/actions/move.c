/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:43:56 by nsakanou          #+#    #+#             */
/*   Updated: 2025/01/23 16:05:20 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_move_valid(t_game *game, double new_pos_x, double new_pos_y)
{
	int	map_x;
	int	map_y;

	map_x = (int)new_pos_x;
	map_y = (int)new_pos_y;
	if (map_x < 0 || map_x >= game->mapinfo.map_width
		|| map_y < 0 || map_y >= game->mapinfo.map_height)
		return (false);
	if (game->mapinfo.map[map_y][map_x] == '1')
		return (false);
	return (true);
}

void	move_forward(t_player *player, t_game *game)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = player->map_x + player->x_vec_dir * MOVE_SPEED;
	new_pos_y = player->map_y + player->y_vec_dir * MOVE_SPEED;
	if (is_move_valid(game, new_pos_x, new_pos_y))
	{
		player->map_x = new_pos_x;
		player->map_y = new_pos_y;
	}
}

void	move_backward(t_player *player, t_game *game)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = player->map_x - player->x_vec_dir * MOVE_SPEED;
	new_pos_y = player->map_y - player->y_vec_dir * MOVE_SPEED;
	if (is_move_valid(game, new_pos_x, new_pos_y))
	{
		player->map_x = new_pos_x;
		player->map_y = new_pos_y;
	}
}

void	move_left(t_player *player, t_game *game)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = player->map_x + player->y_vec_dir * MOVE_SPEED;
	new_pos_y = player->map_y - player->x_vec_dir * MOVE_SPEED;
	if (is_move_valid(game, new_pos_x, new_pos_y))
	{
		player->map_x = new_pos_x;
		player->map_y = new_pos_y;
	}
}

void	move_right(t_player *player, t_game *game)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = player->map_x - player->y_vec_dir * MOVE_SPEED;
	new_pos_y = player->map_y + player->x_vec_dir * MOVE_SPEED;
	if (is_move_valid(game, new_pos_x, new_pos_y))
	{
		player->map_x = new_pos_x;
		player->map_y = new_pos_y;
	}
}
