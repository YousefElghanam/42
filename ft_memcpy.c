/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jel-ghna <jel-ghna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 21:53:53 by josefelghna       #+#    #+#             */
/*   Updated: 2025/04/22 13:49:59 by jel-ghna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*p_src;
	unsigned char	*p_dest;

	p_src = (unsigned char *)src;
	p_dest = (unsigned char *)dest;
	if (!n)
		return (dest);
	if ((src <= dest && dest <= (src + n - 1))
		|| (dest <= src && src <= (dest + n - 1)))
		return (ft_memmove(dest, src, n));
	while (n--)
		*p_dest++ = *p_src++;
	return (dest);
}

// #include <stdio.h>
// #include <unistd.h>

// int	main(void)
// {
// 	char	*str = ft_strdup("this is the string!!!");
// 	char	*dst = malloc(22 * sizeof(char));

// 	printf("%s\n", (char *)ft_memcpy(dst, str, 5));
// 	write(1, dst, 30);
// 	return (0);
// }