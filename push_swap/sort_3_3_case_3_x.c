#include "push_swap.h"

void	sort_3_1(t_stack *stack_a, t_stack *stack_b)
{
	ss(stack_a, stack_b);
	rr(stack_a, stack_b);
	ss(stack_a, stack_b);
	rrr(stack_a, stack_b);
	sb(stack_b, 1);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	sort_3_2(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a, 1);
	rr(stack_a, stack_b);
	ss(stack_a, stack_b);
	rrr(stack_a, stack_b);
	sb(stack_b, 1);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	sort_3_3(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a, 1);
	rr(stack_a, stack_b);
	ss(stack_a, stack_b);
	rrr(stack_a, stack_b);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}
