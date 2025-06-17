/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_seq.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jel-ghna <jel-ghna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 12:16:53 by jel-ghna          #+#    #+#             */
/*   Updated: 2025/06/15 12:42:52 by jel-ghna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	**sequence_list(void)
{
	static t_list	**ptr;

	if (!ptr)
	{
		ptr = ft_malloc(sizeof(t_list *));
		if (!ptr)
			return_error(1);
		*ptr = NULL;
	}
	return (ptr);
}

void	add_seq(t_list **seq_list, t_stack *stack_b, t_node *prev_seq_end)
{
	size_t	*len;
	t_list	*node;

	len = ft_malloc(sizeof(size_t));
	if (!len)
		return_error(1);
	if (prev_seq_end)
		*len = len_from_here(prev_seq_end->next);
	else
		*len = len_from_here(stack_b->head);
	node = ft_lstnew_ft_malloc(len);
	if (!node)
		return_error(1);
	ft_lstadd_back(seq_list, node);
}

void	delete_seq(t_list **seq_list)
{
	size_t	list_len;
	t_list	*prev;
	t_list	*node;

	list_len = 0;
	prev = NULL;
	node = *seq_list;
	while (node && node->next)
	{
		list_len++;
		prev = node;
		node = node->next;
	}
	if (prev)
		prev->next = NULL;
	else
		*seq_list = NULL;
}
