#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_set
{
	size_t	capacity;
	size_t	cur_size;
	int		*arr;
}	t_set;

typedef struct s_node
{
	int				num;
	size_t			position;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	size_t	size;
	t_node	*head;
	t_node	*top;
}	t_stack;

void	validate_args(size_t argc, char **argv);
void	solve(t_stack *stack_a, t_stack *stack_b, t_stack *sorted_stack);

t_stack	*init_stack_a(size_t n_count, char **argv);
t_stack	*init_stack_b(void);
t_stack	*init_sorted_stack(t_stack *stack);

t_node	*new_node(int num);
void	push_node(t_node *node, t_stack *stack);
void	fill_arr(int *arr, t_stack *stack);
void	sort_arr(int *arr, size_t size);
t_stack	*arr_to_stack(int *arr, size_t size);

void	init_set(t_set *set, size_t arg_count);
int		in_set(t_set *set, int num);
void	add_to_set(t_set *set, int num);

void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);
void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rra(t_stack *stack);
void	rrb(t_stack *stack);
void	rrr(t_stack *stack_a, t_stack *stack_b);

t_list	**ft_alloc_list(void);
void	*ft_malloc(size_t size);
void	ft_delete(void *ptr);

void	return_error(int state);

#endif