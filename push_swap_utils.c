#include "push_swap.h"

int is_obj_unmarked(t_unmarked *unmarked_nbs, int val)
{
    int i;

    i = 0;
    while (i < unmarked_nbs->unmarked_size)
    {
        if (val == unmarked_nbs->unmarked_nums[i])
            return (1);
        i++;
    }
    return (0);
}

int     get_bottom_val(t_stack *stack)
{
    t_node *cur;
    int bottom;

    cur = stack->top;
    while (cur->next)
        cur = cur->next;
    bottom = *(cur->value);
    return (bottom);
}
