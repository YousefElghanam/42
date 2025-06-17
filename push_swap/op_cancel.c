/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_cancel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jel-ghna <jel-ghna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 12:18:10 by jel-ghna          #+#    #+#             */
/*   Updated: 2025/06/15 12:18:11 by jel-ghna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	can_rev_cancel(t_node *top)
{
	t_node	*prev;

	prev = top->prev;
	if (top->num == 2 && prev->num == 0)
		return (1);
	if (top->num == 2 && prev->num == 1)
		return (2);
	if (top->num == 10 && prev->num == 5)
		return (3);
	if (top->num == 10 && prev->num == 6)
		return (4);
	if (top->num == 7 && prev->num == 8)
		return (5);
	if (top->num == 7 && prev->num == 9)
		return (6);
	return (0);
}

static void	rev_cancel(t_stack *stack, int state)
{
	pop(stack);
	pop(stack);
	if (state == 1)
		add_op(1);
	if (state == 2)
		add_op(2);
	if (state == 3)
		add_op(9);
	if (state == 4)
		add_op(8);
	if (state == 5)
		add_op(6);
	if (state == 6)
		add_op(5);
}

int	can_cancel(t_node *top)
{
	t_node	*prev;

	if (!top || !top->prev)
		return (0);
	prev = top->prev;
	if (top->num == -1)
		return (1);
	if ((top->num == 0 && prev->num == 1) || (top->num == 1 && prev->num == 0))
		return (2);
	if ((top->num == 0 && prev->num == 0) || (top->num == 1 && prev->num == 1))
		return (3);
	if ((top->num == 3 && prev->num == 4) || (top->num == 4 && prev->num == 3))
		return (4);
	if ((top->num == 5 && prev->num == 8) || (top->num == 8 && prev->num == 5))
		return (5);
	if ((top->num == 6 && prev->num == 9) || (top->num == 9 && prev->num == 6))
		return (6);
	if ((top->num == 5 && prev->num == 6) || (top->num == 6 && prev->num == 5))
		return (7);
	if ((top->num == 8 && prev->num == 9) || (top->num == 9 && prev->num == 8))
		return (8);
	return (0);
}

void	cancel(t_stack *stack, int state)
{
	pop(stack);
	if (state == 1)
		return ;
	pop(stack);
	if (state == 2)
		add_op(2);
	else if (state == 7)
		add_op(7);
	else if (state == 8)
		add_op(10);
	if (stack->top && can_rev_cancel(stack->top))
		rev_cancel(stack, can_rev_cancel(stack->top));
}
