#include "get_next_line.h"

int	has_nl(char *buffer, size_t bytes_read)
{
	size_t	i;

	i = 0;
	while (i < bytes_read)
		if (buffer[i++] == '\n')
			return (i - 1);
	return (-1);
}

char	*mk_line(char **line, size_t *line_len, char *chunk, size_t c_len)
{
	char	*res;

	res = malloc((c_len + *line_len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	if (!chunk)
		return (NULL);
	ft_memcpy(res, *line, *line_len);
	free(*line);
	ft_memcpy(res + *line_len, chunk, c_len);
	*line_len += c_len;
	return (res);
}

char	*line_from_list(t_chunk **node)
{
	t_chunk	*c;
	char	*line;
	size_t	line_len;

	c = *node;
	line_len = 0;
	while (c->next)
	{
		line = mk_line(&line, &line_len, c->chunk, c->size);
		if (!line)
			return (lstclear(node), NULL);
		free(c->chunk);
		*node = c->next;
		free(c);
		c = *node;
	}
	line = mk_line(&line, &line_len, c->chunk, has_nl(c->chunk, c->size) + 2);
	line[line_len] = 0;
	return (line);
}

char	*get_next_line(int fd)
{
	static t_chunk	*node;
	char			buffer[BUFFER_SIZE];
	char			*line;
	size_t			bytes_read;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		if (!lstadd_back(&node, lst_new(buffer, bytes_read)))
			return (lstclear(&node), NULL);
		if (has_nl(buffer, bytes_read) == -1)
			break ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	line = line_from_list(&node);
	// del_line_in_list(&node);
	return (line);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test", O_RDWR);
	line = get_next_line(fd);
	printf("%s\n", line);
	line = get_next_line(fd);
	printf("%s\n", line);
	return (0);
}
