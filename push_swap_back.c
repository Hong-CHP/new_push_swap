#include "push_swap.h"

void rotate_sep(t_stack *a, t_stack *b, t_move m)
{
    while (m.a_rot > 0)
    {
        ra(a);
        m.a_rot--;
    }
    while (m.a_rot < 0)
    {
        rra(a);
        m.a_rot++;
    }
    while (m.b_rot > 0)
    {
        rb(b);
        m.b_rot--;
    }
    while (m.b_rot < 0)
    {
        rrb(b);
        m.b_rot++;
    }
}

void rotate_both(t_stack *a, t_stack *b, t_move m)
{
    while (m.a_rot > 0 && m.b_rot > 0)
    {
        rr(a, b);
        m.a_rot--; m.b_rot--;
    }
    while (m.a_rot < 0 && m.b_rot < 0)
    {
        rrr(a, b);
        m.a_rot++; m.b_rot++;
    }
    rotate_sep(a, b, m);
}

int calc_rot_cost(int size, int index)
{
    if (index <= size / 2)
        return index;
    else
        return index - size;
}

t_move  *get_insert_pos_in_a_idx_in_b(t_stack *stack_a, t_stack *stack_b, int val, t_move *best_move)
{
    int a_idx;
    int b_idx;
    int a_cost;
    int b_cost;
    int cost;

    a_idx = find_val_insert_place(stack_a, val);
    if (a_idx == -1)
        a_idx = solve_two_exp_case(stack_a, val);
    b_idx = get_index(stack_b, val);
    a_cost = calc_rot_cost(stack_a->size, a_idx);
    b_cost = calc_rot_cost(stack_b->size, b_idx);
    if ((a_cost >= 0 && b_cost >= 0) || (a_cost < 0 && b_cost < 0))
        cost = ft_max(ft_abs(a_cost), ft_abs(b_cost));
    else
        cost = cost = abs(a_cost) + abs(b_cost);
    // printf("cost is %d\n", cost);
    if (cost < best_move->total_cost)
    {
        best_move->val = val;
        best_move->a_rot = a_cost;
        best_move->b_rot = b_cost;
        best_move->total_cost = cost;
    }
    return (best_move);
}

//one malloc in func, free already
void push_swap_back(t_stack *stack_a, t_stack *stack_b, t_unmarked *unmarked)
{
    int val;
    t_node  *cur;
    t_move *best_move;

    while (stack_b->size > 0)
    {
        // ft_print_stack(stack_a);
        // ft_print_stack(stack_b);
        best_move = malloc(sizeof(t_move));
        if (!best_move)
            return ;
        best_move->total_cost = 2147483647;
        cur = stack_b->top;
        while (cur)
        {
            val = *(cur->value);
            get_insert_pos_in_a_idx_in_b(stack_a, stack_b, val, best_move);
            cur = cur->next;
        }
        // printf("best move total cost is %d\n", best_move->total_cost);
        rotate_both(stack_a, stack_b, *best_move);
        pa(stack_b, stack_a);
        free(best_move);
    }
}
