#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*temp;

	temp = (char *) s;
	while (*temp != (unsigned char)c)
	{
		if (!*temp)
			return (0);
		temp++;
	}
	return (temp);
}
