/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josefelghnam <josefelghnam@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 19:43:19 by josefelghnam      #+#    #+#             */
/*   Updated: 2025/04/16 20:16:04 by josefelghnam     ###   ########.fr       */
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
	while (i + lil_len <= len)
		if (ft_strncmp(big + i, little, lil_len) == 0)
			return ((char *)big + i);
	return (0);
}
