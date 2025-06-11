#include "push_swap.h"

void	rra(t_stack *stack, int print)
{
	t_node	*node;

	if (stack->size == 0 || stack->size == 1)
	{
		ft_printf("rra (nothing)\n");
		return ;
	}
	if (print)
		ft_printf("rra\n");
	node = stack->head;
	stack->head = node->next;
	node->prev = NULL;
	node->prev = stack->top;
	node->next = NULL;
	stack->top->next = node;
	stack->top = node;
}

void	rrb(t_stack *stack, int print)
{
	t_node	*node;

	if (stack->size == 0 || stack->size == 1)
	{
		ft_printf("rrb (nothing)\n");
		return ;
	}
	if (print)
		ft_printf("rrb\n");
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
	ft_printf("rrr\n");
	rra(stack_a, 0);
	rrb(stack_b, 0);
}
