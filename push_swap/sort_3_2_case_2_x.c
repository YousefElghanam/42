#include "push_swap.h"

void	sort_2_1_3_2(t_stack *stack_a, t_stack *stack_b)
{
	ss(stack_a, stack_b);
	ra(stack_a, 1);
	sa(stack_a, 1);
	rra(stack_a, 1);
	sa(stack_a, 1);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	sort_2_2_3_2(t_stack *stack_a, t_stack *stack_b)
{
	ra(stack_a, 1);
	ss(stack_a, stack_b);
	rra(stack_a, 1);
	sa(stack_a, 1);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	sort_2_3_3_2(t_stack *stack_a, t_stack *stack_b)
{
	ss(stack_a, stack_b);
	ra(stack_a, 1);
	sa(stack_a, 1);
	rra(stack_a, 1);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}
