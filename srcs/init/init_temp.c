/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_temp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 22:03:17 by nsakanou          #+#    #+#             */
/*   Updated: 2024/12/15 20:32:31 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_temp(t_temp *temp)
{
	temp->map_count = 0;
	temp->map_path[0] = '\0';
	temp->player_flag = false;
	temp->player_direction = '\0';
	temp->player_mapx = 0;
	temp->player_mapy = 0;
	temp->texture_size = 64;
	temp->max_width = 0;
	temp->map_properties[0] = "NO";
	temp->map_properties[1] = "WE";
	temp->map_properties[2] = "SO";
	temp->map_properties[3] = "EA";
	temp->map_properties[4] = "C";
	temp->map_properties[5] = "F";
	temp->map_properties_flag[0] = false;
	temp->map_properties_flag[1] = false;
	temp->map_properties_flag[2] = false;
	temp->map_properties_flag[3] = false;
	temp->map_properties_flag[4] = false;
	temp->map_properties_flag[5] = false;
}
