/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jel-ghna <jel-ghna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 10:35:50 by josefelghna       #+#    #+#             */
/*   Updated: 2025/04/22 17:43:57 by jel-ghna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char		*ptr;

	if (nmemb * size == 0)
		return (malloc(0));
	if (size && nmemb > SIZE_MAX / size)
		return (0);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (0);
	return (ft_memset(ptr, 0, nmemb * size));
}

// #include <stdio.h>
// int main(void)
// {
// 	char	*ptr = ft_calloc(2, 2);
// 	// free(ptr);
// 	printf("%d", ptr[0]);
// 	printf("%d", ptr[1]);
// 	printf("%d", ptr[2]);
// 	printf("%d", ptr[3]);
// 	// printf("%d", ptr[4]);
// 	free(ptr);
// 	return (0);
// }