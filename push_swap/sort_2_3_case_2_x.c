#include "push_swap.h"

void	sort_2_1_2_3(t_stack *stack_a, t_stack *stack_b)
{
	rb(stack_b, 1);
	sb(stack_b, 1);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
	rrb(stack_b, 1);
	pa(stack_a, stack_b);
}

void	sort_2_2_2_3(t_stack *stack_a, t_stack *stack_b)
{
	rb(stack_b, 1);
	sb(stack_b, 1);
	pa(stack_a, stack_b);
	rrb(stack_b, 1);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	sort_2_3_2_3(t_stack *stack_a, t_stack *stack_b)
{
	pa(stack_a, stack_b);
	sb(stack_b, 1);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}
