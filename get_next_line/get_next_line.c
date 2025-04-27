#include "get_next_line.h"

// size_t	linelen(t_str_list *node)
// {
// 	size_t	len;
// 	size_t	i;
	
// 	i = 0;
// 	len = 0;
// 	while (node)
// 	{
// 		i = 0;
// 		while (node->str[i] && node->str[i] != '\n')
// 		{
// 			i++;
// 			len++;
// 		}
// 		node = node->next;
// 	}
// 	return (len);
// }

// char	*get_line(t_str_list **list)
// {
// 	size_t		i;
// 	t_str_list	*node;
// 	char		*line;
// 	size_t		node_i;

// 	i = 0;
// 	node = *list;
// 	line = malloc((linelen(node) + 1) *sizeof(char));
// 	if (!line)
// 		return (NULL);
// 	while (node)
// 	{
// 		node_i = 0;
// 		while (node->str[node_i] && node->str[node_i] != '\n')
// 			line[i++] = node->str[node_i++];
// 		node = node->next;
// 	}
// 	line[i] = 0;
// 	return (line);
// }

// int	has_nl(char *str)
// {
// 	size_t	i;

// 	i = 0;
// 	while (i < BUFFER_SIZE)
// 		if (str[i++] == '\n')
// 			return (i - 1);
// 	return (0);
// }

// void	fix_list(t_str_list **list)
// {
// 	t_str_list	*node;
// 	t_str_list	*next;

// 	node = *list;
// 	while (node->next)
// 	{
// 		free(node->str);
// 		next = node->next;
// 		free(node);
// 		node = next;
// 	}
// 	*list = lst_new((node->str) + has_nl(node->str));
// 	printf("%s\n", (*list)->str);
// }

// char	*get_next_line(int fd)
// {
// 	static t_str_list	*list;
// 	char				*buffer;
// 	int					bytes_read;
// 	char				*line;

// 	buffer = malloc(BUFFER_SIZE + 1);
// 	bytes_read = read(fd, buffer, BUFFER_SIZE);
// 	while (bytes_read > 0 && !has_nl(buffer))
// 	{
// 		buffer[bytes_read] = 0;
// 		if (!lstadd_back(&list, lst_new(buffer)))
// 			return (lstclear(&list), NULL);
// 		bytes_read = read(fd, buffer, BUFFER_SIZE);
// 	}
// 	// line = malloc((strlen_fromlist(list) + 1) * sizeof(char));
// 	line = get_line(&list);
// 	fix_list(&list);
// 	return (line);
// }

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

char	*grow_file(char *file, size_t *file_size, size_t total_read)
{
	char	*res;

	res = malloc(*file_size + BUFFER_SIZE);
	if (!res)
		return (NULL);
	*file_size += BUFFER_SIZE;
	ft_memcpy(res, file, total_read);
	free(file);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	**arr;
	static int	i;
	char		*file;
	int			bytes_read;
	int			total_read;
	size_t		file_size;

	if (!arr)
	{
		total_read = 0;
		file_size = BUFFER_SIZE;
		file = malloc(BUFFER_SIZE);
		bytes_read = read(fd, file, BUFFER_SIZE);
		while (bytes_read)
		{
			total_read += bytes_read;
			if ((size_t)total_read >= file_size)
				file = grow_file(file, &file_size, total_read);
			bytes_read = read(fd, file + total_read, BUFFER_SIZE);
		}
		file[total_read] = 0;
		arr = ft_split(file, '\n');
		free(file);
	}
	if (arr[i])
		return (arr[i++]);
	return (NULL);
}

int	main(void)
{
	char	*x;
	int		fd;

	fd = open("test", O_RDWR);
	x = get_next_line(fd);
	if (x)
		printf("%s\n", x);
	return (0);
}
