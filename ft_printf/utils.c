#include "ft_printf.h"

int	is_valid_spec(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
	|| c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

t_llist	*init_list(void)
{
	t_llist	*list;

	list = malloc(sizeof(t_llist));
	if (!list)
		return (NULL);
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
	return (list);
}

t_node	*new_node(char *str, size_t size)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->str = malloc(size * sizeof(char));
	if (!(node->str))
		return (free(node), NULL);
	node->size = size;
	ft_memcpy(node->str, str, size);
	node->next = NULL;
	return (node);
}

int	add_node(t_llist *list, t_node *node)
{
	if (!node)
		return (0);
	if (!list)
		list->head = node;
	else
		list->tail->next = node;
	list->tail = node;
	list->size += 1;
	return (1);
}

void	clear_list(t_llist **list)
{
	t_node	*node;
	t_node	*next;

	node = (*list)->head;
	while ((*list)->size)
	{
		free(node->str);
		next = node->next;
		(*list)->size -= 1;
		free(node);
		node = next;
	}
	free(*list);
	*list = NULL;
}

void	*ft_memcpy(void *dest, const void *src, ssize_t n)
{
	unsigned char	*p_src;
	unsigned char	*p_dest;

	p_src = (unsigned char *)src;
	p_dest = (unsigned char *)dest;
	if (!n)
		return (dest);
	while (n--)
		*p_dest++ = *p_src++;
	return (dest);
}

// ssize_t	count_specs(char *format)
// {
// 	ssize_t count;

// 	count = 0;
// 	while (*format)
// 	{
// 		if (*format == '%')
// 		{
// 			if (!is_valid_spec(*(format + 1)))
// 				return (-1);
// 			if (*(format + 1) != '%')
// 				count++;
// 			format++;
// 		}
// 		format++;
// 	}
// 	printf("COUNT IS ((%zd))\n", count);
// 	return (count);
// }

// int	handle_spec_arg_counts(const char *format, va_list args)
// {
// 	ssize_t	count;
	
// 	count = count_specs(format);
// 	if (count == -1)
// 		return (-1);
	
// }