#include "push_swap.h"

int *recup_flags(int size, int best_end, int *prev)
{
    int  *flags;
    int     p;

    flags = malloc(sizeof(int) * size);
    if (!flags)
        return (NULL);
    ft_bzero(flags, size);
    p = best_end;
    while (p != -1) 
    {   
        flags[p] = 1;
        p = prev[p];
    }
    return (flags);
}

void update_max_lis(int *dp, int i, int *max_len, int *best_end)
{
    *max_len = dp[i];
    *best_end = i;
}

int fill_dp_and_prev(int *arr, int size, int *dp, int *prev)
{
    int i;
    int j;
    int max_len;
    int best_end;

    i = 1;
    max_len = 1;
    while (i < size)
    {
        j = 0;
        while (j < i)
        {
            if (arr[i] > arr[j] && (dp[j] + 1 > dp[i] ||
                (dp[j] + 1 == dp[i] && arr[j] < arr[prev[i]])))
            {
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
            j++;
        }
        if (dp[i] > max_len || (dp[i] == max_len && arr[i] < arr[best_end]))
            update_max_lis(dp, i, &max_len, &best_end);
        i++;
    }
    return (best_end);
}

int *get_longest_increasing_nums(int *arr, int size)
{
    int *dp;
    int *prev;
    int *flags;
    int best_end;
    int i;

    dp = malloc(sizeof(int) * size);
    prev = malloc(sizeof(int) * size);
    if (!dp || !prev)
        return (NULL);
    i = 0;
    while (i < size)
    {
        dp[i] = 1;
        prev[i] = -1;
        i++;
    }
    best_end = fill_dp_and_prev(arr, size, dp, prev);
    flags = recup_flags(size, best_end, prev);
    free(dp);
    free(prev);
    return (flags);
}

