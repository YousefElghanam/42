#include "push_swap.h"

t_stack	*op_stack(void)
{
	static t_stack	*ptr;

	if (ptr == NULL)
	{
		ptr = ft_malloc(sizeof(t_stack *));
		if (!ptr)
			return_error(2);
	}
	return (ptr);
}

// -1		0		1		2		3		4		5		6		7		8		9		10
// nothin	sa		sb		ss		pa		pb		ra		rb		rr		rra		rrb		rrr

int	can_rev_cancel(t_node *top)
{
	t_node	*prev;

	prev = top->prev;
	if (top->num == 2 && prev->num == 0) // sa ss => sb
		return (1);
	if (top->num == 2 && prev->num == 1) // sb ss => sa
		return (2);
	if (top->num == 10 && prev->num == 5) // ra rrr => rrb
		return (3);
	if (top->num == 10 && prev->num == 6) // rb rrr => rra
		return (4);
	if (top->num == 7 && prev->num == 8) // rra rr => rb
		return (5);
	if (top->num == 7 && prev->num == 9) // rrb rr => ra
		return (6);
	return (0);
}

void	rev_cancel(t_stack *stack, int state)
{
	pop(stack);
	pop(stack);
	if (state == 1)
		add_op(1);
	if (state == 2)
		add_op(2);
	if (state == 3)
		add_op(9);
	if (state == 4)
		add_op(8);
	if (state == 5)
		add_op(6);
	if (state == 6)
		add_op(5);
}

static int	can_cancel(t_node *top)
{
	t_node	*prev;

	if (!top || !top->prev)
		return (0);
	prev = top->prev;
	if (top->num == -1) // nothing
		return (1);
	if ((top->num == 0 && prev->num == 1) || (top->num == 1 && prev->num == 0)) // sb sa || sa sb => ss
		return (2);
	if ((top->num == 0 && prev->num == 0) || (top->num == 1 && prev->num == 1)) // sa sa || sb sb => 0
		return (3);
	if ((top->num == 3 && prev->num == 4) || (top->num == 4 && prev->num == 3)) // pb pa || pa pb => 0
		return (4);
	if ((top->num == 5 && prev->num == 8) || (top->num == 8 && prev->num == 5)) // rra ra || ra rra => 0
		return (5);
	if ((top->num == 6 && prev->num == 9) || (top->num == 9 && prev->num == 6)) // rrb rb || rb rrb => 0
		return (6);
	if ((top->num == 5 && prev->num == 6) || (top->num == 6 && prev->num == 5)) // rb ra || ra rb => rr
		return (7);
	if ((top->num == 8 && prev->num == 9) || (top->num == 9 && prev->num == 8)) // rrb rra || rra rrb => rrr
		return (8);
	return (0);
}

static void	cancel(t_stack *stack, int state)
{
	pop(stack);
	if (state == 1)
		return ;
	pop(stack);
	if (state == 2)
		add_op(2);
	else if (state == 7)
		add_op(7);
	else if (state == 8)
		add_op(10);
	if (stack && can_rev_cancel(stack->top))
		rev_cancel(stack, can_rev_cancel(stack->top));
}

static void	push_op_node(t_node *node, t_stack *stack)
{
	if (stack->size == 0)
		stack->head = node;
	else
	{
		node->prev = stack->top;
		stack->top->next = node;
	}
	stack->top = node;
	stack->size += 1;
	while (can_cancel(stack->top))
		cancel(stack, can_cancel(stack->top));
}

void	add_op(int op)
{
	if (op == -1)
		push_op_node(new_node(-1, 0), op_stack());
	else if (op == 0)
		push_op_node(new_node(0, 0), op_stack());
	else if (op == 1)
		push_op_node(new_node(1, 0), op_stack());
	else if (op == 2)
		push_op_node(new_node(2, 0), op_stack());
	else if (op == 3)
		push_op_node(new_node(3, 0), op_stack());
	else if (op == 4)
		push_op_node(new_node(4, 0), op_stack());
	else if (op == 5)
		push_op_node(new_node(5, 0), op_stack());
	else if (op == 6)
		push_op_node(new_node(6, 0), op_stack());
	else if (op == 7)
		push_op_node(new_node(7, 0), op_stack());
	else if (op == 8)
		push_op_node(new_node(8, 0), op_stack());
	else if (op == 9)
		push_op_node(new_node(9, 0), op_stack());
	else if (op == 10)
		push_op_node(new_node(10, 0), op_stack());
}
