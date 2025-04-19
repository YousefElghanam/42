/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josefelghnam <josefelghnam@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 10:35:50 by josefelghnam      #+#    #+#             */
/*   Updated: 2025/04/17 19:13:36 by josefelghnam     ###   ########.fr       */
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
// 	char	*ptr = ft_calloc(5, 1);
// 	printf("%d", ptr[0]);
// 	printf("%d", ptr[1]);
// 	printf("%d", ptr[2]);
// 	printf("%d", ptr[3]);
// 	printf("%d", ptr[4]);
// 	free(ptr);
// 	return (0);
// }