LIBFT = ./libft/libft.a

MLX = libmlx.dylib

NAME = cub3D

SRCS = ft_errors.c \
		ft_pars.c \
		ft_struct.c \
		ft_pars_res.c \
		ft_pars_text.c \
		ft_pars_color.c \
		ft_pars_map.c \
		ft_pars_utils.c \
		ft_raycasting.c \
		ft_hooks.c \
		ft_raycasting_init.c \
	

CC = gcc

FLAGS = -c -Wall -Wextra -Werror 

INCLUDE = cub3d.h minilibx/mlx.h

OBJS = $(SRCS:.c=.o)

%.o: %.c $(INCLUDE)
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	$(MAKE) -C ./minilibx
	cp libft/libft.a .
	cp minilibx/libmlx.dylib .
	$(CC) -o $(NAME) $(SRCS) $(LIBFT) $(MLX)

all : $(NAME)

clean :
	$(MAKE) clean -C ./libft 
	rm -rf *.o

fclean : clean
	$(MAKE) fclean -C ./libft
	$(MAKE) clean -C ./minilibx
	rm -rf *.o
	rm -rf *.a
	rm -rf cub3D

re : fclean all

.PHONY: clean fclean re all