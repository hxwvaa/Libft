#include "libft.h"

int	ft_tolower(int i)
{
	if (i >= 'a' && i <= 'z')
		i += 32;
	return (i);
}
