/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jel-ghna <jel-ghna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 19:43:19 by josefelghna       #+#    #+#             */
/*   Updated: 2025/04/22 17:29:58 by jel-ghna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	lil_len;

	if (len == 0)
		return (0);
	i = 0;
	lil_len = ft_strlen(little);
	if (lil_len == 0)
		return ((char *)big);
	while (i + lil_len <= ft_strlen(big) && i + lil_len <= len)
	{
		if (ft_strncmp(big + i, little, lil_len) == 0)
			return ((char *)big + i);
		i++;
	}
	return (0);
}

// #include <stdio.h>
// #include <unistd.h>

// int	main(void)
// {
// 	// write(1, ft_strnstr("VeryBigString", "Big", 7), 40);
// 	printf("%s\n", ft_strnstr("VeryBigString1", "1", 14));
// 	return (0);
// }