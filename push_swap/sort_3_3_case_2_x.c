/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_3_case_2_x.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jel-ghna <jel-ghna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 12:19:44 by jel-ghna          #+#    #+#             */
/*   Updated: 2025/06/15 12:19:44 by jel-ghna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2_1(t_stack *stack_a, t_stack *stack_b)
{
	sb(stack_b, 1);
	rr(stack_a, stack_b);
	ss(stack_a, stack_b);
	rrr(stack_a, stack_b);
	ss(stack_a, stack_b);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	sort_2_2(t_stack *stack_a, t_stack *stack_b)
{
	rr(stack_a, stack_b);
	ss(stack_a, stack_b);
	rrr(stack_a, stack_b);
	ss(stack_a, stack_b);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	sort_2_3(t_stack *stack_a, t_stack *stack_b)
{
	rr(stack_a, stack_b);
	ss(stack_a, stack_b);
	rrr(stack_a, stack_b);
	sa(stack_a, 1);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}
