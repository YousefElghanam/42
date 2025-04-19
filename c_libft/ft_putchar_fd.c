/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josefelghnam <josefelghnam@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 23:52:27 by josefelghnam      #+#    #+#             */
/*   Updated: 2025/04/19 00:01:24 by josefelghnam     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}

// #include <fcntl.h>
// int main(void)
// {
// 	int fd;

// 	fd = open("test", O_RDWR);
// 	ft_putchar_fd('s', fd);
// 	return (0);
// }
