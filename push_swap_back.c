#include "push_swap.h"

int     find_shortest_path_val_among(t_stack *stack, int index)
{
    t_node  *cur;
    int     val;
    int     i;

    cur = stack->top;
    i = 0;
    while (cur->next && i < index)
    {
        i++;
        cur = cur->next;
    }
    val = *(cur->value);
    return (val);
}

void    push_swap_back(t_stack *stack_a, t_stack *stack_b, t_unmarked *unmarked_nbs)
{
    int val;
    int index;
    int insert_pos;
    int real_pos;
    int *path;
//malloc need to be free after used
    push_swap_for_lasts_unmarked(stack_a, stack_b, unmarked_nbs);
    // ft_print_stack(stack_a);
    // ft_print_stack(stack_b);
    while (stack_b->size > 0)
    {
        path = get_val_in_b(stack_a, stack_b);
        index = find_shortest_from_mins(path, stack_b->size);
        val = find_shortest_path_val_among(stack_b, index);
        insert_pos = find_val_insert_place(stack_a, val);
        if (insert_pos == -1)
            insert_pos = solve_two_exp_case(stack_a, val);
        real_pos = get_real_pos(stack_b, val);
        // print_arr(path, stack_b->size);
        // printf("insert val is %d\n", val);
        // printf("insert_pos is %d\n", insert_pos);
        // printf("real pos is %d\n", real_pos);
        if (insert_pos <= (stack_a->size + 1) / 2)
        {
            if (real_pos == 1 && insert_pos != 1)
            {
                while (insert_pos - 1 != 0)
                {
                    ra(stack_a);
                    insert_pos--;
                }
            }
            if (real_pos <= (stack_b->size + 1) / 2)
            {
                if (insert_pos == 1 && real_pos != 1)
                {
                    while (*(stack_b->top->value) != val)
                        rb(stack_b);
                }
                if (path[index] > insert_pos)
                {
                    while (insert_pos - 1 != 0)
                    {
                        rr(stack_a, stack_b);
                        insert_pos--;
                    }
                    while (*(stack_b->top->value) != val)
                        rb(stack_b);
                }
                else
                {
                    while (insert_pos - 1 != 0) 
                    {
                        rr(stack_a, stack_b);
                        insert_pos--;
                    }
                    while (*(stack_b->top->value) != val)
                    {
                        rb(stack_b);
                        insert_pos--;
                    }

                }
            }
            else
            {
                if (insert_pos == 1 && real_pos != 1)
                {
                    while (*(stack_b->top->value) != val)
                        rrb(stack_b);
                }
                if (path[index] > stack_a->size - insert_pos + 1)
                {
                    while (stack_a->size - insert_pos + 1 != 0)
                    {
                        rrr(stack_a, stack_b);
                        insert_pos++;
                    }
                    while (*(stack_b->top->value) != val)
                        rrb(stack_b);
                }
                else
                {
                    while (*(stack_b->top->value) != val)
                        rrb(stack_b);
                    while (insert_pos - 1 != 0)
                    {
                        ra(stack_a);
                        insert_pos--;
                    }
                }
            }
        }
        else
        {
            if (real_pos == 1 && stack_a->size - insert_pos + 1 == 0)
                rra(stack_a);
            if (real_pos == 1 && stack_a->size - insert_pos + 1 != 0)
            {
                while (stack_a->size - insert_pos + 1 != 0)
                {
                    rra(stack_a);
                    insert_pos++;
                }
            }
            if (real_pos <= (stack_b->size + 1) / 2)
            {
                if (path[index] < insert_pos)
                {
                    while (*(stack_b->top->value) != val)
                        rb(stack_b);
                    while (stack_a->size - insert_pos + 1 != 0)
                    {
                        rra(stack_a);
                        insert_pos++;
                    }
                }
                else
                {
                    while (insert_pos - 1 != 0)
                    {
                        rr(stack_a, stack_b);
                        insert_pos--;
                    }
                    while (*(stack_b->top->value) != val)
                        rb(stack_b);
                }
            }
            else
            {
                if (path[index] >= (stack_a->size - insert_pos + 1))
                {
                    while (stack_a->size - insert_pos + 1 != 0)
                    {
                        rrr(stack_a, stack_b);
                        insert_pos++;
                    }
                    while (*(stack_b->top->value) != val)
                        rrb(stack_b);
                }
                else
                {
                    while (*(stack_b->top->value) != val)
                    {
                        rrr(stack_a, stack_b);
                        insert_pos++;
                    }
                    while (stack_a->size - insert_pos + 1 != 0)
                    {
                        rra(stack_a);
                        insert_pos++;
                    }
                }
            }
        }
        pa(stack_b, stack_a);
    }
    free(path);
}