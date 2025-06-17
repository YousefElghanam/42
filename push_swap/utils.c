/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jel-ghna <jel-ghna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 12:19:09 by jel-ghna          #+#    #+#             */
/*   Updated: 2025/06/15 21:30:49 by jel-ghna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	len_from_here(t_node *starting_node)
{
	size_t	len;
	t_node	*node;

	len = 0;
	node = starting_node;
	while (node)
	{
		len++;
		node = node->next;
	}
	return (len);
}

t_stack	*mk_sorted_stack(t_node *starting_node)
{
	size_t	i;
	size_t	len;
	t_node	*node;
	int		*arr;

	i = 0;
	len = len_from_here(starting_node);
	node = starting_node;
	arr = ft_malloc(sizeof(int) * len);
	if (!arr)
		return_error(1);
	while (i < len)
	{
		arr[i] = node->num;
		node = node->next;
		i++;
	}
	sort_arr(arr, len);
	return (arr_to_stack(arr, len));
}

int	is_top_half(t_node *starting_node, t_node *target_node)
{
	size_t	mid_len;
	t_node	*node;

	mid_len = len_from_here(starting_node);
	mid_len = (mid_len % 2 != 0) + (mid_len / 2);
	node = starting_node;
	while (mid_len--)
	{
		if (target_node->num == node->num)
			return (1);
		node = node->next;
	}
	return (0);
}

size_t	unsorted_in_a(t_stack *stack_a, t_stack *stack_s)
{
	t_node	*node_a;
	t_node	*node_s;
	size_t	i;

	node_a = stack_a->head;
	node_s = stack_s->head;
	i = 0;
	while (node_a)
	{
		if (node_a->num != node_s->num)
			return (len_from_here(node_a));
		node_a = node_a->next;
		node_s = node_s->next;
	}
	return (i);
}
