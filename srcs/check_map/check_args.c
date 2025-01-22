/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:47:34 by nsakanou          #+#    #+#             */
/*   Updated: 2024/12/15 22:31:53 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	check_rgb(char *c_line, char **spline, char *line)
{
	char	**colors;
	int		i;
	size_t	j;
	char	*trimedline;

	trimedline = ft_strtrim(c_line, "\n");
	colors = ft_split(trimedline, ',');
	free(trimedline);
	i = -1;
	while (colors[++i])
	{
		if (i > 2)
			return (free_all(colors, spline, line, ERR_RGB), 1);
		j = -1;
		while (++j < ft_strlen(colors[i]))
		{
			if (!ft_isdigit(colors[i][j]) || j > 2 || ft_atoi(colors[i]) > 255)
				return (free_all(colors, spline, line, ERR_RGB), 1);
		}
	}
	if (i < 2)
		return (free_all(colors, spline, line, ERR_RGB), 1);
	return (free_tab((void **)colors), 0);
}

bool	check_map_properties(t_temp *temp, char **spline, char *line, int i)
{
	if (!spline || !spline[0])
		return (free_all(NULL, spline, line, ERR_INFO), 0);
	if (spline[0])
	{
		i = -1;
		while (++i < 6)
		{
			if (!ft_strcmp(spline[0], temp->map_properties[i])
				&& !temp->map_properties_flag[i] && spline[1] && !spline[2]
				&& ((i < 4 && validate_xpm_path(spline[1])) || (i >= 4
				&& check_rgb(spline[1], spline, line) == 0)))
			{
				temp->map_properties_flag[i] = true;
				return (free(line), free_tab((void **)spline), 1);
			}
		}
	}
	return (free_all(NULL, spline, line, ERR_DIRECTION), 0);
}

int	check_filename(int argc, char *filename, t_temp *temp)
{
	int		fd;
	char	*basename;
	int		len;
	int		i;

	if (argc != 2)
		return (free_exit(NULL, err_msg(ERR_USAGE, 1)), ERROR);
	basename = ft_strrchr(filename, '/');
	if (basename)
		basename++;
	else
		basename = filename;
	len = (int)ft_strlen(basename);
	if (len <= 4 || ft_strcmp(basename + len - 4, ".cub") != 0)
		return (free_exit(NULL, err_msg(ERR_USAGE, 1)), ERROR);
	i = -1;
	while (++i < len - 4)
		if (ft_strncmp(basename + i, ".cub", 4) == 0)
			return (free_exit(NULL, err_msg(ERR_USAGE, 1)), ERROR);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (close(fd), free_exit(NULL, err_msg(ERR_ARGMAP, 1)), ERROR);
	ft_strlcpy(temp->map_path, filename, 4095);
	return (fd);
}
