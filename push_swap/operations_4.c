#include "push_swap.h"

void	rra(t_stack *stack)
{
	t_node	*node;

	if (stack->size == 0 || stack->size == 1)
		return ;
	node = stack->head;
	stack->head = node->next;
	node->prev = NULL;
	node->prev = stack->top;
	node->next = NULL;
	stack->top->next = node;
	stack->top = node;
}

void	rrb(t_stack *stack)
{
	t_node	*node;

	if (stack->size == 0 || stack->size == 1)
		return ;
	node = stack->head;
	stack->head = node->next;
	node->prev = NULL;
	node->prev = stack->top;
	node->next = NULL;
	stack->top->next = node;
	stack->top = node;
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
