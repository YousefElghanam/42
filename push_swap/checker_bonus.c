/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jel-ghna <jel-ghna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 12:58:15 by jel-ghna          #+#    #+#             */
/*   Updated: 2025/06/17 16:20:02 by jel-ghna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*op_stack_bonus(void)
{
	static t_stack	*ptr;

	if (!ptr)
	{
		ptr = ft_malloc(sizeof(t_stack));
		if (!ptr)
			return_error(1);
		ptr->size = 0;
		ptr->head = NULL;
		ptr->top = NULL;
	}
	return (ptr);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*stack_s;

	if (!ft_alloc_list() || !op_stack_bonus())
		return_error(1);
	if (argc == 1)
		return_error(0);
	parse_args(&argc, &argv);
	stack_a = init_stack_a(argc, argv);
	if (stack_a->size == 0)
		return_error(1);
	stack_b = init_stack_b();
	stack_s = init_stack_sorted(stack_a);
	read_ops();
	execute_ops(stack_a, stack_b);
	if (!unsorted_in_a(stack_a, stack_s) && stack_a->size == stack_s->size
		&& stack_b->size == 0)
		ft_printf("OK\n");
	else
		return_error(2);
	ft_lstclear(ft_alloc_list(), &ft_delete);
	free(ft_alloc_list());
}
