#include "push_swap.h"

t_obj     *check_lasts_unmarked_path(t_stack *stack_a, t_node *cur, t_unmarked *unmarked_nbs, int *shortest_path)
{
    int     j;
    int     mins_unmarked_path;
    int     mins_unmarked_value;
    t_obj   *obj = NULL;

    obj = malloc(sizeof(t_obj));
    if (!obj)
        return (NULL);
    j = 0;
    while (j < unmarked_nbs->unmarked_size)
    {
        if (*(cur->value) == unmarked_nbs->unmarked_nums[j])
        {
            mins_unmarked_path = find_mins_pos_in_simple(stack_a, unmarked_nbs->unmarked_nums[j]);
            if (*shortest_path > mins_unmarked_path)
            {
                mins_unmarked_value = unmarked_nbs->unmarked_nums[j];
                *shortest_path = mins_unmarked_path;
            }
        }
        j++;
    }
    obj->value = mins_unmarked_value;
    obj->path = *shortest_path;
    return (obj);
}

int     count_lasts_unmarked(t_stack *stack_a, t_unmarked *unmarked_nbs)
{
    t_node  *cur;
    int     count;
    int i;

    count = 0;
    cur = stack_a->top;
    while (cur)
    {
        i = 0;
        while (i < unmarked_nbs->unmarked_size)
        {
            if (*(cur->value) == unmarked_nbs->unmarked_nums[i])
                count++;
            i++;
        }
        cur = cur->next;
    }
    return (count);
}

t_obj     *check_lasts_unmarked_in_a(t_stack *stack_a, t_stack *stack_b, t_unmarked *unmarked_nbs)
{
    int     shortest_unmarked;
    t_obj   *obj;
    t_node  *cur;

    shortest_unmarked = stack_a->size;
    cur = stack_a->top;
    while (cur)
    {
        obj = check_lasts_unmarked_path(stack_a, cur, unmarked_nbs, &shortest_unmarked);
        cur = cur->next;
    }
    if (obj->path == stack_a->size)
        return (NULL);
    return (obj);
}

void    push_swap_for_lasts_unmarked(t_stack *stack_a, t_stack *stack_b, t_unmarked *unmarked_nbs)
{
    int     count;
    int     real_pos;
    t_obj   *obj;
    //malloc in check_lasts_unmarked_path then need to be free

    if (!obj)
        return ;
    count = count_lasts_unmarked(stack_a, unmarked_nbs);
    if (count == 0)
        return ;
    while (count > 0)
    {
        obj = check_lasts_unmarked_in_a(stack_a, stack_b, unmarked_nbs);
        real_pos = get_real_pos(stack_a, obj->value);
        if (stack_b->size >= 2 && *(stack_b->top->value) < *(stack_b->top->next->value))
            sb(stack_b);
        swap_rotate(stack_a, stack_b, obj, real_pos);
        pb(stack_a, stack_b);
        count--;
    }
    free(obj);
}
