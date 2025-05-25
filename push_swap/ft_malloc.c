#include "push_swap.h"

void	ft_delete(void *ptr)
{
	free(ptr);
}

t_list	**ft_alloc_list(void)
{
	static t_list	**ptr;

	if (ptr == NULL)
	{
		ptr = malloc(sizeof(t_list **));
		if (!ptr)
			return_error(2);
		*ptr = NULL;
	}
	return (ptr);
}

static void	ft_add_address(void *ptr)
{
	void	*node;
	t_list	**list;

	list = ft_alloc_list();
	node = ft_lstnew(ptr);
	if (!node)
		ft_lstclear(list, &ft_delete);
	ft_lstadd_back(list, node);
}

void	*ft_malloc(size_t size)
{
	void	*ptr;
	t_list	**list;

	list = ft_alloc_list();
	ptr = malloc(size);
	if (!ptr)
		return (ft_lstclear(list, &ft_delete), NULL);
	ft_add_address(ptr);
	return (ptr);
}
