/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_split_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jel-ghna <jel-ghna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 12:16:45 by jel-ghna          #+#    #+#             */
/*   Updated: 2025/06/15 21:40:56 by jel-ghna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*b_splt_start(t_stack *stack_b, size_t *seq_len)
{
	size_t	i;
	t_node	*node;

	i = 1;
	node = stack_b->top;
	while (i++ < *seq_len)
		node = node->prev;
	return (node);
}

void	fix_a(t_stack *stack_a, size_t len, int reverse)
{
	if (reverse)
	{
		len = (len % 2 != 0) + (len / 2);
		while (len-- > 0)
			rra(stack_a, 1);
	}
}

void	ra_edge_num(t_stack *stack_a, t_stack *sorted)
{
	size_t	sorted_size;
	t_node	*node;

	sorted_size = 0;
	node = sorted->head;
	while (node)
	{
		node = node->next;
		sorted_size++;
	}
	sorted_size /= 2;
	node = sorted->head;
	while (sorted_size-- && node)
		node = node->next;
	if (stack_a && stack_a->top && node && node->prev
		&& stack_a->top->num == node->prev->num)
		ra(stack_a, 1);
}

void	rb_edge_num(t_stack *stack_b, t_stack *sorted)
{
	size_t	sorted_size;
	t_node	*node;

	sorted_size = 0;
	node = sorted->head;
	while (node)
	{
		node = node->next;
		sorted_size++;
	}
	sorted_size /= 2;
	node = sorted->head;
	while (sorted_size-- && node)
		node = node->next;
	if (stack_b && stack_b->top && node && node->next
		&& stack_b->top->num == node->next->num)
		rb(stack_b, 1);
}
