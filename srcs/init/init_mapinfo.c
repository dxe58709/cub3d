/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mapinfo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:47:34 by nsakanou          #+#    #+#             */
/*   Updated: 2024/12/15 22:34:32 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	initialize_mapinfo(t_mapinfo *mapinfo, char *map_path)
{
	mapinfo->path = map_path;
	mapinfo->line_count = 0;
	mapinfo->no_path = NULL;
	mapinfo->so_path = NULL;
	mapinfo->we_path = NULL;
	mapinfo->ea_path = NULL;
	mapinfo->map = NULL;
	mapinfo->map_height = 0;
	mapinfo->map_width = 0;
	mapinfo->floor_rgb[0] = 0;
	mapinfo->floor_rgb[1] = 0;
	mapinfo->floor_rgb[2] = 0;
	mapinfo->ceiling_rgb[0] = 0;
	mapinfo->ceiling_rgb[1] = 0;
	mapinfo->ceiling_rgb[2] = 0;
	return (SUCCESS);
}

static void	put_map_direct(char **line, t_mapinfo *mapinfo)
{
	if (ft_strcmp(line[0], "NO") == 0)
		mapinfo->no_path = ft_strtrim(line[1], "\n");
	else if (ft_strcmp(line[0], "SO") == 0)
		mapinfo->so_path = ft_strtrim(line[1], "\n");
	else if (ft_strcmp(line[0], "WE") == 0)
		mapinfo->we_path = ft_strtrim(line[1], "\n");
	else if (ft_strcmp(line[0], "EA") == 0)
		mapinfo->ea_path = ft_strtrim(line[1], "\n");
}

static void	put_map_rgb(char **line, t_mapinfo *mapinfo)
{
	char	**colors;
	char	*trimedline;

	trimedline = ft_strtrim(line[1], "\n");
	colors = ft_split(trimedline, ',');
	free(trimedline);
	if (ft_strcmp(line[0], "C") == 0)
	{
		mapinfo->ceiling_rgb[0] = ft_atoi(colors[0]);
		mapinfo->ceiling_rgb[1] = ft_atoi(colors[1]);
		mapinfo->ceiling_rgb[2] = ft_atoi(colors[2]);
	}
	else if (ft_strcmp(line[0], "F") == 0)
	{
		mapinfo->floor_rgb[0] = ft_atoi(colors[0]);
		mapinfo->floor_rgb[1] = ft_atoi(colors[1]);
		mapinfo->floor_rgb[2] = ft_atoi(colors[2]);
	}
	free_tab((void **)colors);
}

bool	put_mapinfo(char *line, int count, t_mapinfo *mapinfo, char **map)
{
	char	**temp_line;

	if (ft_strcmp(line, "\n") == 0)
		return (free(line), 0);
	if (count < 6)
	{
		temp_line = ft_split(line, ' ');
		if (count < 4)
			put_map_direct(temp_line, mapinfo);
		else if (count < 6)
			put_map_rgb(temp_line, mapinfo);
		free_tab((void **)temp_line);
	}
	else
		map[count - 6] = ft_strtrim(line, "\n");
	return (free(line), 1);
}

int	init_mapinfo(t_mapinfo *mapinfo, t_temp *temp, int count)
{
	char		**map;
	const int	fd = open(temp->map_path, O_RDONLY);
	size_t		max_width;
	char		*line;

	max_width = 0;
	mapinfo->map_height = temp->map_count - 6;
	map = (char **)ft_calloc(sizeof(char *), (mapinfo->map_height + 1));
	while (count < temp->map_count)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (count > 5 && max_width < ft_strlen(line) - 1)
			max_width = ft_strlen(line) - 1;
		count += put_mapinfo(line, count, mapinfo, map);
	}
	mapinfo->map = map;
	mapinfo->map_width = max_width;
	close(fd);
	return (SUCCESS);
}
