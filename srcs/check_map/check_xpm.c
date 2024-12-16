/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_xpm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:47:34 by nsakanou          #+#    #+#             */
/*   Updated: 2024/12/16 14:44:40 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_directory(char *path)
{
	int	fd;

	fd = open(path, O_DIRECTORY);
	if (fd < 0)
		return (false);
	close(fd);
	return (true);
}

static bool	is_xpm_file(char *path)
{
	size_t	len;

	len = ft_strlen(path);
	if ((int)(len - 5) < 0)
		return (false);
	if (path[len - 4] == '.' && path[len - 3] == 'x' && path[len - 2] == 'p'
		&& path[len - 1] == 'm')
		return (true);
	return (false);
}

static bool	check_xpm_file(char *path)
{
	int	fd;

	if (is_directory(path))
		return (false);
	if (!is_xpm_file(path))
		return (false);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (false);
	close(fd);
	return (true);
}

bool	check_textures_path(t_game *game)
{
	if (!check_xpm_file(game->mapinfo.no_path))
		return (false);
	if (!check_xpm_file(game->mapinfo.so_path))
		return (false);
	if (!check_xpm_file(game->mapinfo.we_path))
		return (false);
	if (!check_xpm_file(game->mapinfo.ea_path))
		return (false);
	return (true);
}

bool	validate_xpm_path(char *path)
{
	int		fd;
	char	*new_path;

	new_path = ft_strtrim(path, "\n");
	if (is_directory(new_path))
		return (free(new_path), false);
	if (ft_strcmp(new_path + ft_strlen(new_path) - 4, ".xpm") != 0)
		return (free(new_path), false);
	fd = open(new_path, O_RDONLY);
	if (fd == -1)
		return (free(new_path), false);
	close(fd);
	return (free(new_path), true);
}
