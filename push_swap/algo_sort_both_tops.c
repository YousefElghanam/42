/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sort_both_tops.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jel-ghna <jel-ghna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 12:07:40 by jel-ghna          #+#    #+#             */
/*   Updated: 2025/06/15 21:43:33 by jel-ghna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_three(t_stack *stack_a, t_stack *stack_b)
{
	t_top	*a;
	t_top	*b;

	a = ft_malloc(sizeof(t_top));
	b = ft_malloc(sizeof(t_top));
	if (!a || !b)
		return_error(1);
	a->top = &stack_a->top->num;
	b->top = &stack_b->top->num;
	a->prev = &stack_a->top->prev->num;
	b->prev = &stack_b->top->prev->num;
	a->prevprev = &stack_a->top->prev->prev->num;
	b->prevprev = &stack_b->top->prev->prev->num;
	if (compare_a_3(a->top, a->prev, a->prevprev) == 1)
		choose_compare_b_1(stack_a, stack_b, b);
	else if (compare_a_3(a->top, a->prev, a->prevprev) == 2)
		choose_compare_b_2(stack_a, stack_b, b);
	else if (compare_a_3(a->top, a->prev, a->prevprev) == 3)
		choose_compare_b_3(stack_a, stack_b, b);
	else if (compare_a_3(a->top, a->prev, a->prevprev) == 4)
		choose_compare_b_4(stack_a, stack_b, b);
	else if (compare_a_3(a->top, a->prev, a->prevprev) == 5)
		choose_compare_b_5(stack_a, stack_b, b);
	else if (compare_a_3(a->top, a->prev, a->prevprev) == 6)
		choose_compare_b_6(stack_a, stack_b, b);
}

void	sort_three_two(t_stack *stack_a, t_stack *stack_b)
{
	t_top	*a;
	t_top	*b;

	a = ft_malloc(sizeof(t_top));
	b = ft_malloc(sizeof(t_top));
	if (!a || !b)
		return_error(1);
	a->top = &stack_a->top->num;
	b->top = &stack_b->top->num;
	a->prev = &stack_a->top->prev->num;
	b->prev = &stack_b->top->prev->num;
	a->prevprev = &stack_a->top->prev->prev->num;
	if (compare_b_2(b->top, b->prev) == 1)
		choose_compare_a_1(stack_a, stack_b, a);
	else if (compare_b_2(b->top, b->prev) == 2)
		choose_compare_a_2(stack_a, stack_b, a);
}

void	sort_two_three(t_stack *stack_a, t_stack *stack_b)
{
	t_top	*b;

	b = ft_malloc(sizeof(t_top));
	if (!b)
		return_error(1);
	b->top = &stack_b->top->num;
	b->prev = &stack_b->top->prev->num;
	b->prevprev = &stack_b->top->prev->prev->num;
	if (compare_a_2(&stack_a->top->num, &stack_a->top->prev->num) == 1)
		choose_compare_b_1_3(stack_a, stack_b, b);
	else if (compare_a_2(&stack_a->top->num, &stack_a->top->prev->num) == 2)
		choose_compare_b_2_3(stack_a, stack_b, b);
}

void	sort_two_two(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->top->num > stack_a->top->prev->num)
	{
		if (stack_b->top->num < stack_b->top->prev->num)
			ss(stack_a, stack_b);
		else
			sa(stack_a, 1);
		pa(stack_a, stack_b);
		pa(stack_a, stack_b);
	}
	else
	{
		if (stack_b->top->num < stack_b->top->prev->num)
			sb(stack_b, 1);
		pa(stack_a, stack_b);
		pa(stack_a, stack_b);
	}
}
