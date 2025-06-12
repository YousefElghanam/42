#include "push_swap.h"

void	sa(t_stack *stack, int print)
{
	t_node	*top;
	t_node	*prev;

	if (stack->size < 2)
	{
		// ft_printf("nothing\n");
		add_op(-1);
		return ;
	}
	if (print)
	{
		// ft_printf("sa\n");
		add_op(0);
	}
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

void	sb(t_stack *stack, int print)
{
	t_node	*top;
	t_node	*prev;

	if (stack->size < 2)
	{
		// ft_printf("nothing\n");
		add_op(-1);
		return ;
	}
	if (print)
	{
		// ft_printf("sb\n");
		add_op(1);
	}
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

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	// ft_printf("ss\n");
	add_op(2);
	sa(stack_a, 0);
	sb(stack_b, 0);
}
