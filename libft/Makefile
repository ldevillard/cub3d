NAME = libft.a
HEADER = libft.h
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCS = libft.h
LIBC = ar rc
LIBI = ranlib
SRCS = ft_memset.c \
ft_bzero.c \
ft_memccpy.c \
ft_memcpy.c \
ft_memmove.c \
ft_memchr.c \
ft_strlen.c \
ft_memcmp.c \
ft_strdup.c \
ft_strlcpy.c \
ft_isalpha.c \
ft_isdigit.c \
ft_isalnum.c \
ft_isascii.c \
ft_isprint.c \
ft_toupper.c \
ft_tolower.c \
ft_strchr.c \
ft_strrchr.c \
ft_strncmp.c \
ft_strnstr.c \
ft_atoi.c \
ft_calloc.c \
ft_strlcat.c \
ft_substr.c \
ft_strjoin.c \
ft_putchar_fd.c \
ft_putstr_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c \
ft_itoa.c \
ft_strrev.c \
ft_strmapi.c \
ft_strtrim.c \
ft_ccheck.c \
ft_split.c \
ft_swap.c \
ft_putchar.c \
ft_putstr.c \
ft_putnbr.c \
ft_u_itoa.c \
get_next_line.c \
ft_itoa_base.c

OBJS = $(SRCS:.c=.o)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I$(INCS)

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	$(LIBC) $(NAME) $(OBJS)
	$(LIBI) $(NAME)

re: fclean all

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

.PHONY: clean fclean re all
