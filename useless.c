
// int     get_bottom_val(t_stack *stack)
// {
//     t_node *cur;
//     int bottom;

//     cur = stack->top;
//     while (cur->next)
//         cur = cur->next;
//     bottom = *(cur->value);
//     return (bottom);
// }

// void    print_arr(int *arr, int size)
// {
//     int i = 0;
//     while (i < size)
//     {
//         printf("%d, ", arr[i]);
//         i++;
//     }
//     printf("\n");
// }

// void    remove_unmarked_value(t_unmarked *unmarked_nbs, int val)
// {
//     int i = 0;
//     while (i < unmarked_nbs->unmarked_size)
//     {
//         if (unmarked_nbs->unmarked_nums[i] == val)
//         {
//             while (i < unmarked_nbs->unmarked_size - 1)
//             {
//                 unmarked_nbs->unmarked_nums[i] = unmarked_nbs->unmarked_nums[i + 1];
//                 i++;
//             }
//             unmarked_nbs->unmarked_size--;
//             return;
//         }
//         i++;
//     }
// }

/* 返回 flags[i] = 1 表示 arr[i] 在最终选定的 LIS 内 */
// int *get_longest_increasing_nums(int *arr, int size)
// {
//     int     i;
//     int     j;
//     int  *dp;
//     int  *prev;
//     int   *flag;
//     int   max_len = 1;
//     int   best_end = 0;

//     init_dp_and_prev(&dp, &prev, size);
//     i = 1;
//     while (i < size)
//     {
//         j = 0; 
//         while (j < i)
//         {
//             if (arr[i] > arr[j] && (dp[j] + 1 > dp[i] ||
//                     (dp[j] + 1 == dp[i] && arr[j] < arr[prev[i]])))
//             {
//                 dp[i] = dp[j] + 1;
//                 prev[i] = j;
//             }
//             j++;
//         }
//         if (dp[i] > max_len ||
//                 (dp[i] == max_len && arr[i] < arr[best_end]))
//         {
//             max_len = dp[i];
//             best_end = i;
//         }
//         i++;
//     }
//     flag = recup_flags(arr, size, best_end, prev);
//     free(dp);
//     free(prev);
//     print_flag(flag, size);
//     return (flag);
// }

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