NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

HEADER = push_swap.h

SOURCES = main.c validate_args.c very_special_set.c ft_malloc.c init_stacks.c init_stacks_2.c utils.c

BASE_SOURCES = $(filter-out %_bonus.c, $(SOURCES))

BONUS_SOURCES = $(filter %_bonus.c, $(SOURCES))

BASE_OBJECTS = $(BASE_SOURCES:.c=.o)

BONUS_OBJECTS = $(BONUS_SOURCES:.c=.o)

LIBFT = libft/libft.a

LIBFT_SOURCES =	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
			ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c \
			ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c \
			ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
			ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c \
			ft_substr.c ft_tolower.c ft_toupper.c ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c \
			ft_lstclear_bonus.c ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c \
			ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c ft_printf.c ft_utils.c \
			ft_write_types.c ft_write_types2.c

LIBFT_OBJECTS = $(addprefix libft/,$(LIBFT_SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(LIBFT) $(BASE_SOURCES) $(HEADER)
	$(CC) $(CFLAGS) $(BASE_SOURCES) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C libft
	make clean -C libft

clean:
	rm -rf $(BASE_OBJECTS) $(BONUS_OBJECTS)
	make clean -C libft

fclean: clean
	rm -rf $(NAME) a.out
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re bonus