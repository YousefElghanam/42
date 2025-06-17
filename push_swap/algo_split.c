/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jel-ghna <jel-ghna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 12:16:39 by jel-ghna          #+#    #+#             */
/*   Updated: 2025/06/15 12:16:41 by jel-ghna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	splt_b(t_stack *stk_a, t_stack *stk_b, size_t *len, size_t *n)
{
	size_t	i;
	t_list	**sq;
	t_stack	*sorted;
	t_list	*last_seq;

	i = 0;
	sq = sequence_list();
	sorted = mk_sorted_stack(b_splt_start(stk_b, ft_lstlast(*sq)->content));
	last_seq = ft_lstlast(*sq);
	while (i++ < *len)
	{
		if (is_top_half(sorted->head, stk_b->top))
		{
			pa(stk_a, stk_b);
			*(size_t *)last_seq->content -= 1;
			if (*len > 25)
				ra_edge_num(stk_a, sorted);
		}
		else
		{
			*n += 1;
			rb(stk_b, 1);
		}
	}
}

void	split_b(t_stack *stk_a, t_stack *stk_b, t_list **seq_list)
{
	size_t	len;
	int		reverse;
	size_t	rev_count;

	reverse = 0;
	rev_count = 0;
	len = *(size_t *)ft_lstlast(*seq_list)->content;
	if (len != stk_b->size)
		reverse = 1;
	splt_b(stk_a, stk_b, &len, &rev_count);
	if (len > 25)
		rra(stk_a, 1);
	if (reverse)
		while (rev_count--)
			rrb(stk_b, 1);
}

void	splt_a(t_stack *stk_a, t_stack *stk_b, t_node *starting_node)
{
	size_t	i;
	size_t	len;
	t_stack	*sorted;
	int		reverse;

	reverse = 0;
	i = 0;
	len = len_from_here(starting_node);
	sorted = mk_sorted_stack(starting_node);
	if (len != stk_a->size)
		reverse = 1;
	while (i++ < len)
	{
		if (!is_top_half(sorted->head, stk_a->top))
		{
			pb(stk_a, stk_b);
			if (len > 6)
				rb_edge_num(stk_b, sorted);
		}
		else
			ra(stk_a, 1);
	}
	if (len > 6)
		rrb(stk_b, 1);
	fix_a(stk_a, len, reverse);
}

void	split_a(t_stack *stk_a, t_stack *stk_b, t_stack *stk_s, t_node *start)
{
	t_list	**seq_list;
	t_node	*prev_seq_last;
	t_node	*prev;
	int		from_head;

	seq_list = sequence_list();
	from_head = 0;
	if (start && start->prev)
		prev = start->prev;
	if (start && !start->prev)
		from_head = 1;
	while (start && len_from_here(start) > 3)
	{
		prev_seq_last = stk_b->top;
		splt_a(stk_a, stk_b, start);
		if (from_head)
			start = stk_a->head;
		else
			start = prev->next;
		add_seq(seq_list, stk_b, prev_seq_last);
	}
	sort(stk_a, stk_b, stk_s, *((size_t *)ft_lstlast(*seq_list)->content));
	delete_seq(seq_list);
}
