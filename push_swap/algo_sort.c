/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jel-ghna <jel-ghna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 12:17:07 by jel-ghna          #+#    #+#             */
/*   Updated: 2025/06/17 16:43:38 by jel-ghna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_b_top(t_stack *stack_a, t_stack *stack_b, size_t b_top)
{
	t_top	*b;

	b = ft_malloc(sizeof(t_top));
	if (!b)
		return_error(1);
	b->top = &stack_b->top->num;
	b->prev = &stack_b->top->prev->num;
	b->prevprev = &stack_b->top->prev->prev->num;
	if (b_top == 2)
	{
		if (stack_b->top->num < stack_b->top->prev->num)
			sb(stack_b, 1);
		pa(stack_a, stack_b);
		pa(stack_a, stack_b);
	}
	else
		choose_compare_b_2_3(stack_a, stack_b, b);
}

void	sort_special_three(t_stack *stack_a, t_stack *stack_b, t_top *a)
{
	if (compare_a_3(a->top, a->prev, a->prevprev) == 6
		|| compare_a_3(a->top, a->prev, a->prevprev) == 5
		|| compare_a_3(a->top, a->prev, a->prevprev) == 4)
		choose_compare_a_1(stack_a, stack_b, a);
	else if (compare_a_3(a->top, a->prev, a->prevprev) == 1)
	{
		ra(stack_a, 1);
		sa(stack_a, 1);
	}
	else if (compare_a_3(a->top, a->prev, a->prevprev) == 2)
		rra(stack_a, 1);
	else if (compare_a_3(a->top, a->prev, a->prevprev) == 3)
		ra(stack_a, 1);
}

void	sort_a_top(t_stack *stack_a, t_stack *stack_b)
{
	t_top	*a;

	a = ft_malloc(sizeof(t_top));
	if (!a)
		return_error(1);
	a->top = &stack_a->top->num;
	a->prev = &stack_a->top->prev->num;
	a->prevprev = &stack_a->top->prev->prev->num;
	if (stack_a->size == 3)
		sort_special_three(stack_a, stack_b, a);
	else if (stack_a->top->num > stack_a->top->prev->num)
		sa(stack_a, 1);
}

void	sort(t_stack *stack_a, t_stack *stack_b, t_stack *stack_s, size_t b_top)
{
	size_t	a_top;

	a_top = unsorted_in_a(stack_a, stack_s);
	if (a_top == 3 && b_top == 3)
		sort_three_three(stack_a, stack_b);
	else if (a_top == 3 && b_top == 2)
		sort_three_two(stack_a, stack_b);
	else if (a_top == 2 && b_top == 3)
		sort_two_three(stack_a, stack_b);
	else if (a_top == 2 && b_top == 2)
		sort_two_two(stack_a, stack_b);
	else if (a_top == 0 && (b_top == 2 || b_top == 3))
		sort_b_top(stack_a, stack_b, b_top);
}
