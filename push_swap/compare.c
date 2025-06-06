#include "push_swap.h"

int	compare_a_3(int *top, int *prev, int *prevprev)
{
	if (*top > *prev && *top > *prevprev && *prev > *prevprev)
		return (1);
	else if (*top < *prev && *top > *prevprev && *prev > *prevprev)
		return (2);
	else if (*top > *prev && *top > *prevprev && *prev < *prevprev)
		return (3);
	else if (*top < *prev && *top < *prevprev && *prev > *prevprev)
		return (4);
	else if (*top > *prev && *top < *prevprev && *prev < *prevprev)
		return (5);
	else if (*top < *prev && *top < *prevprev && *prev < *prevprev)
		return (6);
	return (-1);
}

int	compare_a_2(int *top, int *prev)
{
	if (*top > *prev)
		return (1);
	else if (*top < *prev)
		return (2);
	return (-1);
}
int	compare_b_3(int *top, int *prev, int *prevprev)
{
	if (*top < *prev && *top < *prevprev && *prev < *prevprev)
		return (1);
	else if (*top > *prev && *top < *prevprev && *prev < *prevprev)
		return (2);
	else if (*top > *prev && *top > *prevprev && *prev < *prevprev)
		return (3);
	else if (*top < *prev && *top < *prevprev && *prev > *prevprev)
		return (4);
	else if (*top < *prev && *top > *prevprev && *prev > *prevprev)
		return (5);
	else if (*top > *prev && *top > *prevprev && *prev > *prevprev)
		return (6);
	return (-1);
}

int	compare_b_2(int *top, int *prev)
{
	if (*top > *prev)
		return (1);
	else if (*top < *prev)
		return (2);
	return (-1);
}

void	choose_compare_b_1(t_stack *stack_a, t_stack *stack_b, t_top *b)
{
	if (compare_b_3(b->top, b->prev, b->prevprev) == 1)
		sort_1_1(stack_a, stack_b);
	else if (compare_b_3(b->top, b->prev, b->prevprev) == 2)
		sort_1_2(stack_a, stack_b);
	else if (compare_b_3(b->top, b->prev, b->prevprev) == 3)
		sort_1_3(stack_a, stack_b);
	else if (compare_b_3(b->top, b->prev, b->prevprev) == 4)
		sort_1_4(stack_a, stack_b);
	else if (compare_b_3(b->top, b->prev, b->prevprev) == 5)
		sort_1_5(stack_a, stack_b);
	else if (compare_b_3(b->top, b->prev, b->prevprev) == 6)
		sort_1_6(stack_a, stack_b);
}

void	choose_compare_b_2(t_stack *stack_a, t_stack *stack_b, t_top *b)
{
	if (compare_b_3(b->top, b->prev, b->prevprev) == 1)
		sort_2_1(stack_a, stack_b);
	else if (compare_b_3(b->top, b->prev, b->prevprev) == 2)
		sort_2_2(stack_a, stack_b);
	else if (compare_b_3(b->top, b->prev, b->prevprev) == 3)
		sort_2_3(stack_a, stack_b);
	else if (compare_b_3(b->top, b->prev, b->prevprev) == 4)
		sort_2_4(stack_a, stack_b);
	else if (compare_b_3(b->top, b->prev, b->prevprev) == 5)
		sort_2_5(stack_a, stack_b);
	else if (compare_b_3(b->top, b->prev, b->prevprev) == 6)
		sort_2_6(stack_a, stack_b);
}

void	choose_compare_b_3(t_stack *stack_a, t_stack *stack_b, t_top *b)
{
	if (compare_b_3(b->top, b->prev, b->prevprev) == 1)
		sort_3_1(stack_a, stack_b);
	else if (compare_b_3(b->top, b->prev, b->prevprev) == 2)
		sort_3_2(stack_a, stack_b);
	else if (compare_b_3(b->top, b->prev, b->prevprev) == 3)
		sort_3_3(stack_a, stack_b);
	else if (compare_b_3(b->top, b->prev, b->prevprev) == 4)
		sort_3_4(stack_a, stack_b);
	else if (compare_b_3(b->top, b->prev, b->prevprev) == 5)
		sort_3_5(stack_a, stack_b);
	else if (compare_b_3(b->top, b->prev, b->prevprev) == 6)
		sort_3_6(stack_a, stack_b);
}

void	choose_compare_b_4(t_stack *stack_a, t_stack *stack_b, t_top *b)
{
	if (compare_b_3(b->top, b->prev, b->prevprev) == 1)
		sort_4_1(stack_a, stack_b);
	else if (compare_b_3(b->top, b->prev, b->prevprev) == 2)
		sort_4_2(stack_a, stack_b);
	else if (compare_b_3(b->top, b->prev, b->prevprev) == 3)
		sort_4_3(stack_a, stack_b);
	else if (compare_b_3(b->top, b->prev, b->prevprev) == 4)
		sort_4_4(stack_a, stack_b);
	else if (compare_b_3(b->top, b->prev, b->prevprev) == 5)
		sort_4_5(stack_a, stack_b);
	else if (compare_b_3(b->top, b->prev, b->prevprev) == 6)
		sort_4_6(stack_a, stack_b);
}

