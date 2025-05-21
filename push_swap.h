#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_node
{
    int         *value;
    struct s_node *next;
    struct s_node *prev;
}               t_node;

typedef struct s_stack
{
    t_node *top;
    int     size;
}               t_stack;

int     ft_strlen(char *str);
int     is_space(char c);
int     ft_split_needed(int ac, char *av[]);
char	*ft_strdup(char *src);
char    *ft_strjoin(char *str_tab, int ac, char *av[]);
char    *join_before_split(int ac, char *av[]);
void	free_reverse_params(int ac, char **res);
int     count_words(char *str);
char    **ft_split(char **res, char *str);
char    **allocate_and_split(char *str);
int     is_validate_param(char *str);
int     *ft_bzero(int *s, size_t n);
int     ft_atoi(char *str);
void	get_value_init_stack(int argc, char *argv[]);
void	swap_top_two(t_stack *stack);
void	push_to_top(t_stack *stack_a, t_stack *stack_b);
void	rotate_to_top(t_stack *stack);
void    reverse_rotate(t_stack *stack);
void    sa(t_stack *stack_a);
void    sb(t_stack *stack_b);
void    ss(t_stack *stack_a, t_stack *stack_b);
void    ra(t_stack *stack_a);
void    rb(t_stack *stack_b);
void    rr(t_stack *stack_a, t_stack *stack_b);
void    rra(t_stack *stack_a);
void    rrb(t_stack *stack_b);
void    rrr(t_stack *stack_a, t_stack *stack_b);
void    pb(t_stack *stack_b, t_stack *stack_a);
void    pa(t_stack *stack_b, t_stack *stack_a);
int     *creat_array_from_stack(t_stack *stack_a, int *arr);
int    *stack_mapping_arr_ord(t_stack *stack_a);
int    *stack_mapping_arr_asc(t_stack *stack_a);
int     *get_longest_increasing_nums(int *arr, int size);
void    get_sort_arr(t_stack *stack_a, int *arr);
void    push_swap(t_stack *stack_a, t_stack *stack_b);

#endif