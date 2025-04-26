#include "get_next_line.h"

char	*dupstr(const char *s)
{
	char	*p;
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	p = malloc((i + 1) * sizeof(char));
	if (!p)
		return (0);
	while (i--)
		p[i] = s[i];
	p[0] = s[0];
	return (p);
}

void	lstclear(t_str_list **lst)
{
	t_str_list	*next;

	while (*lst)
	{
		next = (*lst)->next;
		free((*lst)->str);
		free((*lst));
		*lst = next;
	}
	*lst = NULL;
}

int	lstadd_back(t_str_list **lst, t_str_list *new)
{
	t_str_list	*node;

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

t_str_list	*lst_new(char *str)
{
	t_str_list	*node;

	node = malloc(sizeof(t_str_list));
	if (!node)
		return (NULL);
	node->str = (dupstr(str));
	node->next = 0;
	return (node);
}

// size_t	linelen(const char *s)
// {
// 	int	i;

// 	i = 0;
// 	while (s[i] != '\n')
// 		i++;
// 	return (i + 1);
// }

// size_t	linelcpy(char *dst, const char *src, size_t dsize)
// {
// 	size_t	i;

// 	i = 0;
// 	while (src[i] != '\n' && i < dsize - 1)
// 	{
// 		dst[i] = src[i];
// 		i++;
// 	}
// 	if (dsize > 0)
// 		dst[i] = '\n';
// 	return (linelen(src));
// }

// char	*linedup(const char *s)
// {
// 	size_t	len;
// 	char	*p;

// 	len = linelen(s) + 1;
// 	p = malloc(len * sizeof(char));
// 	if (!p)
// 		return (0);
// 	p[len - 1] = 0;
// 	linelcpy(p, s, len);
// 	return (p);
// }

// void	*my_memchr(const void *s, int c, size_t n)
// {
// 	unsigned char	*p;
// 	size_t			i;

// 	p = (unsigned char *)s;
// 	i = 0;
// 	while (i++ < n)
// 		if (*p++ == (unsigned char)c)
// 			return (p - 1);
// 	return (0);
// }