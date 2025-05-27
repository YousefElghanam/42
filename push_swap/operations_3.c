#include "push_swap.h"

void	ra(t_stack *stack)
{
	t_node	*node;

	if (stack->size == 0 || stack->size == 1)
	{
		ft_printf("ra (nothing)\n");
		return ;
	}
	ft_printf("ra\n");
	node = stack->top;
	stack->top = node->prev;
	node->prev->next = NULL;
	node->prev = NULL;
	node->next = stack->head;
	stack->head->prev = node;
	stack->head = node;
}

void	rb(t_stack *stack)
{
	t_node	*node;

	if (stack->size == 0 || stack->size == 1)
	{
		ft_printf("\nrb (nothing)\n");
		return ;
	}
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
	ra(stack_a);
	rb(stack_b);
}
