/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:47:34 by nsakanou          #+#    #+#             */
/*   Updated: 2024/12/03 17:54:10 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * Create initial values for t_game.view_pixels
 * Allocate and store 640*480 int array
 */
void	init_view_pixels(t_game *game)
{
	int	i;

	i = 0;
	if (game->view_pixels)
		free_tab((void **)game->view_pixels);
	game->view_pixels = ft_calloc(sizeof(int *), game->win_height + 1);
	if (!game->view_pixels)
		free_exit(game, err_msg(ERR_MALLOC, ERROR));
	while (i < game->win_height)
	{
		game->view_pixels[i] = ft_calloc(sizeof(int *), game->win_width + 1);
		if (!game->view_pixels[i])
			free_exit(game, err_msg(ERR_MALLOC, ERROR));
		i++;
	}
}

/**
 * The entire t_game structure.
 * All data necessary for processing, such as mapinfo, mlx, etc.,
	are put in at this stage.
 */
void	init_game(t_game *game, t_temp *temp)
{
	(void)temp;
	game->mlx = mlx_init();
	if (!game->mlx)
		free_exit(game, err_msg("mlx_init() Error.", ERROR));
	game->win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	if (!game->win)
		free_exit(game, err_msg("mlx_new_window() Error.", ERROR));
	game->mapinfo.line_count = temp->map_count;
	game->player.direction = temp->player_direction;
	game->player.map_x = temp->player_mapx + 0.5;
	game->player.map_y = temp->player_mapy + 0.5;
	init_mapinfo(&game->mapinfo, temp, 0);
	if (!check_textures_path(game))
		free_exit(game, err_msg("XPM invalid path", ERROR));
	init_player_vec(&game->player);
	init_view_pixels(game);
	init_texinfo(game, &game->texinfo);
}

/**
 * Initialise the t_game structure.
 */
int	initialize_game(t_game *game, char *map_path)
{
	game->mlx = NULL;
	game->win = NULL;
	game->win_width = WIN_WIDTH;
	game->win_height = WIN_HEIGHT;
	game->view_pixels = NULL;
	initialize_mapinfo(&game->mapinfo, map_path);
	initialize_player(&game->player);
	initialize_texinfo(&game->texinfo);
	return (SUCCESS);
}
