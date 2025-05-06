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

ssize_t	make_list(va_list args, const char *format)
{
	t_list	*list;
	size_t	len;
	size_t	i;

	list = init_list();
	if (!list)
		return (-1);
	len = 0;
	i = 0;
	va_arg(args, char*);
	while (format[i])
	{
		len = sub_len(&format[i]);
		if (len)
			if (!add_node(list, new_node(&format[i], len)))
				return (clear_list, -1);
		i += len;
		add_format(format, *i, list);
	}
}

ssize_t	ft_printf(const char *format, ...)
{
	va_list	args;
	char	vars;
	ssize_t	count;

	count = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	make_list(args, format);
	// if (!handle_spec_arg_counts(format, args_copy))
	// 	return (0);
	if (!ft_strchr(format, '%'))
		return (va_end(args), write(1, format, strlen(format)));
	va_end(args);
	return (0);
}

int main(void)
{
	// char *str = "hello<<";

	printf("============== NULL as format ==============\n");
	printf("\n== 0 as a pointer ==\n\n");
	// printf("fn returned %zd\n", count_specs("how many are these ?ds %%"));
	printf("<== ORIG || Count ==> (%d)\n",    ft_printf("hello this is it%s second sub%s third sub%s 4th sub", "hi", "he", "ho"));
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
