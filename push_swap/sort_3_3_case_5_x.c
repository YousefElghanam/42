#include "push_swap.h"

void	sort_5_1(t_stack *stack_a, t_stack *stack_b)
{
	ss(stack_a, stack_b);
	rb(stack_b, 1);
	sb(stack_b, 1);
	rrb(stack_b, 1);
	sb(stack_b, 1);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	sort_5_2(t_stack *stack_a, t_stack *stack_b)
{
	rb(stack_b, 1);
	ss(stack_a, stack_b);
	rrb(stack_b, 1);
	sb(stack_b, 1);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	sort_5_3(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a, 1);
	pa(stack_a, stack_b);
	sb(stack_b, 1);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}
