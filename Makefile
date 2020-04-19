# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: julienngy <julienngy@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/28 14:34:43 by julienngy         #+#    #+#              #
#    Updated: 2020/04/02 13:10:19 by julienngy        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS_PATH = ./srcs/
HEADERS = ./includes/
LIBFT_HEADERS = ./libft/includes/

SRCS_FILES = init_map.c \
			 parse_map.c \
			 ft_tools.c \
			 check_map.c \
			 error_exit.c \
			 main_game.c \
			 init_pos.c \
			 init_texture.c \
			 init_image.c \
			 draw_wall.c \
			 sky.c \
			 main.c \
			 movements.c \
			 events.c \
			 rotations.c \
			 sprite.c \
			 parse_map2.c \
			 main_sprite.c
			 
SRCS = $(addprefix $(SRCS_PATH), $(SRCS_FILES))
OBJS = $(SRCS:.c=.o)
BMP = screenshot.bmp
LIB = libft/libft.a
MLX_LIN = minilibx-linux/libmlx.a
MLX_MAC =  -lmlx -framework OpenGL -framework AppKit
MLX_LINUX = -lm -lbsd -lX11 -lXext
NAME = Cub3D
CC = gcc
FLAGS = -Werror -Wall -Wextra -I $(HEADERS) -I $(LIBFT_HEADERS)

all: setup $(NAME)

$(NAME): $(OBJS) $(LIB) $(MLX_LIN) 
		$(CC) $(FLAGS) $(OBJS) -o $(NAME) $(LIB) $(MLX_LIN) $(MLX_LINUX)

mac: $(OBJS) $(LIB) $(MLX)
		$(CC) $(FLAGS) $(OBJS) $(MLX_MAC)  -o $(NAME) $(LIB)
		
$(LIB):
	make -j4 -C ./libft

$(MLX):
	make -j4 -C ./minilibx_linux

setup:
	sudo cp minilibx-linux/mlx.h /usr/local/include

clean:
	make fclean -C ./libft
	rm -f $(OBJS) $(BMP)

fclean: clean
		$(RM) $(NAME)

remac: fclean mac

re: fclean all

.PHONY: all mac clean fclean re
		
