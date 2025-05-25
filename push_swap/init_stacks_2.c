#include "push_swap.h"

t_node	*new_node(int num)
{
	t_node	*node;

	node = ft_malloc(sizeof(t_node));
	if (!node)
		return_error(2);
	node->num = num;
	node->position = 0;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	push_node(t_node *node, t_stack *stack)
{
	if (stack->size == 0)
		stack->head = node;
	else
	{
		node->prev = stack->top;
		stack->top->next = node;
	}
	stack->top = node;
	stack->size += 1;
}

void	fill_arr(int *arr, t_stack *stack)
{
	size_t	i;
	t_node	*node;

	i = 0;
	node = stack->head;
	while (i < stack->size)
	{
		arr[i++] = node->num;
		node = node->next;
	}
}

void	sort_arr(int *arr, size_t size)
{
	size_t	i;
	size_t	j;
	int		tmp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

t_stack	*arr_to_stack(int *arr, size_t size)
{
	size_t	i;
	t_stack	*stack;

	stack = ft_malloc(sizeof(t_stack));
	if (!stack)
		return_error(2);
	stack->head = NULL;
	stack->top = NULL;
	stack->size = 0;
	i = 0;
	while (i < size)
		push_node(new_node(arr[i++]), stack);
	return (stack);
}
