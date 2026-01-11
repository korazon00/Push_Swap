NAME = push_swap.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = ft_atoi.c	ft_strlcat.c	push_swap.c	swap.c \
		ft_error_exit.c	ft_strlen.c	reverse.c	t_list.c \
			ft_split.c	push.c	rotate.c	ft_sort_3.c		ft_sort_5.c	ft_sort_all.c\
				target.c

OBJ = $(SRC:%.c=%.o)

all : $(NAME)

$(NAME): $(OBJ)
	ar r $(NAME) $(OBJ)
	$(CC) $(CFLAGS) $(NAME) -o push_swap

%.o: %.c push_swap.h
		$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all