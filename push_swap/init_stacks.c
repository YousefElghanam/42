/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jel-ghna <jel-ghna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 12:21:37 by jel-ghna          #+#    #+#             */
/*   Updated: 2025/06/17 17:00:18 by jel-ghna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack_a(int n_count, char **argv)
{
	int		i;
	t_stack	*stack;
	t_node	*node;

	i = 0;
	stack = ft_malloc(sizeof(t_stack));
	if (!stack)
		return_error(1);
	stack->head = NULL;
	stack->top = NULL;
	stack->size = 0;
	while (i < n_count)
	{
		node = new_node(ft_atoi(argv[n_count - i - 1]));
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
		return_error(1);
	stack->head = NULL;
	stack->top = NULL;
	stack->size = 0;
	return (stack);
}

t_stack	*init_stack_sorted(t_stack *stack)
{
	int		*arr;

	arr = ft_malloc(sizeof(int) * stack->size);
	if (!arr)
		return_error(1);
	fill_arr(arr, stack);
	sort_arr(arr, stack->size);
	return (arr_to_stack(arr, stack->size));
}
