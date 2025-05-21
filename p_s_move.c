#include "push_swap.h"

void	swap_top_two(t_stack *stack)
{
	t_node *first;
	t_node *second;
	
	if (!stack || !stack->top || !stack->top->next)
		return ;
	first = stack->top;
	second = first->next;
	first->next = second->next;
	first->prev = second;
	second->prev = NULL;
	second->next = first;
	if (first->next)
		first->next->prev = first;
	stack->top = second;
}

void	push_to_top(t_stack *stack_a, t_stack *stack_b)
{
	t_node *first;

	if (!stack_a || !stack_a->top || !stack_a->top->value)
		return ;
	first = stack_a->top;
	stack_a->top = first->next;
	if (first->next != NULL)
		stack_a->top->prev = NULL;
	stack_a->size--;
	first->next = stack_b->top;
	first->prev = NULL;
	if (stack_b->top != NULL)
		stack_b->top->prev = first;
	stack_b->top = first;
	stack_b->size++;
}

void	rotate_to_top(t_stack *stack)
{
	t_node	*bottom;
	t_node	*first;

	if (stack->size < 2)
		return ;
	first = stack->top;
	stack->top = first->next;
	stack->top->prev = NULL;
	bottom = stack->top;
	while (bottom->next)
		bottom = bottom->next;
	bottom->next = first;
	first->prev = bottom;
	first->next = NULL;
}

void    reverse_rotate(t_stack *stack)
{
	t_node *bottom;

	if (stack->size < 2)
		return ;
	bottom = stack->top;
	while (bottom->next)
		bottom = bottom->next;
	bottom->prev->next = NULL;
	bottom->next = stack->top;
	bottom->prev = NULL;
	stack->top->prev = bottom;
	stack->top = bottom;
}