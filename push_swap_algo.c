#include "push_swap.h"

void    check_a_before_move(t_stack *stack_a, t_stack *stack_b)
{
    if (*(stack_a->top->value) > *(stack_a->top->next->value))
    {
        if (stack_b->size >= 2 && *(stack_b->top->value) < *(stack_b->top->next->value))
            ss(stack_a, stack_b);
        else
            sa(stack_a);
    }
}

void    check_b_before_move(t_stack *stack_a, t_stack *stack_b)
{
    if (stack_b->size >= 2 && *(stack_b->top->value) > *(stack_b->top->next->value))
    {
        // if (*(stack_a->top->value) > *(stack_a->top->next->value))
        //     ss(stack_a, stack_b);
        // else
            sb(stack_b);
    }
}

void    swap_rotate(t_stack *stack_a, t_stack *stack_b, t_obj *shortest, int real_pos)
{
    int b_bottom;

    if (stack_b->size > 2)
        b_bottom = get_bottom_val(stack_b);
    if (real_pos == 2)
    {
        if (stack_b->size >= 2 && *(stack_b->top->value) < *(stack_b->top->next->value))
            ss(stack_a, stack_b);
        else
            sa(stack_a);
    }
    else if (real_pos <= (stack_a->size + 1) / 2)
    {
        while (*(stack_a->top->value) != shortest->value)
        {
            if (stack_b->size > 2 && *(stack_b->top->value) > b_bottom)
                rr(stack_a, stack_b);
            else
                ra(stack_a);
        }
    }
    else if (real_pos > (stack_a->size + 1) / 2)
    {
        while (*(stack_a->top->value) != shortest->value)
        {
            if (stack_b->size > 2 && *(stack_b->top->value) > b_bottom)
                rrr(stack_a, stack_b);
            else
                rra(stack_a);
        }
    }
}

void    swap_rotate_shortest_to_top(t_stack *stack_a, t_stack *stack_b, t_obj *shortest)
{
    int real_pos;

    if (shortest->path == -1)
        return ;
    real_pos = get_real_pos(stack_a, shortest->value);
    // check_a_before_move(stack_a, stack_b);
    check_b_before_move(stack_a, stack_b);
    swap_rotate(stack_a, stack_b, shortest, real_pos);
    pb(stack_a, stack_b);
}

void    push_swap_algo(t_stack *stack_a, t_stack *stack_b, int *arr_asc, t_unmarked *unmarked_nbs)
{
    int i;
    int *pos_obj;
    t_index times;
    t_obj shortest;
    int k;
    int sqrt;

    sqrt = find_sqrt(stack_a->size);
    i = 0;
    while (i < sqrt)
    {
        pos_obj = malloc(sizeof(int) * sqrt);
        if (!pos_obj)
            return ;
        ft_bzero(pos_obj, sqrt);
        k = i * sqrt;
        times.start = i * sqrt;
        times.end = times.start + sqrt;
        printf("\n-----------------------------------------------\n");
        printf("[%d] sqrt: ", i);
        while (k < times.end)
        {
            find_obj_node_pos(stack_a, arr_asc, times, unmarked_nbs, pos_obj);
            shortest = find_shorter_path_rotate(arr_asc, unmarked_nbs, pos_obj, times);
            swap_rotate_shortest_to_top(stack_a, stack_b, &shortest);
            k++;
        }
        free(pos_obj);
        i++;
    }
}

// void    find_obj_by_sqrt(t_stack *stack_a, int *arr_asc, t_unmarked *unmarked_nbs, int index)
// {
//     int *pos_obj;
//     int i;
//     int sqrt;
//     t_index times;
//     t_obj shortest;

//     sqrt = find_sqrt(stack_a->size);
//     pos_obj = malloc(sizeof(int) * sqrt);
//     if (!pos_obj)
//         return ;
//     ft_bzero(pos_obj, sqrt);
//     i = index * sqrt;
//     times.start = index * sqrt;
//     times.end = index * sqrt + sqrt;
//     printf("%d - %d\n", times.start, times.end);
//     while (i < index * sqrt + sqrt)
//     {
//         find_obj_node_pos(stack_a, arr_asc, times, pos_obj);
//         shortest = find_shorter_path_rotate(arr_asc, unmarked_nbs, pos_obj, times);
//         printf("shortest.path is %d and obj.value is %d\n", shortest.path, shortest.value);
//         if (shortest.path == -1)
//             continue ;
//         rotate_shortest_to_top(stack_a, &shortest);
//         i++;
//     }
// }
// printf("\n-----------------------------------------------\n");
// printf("[%d] sqrt: ", i);
// find_obj_by_sqrt(stack_a, arr_asc, unmarked_nbs, i);