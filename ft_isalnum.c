#include "libft.h"

int	ft_isalpha(int i)
{
	if ((i >= 'A' && i <= 'Z') || (i >= 'a' && i <= 'z') || (i >= '0'
			&& i <= '9'))
		return (1);
	return (0);
}
