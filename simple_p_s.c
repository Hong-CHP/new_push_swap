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
    else if (*(first->value) > *(second->value)
        && *(second->value) > *(third->value)) 
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