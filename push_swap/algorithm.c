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
		return_error(2);
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
	while (sorted_size--)
	{
		node = node->next;
	}
	if (stack_b && stack_b->top && stack_b->top->num == node->next->num)
		rb(stack_b, 1);
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
	while (sorted_size--)
	{
		node = node->next;
	}
	if (stack_a && stack_a->top && stack_a->top->num == node->prev->num)
	{
		ra(stack_a, 1);
	}
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

void	split_a(t_stack *stack_a, t_stack *stack_b, t_node *starting_node)
{
	size_t	i;
	size_t	len;
	t_stack	*sorted;
	int		reverse;

	reverse = 0;
	i = 0;
	len = len_from_here(starting_node);
	sorted = mk_sorted_stack(starting_node);
	if (len != stack_a->size)
		reverse = 1;
	while (i++ < len)
	{
		if (!is_top_half(sorted->head ,stack_a->top))
		{
			pb(stack_a, stack_b);
			if (len > 6)
				rb_edge_num(stack_b, sorted);
		}
		else
			ra(stack_a, 1);
	}
	if (len > 6)
		rrb(stack_b, 1);
	fix_a(stack_a, len, reverse);
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

t_node	*b_split_starting_node(t_stack *stack_b, size_t *seq_len)
{
	size_t	i;
	t_node	*node;

	i = 1;
	node = stack_b->top;
	while (i++ < *seq_len)
		node = node->prev;
	return (node);
}

void	split_b(t_stack *stack_a, t_stack *stack_b, t_list **seq_list)
{
	t_node	*starting_node;
	t_list	*last_seq;
	size_t	i;
	size_t	len;
	t_stack	*sorted;
	int		reverse;
	size_t	rev_count;

	last_seq = ft_lstlast(*seq_list);
	reverse = 0;
	rev_count = 0;
	starting_node = b_split_starting_node(stack_b, ft_lstlast(*seq_list)->content);
	i = 0;
	len = *(size_t *)ft_lstlast(*seq_list)->content;
	sorted = mk_sorted_stack(starting_node);
	if (len != stack_b->size)
		reverse = 1;
	// ft_printf("\nseq len is %d here\n", len);
	while (i++ < len) // can make it stop doing "ra" if no more left (but still keep track of how many "ra" we did if we need to "rra" back)
	{
		if (is_top_half(sorted->head ,stack_b->top))
		{
			pa(stack_a, stack_b);
			*(size_t *)last_seq->content -= 1;
			if (len > 25)
				ra_edge_num(stack_a, sorted);
		}
		else
		{
			rev_count++;
			rb(stack_b, 1);
		}
	}
	if (len > 25)
		rra(stack_a, 1);
	if (reverse) // if stopped prev while loop before checking all, make sure you dont do more "rra" than necessary (change len)
		while (rev_count--)
			rrb(stack_b, 1);
}

void	add_seq(t_list **seq_list, t_stack *stack_b, t_node *prev_seq_end) // leaks are possible if one of the programs other errors happend and i have a sequence allocated
{
	size_t	*len;
	t_list	*node;

	len = malloc(sizeof(size_t));
	if (!len)
	{
		ft_lstclear(seq_list, &ft_delete);
		return_error(2);
	}
	if (prev_seq_end)
		*len = len_from_here(prev_seq_end->next);
	else
		*len = len_from_here(stack_b->head);
	node = ft_lstnew(len);
	if (!node)
	{
		free(len);
		ft_lstclear(seq_list, &ft_delete);
		return_error(2);
	}
	ft_lstadd_back(seq_list, node);
}

void	print_seqs(t_list **seq_list)
{
	t_list	*node;

	node = *seq_list;
	while (node && node->content)
	{
		// ft_printf("seq: %d\n", *(size_t *)node->content);
		node = node->next;
	}
	// ft_printf("prev was sequences\n");
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
	ft_lstdelone(node, &ft_delete);
	if (prev)
		prev->next = NULL;
	else
		*seq_list = NULL;
}

void	split_a_main(t_stack *stack_a, t_stack *stack_b, t_stack *stack_s, t_node *starting_node, t_list **seq_list)
{
	t_node	*prev_seq_last;
	t_node	*prev;
	int		from_head;

	from_head = 0;
	if (starting_node && starting_node->prev)
		prev = starting_node->prev;
	if (starting_node && !starting_node->prev)
		from_head = 1;
	while (starting_node && len_from_here(starting_node) > 3)
	{
		prev_seq_last = stack_b->top;
		split_a(stack_a, stack_b, starting_node);
		if (from_head)
			starting_node = stack_a->head;
		else
			starting_node = prev->next;
		add_seq(seq_list, stack_b, prev_seq_last);
	}
	sort_and_pa(stack_a, stack_b, stack_s, *((size_t *)ft_lstlast(*seq_list)->content));
	delete_seq(seq_list);
}

void	solve(t_stack *stack_a, t_stack *stack_b, t_stack *stack_s)
{
	t_list	**seq_list;
	t_node	*a_top;

	seq_list = malloc(sizeof(t_list **));
	if (!seq_list)
		return_error(2);
	*seq_list = NULL;
	split_a_main(stack_a, stack_b, stack_s, stack_a->head, seq_list);
	while (stack_b->size)
	{
		// ft_printf("\nstep6\n");
		a_top = stack_a->top;
		// ft_printf("\nlast_seq: %d\n", *(size_t *)ft_lstlast(*seq_list)->content);
		if (*(size_t *)ft_lstlast(*seq_list)->content > 3)
			split_b(stack_a, stack_b, seq_list); // there is a case where i could split 3 numbers only !! need to handle it most efficiently
		split_a_main(stack_a, stack_b, stack_s, a_top->next, seq_list);
	}
	free(seq_list);
}

		// while (len_from_here(a_top->next) > 3)
		// {
		// 	split_a(stack_a, stack_b, a_top->next);
		// 	len = malloc(sizeof(size_t));
		// 	*len = len_from_here(stack_a->head) / 2;
		// 	seq_node = ft_lstnew(len);
		// 	if (!seq_node)
		// 	{
		// 		ft_lstclear(seq_list, &ft_delete);
		// 		return_error(2);
		// 	}
		// 	ft_lstadd_back(seq_list, seq_node);
		// }

//// SOLUTION 2:

// int	is_sorted(t_stack *stack_a, t_stack *sorted_stack)
// {
// 	t_node	*node;
// 	t_node	*sorted_node;
// 	size_t	i;
	
// 	i = 0;
// 	node = stack_a->head;
// 	sorted_node = sorted_stack->head;
// 	while (node->num != sorted_node->num)
// 		node = node->next;
// 	while (i++ < sorted_stack->size)
// 	{
// 		if (node->num != sorted_node->num)
// 			return (0);
// 		if (node->next)
// 			node = node->next;
// 		else
// 			node = stack_a->head;
// 		sorted_node = sorted_node->next;
// 	}
// 	return (1);
// }

// void	split_stack(t_stack *stack_a, t_stack *stack_b, t_stack *sorted_stack)
// {
// 	size_t	i;

// 	i = 0;
// 	while (i < sorted_stack->size / 2)
// 	{
// 		pb(stack_a, stack_b);
// 		i++;
// 	}
// }

// void	sort_pairs(t_stack *stack_a, t_stack *stack_b, size_t count)
// {
// 	size_t	i;
	
// 	i = 0;
// 	while (i++ < count)
// 	{
// 		if (stack_a->top->num > stack_a->top->prev->num &&
// 			stack_b->top->num < stack_b->top->prev->num)
// 				ss(stack_a, stack_b);
// 		else if (stack_a->top->num > stack_a->top->prev->num)
// 			sa(stack_a, 1);
// 		else if (stack_b->top->num < stack_b->top->prev->num)
// 			sb(stack_b, 1);
// 		if (i < count)
// 		{
// 			rrr(stack_a, stack_b);
// 			rrr(stack_a, stack_b);
// 		}
// 	}
// }

// void	shake_sort_rr(t_stack *stack_a, t_stack *stack_b, size_t count)
// {
// 	size_t	i;

// 	i = 0;
// 	if (count == 2)
// 		return ;
// 	while (i++ < count - 1)
// 	{
// 		rr(stack_a, stack_b);
// 		if (stack_a->top->num > stack_a->top->prev->num
// 			&& stack_b->top->num < stack_b->top->prev->num)
// 				ss(stack_a, stack_b);
// 		else if (stack_b->top->num < stack_b->top->prev->num)
// 			sb(stack_b, 1);
// 		else if (stack_a->top->num > stack_a->top->prev->num)
// 			sa(stack_a, 1);
// 	}
// 	shake_sort_rrr(stack_a, stack_b, count - 1);
// }

// void	shake_sort_rrr(t_stack *stack_a, t_stack *stack_b, size_t count)
// {
// 	size_t	i;

// 	i = 0;
// 	if (count == 2)
// 		return ;
// 	while (i++ < count - 1)
// 	{
// 		rrr(stack_a, stack_b);
// 		if (stack_a->top->num > stack_a->top->prev->num
// 			&& stack_b->top->num < stack_b->top->prev->num)
// 				ss(stack_a, stack_b);
// 		else if (stack_b->top->num < stack_b->top->prev->num)
// 			sb(stack_b, 1);
// 		else if (stack_a->top->num > stack_a->top->prev->num)
// 			sa(stack_a, 1);
// 	}
// 	shake_sort_rr(stack_a, stack_b, count);
// }

// int	is_in_b(t_node *node, t_stack *stack_b)
// {
// 	t_node	*b_node;

// 	b_node = stack_b->head;
// 	while (b_node)
// 	{
// 		if (node->num == b_node->num)
// 			return (1);
// 		b_node = b_node->next;
// 	}
// 	return (0);
// }

// int	is_in_a(t_node *node, t_stack *stack_a)
// {
// 	t_node	*a_node;

// 	a_node = stack_a->head;
// 	while (a_node)
// 	{
// 		if (node->num == a_node->num)
// 			return (1);
// 		a_node = a_node->next;
// 	}
// 	return (0);
// }

// int	is_next_in_b(t_stack *stack_a, t_stack *stack_b, t_stack *sorted_stack)
// {
// 	t_node	*node;

// 	node = sorted_stack->head;
// 	while (node)
// 	{
// 		if (node->num == stack_a->top->num)
// 			break ;
// 		node = node->next;
// 	}
// 	if (node->next)
// 	{
// 		if (is_in_b(node->next, stack_b))
// 			return (node->next->num);
// 	}
// 	else if (is_in_b(sorted_stack->head, stack_b))
// 		return (sorted_stack->head->num);
// 	return (0);
// }

// int	is_next_in_a(t_stack *stack_a, t_stack *sorted_stack)
// {
// 	t_node	*node;

// 	node = sorted_stack->head;
// 	while (node)
// 	{
// 		if (node->num == stack_a->top->num)
// 			break ;
// 		node = node->next;
// 	}
// 	if (node->next)
// 	{
// 		if (is_in_a(node->next, stack_a))
// 			return (1);
// 	}
// 	else if (is_in_a(sorted_stack->head, stack_a))
// 		return (1);
// 	return (0);
// }

// void	inject_into_a(t_stack *stack_a, t_stack *stack_b, t_stack *sorted_stack)
// {
// 	int	next;

// 	rr(stack_a, stack_b);
// 	rb(stack_b, 1);
// 	while (stack_b->size)
// 	{
// 		next = is_next_in_b(stack_a, stack_b, sorted_stack);
// 		while (next)
// 		{
// 			while (stack_b->top->num != next)
// 				rb(stack_b, 1);
// 			pa(stack_a, stack_b);
// 			next = is_next_in_b(stack_a, stack_b, sorted_stack);
// 		}
// 		if (is_next_in_a(stack_a, sorted_stack))
// 			rra(stack_a, 1);
// 	}
// }

// void	solve(t_stack *stack_a, t_stack *stack_b, t_stack *sorted_stack)
// {
// 	split_stack(stack_a, stack_b, sorted_stack);
// 	sort_pairs(stack_a, stack_b, stack_a->size / 2);
// 	ft_printf("here\n");
// 	shake_sort_rr(stack_a, stack_b, sorted_stack->size / 2);
// 	ft_printf("here\n");
// 	inject_into_a(stack_a, stack_b, sorted_stack);
// }

// void	solve(t_stack *stack_a, t_stack *stack_b, t_stack *sorted_stack)
// {
// 	int	top_a;
// 	int	top_b;
// 	int	sec_top_a;
// 	int	sec_top_b;

// 	while (!is_sorted(stack_a, sorted_stack))
// 	{
// 		while (top_a < sec_top_a)
// 		{
// 			pb(stack_a, stack_b);
// 			pb(stack_a, stack_b);
// 			swap(stack_a, stack_b); // checks if i can do ss
// 			while (top_b < top_a)
// 			{
// 				if (stack_a->size < sorted_stack->size / 2)
// 				{
// 					pa(stack_a, stack_b);
// 					swap(stack_a, stack_b);
// 				}
// 				else
// 				{
// 					pb(stack_a, stack_b);
// 					swap(stack_a, stack_b);
// 				}
// 			}
// 			pa(stack_a, stack_b);
// 		}
// 		if ()
// 	}
// }

// // how much is sorted (longest sorted seq / num of total nodes)
// // < 30% :

// main algo:
// 1. check of top 2 of A
// 	if sorted:		move longest sorted seq to its pos (first node to first place if longest seq is less than 20-30% of all elmnts)
// 	if not sorted:	push them to B, then check if need swapping (ss too)