/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josefelghnam <josefelghnam@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 23:56:06 by josefelghnam      #+#    #+#             */
/*   Updated: 2025/04/19 00:01:48 by josefelghnam     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (fd < 0)
		return ;
	while (*s)
		ft_putchar_fd(*s++, fd);
}

// #include <fcntl.h>
// int main(void)
// {
// 	int fd;

// 	fd = open("test", O_RDWR);
// 	ft_putstr_fd("q", fd);
// 	return (0);
// }