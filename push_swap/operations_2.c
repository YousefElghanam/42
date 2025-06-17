/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jel-ghna <jel-ghna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 12:22:59 by jel-ghna          #+#    #+#             */
/*   Updated: 2025/06/15 12:43:37 by jel-ghna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*pop(t_stack *stack)
{
	t_node	*node;

	if (stack->size == 0)
		return_error(1);
	node = stack->top;
	stack->top = node->prev;
	if (stack->size == 1)
		stack->head = NULL;
	else
		node->prev->next = NULL;
	node->next = NULL;
	node->prev = NULL;
	stack->size -= 1;
	return (node);
}

void	push(t_node *node, t_stack *stack)
{
	if (stack->size == 0)
	{
		stack->head = node;
		stack->top = node;
	}
	else
	{
		stack->top->next = node;
		node->prev = stack->top;
		stack->top = node;
	}
	stack->size += 1;
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node;

	if (stack_b->size == 0)
	{
		add_op(-1);
		return ;
	}
	add_op(3);
	node = pop(stack_b);
	push(node, stack_a);
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node;

	if (stack_a->size == 0)
	{
		add_op(-1);
		return ;
	}
	add_op(4);
	node = pop(stack_a);
	push(node, stack_b);
}
