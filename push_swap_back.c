#include "push_swap.h"

int    find_val_insert_place(t_stack *stack_a, int val)
{
    t_node *cur;
    int pos_in_a;

    pos_in_a = 1;
    cur = stack_a->top;
    while (cur->next)
    {
        if (val > *(cur->value) && val < *(cur->next->value))
            return (pos_in_a + 1);
        pos_in_a++;
        cur = cur->next;
    }
    return (-1);
}

int    find_val_insert_place_exp_one(t_stack *stack_a, int val)
{
    t_node *cur;
    int pos_in_a;
    int max;
    int pos;

    max = *(stack_a->top->value);
    cur = stack_a->top;
    pos_in_a = -1;
    pos = 1;
    while (cur)
    {
        if (max < *(cur->value))
        {
            max = *(cur->value);
            pos_in_a = pos;
        }
        pos++;
        cur = cur->next;
    }
    return (pos_in_a + 1);
}

int    find_val_insert_place_exp_two(t_stack *stack_a, int val)
{
    t_node *cur;

    cur = stack_a->top;
    if (val < *(cur->value))
    {
        while (cur->next)
            cur = cur->next;
        if (val > *(cur->value))
            return (1);
    }
    return (0);    
}
int    solve_two_exp_case(t_stack *stack_a, int val)
{
    t_node *cur;
    int max;

    max = val;
    cur = stack_a->top;
    while (cur)
    {
        if (max < *(cur->value))
            max = *(cur->value);
        cur = cur->next;
    }
    if (val == max)
        return (find_val_insert_place_exp_one(stack_a, val));
    else
        return (find_val_insert_place_exp_two(stack_a, val));
}

int    find_pos_in_b(t_stack *stack_b, int pos)
{
    if (pos <= (stack_b->size + 1) / 2)
        return (pos - 1);
    else
        return (stack_b->size - pos + 1);
}

void    get_val_in_b(t_stack *stack_a, t_stack *stack_b)
{
    t_node *cur;
    int     insert_pos;
    int     real_pos;
    int     pos;
    int     i;
    int     *path;
    //malloc need to be free after used

    path = malloc(sizeof(int) * stack_b->size);
    if (!path)
        return ;
    cur = stack_b->top;
    i = 0;
    while (cur)
    {
        real_pos = get_real_pos(stack_b, *(cur->value));
        pos = find_pos_in_b(stack_b, real_pos);
        insert_pos = find_val_insert_place(stack_a, *(cur->value));
        if (insert_pos == -1)
            insert_pos = solve_two_exp_case(stack_a, *(cur->value));
        printf("value is %d, insert_pos is %d, real_pos is %d, pos is %d\n", *(cur->value), insert_pos, real_pos, pos);
        if (insert_pos <= (stack_a->size + 1) / 2 + 1)
        {
            if (real_pos <= (stack_b->size + 1) / 2)
            {
                if (pos > insert_pos)
                    path[i] = pos;
                else
                    path[i] = insert_pos - 1;
            }
            else
            {
                //path[i] = pos;
                if (pos > stack_a->size - insert_pos + 1)
                   path[i] = pos;
                else
                    path[i] = pos + insert_pos - 1;
                // path[i] = stack_a->size - insert_pos + 1;   
            }
        }
        else
        {
            if (real_pos <= (stack_b->size + 1) / 2)
                path[i] = pos + stack_a->size - insert_pos + 1;
            else
            {
                if (pos > stack_a->size - insert_pos + 1)
                    path[i] = pos;
                else
                    path[i] = stack_a->size - insert_pos + 1;
            }
        }
        printf("path is %d\n", path[i]);
        printf("\n");
        i++;
        cur = cur->next;
    }
}