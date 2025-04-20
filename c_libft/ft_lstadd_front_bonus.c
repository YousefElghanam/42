/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josefelghnam <josefelghnam@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 19:52:04 by josefelghnam      #+#    #+#             */
/*   Updated: 2025/04/20 23:40:47 by josefelghnam     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

// #include <stdio.h>
// void	del(void *content)
// {
// 	free(content);
// }

// void	*to_upper(void *content)
// {
// 	char	*res;
// 	char	*str;
// 	size_t	i;

// 	i = 0;
// 	str = (char *)content;
// 	res = ft_strdup(str);
// 	while (res[i])
// 	{
// 		res[i] = ft_toupper(res[i]);
// 		i++;
// 	}
// 	return (res);
// }

// int		main(void)
// {
// 	t_list	*lst;
// 	t_list	*tmp;

// 	//Always initialize :D
// 	lst = 0;

// 	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("the content :O")));
// 	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("Bombombini Guzini")));
// 	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("i'm the captain now")));
// 	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("this is the last")));
// 	tmp = lst;
// 	while (tmp)
// 	{
// 		printf("%s\n", (char *)tmp->content);
// 		tmp = tmp->next;
// 	}
// 	printf("\n");
// 	// printf("%d\n", ft_lstsize(lst));
// 	// if (lst)
// 	// 	printf("%s\n", (char *)ft_lstlast(lst)->content);
// 	// else
// 	// 	printf("list is empty, idiot :D\n");
// 	//////////////////////////////////////////
// 	// ft_lstclear(&lst, &del);
// 	// printf("\n");
// 	// if (lst)
// 	// 	printf("list not empty, smth wrong, should be cleared\n");
// 	// else
// 	// 	printf("list is empty, idiot :D (cleared)\n");
// 	/////////////////////////////////////////
// 	t_list *new_list = ft_lstmap(lst, &to_upper, &del);
// 	while (new_list)
// 	{
// 		printf("%s\n", (char *)new_list->content);
// 		new_list = new_list->next;
// 	}
// 	return (0);
// }