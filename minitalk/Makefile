SRCC		=	client.c \
				utils.c

NAMEC		=	client

SRCS		=	server.c \
				utils.c

NAMES		=	server

OBJS		=	$(SRCS:c=o)

OBJC		=	$(SRCC:c=o)

LIBFTDIR 	=	libft

LIBFT 		=	$(LIBFTDIR)/libft.a

INCLUDES 	=	-I $(LIBFTDIR)

HEADER		=	minitalk.h

RM			=	rm -f

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror $(INCLUDES)

LFLAGS 		=	-lft -L $(LIBFTDIR)

%.o:		%.c $(HEADER)
			$(CC) $(CFLAGS) -c -o $@ $<

all:		$(NAMEC) $(NAMES)

$(LIBFT):
			make -C $(LIBFTDIR)
			make bonus -C $(LIBFTDIR)

$(NAMEC):	$(OBJC) $(HEADER) $(LIBFT)
			$(CC) $(OBJC) -o $(NAMEC) $(LFLAGS)

$(NAMES):	$(OBJS) $(HEADER) $(LIBFT)
			$(CC) $(OBJS) -o $(NAMES) $(LFLAGS)

clean:
			make clean -C $(LIBFTDIR)
			$(RM) $(OBJC)
			$(RM) $(OBJS)

fclean:		clean
			make fclean -C $(LIBFTDIR)
			$(RM) $(NAMEC)
			$(RM) $(NAMES)

re:			fclean all