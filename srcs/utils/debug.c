/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 22:03:17 by nsakanou          #+#    #+#             */
/*   Updated: 2024/12/03 18:02:13 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_str_arr(char **str_arr, char *name)
{
	int	i;

	i = 0;
	while (str_arr[i])
	{
		printf("%s[%d]\t: \"%s\"\n", name, i, str_arr[i]);
		i++;
	}
}

void	put_tab_arr(int **tab_arr, int size, int max, char *name)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		printf("%s[%d]\t: ", name, i);
		while (j < size)
		{
			if (i * size + j > max)
				break ;
			printf("%d, ", tab_arr[i][j]);
			j++;
		}
		printf("\n");
		if (i * size + j > max)
			break ;
		i++;
	}
}

void	put_ray(t_ray *ray)
{
	printf("RAY[%lf]: map(%d, %d) step(%d, %d) dir(%lf, %lf) deltadist(%lf,\
 %lf) sidedist(%lf, %lf) wall(%d %lf) draw(%d ~ %d) wall_x(%lf)\n",
		ray->camera_x,
		ray->map_x,
		ray->map_y,
		ray->step_x,
		ray->step_y,
		ray->vec_dir_x,
		ray->vec_dir_y,
		ray->deltadist_x,
		ray->deltadist_y,
		ray->sidedist_x,
		ray->sidedist_y,
		ray->wall_height,
		ray->wall_dist,
		ray->wall_start_y,
		ray->wall_end_y,
		ray->wall_x);
}

void	put_tex_ray(t_tex_ray *tex_ray)
{
	printf("TEX_RAY xy(%d %d) step(%lf) pos(%lf)\n", tex_ray->x, tex_ray->y,
		tex_ray->step, tex_ray->pos);
}

void	print_mapinfo(t_mapinfo *mapinfo)
{
	printf("\n################## mapinfo ##################\n");
	printf("path\t\t: \"%s\"\n", mapinfo->path);
	printf("no_path\t\t: \"%s\"\n", mapinfo->no_path);
	printf("so_path\t\t: \"%s\"\n", mapinfo->so_path);
	printf("we_path\t\t: \"%s\"\n", mapinfo->we_path);
	printf("ea_path\t\t: \"%s\"\n", mapinfo->ea_path);
	printf("map_height\t: %d\n", mapinfo->map_height);
	printf("map_width\t: %d\n", mapinfo->map_width);
	printf("line_count\t: %d\n", mapinfo->line_count);
	printf("floor_rgb\t: R[%d], G[%d], B[%d]\n", mapinfo->floor_rgb[0],
		mapinfo->floor_rgb[1], mapinfo->floor_rgb[2]);
	printf("ceiling_rgb\t: R[%d], G[%d], B[%d]\n", mapinfo->ceiling_rgb[0],
		mapinfo->ceiling_rgb[1], mapinfo->ceiling_rgb[2]);
	put_str_arr(mapinfo->map, "map");
}

// void	put_player(t_player *player)
// {
// 	printf("\n################## player ##################\n");
// 	printf("direction\t: \'%c\'\n", player->direction);
// 	printf("map_xy\t\t: X[%lf] Y[%lf]\n", player->map_x, player->map_y);
// 	printf("vec_xy_dir\t: X[%lf] Y[%lf]\n", player->vec_dir_x,
// 		player->vec_dir_y);
// 	printf("vec_xy_plane\t: X[%lf] Y[%lf]\n", player->vec_plane_x,
// 		player->vec_plane_y);
// }

// void	put_texinfo(t_texinfo *texinfo)
// {
// 	printf("\n################## texinfo ##################\n");
// 	printf("size\t\t: %d\n", texinfo->size);
// 	put_tab_arr(texinfo->tex_north, texinfo->size, 10, "tex_north");
// 	put_tab_arr(texinfo->tex_south, texinfo->size, 10, "tex_south");
// 	put_tab_arr(texinfo->tex_east, texinfo->size, 10, "tex_east");
// 	put_tab_arr(texinfo->tex_west, texinfo->size, 10, "tex_west");
// }