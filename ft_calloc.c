#include "libft.h"
#include <stdio.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*s;

	if (nmemb == 0 || size == 0)
	{
		nmemb = 1;
		size = 1;
	}
	s = malloc(nmemb * size);
	if (s == NULL)
		return (NULL);
	ft_bzero(s, nmemb * size);
	return (s);
}
