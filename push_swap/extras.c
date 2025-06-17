#include "push_swap.h"

void	print_sorted(t_stack *stack)
{
	t_node *node = stack->head;
	ft_printf("sorted	:	");
	while (node)
	{
		ft_putnbr_fd(node->num, 1);
		ft_printf("	");
		node = node->next;
	}
	node = stack->head;
	while (node)
	{
		ft_printf("	");
		node = node->next;
	}
	ft_printf("\n");
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
	ft_printf("\n");
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
