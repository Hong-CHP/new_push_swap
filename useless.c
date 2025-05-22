
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