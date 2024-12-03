/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 22:03:17 by nsakanou          #+#    #+#             */
/*   Updated: 2024/12/03 18:01:28 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_tab(void **tab)
{
	size_t	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
		tab = NULL;
	}
}

void	matomete_free(char **tab, char **spline, char *line, char *message)
{
	if (tab)
		free_tab((void **)tab);
	if (spline)
		free_tab((void **)spline);
	if (line)
		free(line);
	free_exit(NULL, err_msg(message, 1));
}
