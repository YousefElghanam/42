#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_top
{
	int	*top;
	int	*prev;
	int	*prevprev;
}	t_top;

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

t_node	*new_node(int num, size_t pos);
void	push_node(t_node *node, t_stack *stack);
void	fill_arr(int *arr, t_stack *stack);
void	sort_arr(int *arr, size_t size);
t_stack	*arr_to_stack(int *arr, size_t size);

void	init_set(t_set *set, size_t arg_count);
int		in_set(t_set *set, int num);
void	add_to_set(t_set *set, int num);

void	sa(t_stack *stack, int print);
void	sb(t_stack *stack, int print);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);
void	ra(t_stack *stack, int print);
void	rb(t_stack *stack, int print);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rra(t_stack *stack, int print);
void	rrb(t_stack *stack, int print);
void	rrr(t_stack *stack_a, t_stack *stack_b);

t_list	**ft_alloc_list(void);
void	*ft_malloc(size_t size);
void	ft_delete(void *ptr);

void	return_error(int state, ...);

/// new functions
size_t	len_from_here(t_node *starting_node);
t_stack	*mk_sorted_stack(t_node *starting_node);
int		is_top_half(t_node *starting_node, t_node *target_node);
void	split_a(t_stack *stack_a, t_stack *stack_b, t_node *starting_node);
size_t	unsorted_in_a(t_stack *stack_a, t_stack *stack_s);
void	sort_two_two(t_stack *stack_a,t_stack *stack_b);
void	sort_and_pa(t_stack *stack_a, t_stack *stack_b, t_stack *stack_s, size_t b_top);
t_node	*b_split_starting_node(t_stack *stack_b, size_t *seq_len);
void	split_b(t_stack *stack_a, t_stack *stack_b, t_list **seq_list);

void	sort_three_three(t_stack *stack_a, t_stack *stack_b);
void	sort_three_two(t_stack *stack_a, t_stack *stack_b);
void	sort_two_three(t_stack *stack_a, t_stack *stack_b);

int	compare_a_3(int *top, int *prev, int *prevprev);
int	compare_a_2(int *top, int *prev);
int	compare_b_3(int *top, int *prev, int *prevprev);
int	compare_b_2(int *top, int *prev);
void	choose_compare_b_1(t_stack *stack_a, t_stack *stack_b, t_top *b);
void	choose_compare_b_2(t_stack *stack_a, t_stack *stack_b, t_top *b);
void	choose_compare_b_3(t_stack *stack_a, t_stack *stack_b, t_top *b);
void	choose_compare_b_4(t_stack *stack_a, t_stack *stack_b, t_top *b);
void	choose_compare_b_5(t_stack *stack_a, t_stack *stack_b, t_top *b);
void	choose_compare_b_6(t_stack *stack_a, t_stack *stack_b, t_top *b);

void	choose_compare_a_1(t_stack *stack_a, t_stack *stack_b, t_top *a);
void	choose_compare_a_2(t_stack *stack_a, t_stack *stack_b, t_top *a);

void	choose_compare_b_1_3(t_stack *stack_a, t_stack *stack_b, t_top *b);
void	choose_compare_b_2_3(t_stack *stack_a, t_stack *stack_b, t_top *b);

