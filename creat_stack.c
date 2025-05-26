#include "push_swap.h"

void    ft_free_stack(t_stack *stack)
{
    t_node *node;
    t_node *next;

    if (!stack)
        return ;
    node = stack->top;
    while (node)
    {
        next = node->next;
        if (node->value)
            free(node->value);
        free(node);
        node = next;
    }
    stack->top = NULL;
    stack->size = 0;
}

void    ft_push(t_stack *stack, int *value)
{
    t_node *node;

    node = (t_node *)malloc(sizeof(t_node));
    if (!node)
        return ;
    node->value = value;
    node->next = stack->top;
    node->prev = NULL;
    if (stack->top != NULL)
        stack->top->prev = node;
    stack->top = node;
    stack->size++;
}

void    ft_print_stack(t_stack *stack)
{
    t_node *cur;

    cur = stack->top;
    while (cur)
    {
        printf(" <- %d - > ", *(cur->value));
        cur = cur->next;
    }
    printf("NULL\n");
}

int is_dup_value(t_stack *stack, int *value)
{
    t_node  *cur;

    cur = stack->top;
    while (cur)
    {
        if (*value == *(cur->value))
            return (1);
        cur = cur->next;
    }
    return (0);
}

void	get_value_init_stack(int argc, char *argv[])
{
    int *value;
    int i;
    t_stack stack_a = {NULL, 0};
    t_stack stack_b = {NULL, 0};

    i = 0;
    while (i < argc)
    {
        value = malloc(sizeof(int));
        if (!value)
            return ;
        *value = ft_atoi(argv[i]);
        if (is_dup_value(&stack_a, value))
        {
            write(1, "Error\n", 6);
            exit(1);
        }
        ft_push(&stack_a, value);
        i++;
    }
    // ft_print_stack(&stack_a);
    if (stack_a.size <= 6)
        easy_push_swap(&stack_a, &stack_b);
    else
        push_swap(&stack_a, &stack_b);
    // if (stack_a.size >= 3 && stack_b.size > 0)
    //     back_to_a(&stack_a, &stack_b);
    // ft_print_stack(&stack_a);
    // if (stack_b.size != 0)
    //     ft_print_stack(&stack_b);
    // else
    //     printf("NULL\n");
    ft_free_stack(&stack_a);
    ft_free_stack(&stack_b);
}