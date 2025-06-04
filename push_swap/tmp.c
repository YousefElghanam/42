void	split_a(t_stack *stack_a, t_stack *stack_b, t_node *starting_node)
{
	size_t	len;
	size_t	i;
	t_stack	*sorted;
	// int		reverse;

	// reverse = 0;
	len = len_from_here(starting_node);
	ft_printf("\n>%d<\n", len);
	i = 0;
	sorted = mk_sorted_stack(starting_node);
	// if (len != stack_a->size)
	// 	reverse = 1;
	while (i++ < len) // can make it stop doing "ra" if no more left (but still keep track of how many "ra" we did if we need to "rra" back)
	{
		if (!is_top_half(sorted->head ,stack_a->top))
			pb(stack_a, stack_b);
		else
			ra(stack_a, 1);
	}
	// if (reverse) // if stopped prev while loop before checking all, make sure you dont do more "rra" than necessary (change len)
	// {
	// 	len = (len % 2 != 0) + (len / 2);
	// 	while (len--)
	// 		rra(stack_a, 1);
	// }
}

void	split_b(t_stack *stack_a, t_stack *stack_b, t_stack *stack_s)
{
	
}

void	recurse_solve(t_stack *stack_a, t_stack *stack_b, t_stack *stack_s)
{
	if (stack_state(stack_a) == 1)
		return (1);
	if (stack_state(stack_a) == 4)
	{
		split_a(stack_a, stack_b, stack_a->head);
		recurse_solve(stack_a, stack_b, stack_s);
	}
	if (stack_state(stack_a) == 3)
		swap_and_pa()
}

void	solve(t_stack *stack_a, t_stack *stack_b, t_stack *stack_s)
{
	recurse_solve(stack_a, stack_b, stack_s);
}