/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jel-ghna <jel-ghna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 20:53:07 by josefelghna       #+#    #+#             */
/*   Updated: 2025/04/23 17:43:02 by jel-ghna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	len_till_delimiter(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (*s && *s != c)
	{
		s++;
		i++;
	}
	return (i);
}

static int	one_more_string(char ***res, size_t size, char const *s, char c)
{
	char	**new_res;
	char	*sub_string;
	size_t	sub_size;
	size_t	i;

	i = -1;
	new_res = malloc((size + 1) * sizeof(char *));
	if (!new_res)
		return (0);
	while (++i < size)
		new_res[i] = (*res)[i];
	free(*res);
	*res = new_res;
	sub_size = len_till_delimiter(s, c);
	sub_string = malloc((sub_size + 1) * sizeof(char));
	if (!sub_string)
	{
		while (i > 0)
			free(res[i--]);
		free(res);
		return (0);
	}
	ft_strlcpy(sub_string, s, sub_size + 1);
	(*res)[i] = sub_string;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	i;

	i = 0;
	res = 0;
	while (*s)
	{
		if (*s != c)
		{
			if (!one_more_string(&res, i, s, c))
				return (0);
			while (*s && *s != c)
				s++;
			i++;
		}
		while (*s && *s == c)
			s++;
	}
	if (!one_more_string(&res, i, s, c))
		return (0);
	res[i] = NULL;
	return (res);
}

// #include <stdio.h>
// int main(void)
// {
// 	char **res = ft_split("	This is the 	splitted string", '	');
// 	for (int i = 0; res[i]; i++)
// 	{
// 		printf("%s\n", res[i]);
// 		free(res[i]);
// 	}
// 	free(res);
// 	return (0);
// }