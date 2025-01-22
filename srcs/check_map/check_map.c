/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:47:34 by nsakanou          #+#    #+#             */
/*   Updated: 2024/12/15 22:31:53 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	check_rgb(char *c_line, char **spline, char *line);
bool	check_map_properties(t_temp *temp, char **spline, char *line, int i);
int	    check_filename(int argc, char *filename, t_temp *temp);

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

int	check_map(int argc, char **argv, t_temp *temp)
{
	int		fd;
	int		count;
	char	*line;

	fd = check_filename(argc, argv[1], temp);
	if (fd == -1)
		return (-1);
	count = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		if (ft_strcmp(line, "\n"))
			count++;
		if (temp->max_width < ft_strlen(line))
			temp->max_width = ft_strlen(line);
		read_map(line, count - 1, temp, ft_strlen(line));
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