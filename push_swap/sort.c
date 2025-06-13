#include "push_swap.h"

void	sort_three_three(t_stack *stack_a, t_stack *stack_b)
{
	t_top	*a;
	t_top	*b;

	a = ft_malloc(sizeof(t_top));
	b = ft_malloc(sizeof(t_top));
	a->top = &stack_a->top->num;
	b->top = &stack_b->top->num;
	a->prev = &stack_a->top->prev->num;
	b->prev = &stack_b->top->prev->num;
	a->prevprev = &stack_a->top->prev->prev->num;
	b->prevprev = &stack_b->top->prev->prev->num;
	if (compare_a_3(a->top, a->prev, a->prevprev) == 1)
		choose_compare_b_1(stack_a, stack_b, b);
	else if (compare_a_3(a->top, a->prev, a->prevprev) == 2)
		choose_compare_b_2(stack_a, stack_b, b);
	else if (compare_a_3(a->top, a->prev, a->prevprev) == 3)
		choose_compare_b_3(stack_a, stack_b, b);
	else if (compare_a_3(a->top, a->prev, a->prevprev) == 4)
		choose_compare_b_4(stack_a, stack_b, b);
	else if (compare_a_3(a->top, a->prev, a->prevprev) == 5)
		choose_compare_b_5(stack_a, stack_b, b);
	else if (compare_a_3(a->top, a->prev, a->prevprev) == 6)
		choose_compare_b_6(stack_a, stack_b, b);
}

void	sort_three_two(t_stack *stack_a, t_stack *stack_b)
{
	t_top	*a;
	t_top	*b;

	a = ft_malloc(sizeof(t_top));
	b = ft_malloc(sizeof(t_top));
	a->top = &stack_a->top->num;
	b->top = &stack_b->top->num;
	a->prev = &stack_a->top->prev->num;
	b->prev = &stack_b->top->prev->num;
	a->prevprev = &stack_a->top->prev->prev->num;
	if (compare_b_2(b->top, b->prev) == 1)
		choose_compare_a_1(stack_a, stack_b, a);
	else if (compare_b_2(b->top, b->prev) == 2)
		choose_compare_a_2(stack_a, stack_b, a);
}

void	sort_two_three(t_stack *stack_a, t_stack *stack_b)
{
	t_top	*b;

	b = ft_malloc(sizeof(t_top));
	b->top = &stack_b->top->num;
	b->prev = &stack_b->top->prev->num;
	b->prevprev = &stack_b->top->prev->prev->num;
	if (compare_a_2(&stack_a->top->num, &stack_a->top->prev->num) == 1)
		choose_compare_b_1_3(stack_a, stack_b, b);
	else if (compare_a_2(&stack_a->top->num , &stack_a->top->prev->num) == 2)
		choose_compare_b_2_3(stack_a, stack_b, b);
}

void	sort_two_two(t_stack *stack_a,t_stack *stack_b)
{
	if (stack_a->top->num > stack_a->top->prev->num)
	{
		if (stack_b->top->num < stack_b->top->prev->num)
			ss(stack_a, stack_b);
		else
			sa(stack_a, 1);
		pa(stack_a, stack_b);
		pa(stack_a, stack_b);
	}
	else
	{
		if (stack_b->top->num < stack_b->top->prev->num)
			sb(stack_b, 1);
		pa(stack_a, stack_b);
		pa(stack_a, stack_b);
	}
}

void	sort_b_pa(t_stack *stack_a, t_stack *stack_b, size_t b_top)
{
	t_top	*b;

	b = ft_malloc(sizeof(t_top));
	b->top = &stack_b->top->num;
	b->prev = &stack_b->top->prev->num;
	b->prevprev = &stack_b->top->prev->prev->num;
	if (b_top == 2)
	{
		if (stack_b->top->num < stack_b->top->prev->num)
			sb(stack_b, 1);
		pa(stack_a, stack_b);
		pa(stack_a, stack_b);
	}
	else
		choose_compare_b_2_3(stack_a, stack_b, b);
}

void	sort_and_pa(t_stack *stack_a, t_stack *stack_b, t_stack *stack_s, size_t b_top)
{
	size_t	a_top;

	a_top = unsorted_in_a(stack_a, stack_s);
	// ft_printf("\na_top: %d\nb_top: %d\n", a_top, b_top);
	if (a_top == 3 && b_top == 3)
		sort_three_three(stack_a, stack_b);
	else if (a_top == 3 && b_top == 2)
		sort_three_two(stack_a, stack_b);
	else if (a_top == 2 && b_top == 3)
		sort_two_three(stack_a, stack_b);
	else if (a_top == 2 && b_top == 2)
		sort_two_two(stack_a, stack_b);
	else if (a_top == 0 && (b_top == 2 || b_top == 3))
		sort_b_pa(stack_a, stack_b, b_top);
	// else
	// 	ft_printf("\n>>unkown combination to sort<<\n");
}