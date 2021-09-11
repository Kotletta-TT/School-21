NAME		=	philo

HEADER		=	philo.h

SRC			=	main.c			\
				print_func.c	\
				service_func.c	\
				start_func.c	\
				validate.c

OBJ			=	$(SRC:c=o)

RM			=	rm -f

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror

%.o:		%.c $(HEADER)
			$(CC) $(CFLAGS) -c -o $@ $<

all:		$(NAME)

$(NAME):	$(OBJ) $(HEADER)
			$(CC) $(OBJ) -o $(NAME)

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re