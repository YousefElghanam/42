/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jel-ghna <jel-ghna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 12:21:28 by jel-ghna          #+#    #+#             */
/*   Updated: 2025/06/15 12:42:52 by jel-ghna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solve(t_stack *stack_a, t_stack *stack_b, t_stack *stack_s)
{
	t_list	**seq_list;
	t_node	*a_top;

	if (stack_a->size == 3 || stack_a->size == 2)
	{
		sort_a_top(stack_a, stack_b);
		return ;
	}
	seq_list = sequence_list();
	if (!seq_list)
		return_error(1);
	*seq_list = NULL;
	split_a(stack_a, stack_b, stack_s, stack_a->head);
	while (stack_b->size)
	{
		a_top = stack_a->top;
		if (*(size_t *)ft_lstlast(*seq_list)->content > 3)
			split_b(stack_a, stack_b, seq_list);
		split_a(stack_a, stack_b, stack_s, a_top->next);
	}
}
