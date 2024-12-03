/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_xpm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:47:34 by nsakanou          #+#    #+#             */
/*   Updated: 2024/12/03 17:55:29 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_dir(char *path)
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

bool	xpm_file_check(char *path)
{
	int	fd;

	if (is_dir(path))
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
	if (!xpm_file_check(game->mapinfo.no_path))
		return (false);
	if (!xpm_file_check(game->mapinfo.so_path))
		return (false);
	if (!xpm_file_check(game->mapinfo.we_path))
		return (false);
	if (!xpm_file_check(game->mapinfo.ea_path))
		return (false);
	return (true);
}

bool	xpm_nl_check(char *path)
{
	int		fd;
	char	*trimedpath;

	trimedpath = ft_strtrim(path, "\n");
	if (is_dir(trimedpath))
		return (free(trimedpath), false);
	if (ft_strcmp(trimedpath + ft_strlen(trimedpath) - 4, ".xpm") != 0)
		return (free(trimedpath), false);
	fd = open(trimedpath, O_RDONLY);
	if (fd == -1)
		return (free(trimedpath), false);
	close(fd);
	return (free(trimedpath), true);
}
