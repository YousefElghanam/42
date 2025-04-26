#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_str_list
{
	char				*str;
	struct s_str_list	*next;
}	t_str_list;

void		lstclear(t_str_list **lst);
int			lstadd_back(t_str_list **lst, t_str_list *new);
t_str_list	*lst_new(char *str);

char	*get_next_line(int fd);

#endif