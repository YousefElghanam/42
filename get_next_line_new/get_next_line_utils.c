#include "get_next_line.h"

void	lstclear(t_chunk **lst)
{
	t_chunk	*next;

	while (*lst)
	{
		next = (*lst)->next;
		free((*lst)->chunk);
		free((*lst));
		*lst = next;
	}
	*lst = NULL;
}

int	lstadd_back(t_chunk **lst, t_chunk *new)
{
	t_chunk	*node;

	if (!new)
		return (0);
	node = *lst;
	if (!node)
		return (*lst = new, 1);
	while (node->next)
		node = node->next;
	node->next = new;
	return (1);
}

t_chunk	*lst_new(char *str, size_t bytes_read)
{
	t_chunk	*node;
	size_t	i;

	i = -1;
	node = malloc(sizeof(t_chunk));
	if (!node)
		return (NULL);
	node->chunk = malloc(bytes_read * sizeof(char));
	if (!(node->chunk))
		return (NULL);
	while (++i < bytes_read)
		(node->chunk)[i] = str[i];
	node->next = 0;
	return (node);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
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
