/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jel-ghna <jel-ghna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 12:21:54 by jel-ghna          #+#    #+#             */
/*   Updated: 2025/06/17 16:44:07 by jel-ghna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*stack_s;

	if (!ft_alloc_list() || !op_stack() || !sequence_list())
		return_error(1);
	if (argc == 1)
		return_error(0);
	if (argc < 2)
		return_error(1);
	parse_args(&argc, &argv);
	stack_a = init_stack_a(argc, argv);
	stack_b = init_stack_b();
	stack_s = init_stack_sorted(stack_a);
	if (unsorted_in_a(stack_a, stack_s) > 1)
		solve(stack_a, stack_b, stack_s);
	print_ops(op_stack()->head);
	ft_lstclear(ft_alloc_list(), &ft_delete);
	free(ft_alloc_list());
}
