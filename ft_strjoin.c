#include "libft.h"

//CHECK FOR 
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	char	*s;

	if (!s1 && !s2)
		return (NULL);
	s = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (s == NULL)
		return (NULL);
	str = s;
	if (s1)
		while (*s1)
			*str++ = *s1++;
	if (s2)
		while (*s2)
			*str++ = *s2++;
	*str = '\0';
	return (s);
}
