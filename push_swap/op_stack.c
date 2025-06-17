/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jel-ghna <jel-ghna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 12:18:16 by jel-ghna          #+#    #+#             */
/*   Updated: 2025/06/15 12:18:17 by jel-ghna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_op_name(t_node *node)
{
	if (node->num == 0)
		ft_printf("sa\n");
	if (node->num == 1)
		ft_printf("sb\n");
	if (node->num == 2)
		ft_printf("ss\n");
	if (node->num == 3)
		ft_printf("pa\n");
	if (node->num == 4)
		ft_printf("pb\n");
	if (node->num == 5)
		ft_printf("ra\n");
	if (node->num == 6)
		ft_printf("rb\n");
	if (node->num == 7)
		ft_printf("rr\n");
	if (node->num == 8)
		ft_printf("rra\n");
	if (node->num == 9)
		ft_printf("rrb\n");
	if (node->num == 10)
		ft_printf("rrr\n");
}

static void	push_op_node(t_node *node, t_stack *stack)
{
	if (stack->size == 0)
		stack->head = node;
	else
	{
		node->prev = stack->top;
		stack->top->next = node;
	}
	stack->top = node;
	stack->size += 1;
	while (can_cancel(stack->top))
		cancel(stack, can_cancel(stack->top));
}

t_stack	*op_stack(void)
{
	static t_stack	*ptr;

	if (ptr == NULL)
	{
		ptr = ft_malloc(sizeof(t_stack));
		if (!ptr)
			return_error(1);
		ptr->size = 0;
		ptr->head = NULL;
		ptr->top = NULL;
	}
	return (ptr);
}

void	print_ops(t_node *node)
{
	while (node)
	{
		print_op_name(node);
		node = node->next;
	}
}

void	add_op(int op)
{
	if (op == -1)
		push_op_node(new_node(-1), op_stack());
	else if (op == 0)
		push_op_node(new_node(0), op_stack());
	else if (op == 1)
		push_op_node(new_node(1), op_stack());
	else if (op == 2)
		push_op_node(new_node(2), op_stack());
	else if (op == 3)
		push_op_node(new_node(3), op_stack());
	else if (op == 4)
		push_op_node(new_node(4), op_stack());
	else if (op == 5)
		push_op_node(new_node(5), op_stack());
	else if (op == 6)
		push_op_node(new_node(6), op_stack());
	else if (op == 7)
		push_op_node(new_node(7), op_stack());
	else if (op == 8)
		push_op_node(new_node(8), op_stack());
	else if (op == 9)
		push_op_node(new_node(9), op_stack());
	else if (op == 10)
		push_op_node(new_node(10), op_stack());
}
