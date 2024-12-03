/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 21:34:34 by nsakanou          #+#    #+#             */
/*   Updated: 2024/12/03 18:26:21 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game	game;
	t_temp	temp;

	init_temp(&temp);
	if (args_checker(argc, argv, &temp))
		return (ERROR);
	initialize_game(&game, argv[1]);
	init_game(&game, &temp);
	render_raycasting(&game);
	hooks_keys(&game);
	mlx_loop(game.mlx);
	free_exit(&game, SUCCESS);
	return (SUCCESS);
}
