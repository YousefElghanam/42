/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_execute_ops_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jel-ghna <jel-ghna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 14:04:13 by jel-ghna          #+#    #+#             */
/*   Updated: 2025/06/15 14:07:42 by jel-ghna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	execute_op(t_stack *stack_a, t_stack *stack_b, int op)
{
	if (op == 1)
		sa(stack_a, 0);
	else if (op == 2)
		sb(stack_b, 0);
	else if (op == 3)
		ss(stack_a, stack_b);
	else if (op == 4)
		pa(stack_a, stack_b);
	else if (op == 5)
		pb(stack_a, stack_b);
	else if (op == 6)
		ra(stack_a, 0);
	else if (op == 7)
		rb(stack_b, 0);
	else if (op == 8)
		rr(stack_a, stack_b);
	else if (op == 9)
		rra(stack_a, 0);
	else if (op == 10)
		rrb(stack_b, 0);
	else if (op == 11)
		rrr(stack_a, stack_b);
}

void	execute_ops(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node;

	node = op_stack_bonus()->head;
	while (node)
	{
		execute_op(stack_a, stack_b, node->num);
		node = node->next;
	}
}
