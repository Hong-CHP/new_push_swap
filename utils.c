#include "push_swap.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while(str[len])
		len++;
	return (len);
}

int	is_validate_param(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (is_space(str[i]))
			i++;
		if (str[i] == '+' || str[i] == '-')
			i++;
		if(!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*dest;
	int		len;

	if (!src)
		return (NULL);
	len = ft_strlen(src);
	dest = (char *)malloc((len + 1) *sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	*ft_bzero(int *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		s[i++] = 0;
	return (s);
}

int ft_atoi(char *str)
{
	int nb;
	int	i;
	int flag;

	i = 0;
	nb = 0;
	flag = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			flag *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10;
		nb = nb + (str[i] - '0');
		i++;
	}
	return (nb * flag);
}