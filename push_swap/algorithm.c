#include "push_swap.h"

// void	percentage_correctness_checker(t_stack *stack);

// void	longest_sorted_seq(t_stack *stack_a, t_stack *stack_b)
// {
// 	;
// }

int	is_sorted(t_stack *stack_a, t_stack *sorted_stack)
{
	t_node	*node;
	t_node	*sorted_node;
	size_t	i;
	
	i = 0;
	node = stack_a->head;
	sorted_node = sorted_stack->head;
	while (node->num != sorted_node->num)
		node = node->next;
	while (i++ < sorted_stack->size)
	{
		if (node->num != sorted_node->num)
			return (0);
		if (node->next)
			node = node->next;
		else
			node = stack_a->head;
		sorted_node = sorted_node->next;
	}
	return (1);
}

void	split_stack(t_stack *stack_a, t_stack *stack_b, t_stack *sorted_stack)
{
	size_t	i;

	i = 0;
	while (i < sorted_stack->size / 2)
	{
		pb(stack_a, stack_b);
		i++;
	}
}

void	sort_pairs(t_stack *stack_a, t_stack *stack_b, size_t count)
{
	size_t	i;
	
	i = 0;
	while (i++ < count)
	{
		if (stack_a->top->num > stack_a->top->prev->num &&
			stack_b->top->num < stack_b->top->prev->num)
				ss(stack_a, stack_b);
		else if (stack_a->top->num > stack_a->top->prev->num)
			sa(stack_a, 1);
		else if (stack_b->top->num < stack_b->top->prev->num)
			sb(stack_b, 1);
		if (i < count)
		{
			rrr(stack_a, stack_b);
			rrr(stack_a, stack_b);
		}
	}
}

void	shake_sort_rr(t_stack *stack_a, t_stack *stack_b, size_t count)
{
	size_t	i;

	i = 0;
	if (count == 2)
		return ;
	while (i++ < count - 1)
	{
		rr(stack_a, stack_b);
		if (stack_a->top->num > stack_a->top->prev->num
			&& stack_b->top->num < stack_b->top->prev->num)
				ss(stack_a, stack_b);
		else if (stack_b->top->num < stack_b->top->prev->num)
			sb(stack_b, 1);
		else if (stack_a->top->num > stack_a->top->prev->num)
			sa(stack_a, 1);
	}
	shake_sort_rrr(stack_a, stack_b, count - 1);
}

void	shake_sort_rrr(t_stack *stack_a, t_stack *stack_b, size_t count)
{
	size_t	i;

	i = 0;
	if (count == 2)
		return ;
	while (i++ < count - 1)
	{
		rrr(stack_a, stack_b);
		if (stack_a->top->num > stack_a->top->prev->num
			&& stack_b->top->num < stack_b->top->prev->num)
				ss(stack_a, stack_b);
		else if (stack_b->top->num < stack_b->top->prev->num)
			sb(stack_b, 1);
		else if (stack_a->top->num > stack_a->top->prev->num)
			sa(stack_a, 1);
	}
	shake_sort_rr(stack_a, stack_b, count);
}

int	whats_next(int num, t_stack *sorted_stack)
{
	t_node	*node;

	node = sorted_stack->head;
	while (node)
	{
		if (node->num == num)
		{
			if (node->next)
				return (node->next->num);
			return (sorted_stack->head->num);
		}
		node = node->next;
	}
	return (0);
}

void	inject_into_a(t_stack *stack_a, t_stack *stack_b, t_stack *sorted_stack)
{
	rr(stack_a, stack_b);
	rb(stack_b, 1);
	while (stack_b->size)
	{
		while (stack_b->top && stack_b->top->num == whats_next(stack_a->top->num, sorted_stack))
			pa(stack_a, stack_b);
		rb(stack_b, 1);
	}
}

void	solve(t_stack *stack_a, t_stack *stack_b, t_stack *sorted_stack)
{
	split_stack(stack_a, stack_b, sorted_stack);
	sort_pairs(stack_a, stack_b, stack_a->size / 2);
	shake_sort_rr(stack_a, stack_b, sorted_stack->size / 2);
	inject_into_a(stack_a, stack_b, sorted_stack);
}

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