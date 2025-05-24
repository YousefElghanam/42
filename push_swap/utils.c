#include "push_swap.h"

void	return_error(int state)
{
	t_list	*list;

	list = ft_alloc_list();
	if (state == 1)
		write(1, "Error\n", 5);
	else if (state == 2)
		write(1, "Allocation Error\n", 17);
	ft_lstclear(&list, &ft_delete);
	exit(1);
}
