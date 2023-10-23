# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anmande <anmande@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/17 15:45:22 by agengemb          #+#    #+#              #
#    Updated: 2023/10/23 14:06:11 by anmande          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = cub3D
LIBFT = ./libft/libft.a
GET = ./get_next_line/get_next_line.a
SRC = $(wildcard srcs/*.c)
SRC2 = $(wildcard srcs/*/*.c)

OBJ = $(SRC:.c=.o)
//OBJ = $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SRCS))
OBJ2 = $(SRC2:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(OBJ2) $(LIBFT) $(GET)
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
	rm -rf $(OBJ) $(OBJ2)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
