/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_3_case_6_x.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jel-ghna <jel-ghna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 12:19:59 by jel-ghna          #+#    #+#             */
/*   Updated: 2025/06/15 12:20:00 by jel-ghna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_6_1(t_stack *stack_a, t_stack *stack_b)
{
	sb(stack_b, 1);
	rb(stack_b, 1);
	sb(stack_b, 1);
	rrb(stack_b, 1);
	sb(stack_b, 1);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	sort_6_2(t_stack *stack_a, t_stack *stack_b)
{
	rb(stack_b, 1);
	sb(stack_b, 1);
	rrb(stack_b, 1);
	sb(stack_b, 1);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	sort_6_3(t_stack *stack_a, t_stack *stack_b)
{
	rb(stack_b, 1);
	sb(stack_b, 1);
	rrb(stack_b, 1);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}
