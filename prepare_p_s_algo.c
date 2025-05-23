#include "push_swap.h"

void    print_arr(int *arr, int size)
{
    int i = 0;
    while (i < size)
    {
        printf("%d, ", arr[i]);
        i++;
    }
    printf("\n");
}

void    sort_less_than_seven(t_stack *stack_a, t_stack *stack_b)
{
    int *arr;

    arr = malloc(sizeof(int) * stack_a->size);
    if (!arr)
        return ;
    get_arr_min_check_rotate_push(stack_a, stack_b, arr);
    sort_three(stack_a);
    while (stack_b->size > 0)
        pa(stack_b, stack_a);
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
    print_arr(unmarked_nbs->unmarked_nums, j);
    return (unmarked_nbs);
}

t_unmarked  *allocate_and_fill_unmarked(int *flags, int *arr_ord, int size)
{
    t_unmarked *unmarked_nbs;
    //(malloc in func, need to be free)

    unmarked_nbs = malloc(sizeof(t_unmarked));
    if (!unmarked_nbs)
        return (0);
        unmarked_nbs->unmarked_nums = malloc(sizeof(int) * size);
    if (!unmarked_nbs->unmarked_nums)
    {
        free(unmarked_nbs);
        return NULL;
    }
    find_unmarked_nums_sort(unmarked_nbs, flags, arr_ord, size);
    return (unmarked_nbs);
}

void    push_swap(t_stack *stack_a, t_stack *stack_b)
{
    int *flags;
    //(malloc in get_longest_increasing_nums, need to be free at last of program)
    int *arr_dsc;
    //(malloc in stack_mapping_arr_ord, need to be free)
    int *arr_ord;
    //(malloc in stack_mapping_arr_ord, need to be free)
    t_unmarked *unmarked_nbs;
    //(malloc in func, need to be free)

    arr_ord = stack_mapping_arr_ord(stack_a);
    arr_dsc = stack_mapping_arr_ord(stack_a);
    get_sort_arr(stack_a->size, arr_dsc);
    print_arr(arr_ord, stack_a->size);
    print_arr(arr_dsc, stack_a->size);
    flags = stack_mapping_arr_flags(stack_a);
    unmarked_nbs = allocate_and_fill_unmarked(flags, arr_ord, stack_a->size);
    push_swap_algo(stack_a, stack_b, arr_dsc, unmarked_nbs);
    free(flags);
    free(arr_ord);
    free(arr_dsc);
    free(unmarked_nbs->unmarked_nums);
    free(unmarked_nbs);
}

//./a.out 45 72 7 23 40 0 42 9 19 12 17 77 28 22 3 10 78 38 16 39 46
//ord is : 45, 72, 7, 23, 40, 0, 42, 9, 19, 12, 17, 77, 28, 22, 3, 10, 78, 38, 16, 39, 46
//flag is: 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 1, 1
//asc is : 0, 3, 7, 9, 10, 12, 16, 17, 19, 22, 23, 28, 38, 39, 40, 42, 45, 46, 72, 77, 78
//unmarked is : 3, 7, 10, 16, 19, 23, 28, 40, 42, 45, 72, 77, 78
//sqrt is 4

// print_arr(arr_ord, stack_a->size);
// print_arr(flags, stack_a->size);
// print_arr(arr_asc, stack_a->size);