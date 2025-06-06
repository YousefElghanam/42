#include "push_swap.h"

void	sort_6_4(t_stack *stack_a, t_stack *stack_b)
{
	sb(stack_b, 1);
	pa(stack_a, stack_b);
	sb(stack_b, 1);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	sort_6_5(t_stack *stack_a, t_stack *stack_b)
{
	sb(stack_b, 1);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	sort_6_6(t_stack *stack_a, t_stack *stack_b)
{
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}
