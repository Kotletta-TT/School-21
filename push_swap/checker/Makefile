NAME		=	checker

GNL_DIR		=	../get_next_line

LIBFTDIR 	=	../libft

LIBFT 		=	$(LIBFTDIR)/libft.a

INCLUDES 	=	-I $(LIBFTDIR) -I $(GNL_DIR)

SRC			=	check.c								\
				arr_sorted.c						\
				func.c								\
				func2.c								\
				init_list.c							\
				sorted.c							\
				validate_2.c						\
				validate_int.c						\
				$(GNL_DIR)/get_next_line.c			\
				$(GNL_DIR)/get_next_line_utils.c

HEADER		=	checker.h							\
				$(GNL_DIR)/get_next_line.h

OBJS		=	$(SRC:c=o)

RM			=	rm -f

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror $(INCLUDES)

LFLAGS 		=	-lft -L $(LIBFTDIR)

%.o			:	%.c ${HEADER}
				${CC} ${CFLAGS} -c -o $@ $<

all			:	$(NAME)

$(NAME)		:	$(OBJS) $(HEADER) $(LIBFT)
				$(CC) $(OBJS) -o $(NAME) $(LFLAGS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