void	choose_compare_b_5(t_stack *stack_a, t_stack *stack_b, t_top *b)
{
	if (compare_b_3(b->top, b->prev, b->prevprev) == 1)
		sort_5_1(stack_a, stack_b);
	else if (compare_b_3(b->top, b->prev, b->prevprev) == 2)
		sort_5_2(stack_a, stack_b);
	else if (compare_b_3(b->top, b->prev, b->prevprev) == 3)
		sort_5_3(stack_a, stack_b);
	else if (compare_b_3(b->top, b->prev, b->prevprev) == 4)
		sort_5_4(stack_a, stack_b);
	else if (compare_b_3(b->top, b->prev, b->prevprev) == 5)
		sort_5_5(stack_a, stack_b);
	else if (compare_b_3(b->top, b->prev, b->prevprev) == 6)
		sort_5_6(stack_a, stack_b);
}

void	choose_compare_b_6(t_stack *stack_a, t_stack *stack_b, t_top *b)
{
	if (compare_b_3(b->top, b->prev, b->prevprev) == 1)
		sort_6_1(stack_a, stack_b);
	else if (compare_b_3(b->top, b->prev, b->prevprev) == 2)
		sort_6_2(stack_a, stack_b);
	else if (compare_b_3(b->top, b->prev, b->prevprev) == 3)
		sort_6_3(stack_a, stack_b);
	else if (compare_b_3(b->top, b->prev, b->prevprev) == 4)
		sort_6_4(stack_a, stack_b);
	else if (compare_b_3(b->top, b->prev, b->prevprev) == 5)
		sort_6_5(stack_a, stack_b);
	else if (compare_b_3(b->top, b->prev, b->prevprev) == 6)
		sort_6_6(stack_a, stack_b);
}

void	choose_compare_a_1(t_stack *stack_a, t_stack *stack_b, t_top *a)
{
	if (compare_a_3(a->top, a->prev, a->prevprev) == 1)
		sort_1_1_3_2(stack_a, stack_b);
	else if (compare_a_3(a->top, a->prev, a->prevprev) == 2)
		sort_1_2_3_2(stack_a, stack_b);
	else if (compare_a_3(a->top, a->prev, a->prevprev) == 3)
		sort_1_3_3_2(stack_a, stack_b);
	else if (compare_a_3(a->top, a->prev, a->prevprev) == 4)
		sort_1_4_3_2(stack_a, stack_b);
	else if (compare_a_3(a->top, a->prev, a->prevprev) == 5)
		sort_1_5_3_2(stack_a, stack_b);
	else if (compare_a_3(a->top, a->prev, a->prevprev) == 6)
		sort_1_6_3_2(stack_a, stack_b);
}

void	choose_compare_a_2(t_stack *stack_a, t_stack *stack_b, t_top *a)
{
	if (compare_a_3(a->top, a->prev, a->prevprev) == 1)
		sort_2_1_3_2(stack_a, stack_b);
	else if (compare_a_3(a->top, a->prev, a->prevprev) == 2)
		sort_2_2_3_2(stack_a, stack_b);
	else if (compare_a_3(a->top, a->prev, a->prevprev) == 3)
		sort_2_3_3_2(stack_a, stack_b);
	else if (compare_a_3(a->top, a->prev, a->prevprev) == 4)
		sort_2_4_3_2(stack_a, stack_b);
	else if (compare_a_3(a->top, a->prev, a->prevprev) == 5)
		sort_2_5_3_2(stack_a, stack_b);
	else if (compare_a_3(a->top, a->prev, a->prevprev) == 6)
		sort_2_6_3_2(stack_b);
}

void	choose_compare_b_1_3(t_stack *stack_a, t_stack *stack_b, t_top *b)
{
	if (compare_b_3(b->top, b->prev, b->prevprev) == 1)
		sort_1_1_2_3(stack_a, stack_b);
	else if (compare_b_3(b->top, b->prev, b->prevprev) == 2)
		sort_1_2_2_3(stack_a, stack_b);
	else if (compare_b_3(b->top, b->prev, b->prevprev) == 3)
		sort_1_3_2_3(stack_a, stack_b);
	else if (compare_b_3(b->top, b->prev, b->prevprev) == 4)
		sort_1_4_2_3(stack_a, stack_b);
	else if (compare_b_3(b->top, b->prev, b->prevprev) == 5)
		sort_1_5_2_3(stack_a, stack_b);
	else if (compare_b_3(b->top, b->prev, b->prevprev) == 6)
		sort_1_6_2_3(stack_a, stack_b);
}

void	choose_compare_b_2_3(t_stack *stack_a, t_stack *stack_b, t_top *b)
{
	if (compare_b_3(b->top, b->prev, b->prevprev) == 1)
		sort_2_1_2_3(stack_a, stack_b);
	else if (compare_b_3(b->top, b->prev, b->prevprev) == 2)
		sort_2_2_2_3(stack_a, stack_b);
	else if (compare_b_3(b->top, b->prev, b->prevprev) == 3)
		sort_2_3_2_3(stack_a, stack_b);
	else if (compare_b_3(b->top, b->prev, b->prevprev) == 4)
		sort_2_4_2_3(stack_a, stack_b);
	else if (compare_b_3(b->top, b->prev, b->prevprev) == 5)
		sort_2_5_2_3(stack_a, stack_b);
	else if (compare_b_3(b->top, b->prev, b->prevprev) == 6)
		sort_2_6_2_3(stack_a, stack_b);
}
