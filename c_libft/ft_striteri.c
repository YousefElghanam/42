/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josefelghnam <josefelghnam@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 22:34:05 by josefelghnam      #+#    #+#             */
/*   Updated: 2025/04/18 23:35:34 by josefelghnam     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (*s)
	{
		f(i, s);
		s++;
		i++;
	}
}

// void	to_upper(unsigned int i, char *c)
// {
// 	if (i < 15)
// 		if (97 <= *c && *c <= 122)
// 			*c = *c - 32;
// }

// #include <stdio.h>
// int main(void)
// {
// 	char	str[] = "this will be capital";
// 	ft_striteri(str, &to_upper);
// 	printf("%s\n", str);
// 	return (0);
// }