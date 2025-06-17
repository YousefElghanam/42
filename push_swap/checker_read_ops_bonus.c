/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_read_ops_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jel-ghna <jel-ghna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 14:06:07 by jel-ghna          #+#    #+#             */
/*   Updated: 2025/06/15 22:02:47 by jel-ghna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	read_op(char *line)
{
	if (ft_strncmp((const char *)line, "sa\n", 3) == 0)
		push_node(new_node(1), op_stack_bonus());
	else if (ft_strncmp((const char *)line, "sb\n", 3) == 0)
		push_node(new_node(2), op_stack_bonus());
	else if (ft_strncmp((const char *)line, "ss\n", 3) == 0)
		push_node(new_node(3), op_stack_bonus());
	else if (ft_strncmp((const char *)line, "pa\n", 3) == 0)
		push_node(new_node(4), op_stack_bonus());
	else if (ft_strncmp((const char *)line, "pb\n", 3) == 0)
		push_node(new_node(5), op_stack_bonus());
	else if (ft_strncmp((const char *)line, "ra\n", 3) == 0)
		push_node(new_node(6), op_stack_bonus());
	else if (ft_strncmp((const char *)line, "rb\n", 3) == 0)
		push_node(new_node(7), op_stack_bonus());
	else if (ft_strncmp((const char *)line, "rr\n", 3) == 0)
		push_node(new_node(8), op_stack_bonus());
	else if (ft_strncmp((const char *)line, "rra\n", 4) == 0)
		push_node(new_node(9), op_stack_bonus());
	else if (ft_strncmp((const char *)line, "rrb\n", 4) == 0)
		push_node(new_node(10), op_stack_bonus());
	else if (ft_strncmp((const char *)line, "rrr\n", 4) == 0)
		push_node(new_node(11), op_stack_bonus());
	else
		return_error(1);
}

void	read_ops(void)
{
	char	*line;

	line = get_next_line(0);
	ft_add_address(line);
	while (line)
	{
		read_op(line);
		line = get_next_line(0);
		ft_add_address(line);
	}
}
