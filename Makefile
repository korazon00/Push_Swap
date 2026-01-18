NAME = push_swap
NAME_BONUS = checker

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = ft_atoi.c		ft_strlcat.c	push_swap.c	swap.c \
		ft_error_exit.c		ft_strlen.c	reverse.c	t_list.c \
			ft_split.c	push.c	rotate.c	ft_sort_3.c		ft_sort_5.c	ft_sort_all.c \
				target.c

BONUS = checker_bonus/checker.c		checker_bonus/free.c	checker_bonus/ft_help.c		checker_bonus/help_1.c	checker_bonus/ft_split.c \
		checker_bonus/get_next_line.c		checker_bonus/get_next_line_utils.c \
	checker_bonus/t_list.c		checker_bonus/operations.c		checker_bonus/operations_2.c

OBJ = $(SRC:%.c=%.o)

BONUS_OBJ = $(BONUS:%.c=%.o)

all : $(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS) : $(BONUS_OBJ)
	 $(CC) $(CFLAGS) $(BONUS_OBJ) -o $(NAME_BONUS)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c push_swap.h checker_bonus/checker.h
		$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all