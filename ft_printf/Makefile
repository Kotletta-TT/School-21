NAME 			=	libftprintf.a

SRC_DIR			=	src/
HEAD_DIR		=	includes/

HEADER			=	$(HEAD_DIR)ft_printf.h

SRC				=	$(SRC_DIR)print/ft_print_format.c		\
					$(SRC_DIR)print/p_c.c					\
					$(SRC_DIR)print/p_cc.c					\
					$(SRC_DIR)print/p_d_i.c					\
					$(SRC_DIR)print/treat_d_i.c				\
					$(SRC_DIR)print/treat_x_X.c				\
					$(SRC_DIR)print/treat_u.c				\
					$(SRC_DIR)print/treat_p.c				\
					$(SRC_DIR)print/p_p.c					\
					$(SRC_DIR)print/p_s.c					\
					$(SRC_DIR)print/p_u.c					\
					$(SRC_DIR)print/p_x_X.c					\
					$(SRC_DIR)parser/ft_format_parser.c		\
					$(SRC_DIR)parser/parse_minus.c			\
					$(SRC_DIR)parser/parse_point.c			\
					$(SRC_DIR)parser/parse_precision.c		\
					$(SRC_DIR)parser/parse_star.c			\
					$(SRC_DIR)parser/parse_width.c			\
					$(SRC_DIR)parser/parse_zero.c			\
					$(SRC_DIR)ft_isdigit.c					\
					$(SRC_DIR)ft_putchar_fd.c				\
					$(SRC_DIR)ft_putnbr_fd.c				\
					$(SRC_DIR)ft_strchr.c					\
					$(SRC_DIR)ft_strlen.c					\
					$(SRC_DIR)ft_printf.c

CC				=	GCC
CFLAGS			=	-Wall -Wextra -Werror
AR				=	ar rcs
RM				=	rm -f

OBJS			=	$(SRC:.c=.o)

%.o				:	%.c $(HEADER)
					$(CC) $(CFLAGS) -c -o $@ $<

$(NAME)			:	$(OBJS)
					$(AR) $@ $?

all				:	$(NAME)

clean			:
					$(RM) $(OBJS)

fclean			:	clean
					$(RM) $(NAME)

re				:	clean all

.PHONY:		all clean fclean re