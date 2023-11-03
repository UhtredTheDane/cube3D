# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anmande <anmande@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/17 15:45:22 by agengemb          #+#    #+#              #
#    Updated: 2023/11/03 18:10:39 by anmande          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = cub3D
LIBFT = ./libft/libft.a
GET = ./get_next_line/get_next_line.a
SRC_PATH = srcs/

SRC = loading/color.c \
		loading/file.c \
		loading/map.c  \
		loading/texture.c  \
		loading/utils.c \
		map/map.c \
		map/map_utils.c \
		map/check.c \
		player/player.c \
		player/control.c \
		window/window.c \
		window/draw.c \
		window/utils.c \
		block.c \
		canvas.c \
		img.c \
		main.c \

SRCS    = $(addprefix $(SRC_PATH), $(SRC))
OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(GET)
	make -C mlx_linux
	$(CC) $^ -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -g -o $@

%o: %.c
	$(CC) -o $@ -c $< $(CFAGS)

$(LIBFT):
	make -C libft

$(GET):
	make -C get_next_line

clean:
	make -C libft clean
	make -C get_next_line clean
	rm -rf $(LIBFT)
	rm -rf $(GET)
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
