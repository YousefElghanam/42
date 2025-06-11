#include "push_swap.h"

void	ra(t_stack *stack, int print)
{
	t_node	*node;

	if (stack->size == 0 || stack->size == 1) // should do nothing.
	{
		ft_printf("ra (nothing)\n");
		return ;
	}
	if (print)
		ft_printf("ra\n");
	node = stack->top;
	stack->top = node->prev;
	node->prev->next = NULL;
	node->prev = NULL;
	node->next = stack->head;
	stack->head->prev = node;
	stack->head = node;
}

void	rb(t_stack *stack, int print)
{
	t_node	*node;

	if (stack->size == 0 || stack->size == 1)
	{
		ft_printf("rb (nothing)\n");
		return ;
	}
	if (print)
		ft_printf("rb\n");
	node = stack->top;
	stack->top = node->prev;
	node->prev->next = NULL;
	node->prev = NULL;
	node->next = stack->head;
	stack->head->prev = node;
	stack->head = node;
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	ft_printf("rr\n");
	ra(stack_a, 0);
	rb(stack_b, 0);
}
