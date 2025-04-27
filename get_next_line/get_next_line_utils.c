#include "get_next_line.h"

// char	*dupstr(const char *s)
// {
// 	char	*p;
// 	size_t	i;

// 	i = 0;
// 	while (s[i])
// 		i++;
// 	p = malloc((i + 1) * sizeof(char));
// 	if (!p)
// 		return (0);
// 	while (i--)
// 		p[i] = s[i];
// 	p[0] = s[0];
// 	return (p);
// }

// void	lstclear(t_str_list **lst)
// {
// 	t_str_list	*next;

// 	while (*lst)
// 	{
// 		next = (*lst)->next;
// 		free((*lst)->str);
// 		free((*lst));
// 		*lst = next;
// 	}
// 	*lst = NULL;
// }

// int	lstadd_back(t_str_list **lst, t_str_list *new)
// {
// 	t_str_list	*node;

// 	if (!new)
// 		return (0);
// 	node = *lst;
// 	if (!node)
// 		return (*lst = new, 1);
// 	while (node->next)
// 		node = node->next;
// 	node->next = new;
// 	return (1);
// }

// t_str_list	*lst_new(char *str)
// {
// 	t_str_list	*node;

// 	node = malloc(sizeof(t_str_list));
// 	if (!node)
// 		return (NULL);
// 	node->str = (dupstr(str));
// 	node->next = 0;
// 	return (node);
// }

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}


size_t	ft_strlcpy(char *dst, const char *src, size_t dsize)
{
	size_t	i;

	i = 0;
	while (src[i] && i < dsize - 1 && dsize)
	{
		dst[i] = src[i];
		i++;
	}
	if (dsize > 0)
		dst[i] = 0;
	return (ft_strlen(src));
}

static size_t	len_till_delimiter(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (*s && *s != c)
	{
		s++;
		i++;
	}
	return (i);
}

static int	one_more_string(char ***res, size_t size, char const *s, char c)
{
	char	**new_res;
	char	*sub_string;
	size_t	sub_size;
	size_t	i;

	i = -1;
	new_res = malloc((size + 1) * sizeof(char *));
	if (!new_res)
		return (0);
	while (++i < size)
		new_res[i] = (*res)[i];
	free(*res);
	*res = new_res;
	sub_size = len_till_delimiter(s, c);
	sub_string = malloc((sub_size + 1) * sizeof(char));
	if (!sub_string)
	{
		while (i > 0)
			free(res[i--]);
		free(res);
		return (0);
	}
	ft_strlcpy(sub_string, s, sub_size + 1);
	(*res)[i] = sub_string;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	char	**tmp;
	size_t	i;

	i = 0;
	res = 0;
	while (*s)
	{
		if (*s != c)
		{
			if (!one_more_string(&res, i, s, c))
				return (0);
			while (*s && *s != c)
				s++;
			i++;
		}
		while (*s && *s == c)
			s++;
	}
	tmp = malloc((i + 1) * sizeof(char *));
	ft_memcpy(tmp, res, i * sizeof(char *));
	free(res);
	tmp[i] = NULL;
	return (tmp);
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