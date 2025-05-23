#include "push_swap.h"

int	main(int argc, char **argv)
{
	validate_args((size_t)argc, argv);
    init_stack_a((size_t)argc, argv);
    init_stack_b();
    solve();
}
