#include "push_swap.h"

int is_space(char c)
{
    if (c == ' ' || (c >= 9 && c <= 13))
        return (1);
    else
        return (0);
}

int ft_split_needed(int ac, char *av[])
{
    int i;
    int j;

    i = 0;
    while (i < ac)
    {
        j = 0;
        while (j < ft_strlen(av[i]))
        {
            if (is_space(av[i][j]))
                return (i);
            j++;
        }    
        i++;
    }
    return (-1);
}

char *ft_strjoin(char *str_tab, int ac, char *av[])
{
    int i;
    char *ptr;
    int j;
    int k;

    ptr = str_tab;
    i = 0;
    k = 0;  
    while (i < ac)
    {
        j = 0;
        while (j < ft_strlen(av[i]))
        {
            ptr[k] = av[i][j];
            k++;
            j++;
        }
        if (i < ac - 1)
            ptr[k++] = ' ';
        i++;
    }
    ptr[k] = '\0';
    return (str_tab);
}

char	*join_before_split(int ac, char *av[])
{
	char *str_join;
	int i;
	int	tot_len;
	
	i = 0;
	tot_len = 0;
	tot_len = 0;
	while (i < ac)
		tot_len += ft_strlen(av[i++]);
	str_join = (char *)malloc((tot_len + ac) *sizeof(char));
	if (!str_join)
		return (NULL);
	ft_strjoin(str_join, ac, av);
	return (str_join);
}
