#include "push_swap.h"

void	sort_1_4_2_3(t_stack *stack_a, t_stack *stack_b)
{
	ss(stack_a, stack_b);
	pa(stack_a, stack_b);
	sb(stack_b, 1);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	sort_1_5_2_3(t_stack *stack_a, t_stack *stack_b)
{
	ss(stack_a, stack_b);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	sort_1_6_2_3(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a, 1);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}
