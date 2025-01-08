/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   round_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:47:34 by nsakanou          #+#    #+#             */
/*   Updated: 2024/12/16 18:27:55 by nsakanou         ###   ########.fr       */
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
				// 位置とその周囲のセルを詳細に表示
				printf("\n====================\n");
				printf("Checking 0 at (i=%d, j=%zu)\n", i, j);
				printf("Top-left (i-1,j-1): [%c] | Top (i-1,j): [%c] | Top-right (i-1,j+1): [%c]\n", round[0], round[1], round[2]);
				printf("Left (i,j-1): [%c] | Right (i,j+1): [%c]\n", round[3], round[4]);
				printf("Bottom-left (i+1,j-1): [%c] | Bottom (i+1,j): [%c] | Bottom-right (i+1,j+1): [%c]\n", round[5], round[6], round[7]);

				if (ft_strchr(round, '$') || ft_strchr(round, ' '))
				{
					printf("Found invalid character ('$' or ' ') at (i=%d, j=%zu)\n", i, j);
					return (free_all(temp_map, NULL, NULL, ERR_ZERO), 1);
				}
				printf("====================\n");
			}
		}
	}
	return (0);
}
