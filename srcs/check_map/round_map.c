/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   round_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:47:34 by nsakanou          #+#    #+#             */
/*   Updated: 2024/12/15 20:03:43 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	fill_round(char **temp_map, int i, size_t j, char round[8])
{
	round[0] = temp_map[i - 1][j - 1];
	round[1] = temp_map[i - 1][j];
	round[2] = temp_map[i - 1][j + 1];
	round[3] = temp_map[i][j - 1];
	round[4] = temp_map[i][j + 1];
	round[5] = temp_map[i + 1][j - 1];
	round[6] = temp_map[i + 1][j];
	round[7] = temp_map[i + 1][j + 1];
}

bool	validate_round_player(char **temp_map)
{
	int			i;
	size_t		j;
	char		round[8];

	i = -1;
	while (temp_map[++i])
	{
		j = -1;
		while (temp_map[i][++j])
		{
			if (ft_strchr("NEWS", temp_map[i][j]))
			{
				fill_round(temp_map, i, j, round);
				if (ft_strchr(round, ' ') || ft_strchr(round, '$'))
					return (free_all(temp_map, NULL, NULL, ERR_PLAYER), 1);
			}
		}
	}
	return (0);
}

bool	validate_round_space(char **temp_map)
{
	int			i;
	size_t		j;
	char		round[8];

	i = -1;
	while (temp_map[++i])
	{
		j = -1;
		while (temp_map[i][++j])
		{
			if (temp_map[i][j] == ' ')
			{
				fill_round(temp_map, i, j, round);
				if (ft_strchr(round, '0'))
					return (free_all(temp_map, NULL, NULL, ERR_SPACE), 1);
			}
		}
	}
	return (0);
}

bool	validate_round_zero(char **temp_map)
{
	int			i;
	size_t		j;
	char		round[8];

	i = -1;
	while (temp_map[++i])
	{
		j = -1;
		while (temp_map[i][++j])
		{
			if (temp_map[i][j] == '0')
			{
				fill_round(temp_map, i, j, round);
				if (ft_strchr(round, '$') || ft_strchr(round, ' '))
					return (free_all(temp_map, NULL, NULL, ERR_ZERO), 1);
			}
		}
	}
	return (0);
}
