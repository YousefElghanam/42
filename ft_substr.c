/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josefelghnam <josefelghnam@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 19:22:05 by josefelghnam      #+#    #+#             */
/*   Updated: 2025/04/17 19:58:46 by josefelghnam     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (len == 0 || s_len <= start)
		return (malloc(0));
	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return (0);
	ft_strlcpy(res, s + start, len + 1);
	return (res);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char	*sub;

// 	sub = ft_substr("ThiS_Will_be_COPIED", 0, 0);
// 	printf("%s\n", sub);
// 	free(sub);
// 	return (0);
// }