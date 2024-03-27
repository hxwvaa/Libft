#include "libft.h"
#include <stdio.h>
#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	const char	*s;
	char		*d;

	i = 0;
	s = src;
	d = dest;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
