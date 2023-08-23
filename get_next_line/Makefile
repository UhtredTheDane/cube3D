CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar crs
NAME = get_next_line.a
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $^

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS) -D BUFFER_SIZE=200

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re