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
    pos_in_a = 1;
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
    if (pos_in_a == 1)
        return (1);
    return (pos_in_a + 1);
}

int    find_val_insert_place_exp_two(t_stack *stack_a, int val)
{
    t_node *cur;
    int min;

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

int    find_val_insert_place_exp_three(t_stack *stack_a, int val)
{
    int pos;
    int pos_in_a;
    t_node *cur;
    int min;

    cur = stack_a->top;
    min = *(cur->value);
    pos_in_a = 1;
    pos = 1;
    while (cur)
    {
        if (min > *(cur->value))
        {
            min = *(cur->value);
            pos_in_a = pos;
        }
        pos++;
        cur = cur->next;
    }
    if (pos_in_a == 1)
        return (1);
    else
        return (pos_in_a + 1); 
}

int    solve_two_exp_case(t_stack *stack_a, int val)
{
    t_node *cur;
    int max;
    int min;

    max = val;
    min = val;
    cur = stack_a->top;
    while (cur)
    {
        if (max < *(cur->value))
            max = *(cur->value);
        if (min > *(cur->value))
            min = *(cur->value);
        cur = cur->next;
    }
    if (val == max)
        return (find_val_insert_place_exp_one(stack_a, val));
    else if (val == min)
        return (find_val_insert_place_exp_three(stack_a, val));
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
