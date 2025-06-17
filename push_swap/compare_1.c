/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jel-ghna <jel-ghna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 12:34:27 by jel-ghna          #+#    #+#             */
/*   Updated: 2025/06/15 12:36:44 by jel-ghna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	choose_compare_b_1(t_stack *stack_a, t_stack *stack_b, t_top *b)
{
	if (compare_b_3(b->top, b->prev, b->prevprev) == 1)
		sort_1_1(stack_a, stack_b);
	else if (compare_b_3(b->top, b->prev, b->prevprev) == 2)
		sort_1_2(stack_a, stack_b);
	else if (compare_b_3(b->top, b->prev, b->prevprev) == 3)
		sort_1_3(stack_a, stack_b);
	else if (compare_b_3(b->top, b->prev, b->prevprev) == 4)
		sort_1_4(stack_a, stack_b);
	else if (compare_b_3(b->top, b->prev, b->prevprev) == 5)
		sort_1_5(stack_a, stack_b);
	else if (compare_b_3(b->top, b->prev, b->prevprev) == 6)
		sort_1_6(stack_a, stack_b);
}

void	choose_compare_b_2(t_stack *stack_a, t_stack *stack_b, t_top *b)
{
	if (compare_b_3(b->top, b->prev, b->prevprev) == 1)
		sort_2_1(stack_a, stack_b);
	else if (compare_b_3(b->top, b->prev, b->prevprev) == 2)
		sort_2_2(stack_a, stack_b);
	else if (compare_b_3(b->top, b->prev, b->prevprev) == 3)
		sort_2_3(stack_a, stack_b);
	else if (compare_b_3(b->top, b->prev, b->prevprev) == 4)
		sort_2_4(stack_a, stack_b);
	else if (compare_b_3(b->top, b->prev, b->prevprev) == 5)
		sort_2_5(stack_a, stack_b);
	else if (compare_b_3(b->top, b->prev, b->prevprev) == 6)
		sort_2_6(stack_a, stack_b);
}

void	choose_compare_b_3(t_stack *stack_a, t_stack *stack_b, t_top *b)
{
	if (compare_b_3(b->top, b->prev, b->prevprev) == 1)
		sort_3_1(stack_a, stack_b);
	else if (compare_b_3(b->top, b->prev, b->prevprev) == 2)
		sort_3_2(stack_a, stack_b);
	else if (compare_b_3(b->top, b->prev, b->prevprev) == 3)
		sort_3_3(stack_a, stack_b);
	else if (compare_b_3(b->top, b->prev, b->prevprev) == 4)
		sort_3_4(stack_a, stack_b);
	else if (compare_b_3(b->top, b->prev, b->prevprev) == 5)
		sort_3_5(stack_a, stack_b);
	else if (compare_b_3(b->top, b->prev, b->prevprev) == 6)
		sort_3_6(stack_a, stack_b);
}

void	choose_compare_b_4(t_stack *stack_a, t_stack *stack_b, t_top *b)
{
	if (compare_b_3(b->top, b->prev, b->prevprev) == 1)
		sort_4_1(stack_a, stack_b);
	else if (compare_b_3(b->top, b->prev, b->prevprev) == 2)
		sort_4_2(stack_a, stack_b);
	else if (compare_b_3(b->top, b->prev, b->prevprev) == 3)
		sort_4_3(stack_a, stack_b);
	else if (compare_b_3(b->top, b->prev, b->prevprev) == 4)
		sort_4_4(stack_a, stack_b);
	else if (compare_b_3(b->top, b->prev, b->prevprev) == 5)
		sort_4_5(stack_a, stack_b);
	else if (compare_b_3(b->top, b->prev, b->prevprev) == 6)
		sort_4_6(stack_a, stack_b);
}

void	choose_compare_b_5(t_stack *stack_a, t_stack *stack_b, t_top *b)
{
	if (compare_b_3(b->top, b->prev, b->prevprev) == 1)
		sort_5_1(stack_a, stack_b);
	else if (compare_b_3(b->top, b->prev, b->prevprev) == 2)
		sort_5_2(stack_a, stack_b);
	else if (compare_b_3(b->top, b->prev, b->prevprev) == 3)
		sort_5_3(stack_a, stack_b);
	else if (compare_b_3(b->top, b->prev, b->prevprev) == 4)
		sort_5_4(stack_a, stack_b);
	else if (compare_b_3(b->top, b->prev, b->prevprev) == 5)
		sort_5_5(stack_a, stack_b);
	else if (compare_b_3(b->top, b->prev, b->prevprev) == 6)
		sort_5_6(stack_a, stack_b);
}
