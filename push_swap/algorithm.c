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
	while (i++ < len) // can make it stop doing "ra" if no more left (but still keep track of how many "ra" we did if we need to "rra" back)
	{
		if (!is_top_half(sorted->head ,stack_a->top))
			pb(stack_a, stack_b);
		else
			ra(stack_a, 1);
	}
	if (reverse) // if stopped prev while loop before checking all, make sure you dont do more "rra" than necessary (change len)
	{
		len = (len % 2 != 0) + (len / 2);
		while (len--)
			rra(stack_a, 1);
	}
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
			i++;
		node_a = node_a->next;
		node_s = node_s->next;
	}
	return (i);
}

void	sort_two_two(t_stack *stack_a,t_stack *stack_b)
{
	if (stack_a->top->num > stack_a->top->prev->num)
	{
		if (stack_b->top->num < stack_b->top->prev->num)
			ss(stack_a, stack_b);
		else
			sa(stack_a, 1);
		pa(stack_a, stack_b);
		pa(stack_a, stack_b);
	}
	else
	{
		if (stack_b->top->num < stack_b->top->prev->num)
			sb(stack_b, 1);
		pa(stack_a, stack_b);
		pa(stack_a, stack_b);
	}
}

void	sort_b_pa(t_stack *stack_a, t_stack *stack_b, size_t b_top)
{
	t_top	*b;

	b = ft_malloc(sizeof(t_top));
	b->top = &stack_b->top->num;
	b->prev = &stack_b->top->prev->num;
	b->prevprev = &stack_b->top->prev->prev->num;
	if (b_top == 2)
	{
		sb(stack_b, 1);
		pa(stack_a, stack_b);
		pa(stack_a, stack_b);
	}
	else
		choose_compare_b_2_3(stack_a, stack_b, b);
}

void	sort_and_pa(t_stack *stack_a, t_stack *stack_b, t_stack *stack_s, size_t b_top)
{
	size_t	a_top;

	a_top = unsorted_in_a(stack_a, stack_s);
	ft_printf("\na_top: %d\nb_top: %d\n", a_top, b_top);
	if (a_top == 3 && b_top == 3)
		sort_three_three(stack_a, stack_b);
	else if (a_top == 3 && b_top == 2)
		sort_three_two(stack_a, stack_b);
	else if (a_top == 2 && b_top == 3)
		sort_two_three(stack_a, stack_b);
	else if (a_top == 2 && b_top == 2)
		sort_two_two(stack_a, stack_b);
	else if (a_top == 0 && (b_top == 2 || b_top == 3))
		sort_b_pa(stack_a, stack_b, b_top);
	else
		ft_printf("\n>>unkown combination to sort<<\n");
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
	size_t	i;
	size_t	*len;
	t_stack	*sorted;
	int		reverse;
	size_t	rev_count;

	reverse = 0;
	rev_count = 0;
	if (*seq_list)
		starting_node = b_split_starting_node(stack_b, ft_lstlast(*seq_list)->content);
	else
		starting_node = stack_b->head;
	i = 0;
	len = (size_t *)ft_lstlast(*seq_list)->content;
	sorted = mk_sorted_stack(starting_node);
	if (*len != stack_b->size)
		reverse = 1;
	while (i++ < *len) // can make it stop doing "ra" if no more left (but still keep track of how many "ra" we did if we need to "rra" back)
	{
		if (is_top_half(sorted->head ,stack_b->top))
			pa(stack_a, stack_b);
		else
		{
			rev_count++;
			rb(stack_b, 1);
		}
	}
	if (reverse) // if stopped prev while loop before checking all, make sure you dont do more "rra" than necessary (change len)
		while (rev_count--)
			rra(stack_a, 1);
}

void	solve(t_stack *stack_a, t_stack *stack_b, t_stack *stack_s)
{
	t_list	**seq_list;
	t_list	*seq_node;
	size_t	*len;
	t_node	*a_top;

	seq_list = ft_malloc(sizeof(t_list **));
	*seq_list = NULL;
	if (stack_s)
	while (len_from_here(stack_a->head) > 3)
	{
		t_node	*b_top = stack_b->top;
		split_a(stack_a, stack_b, stack_a->head);
		len = malloc(sizeof(size_t));
		if (b_top)
			*len = len_from_here(b_top->next);
		else
			*len = len_from_here(stack_b->head);
		seq_node = ft_lstnew(len);
		if (!seq_node)
		{
			ft_lstclear(seq_list, &ft_delete);
			return_error(2);
		}
		ft_lstadd_back(seq_list, seq_node);
	}
	t_list *test_node = *seq_list;
	while (test_node)
	{
		ft_printf("seq: %d\n", *(size_t *)test_node->content);
		test_node = test_node->next;
	}
	// PREV WHILE LOOP REPLACEMENT ||
	//							   VV
	// init_split_a(stack_a, stack_b, stack_a->head);
	sort_and_pa(stack_a, stack_b, stack_s, *((size_t *)ft_lstlast(*seq_list)->content));
	ft_lstdelone(ft_lstlast(*seq_list), &ft_delete);
	// test_node = *seq_list;
	// while (test_node)
	// {
	// 	ft_printf("seq: %d\n", *(size_t *)test_node->content);
	// 	test_node = test_node->next;
	// }
	while (stack_b->size)
	{
		a_top = stack_a->top;
		split_b(stack_a, stack_b, seq_list); // there is a case where i could split 3 numbers only !! need to handle it most efficiently
		/////
		while (len_from_here(a_top->next) > 3)
		{
			split_a(stack_a, stack_b, a_top->next);
			len = malloc(sizeof(size_t));
			*len = len_from_here(stack_a->head) / 2;
			seq_node = ft_lstnew(len);
			if (!seq_node)
			{
				ft_lstclear(seq_list, &ft_delete);
				return_error(2);
			}
			ft_lstadd_back(seq_list, seq_node);
		}
		/////
		sort_and_pa(stack_a, stack_b, stack_s, *(size_t *)ft_lstlast(*seq_list)->content);
		ft_lstdelone(ft_lstlast(*seq_list), &ft_delete);
	}
	ft_lstclear(seq_list, &ft_delete);
}

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