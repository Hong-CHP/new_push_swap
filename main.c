#include "push_swap.h"

void	free_reverse_params(int ac, char **res)
{
	int i;

	i = 0;
	while (i < ac)
	{
		free(res[i]);
		i++;
	}
	free(res);
	res = NULL;
}

char	**reverse_params(int ac, char *av[])
{
	char	**res;
	int		i;
	int		j;

	res = (char **)malloc((ac + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	i = 0;
	j = ac - 1;
	while (i < ac)
	{
		res[i] = ft_strdup(av[j]);
		j--;
		i++;
	}
	res[i] = NULL;
	return (res);
}

void	split_reverse_put_into_stack(int ac, char *av[])
{
	char **res;
	char **ptr;
	char *str_join;

	if (ac == 1 && ft_split_needed(ac, av) == 0)
	{
		res = allocate_and_split(av[0]);
		ptr = reverse_params(count_words(av[0]), res);
		free_reverse_params(count_words(av[0]), res);
		get_value_init_stack(count_words(av[0]), ptr);
		free_reverse_params(count_words(av[0]), ptr);
	}
	else
	{
		str_join = join_before_split(ac, av);
		res = allocate_and_split(str_join);
		ptr = reverse_params(count_words(str_join), res);
		free_reverse_params(count_words(str_join), res);
		get_value_init_stack(count_words(str_join), ptr);
		free_reverse_params(count_words(str_join), ptr);
		free(str_join);
	}
}

void	split_op_params_put_stack(int ac, char *av[])
{
	char **res;

	if (ft_split_needed(ac, av) != -1)
			split_reverse_put_into_stack(ac, av);
	else
	{
		res = reverse_params(ac, av);
		if (!res)
			return ;
		get_value_init_stack(ac, res);
		free_reverse_params(ac, res);
	}
}

int main(int argc, char *argv[])
{
	int i;

	if (argc <= 1)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	i = 1;
	while (i < argc)
	{
		if (!is_validate_param(argv[i]))
		{
			write(1, "Error\n", 6);
			exit(1);
		}
		i++;
	}
	split_op_params_put_stack(argc - 1, argv + 1);
	return (0);
}