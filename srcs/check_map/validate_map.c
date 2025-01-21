/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:47:34 by nsakanou          #+#    #+#             */
/*   Updated: 2024/12/15 17:53:30 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_temp_map(char **temp_map, int map_count, size_t max_width)
{
	int		i;
	size_t	j;

	i = 0;
	while (i < map_count - 4)
	{
		temp_map[i] = ft_calloc(sizeof(char), max_width + 2);
		j = 0;
		while (j < max_width + 1)
			temp_map[i][j++] = '$';
		i++;
	}
}

static int	copy_line_to_map(char **temp_map, char *line, int i)
{
	size_t	j;

	j = 0;
	while (j < ft_strlen(line) - 1)
	{
		temp_map[i][j + 1] = line[j];
		j++;
	}
	temp_map[i][j + 1] = '\0';
	return (i + 1);
}

static bool	validate_lines(char *line, int i)
{
	if (ft_strncmp(line, "NO", 2) == 0 || ft_strncmp(line, "SO", 2) == 0
		|| ft_strncmp(line, "WE", 2) == 0 || ft_strncmp(line, "EA", 2) == 0
		|| ft_strncmp(line, "C", 1) == 0 || ft_strncmp(line, "F", 1) == 0
		|| (i < 6 && ft_strcmp(line, "\n") == 0))
		return (true);
	return (false);
}

bool	validate_map(t_temp *temp)
{
	const int	fd = open(temp->map_path, O_RDONLY);
	char		*line;
	char		**temp_map;
	int			i;

	temp_map = ft_calloc(sizeof(char *), temp->map_count - 3);
	init_temp_map(temp_map, temp->map_count, temp->max_width);
	i = 1;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (validate_lines(line, i))
		{
			free(line);
			continue ;
		}
		i = copy_line_to_map(temp_map, line, i);
		free(line);
	}
	if (validate_round_player(temp_map) || validate_round_space(temp_map)
		|| validate_round_zero(temp_map))
		return (close(fd), free_all(NULL, temp_map, NULL, ERR_MSG), 1);
	return (close(fd), free_tab((void **)temp_map), 0);
}
