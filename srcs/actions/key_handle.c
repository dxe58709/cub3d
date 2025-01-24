/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:41:29 by nsakanou          #+#    #+#             */
/*   Updated: 2025/01/23 16:09:50 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_forward(t_player *player, t_game *game);
void	move_backward(t_player *player, t_game *game);
void	move_left(t_player *player, t_game *game);
void	move_right(t_player *player, t_game *game);
void	rotate_left(t_player *player);
void	rotate_right(t_player *player);

static int	key_handle(int key, t_game *game)
{
	if (key == XK_Escape)
		finish_game(game);
	if (key == XK_w)
		move_forward(&game->player, game);
	if (key == XK_a)
		move_left(&game->player, game);
	if (key == XK_s)
		move_backward(&game->player, game);
	if (key == XK_d)
		move_right(&game->player, game);
	if (key == XK_Left)
		rotate_left(&game->player);
	if (key == XK_Right)
		rotate_right(&game->player);
	return (SUCCESS);
}

void	set_hook(t_game *game)
{
	mlx_hook(game->win, ClientMessage, NoEventMask, finish_game, game);
	mlx_hook(game->win, KeyPress, KeyPressMask, key_handle, game);
}
