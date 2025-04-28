/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jel-ghna <jel-ghna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 00:37:43 by josefelghna       #+#    #+#             */
/*   Updated: 2025/04/28 13:17:41 by jel-ghna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (fd < 0)
		return ;
	ft_putstr_fd(ft_itoa(n), fd);
}

// #include <fcntl.h>
// #include <unistd.h>

// int	main(void)
// {
// 	int	fd;

// 	fd = open("test", O_RDWR);
// 	ft_putnbr_fd(3, fd);
// 	return (0);
// }