/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josefelghnam <josefelghnam@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 21:55:08 by josefelghnam      #+#    #+#             */
/*   Updated: 2025/04/16 19:42:16 by josefelghnam     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dsize)
{
	size_t	i_dst;
	size_t	i_src;
	size_t	len;

	i_dst = 0;
	i_src = 0;
	len = ft_strlen(src);
	while (dst[i_dst] && i_dst < dsize)
		i_dst++;
	if (i_dst == dsize)
		return (len + dsize);
	len += i_dst;
	while (src[i_src] && i_dst + 1 < dsize)
		dst[i_dst++] = src[i_src++];
	dst[i_dst] = 0;
	return (len);
}
