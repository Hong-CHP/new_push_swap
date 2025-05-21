#include "push_swap.h"

void    ra(t_stack *stack_a)
{
    rotate_to_top(stack_a);
    write(1, "ra\n", 3);
}

void    rb(t_stack *stack_b)
{
    rotate_to_top(stack_b);
    write(1, "rb\n", 3);
}

void    rr(t_stack *stack_a, t_stack *stack_b)
{
    rotate_to_top(stack_a);
    rotate_to_top(stack_b);
    write(1, "rr\n", 3);
}

void    rra(t_stack *stack_a)
{
    reverse_rotate(stack_a);
    write(1, "rra\n", 4);
}

void    rrb(t_stack *stack_b)
{
    reverse_rotate(stack_b);
    write(1, "rrb\n", 4);
}