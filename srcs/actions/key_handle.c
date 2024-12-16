/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:41:29 by nsakanou          #+#    #+#             */
/*   Updated: 2024/12/16 18:31:35 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	key_handle(int key, t_game *game)
{
	if (key == XK_Escape)
		finish_game(game);
	if (key == XK_w)
		move_forward(&game->player);
	if (key == XK_a)
		move_left(&game->player);
	if (key == XK_s)
		move_backward(&game->player);
	if (key == XK_d)
		move_right(&game->player);
	if (key == XK_Left)
		rotate_left(&game->player);
	if (key == XK_Right)
		rotate_right(&game->player);
	//render_raycasting(game);
	return (SUCCESS);
}

void	set_hook(t_game *game)
{
	mlx_hook(game->win, ClientMessage, NoEventMask, finish_game, game);
	mlx_hook(game->win, KeyPress, KeyPressMask, key_handle, game);
}
