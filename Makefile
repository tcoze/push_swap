NAME = push_swap

CFLAGS = -Wall -Wextra -Werror

MY_SOURCES =	algo_inferior.c \
				algo_superior.c \
				choose_rotate_reverse.c \
				count_op.c \
				count_op_supp.c \
				count_op_inff.c \
				fill_back_a.c \
				push_swap.c \
				push_swap_check_entry.c \
				reverse_rotate.c \
				rotate.c \
				sort_and_utils.c \
				swap_or_push.c

MY_OBJECTS = $(MY_SOURCES:.c=.o)

$(CC) = cc

$(NAME) : $(MY_OBJECTS)
		$(CC) $(CFLAGS) -o $(NAME) $(MY_OBJECTS)

clean :
	rm -f $(MY_OBJECTS)

fclean : clean
	rm -f $(NAME)

re : fclean all

all : $(NAME)

%.o : %.c push_swap.h
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY: clean fclean re all
