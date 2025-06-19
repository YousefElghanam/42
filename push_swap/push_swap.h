/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jel-ghna <jel-ghna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 12:28:34 by jel-ghna          #+#    #+#             */
/*   Updated: 2025/06/18 23:49:07 by jel-ghna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_node
{
	int				num;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	size_t	size;
	t_node	*head;
	t_node	*top;
}	t_stack;

typedef struct s_set
{
	size_t	capacity;
	size_t	cur_size;
	int		*arr;
}	t_set;

typedef struct s_top
{
	int	*top;
	int	*prev;
	int	*prevprev;
}	t_top;

size_t	len_from_here(t_node *starting_node);
t_stack	*mk_sorted_stack(t_node *starting_node);
int		is_top_half(t_node *starting_node, t_node *target_node);
size_t	unsorted_in_a(t_stack *stack_a, t_stack *stack_s);

t_stack	*op_stack(void);
void	add_op(int op);
t_node	*pop(t_stack *stack);
void	cancel(t_stack *stack, int state);
int		can_cancel(t_node *top);
void	print_ops(t_node *node);

void	manual_input(int *argc, char ***argv);

void	parse_args(int *argc, char ***argv);
void	init_set(t_set *set, size_t arg_count);
int		in_set(t_set *set, int num);
void	add_to_set(t_set *set, int num);

t_stack	*init_stack_a(int n_count, char **argv);
t_stack	*init_stack_b(void);
t_stack	*init_stack_sorted(t_stack *stack);
t_node	*new_node(int num);
void	push_node(t_node *node, t_stack *stack);
void	fill_arr(int *arr, t_stack *stack);
void	sort_arr(int *arr, size_t size);
t_stack	*arr_to_stack(int *arr, size_t size);

t_list	**sequence_list(void);
void	add_seq(t_list **seq_list, t_stack *stack_b, t_node *prev_seq_end);
void	delete_seq(t_list **seq_list);

void	solve(t_stack *stack_a, t_stack *stack_b, t_stack *stack_s);

void	split_b(t_stack *stk_a, t_stack *stk_b, t_list **seq_list);
void	split_a(t_stack *stk_a, t_stack *stk_b, t_stack *stk_s, t_node *start);
t_node	*b_splt_start(t_stack *stk_b, size_t *seq_len);
void	fix_a(t_stack *stk_a, size_t len, int reverse);
void	ra_edge_num(t_stack *stk_a, t_stack *sorted);
int		rb_edge_num(t_stack *stk_b, t_stack *sorted, void **j);

void	sort_a_top(t_stack *stk_a, t_stack *stk_b);
void	sort_b_top(t_stack *stk_a, t_stack *stk_b, size_t b_top);
void	sort(t_stack *stk_a, t_stack *stk_b, t_stack *stack_s, size_t b_top);

void	sort_three_three(t_stack *stk_a, t_stack *stk_b);
void	sort_three_two(t_stack *stk_a, t_stack *stk_b);
void	sort_two_three(t_stack *stk_a, t_stack *stk_b);
void	sort_two_two(t_stack *stk_a, t_stack *stk_b);

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

int		compare_a_3(int *top, int *prev, int *prevprev);
int		compare_a_2(int *top, int *prev);
int		compare_b_3(int *top, int *prev, int *prevprev);
int		compare_b_2(int *top, int *prev);
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

void	sort_1_1_2_3(t_stack *stack_a, t_stack *stack_b);
void	sort_1_2_2_3(t_stack *stack_a, t_stack *stack_b);
void	sort_1_3_2_3(t_stack *stack_a, t_stack *stack_b);
void	sort_1_4_2_3(t_stack *stack_a, t_stack *stack_b);
void	sort_1_5_2_3(t_stack *stack_a, t_stack *stack_b);
void	sort_1_6_2_3(t_stack *stack_a, t_stack *stack_b);
void	sort_2_1_2_3(t_stack *stack_a, t_stack *stack_b);
void	sort_2_2_2_3(t_stack *stack_a, t_stack *stack_b);
void	sort_2_3_2_3(t_stack *stack_a, t_stack *stack_b);
void	sort_2_4_2_3(t_stack *stack_a, t_stack *stack_b);
void	sort_2_5_2_3(t_stack *stack_a, t_stack *stack_b);
void	sort_2_6_2_3(t_stack *stack_a, t_stack *stack_b);
void	sort_1_1_3_2(t_stack *stack_a, t_stack *stack_b);
void	sort_1_2_3_2(t_stack *stack_a, t_stack *stack_b);
void	sort_1_3_3_2(t_stack *stack_a, t_stack *stack_b);
void	sort_1_4_3_2(t_stack *stack_a, t_stack *stack_b);
void	sort_1_5_3_2(t_stack *stack_a, t_stack *stack_b);
void	sort_1_6_3_2(t_stack *stack_a, t_stack *stack_b);
void	sort_2_1_3_2(t_stack *stack_a, t_stack *stack_b);
void	sort_2_2_3_2(t_stack *stack_a, t_stack *stack_b);
void	sort_2_3_3_2(t_stack *stack_a, t_stack *stack_b);
void	sort_2_4_3_2(t_stack *stack_a, t_stack *stack_b);
void	sort_2_5_3_2(t_stack *stack_a, t_stack *stack_b);
void	sort_2_6_3_2(t_stack *stack_b);
void	sort_1_1(t_stack *stack_a, t_stack *stack_b);
void	sort_1_2(t_stack *stack_a, t_stack *stack_b);
void	sort_1_3(t_stack *stack_a, t_stack *stack_b);
void	sort_1_4(t_stack *stack_a, t_stack *stack_b);
void	sort_1_5(t_stack *stack_a, t_stack *stack_b);
void	sort_1_6(t_stack *stack_a, t_stack *stack_b);
void	sort_2_1(t_stack *stack_a, t_stack *stack_b);
void	sort_2_2(t_stack *stack_a, t_stack *stack_b);
void	sort_2_3(t_stack *stack_a, t_stack *stack_b);
void	sort_2_4(t_stack *stack_a, t_stack *stack_b);
void	sort_2_5(t_stack *stack_a, t_stack *stack_b);
void	sort_2_6(t_stack *stack_a, t_stack *stack_b);
void	sort_3_1(t_stack *stack_a, t_stack *stack_b);
void	sort_3_2(t_stack *stack_a, t_stack *stack_b);
void	sort_3_3(t_stack *stack_a, t_stack *stack_b);
void	sort_3_4(t_stack *stack_a, t_stack *stack_b);
void	sort_3_5(t_stack *stack_a, t_stack *stack_b);
void	sort_3_6(t_stack *stack_a, t_stack *stack_b);
void	sort_4_1(t_stack *stack_a, t_stack *stack_b);
void	sort_4_2(t_stack *stack_a, t_stack *stack_b);
void	sort_4_3(t_stack *stack_a, t_stack *stack_b);
void	sort_4_4(t_stack *stack_a, t_stack *stack_b);
void	sort_4_5(t_stack *stack_a, t_stack *stack_b);
void	sort_4_6(t_stack *stack_a, t_stack *stack_b);
void	sort_5_1(t_stack *stack_a, t_stack *stack_b);
void	sort_5_2(t_stack *stack_a, t_stack *stack_b);
void	sort_5_3(t_stack *stack_a, t_stack *stack_b);
void	sort_5_4(t_stack *stack_a, t_stack *stack_b);
void	sort_5_5(t_stack *stack_a, t_stack *stack_b);
void	sort_5_6(t_stack *stack_a, t_stack *stack_b);
void	sort_6_1(t_stack *stack_a, t_stack *stack_b);
void	sort_6_2(t_stack *stack_a, t_stack *stack_b);
void	sort_6_3(t_stack *stack_a, t_stack *stack_b);
void	sort_6_4(t_stack *stack_a, t_stack *stack_b);
void	sort_6_5(t_stack *stack_a, t_stack *stack_b);
void	sort_6_6(t_stack *stack_a, t_stack *stack_b);

t_stack	*op_stack_bonus(void);
void	read_ops(void);
void	execute_ops(t_stack *stack_a, t_stack *stack_b);

#endif