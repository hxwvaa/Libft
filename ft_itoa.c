#include "libft.h"
#include <stdio.h>

int	count(int n)
{
	int	i;

	if (n == 0)
		return (1);
	i = 0;
	if (n < 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	unsigned int	len;
	unsigned int	num;
	char			*str;

	num = n;
	len = count(n);
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	if (num == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		num = num * -1;
	}
	while (num != 0)
	{
		str[len - 1] = ('0' + (num % 10));
		num = num / 10;
		len--;
	}
	return (str);
}
