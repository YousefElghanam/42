#include "ft_printf.h"


char	*ft_strchr(const char *s, int c)
{
	while (*s++)
		if (*(s - 1) == c)
			return ((char *)(s - 1));
	if (c == 0)
		return ((char *)(s - 1));
	return (NULL);
}

size_t	sub_len(const char *format)
{
	char	*p;

	p = ft_strchr(format, '%');
	if (p)
		return (p - format);
	return ft_strlen(format);
}

int	handle_specifier(va_list args, const char *format, size_t *i, t_list **list)
{
	int	res;
	
	res = 0;
	if (format[1] == '%')
		if (!add_node(*list, new_node(ft_strdup("%"), 1)))
			return (clear_list(list), -1);
	else if (format[1] == 's')
		res = add_string(list, va_arg(args, char*));
	else if (format[1] == 'c')
		res = add_char(list, va_arg(args, char));
	else if (format[1] == 'p')
		res = add_pointer(list, va_arg(args, void*));
	else if (format[1] == 'd' || format[1] == 'i')
		res = add_decimal(list, va_arg(args, int));
	else if (format[1] == 'u')
		res = add_udecimal(list, va_arg(args, unsigned int)); // need recheck
	else if (format[1] == 'x')
		res = add_lowhex(list, va_arg(args, unsigned int));
	else if (format[1] == 'X')
		res = add_upphex(list, va_arg(args, unsigned int));
	return (res);
}

ssize_t	make_list(va_list args, const char *format, t_list **list)
{
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	va_arg(args, char*);
	while (format[i])
	{
		len = sub_len(&format[i]);
		if (len)
			if (!add_node(*list, new_node(&format[i], len)))
				return (clear_list(list), -1);
		i += len;
		if (format[i] == '%')
			if (!handle_specifier(args, format + i, &i, list))
				return (clear_list(list), -1);
		if (format[i])
			i++;
	}
}

ssize_t	ft_printf(const char *format, ...)
{
	va_list	args;
	char	vars;
	ssize_t	count;
	t_list	*list;

	count = 0;
	if (!format)
		return (-1);
	if (!ft_strchr(format, '%'))
		return (va_end(args), write(1, format, strlen(format)));
	va_start(args, format);
	list = init_list();
	if (!list)
		return (-1);
	if (!make_list(args, format, &list))
		return (-1);
	count = write_list(list);
	// if (!handle_spec_arg_counts(format, args_copy))
	// 	return (0);
	va_end(args);
	return (count);
}

int main(void)
{
	// char *str = "hello<<";

	printf("============== NULL as format ==============\n");
	printf("\n== 0 as a pointer ==\n\n");
	// printf("fn returned %zd\n", count_specs("how many are these ?ds %%"));
	printf("<== ORIG || Count ==> (%d)\n",    printf("%xhi", 2147483648));
	// printf("<== MINE => Count:(%d)\n", ft_printf(NULL, -5));

	// printf("============== Handling %%s ==============\n");
	// printf("\n== 0 as a pointer ==\n\n");
	// printf("<== ORIG => Count:(%d)\n",    printf("sss%s", 0));
	// printf("<== MINE => Count:(%d)\n", printf("sss%s", -1));

	// printf("\n== -1 as a pointer ==\n\n");
	// printf("<== ORIG => Count:(%d)\n",    printf("sss%s", -1));
	// printf("<== MINE => Count:(%d)\n", ft_printf("sss%s", -1));

	// printf("\n== -5 as a pointer ==\n\n");
	// printf("<== ORIG => Count:(%d)\n",    printf("sss%s", -5));
	// printf("<== MINE => Count:(%d)\n", ft_printf("sss%s", -5));

	// printf("\n== A positive num as a pointer ==\n\n");
	// printf("<== ORIG => Count:(%d)\n",    printf("sss%s", 24));
	// printf("<== MINE => Count:(%d)\n", ft_printf("sss%s", 24));

	// printf("\n== 0 as a pointer ==\n\n");
	// printf("<== ORIG => Count:(%d)\n",    printf("sss%s", 0));
	// printf("<== MINE => Count:(%d)\n", ft_printf("sss%s", 0));

	// printf("\n== 0 as a pointer ==\n\n");
	// printf("<== ORIG => Count:(%d)\n",    printf("sss%s", 0));
	// printf("<== MINE => Count:(%d)\n", ft_printf("sss%s", 0));

	// printf("\n== 0 as a pointer ==\n\n");
	// printf("<== ORIG => Count:(%d)\n",    printf("sss%s", 0));
	// printf("<== MINE => Count:(%d)\n", ft_printf("sss%s", 0));

	// printf("\n== 0 as a pointer ==\n\n");
	// printf("<== ORIG => Count:(%d)\n",    printf("sss%s", 0));
	// printf("<== MINE => Count:(%d)\n", ft_printf("sss%s", 0));

	
	return (0);
}
