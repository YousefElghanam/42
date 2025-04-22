/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jel-ghna <jel-ghna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 19:04:12 by josefelghna       #+#    #+#             */
/*   Updated: 2025/04/22 15:35:03 by jel-ghna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;
	size_t			i;

	p = (unsigned char *)s;
	i = 0;
	while (i++ < n)
		if (*p++ == (unsigned char)c)
			return (p - 1);
	return (0);
}

// #include <stdio.h>
// #include <unistd.h>

// int	main(void)
// {
// 	char	*str;

// 	str = "this is the string";
// 	printf("%p\n", ft_memchr(str, ' ', 5));
// 	write(1, ft_memchr(str, ' ', 5), 5);
// 	return (0);
// }