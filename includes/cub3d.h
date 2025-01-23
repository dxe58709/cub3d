/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 21:43:23 by nsakanou          #+#    #+#             */
/*   Updated: 2025/01/23 15:28:09 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define ERROR 1
# define SUCCESS 0

# define WIN_HEIGHT 480
# define WIN_WIDTH 640
# define FOV 0.66
# define MOVE_SPEED 0.05
# define ROT_SPEED 0.05
# define TEX_SIZE 64

# define ERR_USAGE "Usage: ./cub3D <path/to/map.cub>"
# define ERR_MALLOC "Failed to malloc"
# define ERR_ARGMAP "Confirm map name or map path"
# define ERR_MSG "INVALID"
# define ERR_MAP "Invalid map content"
# define ERR_RGB "Invalid RGB"
# define ERR_DIRECTION "Invalid Direction"
# define ERR_INFO "too few map properties infomation"
# define ERR_PLAYER "Invalid Player"
# define ERR_SPACE "' ' need walls"
# define ERR_ZERO "'0' need walls"

typedef struct s_img
{
	void	*img;
	int		*addr;
	int		bits_par_pixel;
	int		bytes_line;
	int		endian;
}	t_img;

typedef struct s_texinfo
{
	int		**tex_north;
	int		**tex_south;
	int		**tex_west;
	int		**tex_east;
	int		size;
}	t_texinfo;

typedef struct s_mapinfo
{
	char	*path;
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	char	**map;
	int		map_height;
	int		map_width;
	int		floor_rgb[3];
	int		ceiling_rgb[3];
	int		line_count;
}	t_mapinfo;

/**
Screen coordinates.
(0, 0) -----> x (positive direction)
 |
 |
 v
 y (positive direction)
 */

typedef struct s_ray
{
	double		camera_x;
	int			side;

	int			map_x;
	int			map_y;

	int			next_x;
	int			next_y;

	double		x_vec_dir;
	double		y_vec_dir;

	double		distance_x;
	double		distance_y;

	double		x_cell_dist;
	double		y_cell_dist;

	int			wall_height;
	double		wall_dist;
	int			wall_start_y;
	int			wall_end_y;
	double		wall_x;
}	t_ray;

typedef struct s_tex_ray
{
	int			x;
	int			y;
	double		next;
	double		pos;
}	t_tex_ray;

typedef struct s_player
{
	char		direction;
	double		map_x;
	double		map_y;
	double		x_vec_dir;
	double		y_vec_dir;
	double		vec_plane_x;
	double		vec_plane_y;
}	t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	int			win_height;
	int			win_width;
	int			**view_pixels;
	t_texinfo	texinfo;
	t_mapinfo	mapinfo;
	t_player	player;
	t_ray		ray;
}	t_game;

typedef struct s_temp
{
	int			map_count;
	char		map_path[4096];
	bool		player_flag;
	char		player_direction;
	int			player_mapx;
	int			player_mapy;
	int			texture_size;
	size_t		max_width;
	const char	*map_properties[6];
	bool		map_properties_flag[6];
}	t_temp;

//actions
void			set_hook(t_game *game);

void			move_forward(t_player *player);
void			move_backward(t_player *player);
void			move_right(t_player *player);
void			move_left(t_player *player);

void			rotate_left(t_player *player);
void			rotate_right(t_player *player);

//inits
int				new_init_mapinfo(t_game *game, t_mapinfo *mapinfo,
					t_temp *temp);
int				init_mapinfo(t_mapinfo *mapinfo, t_temp *temp, int count);
int				initialize_mapinfo(t_mapinfo *mapinfo, char *map_path);

void			init_game(t_game *game, t_temp *temp);
void			init_view_pixels(t_game *game);
int				initialize_game(t_game *game, char *map_path);

void			init_img(t_game *game, t_img *image, int width, int height);
void			init_xpm_img(t_game *game, t_img *image, char *path);

void			init_player_vec(t_player *player);
void			initialize_player(t_player *player);

void			init_temp(t_temp *temp);

void			init_ray(t_ray *ray, t_player *player, int x);

void			init_tex_ray(t_game *game, t_ray *ray, t_tex_ray *tex_ray);

void			init_texinfo(t_game *game, t_texinfo *texinfo);
void			initialize_texinfo(t_texinfo *texinfo);

//map_check
int				check_map(int argc, char **argv, t_temp *temp);
bool			check_textures_path(t_game *game);
bool			validate_xpm_path(char *path);
bool			validate_map(t_temp *temp);
bool			validate_round_player(char **temp_map);
bool			validate_round_space(char **temp_map);
bool			validate_round_zero(char **temp_map);

//render
void			raycasting(t_game *game);
int				render_raycasting(t_game *game);

//textures
int				get_ceiling_color(t_game *game);
int				get_floor_color(t_game *game);
int				**get_wall_texture(t_game *game, t_ray *ray);
int				get_wall_color(t_game *game, int **wall_tex,
					t_tex_ray *tex_ray);

//utils
void			print_mapinfo(t_mapinfo *mapinfo);
void			put_player(t_player *player);
void			put_ray(t_ray *ray);
void			put_tex_ray(t_tex_ray *tex_ray);
void			put_texinfo(t_texinfo *texinfo);

int				err_msg(char *msg, int status);
void			free_exit(t_game *game, int status);
int				finish_game(t_game *game);
void			free_tab(void **tab);
void			free_all(char **tab, char **spline, char *line,
					char *message);

#endif
