#include "push_swap.h"

void    find_obj_by_sqrt(t_stack *stack_a, int *arr_asc, t_unmarked *unmarked_nbs, int index)
{
    int *pos_obj;
    int i;
    int sqrt;
    t_index times;
    t_obj shortest;

    sqrt = find_sqrt(stack_a->size);
    pos_obj = malloc(sizeof(int) * sqrt);
    if (!pos_obj)
        return ;
    ft_bzero(pos_obj, sqrt);
    i = index * sqrt;
    times.start = index * sqrt;
    times.end = index * sqrt + sqrt;
    printf("%d - %d\n", times.start, times.end);
    while (i < index * sqrt + sqrt)
    {
        find_obj_node_pos(stack_a, arr_asc, times, pos_obj);
        shortest = find_shorter_path_rotate(arr_asc, unmarked_nbs, pos_obj, times);
        printf("shortest.path is %d and obj.value is %d\n", shortest.path, shortest.value);
        if (shortest.path == -1)
            continue ;
        i++;
    }
}

void    push_swap_algo(t_stack *stack_a, t_stack *stack_b, int *arr_asc, t_unmarked *unmarked_nbs)
{
    int sqrt;
    int i;

    sqrt = find_sqrt(stack_a->size);
    i = 0;
    while (i < sqrt)
    {
        printf("\n-----------------------------------------------\n");
        printf("[%d] sqrt: ", i);
        find_obj_by_sqrt(stack_a, arr_asc, unmarked_nbs, i);
        i++;
    }
}