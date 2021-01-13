LIBFT = ./libft/libft.a

NAME = cub3D

SRCS = ft_errors.c \
		ft_pars.c \
		ft_struct.c \
		ft_pars_res.c

CC = gcc

FLAGS = -c -Wall -Wextra -Werror

INCLUDE = cub3d.h

OBJS = $(SRCS:.c=.o)

%.o: %.c $(INCLUDE)
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	cp libft/libft.a .
	$(CC) -o $(NAME) $(SRCS) $(LIBFT)

all : $(NAME)

clean :
	$(MAKE) clean -C ./libft 
	rm -rf *.o

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -rf *.o
	rm -rf *.a
	rm -rf cub3D

re : fclean all

.PHONY: clean fclean re all