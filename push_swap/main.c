#include "push_swap.h"

void	print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node;

	ft_printf("stack A (%d): ", stack_a->size);
	node = stack_a->head;
	while (node)
	{
		ft_putnbr_fd(node->num, 1);
		ft_putstr_fd(" ", 1);
		node = node->next;
	}

	ft_printf("\nstack B (%d): ", stack_b->size);
	node = stack_b->head;
	while (node)
	{
		ft_putnbr_fd(node->num, 1);
		ft_putstr_fd(" ", 1);
		node = node->next;
	}
	ft_putstr_fd("\n", 1);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*stack_goal;
	t_node	*node;

	if (!ft_alloc_list() || argc < 2)
		return_error(3);
	validate_args((size_t)argc, argv);
	stack_a = init_stack_a((size_t)argc - 1, argv);
	stack_b = init_stack_b();
	stack_goal = init_sorted_stack(stack_a);

	ft_putstr_fd("\nsorted :", 1);
	node = stack_goal->head;
	while (node)
	{
		ft_putnbr_fd(node->num, 1);
		ft_putstr_fd(" ", 1);
		node = node->next;
	}

	ft_putstr_fd("\n\n", 1);
	print_stacks(stack_a, stack_b);

	ra(stack_a);
	print_stacks(stack_a, stack_b);
	ra(stack_a);
	print_stacks(stack_a, stack_b);

	// pa(stack_a, stack_b);
	// print_stacks(stack_a, stack_b);
	// pa(stack_a, stack_b);
	// print_stacks(stack_a, stack_b);
	// sb(stack_b);
	// print_stacks(stack_a, stack_b);
	// pb(stack_a, stack_b);
	// print_stacks(stack_a, stack_b);

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
