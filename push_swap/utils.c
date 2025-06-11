#include "push_swap.h"

void	return_error(int state, ...)
{
	t_list	**list;

	list = ft_alloc_list();
	if (state == 1)
		write(1, "Error\n", 5);
	else if (state == 2)
		write(1, "Allocation Error\n", 17);
	else if (state == 3)
		write(1, "Not enough arguments\n", 21);
	else if (state == 4)
		write(1, "Duplicate Number\n", 17);
	else if (state == 5)
		write(1, "Tried to pop empty stack\n", 25);
	ft_lstclear(list, &ft_delete);
	free(list);
	exit(1);
}
