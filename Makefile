NAME = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SOURCES = $(wildcard *.c)

BASE_SOURCES = $(filter-out %_bonus.c, $(SOURCES))

BONUS_SOURCES = $(filter %_bonus.c, $(SOURCES))

BASE_OBJECTS = $(BASE_SOURCES:.c=.o)

BONUS_OBJECTS = $(BONUS_SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(BASE_OBJECTS)
	ar rcs $(NAME) $(BASE_OBJECTS)

bonus: $(NAME) $(BONUS_OBJECTS)
	ar rcs $(NAME) $(BONUS_OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(BASE_OBJECTS) $(BONUS_OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all


.PHONY: all clean fclean re bonus