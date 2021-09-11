NAME 		=	push_swap

HEADER 		=	include/push_swap.h

LIBFTDIR 	=	libft

LIBFT 		=	$(LIBFTDIR)/libft.a

CHECKDIR	=	checker

CHECKER		=	$(CHECKDIR)/checker

INCLUDES 	=	-I include -I $(LIBFTDIR)

SRCS 		=	main.c						\
				validate/validate_int.c 	\
				validate/validate_2.c		\
				sorting/arr_sorted.c		\
				sorting/sorted.c			\
				sorting/small_one.c			\
				sorting/speed_func.c		\
				sorting/small_two.c			\
				sorting/sort_func_two.c		\
				sorting/sort_func_tree.c	\
				service_func/init_list.c	\
				push_swap_func/func2.c		\
				push_swap_func/func.c


OBJS 		=	$(SRCS:c=o)

RM 			=	rm -f

CC 			=	gcc

CFLAGS 		=	-Wall -Wextra -Werror $(INCLUDES)

LFLAGS 		=	-lft -L $(LIBFTDIR)

%.o:		%.c ${HEADER}
			${CC} ${CFLAGS} -c -o $@ $<

all: 		$(NAME)

$(LIBFT):
			make -C $(LIBFTDIR)
			make bonus -C $(LIBFTDIR)

$(CHECKER):
			make -C $(CHECKDIR)

$(NAME): 	$(OBJS) $(HEADER) $(LIBFT) $(CHECKER)
			$(CC) $(OBJS) -o $(NAME) $(LFLAGS)

clean:
			make clean -C $(CHECKDIR)
			make clean -C $(LIBFTDIR)
			$(RM) $(OBJS)

fclean:		clean
			make fclean -C $(CHECKDIR)
			make fclean -C $(LIBFTDIR)
			$(RM) $(NAME)

re:			fclean all