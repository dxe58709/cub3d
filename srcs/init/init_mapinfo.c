/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mapinfo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:47:34 by nsakanou          #+#    #+#             */
/*   Updated: 2024/12/03 17:54:25 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

/**
 * Get Map information from file.
 */
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
	return (close(fd), SUCCESS);
}

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

// mapinfo->no_path = ft_strdup("textures/bookshelf.xpm");
// mapinfo->so_path = ft_strdup("textures/bookshelf.xpm");
// mapinfo->we_path = ft_strdup("textures/bookshelf.xpm");
// mapinfo->ea_path = ft_strdup("textures/bookshelf.xpm");
// mapinfo->line_count = 22;
// mapinfo->floor_rgb[0] = 53;
// mapinfo->floor_rgb[1] = 41;
// mapinfo->floor_rgb[2] = 34;
// mapinfo->ceiling_rgb[0] = 45;
// mapinfo->ceiling_rgb[1] = 33;
// mapinfo->ceiling_rgb[2] = 27;
// map = malloc(sizeof(char *) * 14);
// map[0] = ft_strdup("111111111111111");
// map[1] = ft_strdup("111111000111111");
// map[2] = ft_strdup("111110000011111");
// map[3] = ft_strdup("1111000N0001111");
// map[4] = ft_strdup("111000000000111");
// map[5] = ft_strdup("110000000000011");
// map[6] = ft_strdup("100001111100001");
// map[7] = ft_strdup("110000111000011");
// map[8] = ft_strdup("111000010000111");
// map[9] = ft_strdup("111100000001111");
// map[10] = ft_strdup("111110000011111");
// map[11] = ft_strdup("111111000111111");
// map[12] = ft_strdup("111111111111111");
// map[13] = NULL;

/**
 * Map情報をファイルから取得する
 */
// void	init_mapinfo(t_game *game, t_mapinfo *mapinfo)
// {
// 	char	**map;

// 	/** @TODO ファイルから取得する */
// 	mapinfo->no_path = ft_strdup("textures/bookshelf.xpm");
// 	mapinfo->so_path = ft_strdup("textures/bookshelf.xpm");
// 	mapinfo->we_path = ft_strdup("textures/bookshelf.xpm");
// 	mapinfo->ea_path = ft_strdup("textures/bookshelf.xpm");
// 	mapinfo->line_count = 22;
// 	mapinfo->floor_rgb[0] = 53;
// 	mapinfo->floor_rgb[1] = 41;
// 	mapinfo->floor_rgb[2] = 34;
// 	mapinfo->ceiling_rgb[0] = 45;
// 	mapinfo->ceiling_rgb[1] = 33;
// 	mapinfo->ceiling_rgb[2] = 27;
// 	map = malloc(sizeof(char *) * 14);
// 	map[0] = ft_strdup("111111111111111");
// 	map[1] = ft_strdup("111111000111111");
// 	map[2] = ft_strdup("111110000011111");
// 	map[3] = ft_strdup("111100000001111"); /** Nを0にする */
// 	map[4] = ft_strdup("111000000000111");
// 	map[5] = ft_strdup("110000000000011");
// 	map[6] = ft_strdup("100001111100001");
// 	map[7] = ft_strdup("110000111000011");
// 	map[8] = ft_strdup("111000010000111");
// 	map[9] = ft_strdup("111100000001111");
// 	map[10] = ft_strdup("111110000011111");
// 	map[11] = ft_strdup("111111000111111");
// 	map[12] = ft_strdup("111111111111111");
// 	map[13] = NULL;
// 	mapinfo->map = map;
// 	game->player.direction = 'E';
// 	game->player.map_x = 7.5; /** プレイヤーのIndex + 0.5 */
// 	game->player.map_y = 3.5; /** プレイヤーのIndex + 0.5 */
// }