#include "push_swap.h"

void	print_sorted(t_stack *stack)
{
	t_node *node = stack->head;
	ft_printf("\nsorted	:	");
	while (node)
	{
		ft_putnbr_fd(node->num, 1);
		ft_printf("	");
		node = node->next;
	}
	ft_printf("\npositions:	");
	node = stack->head;
	while (node)
	{
		ft_putnbr_fd(node->position, 1);
		ft_printf("	");
		node = node->next;
	}
}

void	print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node;

	ft_printf("\nstack A (%d)(head:%d)(top:%d):	", stack_a->size, stack_a->head->num, stack_a->top->num);
	node = stack_a->head;
	while (node)
	{
		ft_putnbr_fd(node->num, 1);
		ft_printf("	");
		node = node->next;
	}
	if (stack_b->head && stack_b->top)
		ft_printf("\nstack B (%d)(head:%d)(top:%d):	", stack_b->size, stack_b->head->num, stack_b->top->num);
	else
		ft_printf("\nstack B (%d)(head:%p)(top:%p):	", stack_b->size, NULL, NULL);
	node = stack_b->head;
	while (node)
	{
		ft_putnbr_fd(node->num, 1);
		ft_printf("	");
		node = node->next;
	}
	ft_printf("\n", 1);
}

void	input_operations(t_stack *stack_a, t_stack *stack_b)
{
	char	*input = NULL;
	int flag = 1;
	while (input || flag)
	{
		flag = 0;
		input = get_next_line(0);
		ft_printf("\n>>input: %s\n", input);
		if (!input)
			;
		else if (!ft_strncmp(input, "sa\n", 3))
			sa(stack_a, 1);
		else if (!ft_strncmp(input, "sb\n", 3))
			sb(stack_b, 1);
		else if (!ft_strncmp(input, "ss\n", 3))
			ss(stack_a, stack_b);
		else if (!ft_strncmp(input, "pa\n", 3))
			pa(stack_a, stack_b);
		else if (!ft_strncmp(input, "pb\n", 3))
			pb(stack_a, stack_b);
		else if (!ft_strncmp(input, "ra\n", 3))
			ra(stack_a, 1);
		else if (!ft_strncmp(input, "rb\n", 3))
			rb(stack_b, 1);
		else if (!ft_strncmp(input, "rr\n", 3))
			rr(stack_a, stack_b);
		else if (!ft_strncmp(input, "rra\n", 4))
			rra(stack_a, 1);
		else if (!ft_strncmp(input, "rrb\n", 4))
			rrb(stack_b, 1);
		else if (!ft_strncmp(input, "rrr\n", 4))
			rrr(stack_a, stack_b);
		else
			ft_printf("invalid operation\n");
		print_stacks(stack_a, stack_b);
		free(input);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*stack_goal;

	if (!ft_alloc_list() || !op_stack() || argc < 2)
		return_error(3);
	parse_args(&argc, &argv);
	stack_a = init_stack_a((size_t)argc, argv);
	stack_b = init_stack_b();
	stack_goal = init_sorted_stack(stack_a);

	print_sorted(stack_goal);

	// solve(stack_a, stack_b, stack_goal);

	ft_printf("\n\n");
	print_stacks(stack_a, stack_b);
	ft_printf("\n");

	input_operations(stack_a, stack_b);

	ft_lstclear(ft_alloc_list(), &ft_delete);
	free(ft_alloc_list());
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
