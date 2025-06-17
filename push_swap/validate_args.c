/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jel-ghna <jel-ghna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 12:28:47 by jel-ghna          #+#    #+#             */
/*   Updated: 2025/06/17 16:44:20 by jel-ghna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atoi_but_better(const char *nptr)
{
	size_t	i;
	int		sign;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	while ((9 <= nptr[i] && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
		if (nptr[i++] == '-')
			sign = -1;
	if (ft_strlen(&nptr[i]) > 11)
		return (2147483648);
	while ('0' <= nptr[i] && nptr[i] <= '9')
		res = res * 10 + (nptr[i++] - '0');
	if (res > 2147483647 && sign == 1)
		return (2147483648);
	if (res > 2147483648 && sign == -1)
		return (2147483648);
	return (res * sign);
}

static int	is_valid_int(char *str)
{
	size_t	i;
	size_t	strlen;

	i = 0;
	if (*str == 0)
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	strlen = ft_strlen(str);
	while (i < strlen)
		if (!ft_isdigit(str[i++]))
			return (0);
	if (ft_atoi_but_better(str) == 2147483648)
		return (0);
	return (1);
}

static char	**handle_single_arg(int *argc, char **argv)
{
	char	**arr;
	int		i;
	int		contains_sign;

	i = 0;
	contains_sign = 0;
	if (!argv[1][0])
		return_error(1);
	arr = ft_split(argv[1], ' ');
	if (!arr)
		return_error(1);
	ft_add_address(arr);
	while (arr[i])
	{
		ft_add_address(arr[i]);
		if (!ft_strncmp("-", arr[i], 2) || !ft_strncmp("+", arr[i], 2))
			contains_sign = 1;
		i++;
	}
	if (i < 1 || contains_sign)
		return_error(1);
	*argc = i;
	return (arr);
}

void	parse_args(int *argc, char ***argv)
{
	int		i;
	t_set	set;
	int		num;

	i = 0;
	if (*argc == 2)
		*argv = handle_single_arg(argc, *argv);
	else
	{
		*argc -= 1;
		*argv = *argv + 1;
	}
	init_set(&set, *argc);
	while (i < *argc)
	{
		if (!is_valid_int((*argv)[i]))
			return_error(1);
		num = ft_atoi((*argv)[i]);
		if (in_set(&set, num))
			return_error(1);
		add_to_set(&set, num);
		i++;
	}
}
