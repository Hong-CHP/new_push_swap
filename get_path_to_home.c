#include "push_swap.h"

int     real_pos_first_part(int real_pos, int insert_pos, int pos)
{
    if (pos > insert_pos)
        return (pos);
    else
        return (insert_pos - 1);
}

int     get_short_path_one(t_stack *stack_a, t_stack *stack_b, t_node *cur, int insert_pos)
{
    int     real_pos;
    int     pos;
    
    real_pos = get_real_pos(stack_b, *(cur->value));
    pos = find_pos_in_b(stack_b, real_pos);
    if (real_pos == 1 && insert_pos != 1)
        return (insert_pos - 1);
    if (insert_pos == 1)
        return (pos);
    if (real_pos <= (stack_b->size + 1) / 2)
    {
        if (pos > insert_pos)
            return (pos);
        else
            return (insert_pos - 1);
    }
    else
    {
        if (pos > stack_a->size - insert_pos + 1)
            return (pos);
        else
            return (pos + insert_pos - 1);
    }
}

int     get_short_path_two(t_stack *stack_a, t_stack *stack_b, t_node *cur, int insert_pos)
{
    int     real_pos;
    int     pos;

    real_pos = get_real_pos(stack_b, *(cur->value));
    pos = find_pos_in_b(stack_b, real_pos);
    if (real_pos == 1 && stack_a->size - insert_pos + 1 != 0)
        return (stack_a->size - insert_pos + 1);
    if (real_pos <= (stack_b->size + 1) / 2)
    {
        if (pos < insert_pos)
            return (pos + stack_a->size - insert_pos + 1);
        else
            return (pos);
    }
    else
    {
        if (pos > stack_a->size - insert_pos + 1)
            return (pos);
        else
            return (stack_a->size - insert_pos + 1);
    }
}

int    *get_val_in_b(t_stack *stack_a, t_stack *stack_b)
{
    t_node *cur;
    int     insert_pos;
    int     i;
    int     *path;
    //malloc need to be free after used

    path = malloc(sizeof(int) * stack_b->size);
    if (!path)
        return (NULL);
    cur = stack_b->top;
    i = 0;
    while (cur)
    {
        insert_pos = find_val_insert_place(stack_a, *(cur->value));
        if (insert_pos == -1)
            insert_pos = solve_two_exp_case(stack_a, *(cur->value));
        // printf("value is %d, insert_pos is %d, real_pos is %d, pos is %d\n", *(cur->value), insert_pos, real_pos, pos);
        if (insert_pos <= (stack_a->size + 1) / 2)
            path[i] = get_short_path_one(stack_a, stack_b, cur, insert_pos);
        else
            path[i] = get_short_path_two(stack_a, stack_b, cur, insert_pos);
        i++;
        cur = cur->next;
    }
    return (path);
}
