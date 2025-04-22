/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josefelghnam <josefelghnam@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 18:30:46 by josefelghnam      #+#    #+#             */
/*   Updated: 2025/04/16 18:34:46 by josefelghnam     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*res;

	res = 0;
	while (1)
	{
		if (*s == (char)c)
			res = (char *)s;
		if (*s == 0)
			break ;
		s++;
	}
	return (res);
}
