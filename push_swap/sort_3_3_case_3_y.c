#include "push_swap.h"

void	sort_3_4(t_stack *stack_a, t_stack *stack_b)
{
	ss(stack_a, stack_b);
	rr(stack_a, stack_b);
	ss(stack_a, stack_b);
	rrr(stack_a, stack_b);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	sort_3_5(t_stack *stack_a, t_stack *stack_b)
{
	ss(stack_a, stack_b);
	ra(stack_a, 1);
	sa(stack_a, 1);
	rra(stack_a, 1);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	sort_3_6(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a, 1);
	ra(stack_a, 1);
	sa(stack_a, 1);
	rra(stack_a, 1);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}
