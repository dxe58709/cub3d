/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 21:34:34 by nsakanou          #+#    #+#             */
/*   Updated: 2025/01/23 13:43:41 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game	game;
	t_temp	temp;

	init_temp(&temp);
	if (check_map(argc, argv, &temp))
		return (ERROR);
	initialize_game(&game, argv[1]);
	init_game(&game, &temp);
	set_hook(&game);
	mlx_loop_hook(game.mlx, render_raycasting, &game);
	mlx_loop(game.mlx);
	free_exit(&game, SUCCESS);
	return (SUCCESS);
}
