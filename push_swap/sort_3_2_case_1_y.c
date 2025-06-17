/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_2_case_1_y.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jel-ghna <jel-ghna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 12:19:36 by jel-ghna          #+#    #+#             */
/*   Updated: 2025/06/15 12:19:36 by jel-ghna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_1_4_3_2(t_stack *stack_a, t_stack *stack_b)
{
	ra(stack_a, 1);
	sa(stack_a, 1);
	rra(stack_a, 1);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	sort_1_5_3_2(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a, 1);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	sort_1_6_3_2(t_stack *stack_a, t_stack *stack_b)
{
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}
