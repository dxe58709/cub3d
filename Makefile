# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/22 20:39:05 by nsakanou          #+#    #+#              #
#    Updated: 2024/12/15 22:54:06 by nsakanou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

LIBDIR = ./libft
LIBFT = $(LIBDIR)/libft.a

MLXDIR = ./minilibx-linux
MLX = $(MLXDIR)/libmlx.a
MLXLIBS = -L $(MLXDIR) -lmlx -lXext -lX11 -lm -lz

INCLUDES = -I./includes -I ./srcs -I $(LIBDIR) -I $(MLXDIR)
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f

SRCS =  srcs/main.c \
		srcs/actions/key_handle.c \
		srcs/actions/move.c \
		srcs/actions/rotate.c \
		srcs/utils/debug.c \
		srcs/utils/error.c \
		srcs/utils/free.c \
		srcs/utils/free_utils.c \
		srcs/init/init_game.c \
		srcs/init/init_img.c \
		srcs/init/init_mapinfo.c \
		srcs/init/init_player.c \
		srcs/init/init_ray.c \
		srcs/init/init_temp.c \
		srcs/init/init_tex_ray.c \
		srcs/init/init_texture.c \
		srcs/render/raycasting.c \
		srcs/render/render.c \
		srcs/render/floor.c \
		srcs/render/wall.c \
		srcs/check_map/check_args.c \
		srcs/check_map/check_xpm.c \
		srcs/check_map/round_map.c \
		srcs/check_map/validate_map.c \

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLXLIBS) -o $(NAME)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

$(LIBFT):
	$(MAKE) -C $(LIBDIR)
$(MLX):
	$(MAKE) -C $(MLXDIR)

clean:
	$(RM) $(OBJS) $(MLX) $(LIBFT)
	@$(MAKE) -C $(LIBDIR) clean
	@$(MAKE) -C $(MLXDIR) clean

fclean: clean
	$(RM) $(NAME)

re: fclean all

debug: fclean __debug_configure__ all

norminette: $(SRCS)
	norminette $^ cub3d.h

norm: norminette

.PHONY: all clean fclean re debug norminette norm