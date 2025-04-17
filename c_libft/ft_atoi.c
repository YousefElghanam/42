/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josefelghnam <josefelghnam@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 20:17:04 by josefelghnam      #+#    #+#             */
/*   Updated: 2025/04/17 14:53:23 by josefelghnam     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int		i;
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
	while ('0' <= nptr[i] && nptr[i] <= '9')
		res = res * 10 + (nptr[i++] - '0');
	if (res > 2147483647 && sign == 1)
		return (2147483647);
	if (res > 2147483648 && sign == -1)
		return (-2147483648);
	return ((int)res * sign);
}

// #include <stdio.h>
// int main(void)
// {
// 	printf("%d\n", ft_atoi("+2342"));
// 	printf("%d\n", ft_atoi("-2342"));
// 	printf("%d\n", ft_atoi("\t\n\v\f\r2342"));
// 	printf("%d\n", ft_atoi("   	+2342"));
// 	printf("%d\n", ft_atoi("   	-2342"));
// 	printf("%d\n", ft_atoi("   	2342"));
// 	printf("%d\n", ft_atoi("   	++2342"));
// 	printf("%d\n", ft_atoi("   	2147483646"));
// 	printf("%d\n", ft_atoi("   	2147483649"));
// 	printf("%d\n", ft_atoi("   	-2147483647"));
// 	printf("%d\n", ft_atoi("   	"));
// 	printf("%d\n", ft_atoi("   	00"));
// 	printf("%d\n", ft_atoi("   	0001"));
// 	printf("%d\n", ft_atoi("   	-01"));
// 	printf("%d\n", ft_atoi("   	-"));
// 	return (0);
// }