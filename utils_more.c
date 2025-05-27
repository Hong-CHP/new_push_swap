#include "push_swap.h"

int get_index(t_stack *stack, int val)
{
    t_node *cur = stack->top;
    int index = 0;

    while (cur)
    {
        if (*(cur->value) == val)
            return index;
        cur = cur->next;
        index++;
    }
    return -1;
}

int ft_max(int a, int b)
{
    if (a > b)
        return (a);
    else
        return (b);
}

int ft_abs(int nb)
{
    if (nb < 0)
        return (-nb);
    return (nb);
}