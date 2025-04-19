/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josefelghnam <josefelghnam@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 00:10:19 by josefelghnam      #+#    #+#             */
/*   Updated: 2025/04/19 00:40:01 by josefelghnam     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (fd < 0)
		return ;
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

// #include <fcntl.h>
// #include <unistd.h>
// int main(void)
// {
// 	int fd;

// 	fd = open("test", O_RDWR);
// 	ft_putendl_fd("HIHIHIH", fd);
// 	ft_putendl_fd("SECOND LINE", fd);
// 	close(fd);
// 	return (0);
// }