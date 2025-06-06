#include "push_swap.h"

void	sort_4_4(t_stack *stack_a, t_stack *stack_b)
{
	sb(stack_b, 1);
	rr(stack_a, stack_b);
	ss(stack_a, stack_b);
	rrr(stack_a, stack_b);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	sort_4_5(t_stack *stack_a, t_stack *stack_b)
{
	ra(stack_a, 1);
	ss(stack_a, stack_b);
	rra(stack_a, 1);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	sort_4_6(t_stack *stack_a, t_stack *stack_b)
{
	ra(stack_a, 1);
	sa(stack_a, 1);
	rra(stack_a, 1);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}
