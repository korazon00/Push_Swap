NAME = cheker.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = checker.c	free.c	ft_help.c	help_1	ft_split	get_next_line.c		get_next_line_utils.c \
		t_list.c

OBJ = $(SRC:%.c=%.o)

all : $(NAME)

$(NAME): $(OBJ)
	ar r $(NAME) $(OBJ)

%.o: %.c checker.h
		$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all