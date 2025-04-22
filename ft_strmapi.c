/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josefelghnam <josefelghnam@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 22:32:35 by josefelghnam      #+#    #+#             */
/*   Updated: 2025/04/18 23:36:56 by josefelghnam     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	len;
	char			*res;

	i = -1;
	len = ft_strlen(s);
	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return (0);
	while (s[++i])
		res[i] = f(i, (s[i]));
	return (res);
}

// char	to_upper(unsigned int i, char c)
// {
// 	if (i < 15)
// 		if (97 <= c && c <= 122)
// 			return (c - 32);
// 	return (c);
// }

// #include <stdio.h>
// int main(void)
// {
// 	printf("%s\n", ft_strmapi("this will be capital", &to_upper));
// 	return (0);
// }
