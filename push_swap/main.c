#include "push_swap.h"

int	main(int argc, char **argv)
{
	validate_args((size_t)argc, argv);
    init_stack_a((size_t)argc - 1, argv);
    init_stack_b();
    solve();
}

typedef struct s_node
{
    int num;
    int is_top;
    int position;
    struct s_node next;
} t_node;

typdef struct s_stack
{
    int size;
    t_node top;
}

void init_stack_a(size_t n_count, char **argv)
{
    
}