void sort_1_1_2_3(t_stack *stack_a, t_stack *stack_b);
void sort_1_2_2_3(t_stack *stack_a, t_stack *stack_b);
void sort_1_3_2_3(t_stack *stack_a, t_stack *stack_b);
void sort_1_4_2_3(t_stack *stack_a, t_stack *stack_b);
void sort_1_5_2_3(t_stack *stack_a, t_stack *stack_b);
void sort_1_6_2_3(t_stack *stack_a, t_stack *stack_b);
void sort_2_1_2_3(t_stack *stack_a,t_stack *stack_b);
void sort_2_2_2_3(t_stack *stack_a, t_stack *stack_b);
void sort_2_3_2_3(t_stack *stack_a, t_stack *stack_b);
void sort_2_4_2_3(t_stack *stack_a, t_stack *stack_b);
void sort_2_5_2_3(t_stack *stack_a, t_stack *stack_b);
void sort_2_6_2_3(t_stack *stack_a, t_stack *stack_b);
void sort_1_1_3_2(t_stack *stack_a, t_stack *stack_b);
void sort_1_2_3_2(t_stack *stack_a, t_stack *stack_b);
void sort_1_3_3_2(t_stack *stack_a, t_stack *stack_b);
void sort_1_4_3_2(t_stack *stack_a, t_stack *stack_b);
void sort_1_5_3_2(t_stack *stack_a, t_stack *stack_b);
void sort_1_6_3_2(t_stack *stack_a, t_stack *stack_b);
void sort_2_1_3_2(t_stack *stack_a, t_stack *stack_b);
void sort_2_2_3_2(t_stack *stack_a, t_stack *stack_b);
void sort_2_3_3_2(t_stack *stack_a, t_stack *stack_b);
void sort_2_4_3_2(t_stack *stack_a, t_stack *stack_b);
void sort_2_5_3_2(t_stack *stack_a, t_stack *stack_b);
void sort_2_6_3_2(t_stack *stack_b);
void sort_1_1(t_stack *stack_a, t_stack *stack_b);
void sort_1_2(t_stack *stack_a, t_stack *stack_b);
void sort_1_3(t_stack *stack_a, t_stack *stack_b);
void sort_1_4(t_stack *stack_a, t_stack *stack_b);
void sort_1_5(t_stack *stack_a, t_stack *stack_b);
void sort_1_6(t_stack *stack_a, t_stack *stack_b);
void sort_2_1(t_stack *stack_a, t_stack *stack_b);
void sort_2_2(t_stack *stack_a, t_stack *stack_b);
void sort_2_3(t_stack *stack_a, t_stack *stack_b);
void sort_2_4(t_stack *stack_a, t_stack *stack_b);
void sort_2_5(t_stack *stack_a, t_stack *stack_b);
void sort_2_6(t_stack *stack_a, t_stack *stack_b);
void sort_3_1(t_stack *stack_a, t_stack *stack_b);
void sort_3_2(t_stack *stack_a, t_stack *stack_b);
void sort_3_3(t_stack *stack_a, t_stack *stack_b);
void sort_3_4(t_stack *stack_a, t_stack *stack_b);
void sort_3_5(t_stack *stack_a, t_stack *stack_b);
void sort_3_6(t_stack *stack_a, t_stack *stack_b);
void sort_4_1(t_stack *stack_a, t_stack *stack_b);
void sort_4_2(t_stack *stack_a, t_stack *stack_b);
void sort_4_3(t_stack *stack_a, t_stack *stack_b);
void sort_4_4(t_stack *stack_a, t_stack *stack_b);
void sort_4_5(t_stack *stack_a, t_stack *stack_b);
void sort_4_6(t_stack *stack_a, t_stack *stack_b);
void sort_5_1(t_stack *stack_a, t_stack *stack_b);
void sort_5_2(t_stack *stack_a, t_stack *stack_b);
void sort_5_3(t_stack *stack_a, t_stack *stack_b);
void sort_5_4(t_stack *stack_a, t_stack *stack_b);
void sort_5_5(t_stack *stack_a, t_stack *stack_b);
void sort_5_6(t_stack *stack_a, t_stack *stack_b);
void sort_6_1(t_stack *stack_a, t_stack *stack_b);
void sort_6_2(t_stack *stack_a, t_stack *stack_b);
void sort_6_3(t_stack *stack_a, t_stack *stack_b);
void sort_6_4(t_stack *stack_a, t_stack *stack_b);
void sort_6_5(t_stack *stack_a, t_stack *stack_b);
void sort_6_6(t_stack *stack_a, t_stack *stack_b);


#endif