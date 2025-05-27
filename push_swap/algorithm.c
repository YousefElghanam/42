#include "push_swap.h"

void	percentage_correctness_checker(t_stack *stack);

void	longest_sorted_seq(t_stack *stack_a, t_stack *stack_b)
{
	;
}

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

void	solve(t_stack *stack_a, t_stack *stack_b, t_stack *sorted_stack)
{
	int	top_a;
	int	top_b;
	int	sec_top_a;
	int	sec_top_b;

	while (!is_sorted(stack_a, sorted_stack))
	{
		while (top_a < sec_top_a)
		{
			pb(stack_a, stack_b);
			pb(stack_a, stack_b);
			swap(stack_a, stack_b); // checks if i can do ss
			while (top_b < top_a)
			{
				if (stack_a->size < sorted_stack->size / 2)
				{
					pa(stack_a, stack_b);
					swap(stack_a, stack_b);
				}
				else
				{
					pb(stack_a, stack_b);
					swap(stack_a, stack_b);
				}
			}
			pa(stack_a, stack_b);
		}
	}
}

// how much is sorted (longest sorted seq / num of total nodes)
// < 30% :

main algo:
1. check of top 2 of A
	if sorted:		move longest sorted seq to its pos (first node to first place if longest seq is less than 20-30% of all elmnts)
	if not sorted:	push them to B, then check if need swapping (ss too)