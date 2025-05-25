#include "push_swap.h"

// static	void	swap_nodes(t_node *node_1, t_node *node_2)
// {
// 	t_node	*tmp;

// 	tmp = node_2->next;
// 	node_2->prev = node_1->prev;
// 	node_2->next = node_1;
// 	node_1->prev = node_1;
// 	node_1->next = tmp;
// }

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*stack_goal;
	t_node	*node;
	size_t	i;

	i = 0;
	if (!ft_alloc_list() || argc < 2)
		return_error(3);
	validate_args((size_t)argc, argv);
	stack_a = init_stack_a((size_t)argc - 1, argv);
	stack_b = init_stack_b();
	stack_goal = init_sorted_stack(stack_a);

	node = stack_goal->head;
	ft_putstr_fd("sorted stack: ", 1);
	while (i++ < stack_goal->size)
	{
		ft_putnbr_fd(node->num, 1);
		ft_putstr_fd(" ", 1);
		node = node->next;
	}
	pa(stack_a, stack_b);
	i = 0;
	node = stack_a->head;
	ft_putstr_fd("\nstack_a:      ", 1);
	while (i++ < stack_a->size)
	{
		ft_putnbr_fd(node->num, 1);
		ft_putstr_fd(" ", 1);
		node = node->next;
	}
	i = 0;
	node = stack_b->head;
	ft_putstr_fd("\nstack_b:      ", 1);
	while (i++ < stack_b->size)
	{
		ft_putnbr_fd(node->num, 1);
		ft_putstr_fd(" ", 1);
		node = node->next;
	}
	ft_lstclear(ft_alloc_list(), &ft_delete);
	free(ft_alloc_list());
	// solve(stack_a, stack_b, stack_goal);
}

// Make a "score" variable that has how many nodes are in their correct
// position relative to the number of all nodes

// maybe save that variable in the stack struct
// sorted: 			1  3  5  9  12  20
// currnt: 			1  9  12 3  5   20
// state:			two out of five are in correct position
// score(1-100) :   (2 * 100) / 5 = 40 %
// depending on score we can use different algorithms
// keep in mind that also the position of each correct node matters
