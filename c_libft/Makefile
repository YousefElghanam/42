NAME = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SOURCES_ALL = $(wildcard *.c)

SOURCES = $(filter-out %_bonus.c, $(SOURCES_ALL))

BONUS_SOURCES = $(filter %_bonus.c, $(SOURCES_ALL))

SOURCES_USED = $(SOURCES)

OBJECTS = $(SOURCES_USED:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)
	make clean

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

bonus: SOURCES_USED = $(SOURCES_ALL)
bonus: clean $(NAME)

.PHONY: all clean fclean re bonus