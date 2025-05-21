#include "push_swap.h"

void    sort_two(t_stack *stack)
{
    t_node *first;
    t_node *second;

    first = stack->top;
    second = first->next;
    if (*(first->value) > *(second->value))
        sa(stack);
}

void    ops_sort_three(t_stack *stack, t_node *first, t_node *second, t_node *third)
{
    if (*(first->value) > *(second->value)
        && *(second->value) < *(third->value)
        && *(first->value) < *(third->value))
        sa(stack);
    else if (*(first->value) < *(second->value)
        && *(second->value) > *(third->value)
        && *(first->value) > *(third->value))
        rra(stack);
    else if (*(first->value) > *(second->value)
        && *(first->value) > *(third->value)
        && *(second->value) < *(third->value))
        ra(stack);
    else if (*(first->value) < *(third->value)
        && *(first->value) < *(second->value)
        && *(second->value) > *(third->value))
    {
        sa(stack);
        ra(stack);
    }
    else if (*(first->value) > *(second->value) && *(second->value) > *(third->value)) 
    {
        sa(stack);
        rra(stack);
    }
}

void    sort_three(t_stack *stack)
{
    t_node *first;
    t_node *second;
    t_node *third;

    if (!stack || stack->size != 3)
        return ;
    first = stack->top;
    second = first->next;
    third = second->next;
    ops_sort_three(stack, first, second, third);
}

int *find_mins_pos_in_five(t_stack *stack_a, int num)
{
    t_node *cur;
    int pos;
    int feet;

    pos= 1;
    cur = stack_a->top;
    while (cur)
    {
        if (num == *(cur->value))
            break;
        pos++;
        cur = cur->next;
    }
    printf("%d\n", pos);
    if (pos > (stack_a->size + 1) / 2)
        feet = stack_a->size + 1 - pos;
    else
        feet = pos - 1;
    return (feet);
}

void    sort_five(t_stack *stack_a, t_stack *stack_b)
{
    int i;
    int feet;
    int *arr;
    //(malloc in function, need be free then)

    arr = malloc(sizeof(int) * stack_a->size);
    if (!arr)
        return ;
    arr = creat_array_from_stack(stack_a, arr);
    get_sort_arr(stack_a, arr);
    i = 0;
    // while (stack_a->size > 3)
    // {
        feet = find_mins_pos_in_five(stack_a, arr[i]);
        i++;
    // }
    // sort_three(stack_a);
    // free(arr);
}

void    sort_for_more(t_stack *stack_a, t_stack *stack_b)
{
    int i;
    int *arr_ord;
    //(malloc in stack_mapping_arr_ord, need to be free)
    int *flags;
    //(malloc in get_longest_increasing_nums, need to be free at last of program)

    arr_ord = stack_mapping_arr_ord(stack_a);
    flags = stack_mapping_arr_asc(stack_a);
}

void    push_swap(t_stack *stack_a, t_stack *stack_b)
{

    if (stack_a->size <= 1)
        return ;
    if (stack_a->size == 2)
        sort_two(stack_a);
    else if (stack_a->size == 3)
        sort_three(stack_a);
    else if (stack_a->size > 3 && stack_a->size <=5)
        sort_five(stack_a, stack_b);
}