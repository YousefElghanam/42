#include "push_swap.h"

void	sa(t_stack *stack)
{
	t_node	*top;
	t_node	*prev;

	if (stack->size > 1)
	{
		top = stack->top;
		prev = top->prev;
		if (prev->prev)
			prev->prev->next = top;
		top->prev = prev->prev;
		top->next = prev;
		prev->prev = top;
		prev->next = NULL;
		stack->top = prev;
		if (stack->size == 2)
			stack->head = top;
	}
}

void	sb(t_stack *stack)
{
	t_node	*top;
	t_node	*prev;

	if (stack->size > 1)
	{
		top = stack->top;
		prev = top->prev;
		if (prev->prev)
			prev->prev->next = top;
		top->prev = prev->prev;
		top->next = prev;
		prev->prev = top;
		prev->next = NULL;
		stack->top = prev;
		if (stack->size == 2)
			stack->head = top;
	}
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a);
	sb(stack_b);
}
