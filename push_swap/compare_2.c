/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jel-ghna <jel-ghna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 12:34:31 by jel-ghna          #+#    #+#             */
/*   Updated: 2025/06/15 12:34:32 by jel-ghna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	compare_a_3(int *top, int *prev, int *prevprev)
{
	if (*top > *prev && *top > *prevprev && *prev > *prevprev)
		return (1);
	else if (*top < *prev && *top > *prevprev && *prev > *prevprev)
		return (2);
	else if (*top > *prev && *top > *prevprev && *prev < *prevprev)
		return (3);
	else if (*top < *prev && *top < *prevprev && *prev > *prevprev)
		return (4);
	else if (*top > *prev && *top < *prevprev && *prev < *prevprev)
		return (5);
	else if (*top < *prev && *top < *prevprev && *prev < *prevprev)
		return (6);
	return (-1);
}

int	compare_a_2(int *top, int *prev)
{
	if (*top > *prev)
		return (1);
	else if (*top < *prev)
		return (2);
	return (-1);
}

int	compare_b_3(int *top, int *prev, int *prevprev)
{
	if (*top < *prev && *top < *prevprev && *prev < *prevprev)
		return (1);
	else if (*top > *prev && *top < *prevprev && *prev < *prevprev)
		return (2);
	else if (*top > *prev && *top > *prevprev && *prev < *prevprev)
		return (3);
	else if (*top < *prev && *top < *prevprev && *prev > *prevprev)
		return (4);
	else if (*top < *prev && *top > *prevprev && *prev > *prevprev)
		return (5);
	else if (*top > *prev && *top > *prevprev && *prev > *prevprev)
		return (6);
	return (-1);
}

int	compare_b_2(int *top, int *prev)
{
	if (*top > *prev)
		return (1);
	else if (*top < *prev)
		return (2);
	return (-1);
}
