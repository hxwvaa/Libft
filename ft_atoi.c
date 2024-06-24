#include "libft.h"
#include <stdio.h>

int	ft_atoi(const char *str)
{
	int				sign;
	unsigned long	nb;

	sign = 1;
	nb = 0;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		nb = nb * 10 + *str - '0';
		if (sign == -1 && nb >= LLONG_MAX)
			return (0);
		if (nb >= LLONG_MAX)
			return (-1);
		str++;
	}
	return (sign * nb);
}
