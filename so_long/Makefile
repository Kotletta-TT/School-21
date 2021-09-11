NAME		=	so_long

INCLUDE_DIR	=	includes

HEADER		=	$(INCLUDE_DIR)/so_long.h

SRC_DIR		=	src/so_long

SRCS		=	main.c			\
				loads.c			\
				builds.c		\
				game.c			\
				service_func.c	\
				validate.c		\
				validate_func.c	\
				parserx_map.c

OBJS_DIR	=	objects/so_long/

MLX_FLAGS	=	-framework OpenGL -framework AppKit -lmlx

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror

RM			=	rm -f

OBJS		=	$(addprefix $(OBJS_DIR), $(SRCS:c=o))

LIBFT_DIR	=	src/libft

LIBFT		=	libft.a

GNL_DIR		=	src/gnl

GNL			=	libgnl.a

MLX_DIR		=	src/mlx

MLX			=	libmlx.a


$(OBJS_DIR)%.o:		%.c $(HEADER)
					@mkdir -p $(@D)
					@$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDE_DIR)

all:				$(NAME)

$(GNL):
					@make -C $(GNL_DIR)

$(LIBFT):
					@make -C $(LIBFT_DIR)


$(MLX):
					@make -C $(MLX_DIR)

$(NAME):			$(OBJS) $(HEADER) $(GNL) $(LIBFT) $(MLX)
					@$(CC) $(OBJS) -I $(INCLUDE_DIR) $(MLX_FLAGS) -lmlx -lft -lgnl -L. -o $(NAME)

clean:
					@make clean -C $(LIBFT_DIR)
					@make clean -C $(GNL_DIR)
					@make clean -C $(MLX_DIR)
					@$(RM) $(OBJS)

fclean: 			clean
					@make fclean -C $(LIBFT_DIR)
					@make fclean -C $(GNL_DIR)
					@$(RM) $(NAME)

re: 				clean all

.PHONY: 			all clean fclean re