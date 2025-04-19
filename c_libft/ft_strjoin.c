/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josefelghnam <josefelghnam@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 19:59:28 by josefelghnam      #+#    #+#             */
/*   Updated: 2025/04/17 20:17:48 by josefelghnam     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2);
	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return (0);
	ft_strlcpy(res + ft_strlcpy(res, s1, len + 1), s2, len + 1);
	return (res);
}

// #include <stdio.h>
// int main(void)
// {
// 	printf("%s\n", ft_strjoin("1", "2"));
// 	return (0);
// }