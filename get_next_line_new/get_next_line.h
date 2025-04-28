#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdint.h>

typedef struct s_chunk
{
	char				*chunk;
	size_t				size;
	struct s_chunk		*next;
}	t_chunk;

char		*get_next_line(int fd);
t_chunk		*lst_new(char *str, size_t bytes_read);
int			lstadd_back(t_chunk **lst, t_chunk *new);
void		lstclear(t_chunk **lst);
void		*ft_memcpy(void *dest, const void *src, size_t n);

#endif