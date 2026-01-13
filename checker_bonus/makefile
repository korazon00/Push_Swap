NAME = checker.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = checker.c		free.c	ft_help.c	help_1.c	ft_split.c	get_next_line.c		get_next_line_utils.c \
		t_list.c	ft_help.c	operations.c	operations_2.c	

OBJ = $(SRC:%.c=%.o)

all : $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	$(CC) $(NAME) -o checker

%.o: %.c checker.h
		$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all