#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include "../libft/libft.h"

typedef struct	s_node
{
	char			*str;
	size_t			size;
	struct s_node	*next;
} t_node;

typedef struct	s_list
{
	t_node	*head;
	t_node	*tail;
	size_t	size;
} t_list;

int		is_valid_spec(char c);
t_list	*init_list(void);
t_node	*new_node(char *str, size_t size);
int		add_node(t_list *list, t_node *node);
void	clear_list(t_list *list);
ssize_t	count_specs(char *format);
int		handle_spec_arg_counts(const char *format, va_list args);