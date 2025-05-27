#include "push_swap.h"

//two malloc need to be free than, free already in func
void    sort_less_than_seven(t_stack *stack_a, t_stack *stack_b)
{
    int *arr;
    int *mins_path;
    mins_path = malloc(sizeof(int) * stack_a->size);
    if (!mins_path)
        return ;
    arr = malloc(sizeof(int) * stack_a->size);
    if (!arr)
        return ;
    get_arr_min_check_rotate_push(stack_a, stack_b, arr, mins_path);
    sort_three(stack_a);
    while (stack_b->size > 0)
        pa(stack_b, stack_a);
    free(mins_path);
    free(arr);
}

void    easy_push_swap(t_stack *stack_a, t_stack *stack_b)
{
    if (stack_a->size <= 1)
        return ;
    if (stack_a->size <= 1)
        return ;
    if (stack_a->size == 2)
        sort_two(stack_a);
    else if (stack_a->size == 3)
        sort_three(stack_a);
    else if (stack_a->size > 3 && stack_a->size <=6)
        sort_less_than_seven(stack_a, stack_b);
}

t_unmarked  *find_unmarked_nums_sort(t_unmarked *unmarked_nbs, int *flags, int *arr_ord, int size)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < size)
    {
        if (flags[i] != 1)
        {
            unmarked_nbs->unmarked_nums[j] = arr_ord[i];
            j++;
        }
        i++;
    }
    unmarked_nbs->unmarked_size = j;
    get_sort_arr(j, unmarked_nbs->unmarked_nums);
    return (unmarked_nbs);
}

t_unmarked  *allocate_and_fill_unmarked(int *flags, int *arr_ord, int size)
{
    t_unmarked *unmarked_nbs;
    //(malloc in func, need to be free)

    unmarked_nbs = malloc(sizeof(t_unmarked));
    if (!unmarked_nbs)
        return (NULL);
    unmarked_nbs->unmarked_nums = malloc(sizeof(int) * size);
    if (!unmarked_nbs->unmarked_nums)
    {
        free(unmarked_nbs);
        return (NULL);
    }
    find_unmarked_nums_sort(unmarked_nbs, flags, arr_ord, size);
    return (unmarked_nbs);
}

void    rotate_min_to_top(t_stack *stack_a, int min)
{
    int index;
    int cost;

    index = get_index(stack_a, min);
    if (index == 0)
        return ;
    cost = calc_rot_cost(stack_a->size, index);
    while (cost > 0)
    {
        ra(stack_a);
        cost--;
    }
    while (cost < 0)
    {
        rra(stack_a);
        cost++;
    }
}

//four mallocs, five free then including the unmarked arr allocated on top
void    push_swap(t_stack *stack_a, t_stack *stack_b)
{
    int *flags;
    int *arr_asc;
    int *arr_ord;
    t_unmarked *unmarked_nbs;
    int min;

    arr_ord = stack_mapping_arr_ord(stack_a);
    arr_asc = stack_mapping_arr_ord(stack_a);
    get_sort_arr(stack_a->size, arr_asc);
    // print_arr(arr_ord, stack_a->size);
    // print_arr(arr_asc, stack_a->size);
    flags = stack_mapping_arr_flags(stack_a);
    unmarked_nbs = allocate_and_fill_unmarked(flags, arr_ord, stack_a->size);
    // print_arr(unmarked_nbs->unmarked_nums, unmarked_nbs->unmarked_size);
    push_swap_algo(stack_a, stack_b, arr_asc, unmarked_nbs);
    push_swap_back(stack_a, stack_b, unmarked_nbs);
    min = arr_asc[0];
    rotate_min_to_top(stack_a, min);
    free(flags);
    free(arr_ord);
    free(arr_asc);
    free(unmarked_nbs->unmarked_nums);
    free(unmarked_nbs);
}
