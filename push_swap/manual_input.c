/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manual_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jel-ghna <jel-ghna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 12:18:23 by jel-ghna          #+#    #+#             */
/*   Updated: 2025/06/15 12:18:23 by jel-ghna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	add_to_argv(int *argc, char ***argv, char **line)
{
	char	**new_argv;
	int		i;

	i = 1;
	new_argv = ft_malloc((*argc + 1) * sizeof(char *));
	if (!new_argv)
		return_error(1);
	new_argv[0] = (*argv)[0];
	while (i > 0 && i < *argc)
	{
		new_argv[i] = (*argv)[i];
		i++;
	}
	new_argv[i] = *line;
	*argv = new_argv;
}

void	manual_input(int *argc, char ***argv)
{
	char	*line;

	line = get_next_line(0);
	ft_add_address(line);
	while (line)
	{
		line[ft_strlen(line) - 1] = 0;
		add_to_argv(argc, argv, &line);
		*argc += 1;
		line = get_next_line(0);
		ft_add_address(line);
	}
}
