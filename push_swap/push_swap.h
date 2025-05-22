#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include "libft/libft.h"

typedef struct s_set
{
	size_t	capacity;
	size_t	cur_size;
	int		*arr;
}	t_set;

void	kill_everything(t_set *set, int state);
void	validate_args(size_t argc, char **argv);

void	init_set(t_set *set, size_t arg_count);
int		in_set(t_set *set, int num);
void	add_to_set(t_set *set, int num);

#endif
