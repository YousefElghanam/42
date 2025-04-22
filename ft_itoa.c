/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josefelghnam <josefelghnam@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:33:23 by josefelghnam      #+#    #+#             */
/*   Updated: 2025/04/18 22:31:31 by josefelghnam     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	num_len(int n)
{
	size_t	len;
	int		num;

	len = 1;
	num = n;
	if (num < 0)
	{
		num = -num;
		len++;
	}
	while (num / 10)
	{
		num /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	size_t	len;
	char	*res;
	long	num;

	num = (long)n;
	len = num_len(n);
	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return (0);
	res[len] = 0;
	if (n < 0)
	{
		res[0] = '-';
		num = -num;
	}
	while (num && len--)
	{
		res[len] = (num % 10) + '0';
		num /= 10;
	}
	if (n == 0)
		res[0] = '0';
	return (res);
}

// #include <stdio.h>
// int main(void)
// {
// 	printf("%s\n", ft_itoa(233));
// 	return (0);
// }