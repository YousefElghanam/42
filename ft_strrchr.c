/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jel-ghna <jel-ghna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 18:30:46 by josefelghna       #+#    #+#             */
/*   Updated: 2025/04/22 14:55:39 by jel-ghna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*res;

	res = 0;
	while (*s++)
		if (*(s - 1) == c)
			res = (char *)(s - 1);
	if (c == 0)
		return ((char *)s);
	return (res);
}

// #include <stdio.h>
// #include <unistd.h>

// int	main(void)
// {
// 	char	*str;

// 	str = "this is the string";
// 	printf("%s\n", ft_strrchr(str, 'i'));
// 	write(1, ft_strrchr(str, 'i'), 3);
// 	return (0);
// }