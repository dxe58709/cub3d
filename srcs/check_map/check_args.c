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

static bool	check_rgb(char *c_line, char **spline, char *line)
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

static bool	check_map_properties(t_temp *temp, char **spline, char *line, int i)
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

static bool	read_map(char *line, int count, t_temp *temp, size_t line_len)
{
	int	i;

	if (ft_strcmp(line, "\n") == 0)
		return (free(line), (count >= 6));
	if (count < 6)
		return (check_map_properties(temp, ft_split(line, ' '), line, 0));
	if (ft_strchr("NEWS0", line[0]) || ft_strchr("NEWS0 ", line[line_len - 2]))
		return (free_all(NULL, NULL, line, ERR_MAP), 0);
	i = -1;
	while (++i < (int)line_len)
	{
		if ((count == 6 && ft_strchr("NEWS0", line[i]))
			|| (ft_strchr("NEWS01\n ", line[i]) == NULL))
			return (free_all(NULL, NULL, line, ERR_MAP), 0);
		if (ft_strchr("NEWS", line[i]))
		{
			if (temp->player_flag == true)
				return (free_all(NULL, NULL, line, ERR_PLAYER), 0);
			temp->player_direction = line[i];
			temp->player_mapx = i;
			temp->player_mapy = count - 6;
			temp->player_flag = true;
		}
	}
	return (free(line), 1);
}

static int	check_filename(int argc, char *filename, t_temp *temp)
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

int	check_map(int argc, char **argv, t_temp *temp)
{
	int		fd;
	int		count;
	char	*line;

	fd = check_filename(argc, argv[1], temp);
	count = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (temp->max_width < ft_strlen(line))
			temp->max_width = ft_strlen(line);
		count += read_map(line, count, temp, ft_strlen(line));
	}
	if (count < 6 || temp->player_flag == false)
		return (close(fd), free_exit(NULL, err_msg(ERR_MAP, 1)), ERROR);
	temp->map_count = count;
	count = -1;
	while (++count < 6)
		if (temp->map_properties[count] == false)
			return (close(fd), free_exit(NULL, err_msg(ERR_INFO, 1)), ERROR);
	return (close(fd), validate_map(temp), SUCCESS);
}
