/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   very_special_set.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jel-ghna <jel-ghna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 12:28:50 by jel-ghna          #+#    #+#             */
/*   Updated: 2025/06/15 12:28:50 by jel-ghna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_set(t_set *set, size_t arg_count)
{
	set->capacity = arg_count;
	set->cur_size = 0;
	set->arr = ft_malloc(sizeof(int) * (arg_count));
	if (!set->arr)
		return_error(1);
}

int	in_set(t_set *set, int num)
{
	size_t	i;

	i = 0;
	while (i < set->cur_size)
		if ((set->arr)[i++] == num)
			return (1);
	return (0);
}

void	add_to_set(t_set *set, int num)
{
	set->arr[set->cur_size] = num;
	set->cur_size += 1;
}
