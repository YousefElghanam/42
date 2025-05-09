/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jel-ghna <jel-ghna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 18:07:12 by jel-ghna          #+#    #+#             */
/*   Updated: 2025/05/09 18:34:34 by jel-ghna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_sign(char c, va_list args, int *count)
{
	if (c == '%')
		*count += write(1, "%", 1);
	else if (c == 'c')
		*count += write_c(va_arg(args, int));
	else if (c == 's')
		*count += write_s(va_arg(args, char *));
	else if (c == 'p')
		*count += write_p(va_arg(args, void *));
	else if (c == 'd' || c == 'i')
		*count += write_di(va_arg(args, int));
	else if (c == 'u')
		*count += write_u(va_arg(args, unsigned int));
	else if (c == 'x')
		*count += write_x(va_arg(args, unsigned int));
	else if (c == 'X')
		*count += write_cap_x(va_arg(args, unsigned int));
}

int	parse_format(const char *format, va_list args, int *count)
{
	size_t	i;
	size_t	len;
	char	*ptr;

	i = -1;
	while (format[++i])
	{
		ptr = ft_strchr(&format[i], '%');
		if (!ptr)
			return (*count += ft_putstr_fd((char *)&format[i], 1), 0);
		len = (size_t)(ptr - &format[i]);
		write(1, &format[i], len);
		i += len + 1;
		*count += len;
		if (!is_valid_sign(format[i]))
		{
			*count += 2;
			write(1, format + 1, 2);
		}
		else if (format[i])
			handle_sign(format[i], args, count);
	}
	return (1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	if (!format)
		return (-1);
	if (!ft_strchr(format, '%'))
		return (write(1, format, strlen(format)));
	va_start(args, format);
	parse_format(format, args, &count);
	va_end(args);
	return (count);
}

// int main(void)
// {
// 	// char *str = "hello<<";
// 	int	x;
// 	int	y;

// 	// printf("============== NULL as format ==============\n");
// 	// printf("\n            == 0 as a pointer ==\n");
// 	// printf("fn returned %zd\n", count_specs("how many are these ?ds %%"));
// 	// x = 			printf("%dn\0", 20);
// 	y = 		 ft_printf(">%shhh=====++++0000%");
// 	printf("\n%d", y);
// 	return (0);
// }
