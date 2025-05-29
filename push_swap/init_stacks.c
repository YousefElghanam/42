#include "push_swap.h"

t_stack	*init_stack_a(size_t n_count, char **argv)
{
	size_t	i;
	t_stack	*stack;
	t_node	*node;

	i = 0;
	stack = ft_malloc(sizeof(t_stack));
	if (!stack)
		return_error(2);
	stack->head = NULL;
	stack->top = NULL;
	stack->size = 0;
	while (i < n_count)
	{
		node = new_node(ft_atoi(argv[n_count - i]), 0);
		push_node(node, stack);
		i++;
	}
	return (stack);
}

t_stack	*init_stack_b(void)
{
	t_stack	*stack;

	stack = ft_malloc(sizeof(t_stack));
	if (!stack)
		return_error(2);
	stack->head = NULL;
	stack->top = NULL;
	stack->size = 0;
	return (stack);
}

t_stack	*init_sorted_stack(t_stack *stack)
{
	int		*arr;

	arr = ft_malloc(sizeof(int) * stack->size);
	if (!arr)
		return_error(2);
	fill_arr(arr, stack);
	sort_arr(arr, stack->size);
	return (arr_to_stack(arr, stack->size));
}
