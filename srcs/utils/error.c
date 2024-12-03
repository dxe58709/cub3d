/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 22:03:17 by nsakanou          #+#    #+#             */
/*   Updated: 2024/12/03 18:01:51 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	err_msg(char *msg, int status)
{
	ft_putstr_fd("Error\n", status);
	if (msg)
		ft_putstr_fd(msg, status);
	ft_putstr_fd("\n", status);
	return (status);
}
