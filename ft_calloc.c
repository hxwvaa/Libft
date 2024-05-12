#include "libft.h"
#include <stdio.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*s;
	size_t	total;

	total = nmemb * size;
	s = malloc(total);
	if (s == NULL)
		return (NULL);
	ft_bzero(s, total);
	return (s);
}
