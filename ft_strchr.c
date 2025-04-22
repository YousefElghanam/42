/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jel-ghna <jel-ghna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 18:08:22 by josefelghna       #+#    #+#             */
/*   Updated: 2025/04/22 14:47:06 by jel-ghna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	while (*s++)
		if (*(s - 1) == c)
			return ((char *)(s - 1));
	if (c == 0)
		return ((char *)s);
	return (0);
}

// #include <stdio.h>
// #include <unistd.h>

// int	main(void)
// {
// 	char	*str;

// 	str = "this is the string";
// 	printf("%p\n", ft_strchr(str, 'i'));
// 	write(1, ft_strchr(str, 'i'), 1);
// 	return (0);
// }