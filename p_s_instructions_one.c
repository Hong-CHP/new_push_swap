#include "push_swap.h"

void    sa(t_stack *stack_a)
{
    swap_top_two(stack_a);
    write(1, "sa\n", 3);
}

void    sb(t_stack *stack_b)
{
    swap_top_two(stack_b);
    write(1, "sb\n", 3);
}

void    ss(t_stack *stack_a, t_stack *stack_b)
{
    swap_top_two(stack_a);
    swap_top_two(stack_b);
    write(1, "ss\n", 3);
}

void    pa(t_stack *stack_a, t_stack *stack_b)
{
    push_to_top(stack_a, stack_b);
    write(1, "pa\n", 3);
}

void    pb(t_stack *stack_a, t_stack *stack_b)
{
    push_to_top(stack_a, stack_b);
    write(1, "pb\n", 3);
}