#include "libft.h"
#include <stdio.h>

// size_t	count_c(char const *s, char c)
// {
// 	size_t	i;
// 	size_t	count;

// 	i = 0;
// 	count = 0;
// 	while (s[i])
// 	{
// 		if ((i == 0 && s[i] == c) || (s[i + 1] == '\0' && s[i] == c)
// 			|| (s[i] == c && s[i + 1] == c))
// 		{
// 			i++;
// 			continue ;
// 		}
// 		if (s[i] == c)
// 			count++;
// 		i++;
// 	}
// 	return (count);
// }

// char	**ft_split(char const *s, char c)
// {
// 	char	**str_arr;
// 	char	*temp;
// 	size_t	count;
// 	size_t	i;
// 	size_t	j;
// 	size_t	k;

// 	str_arr = malloc(sizeof(char *) * (count_c(s, c) + 1));
// 	if (str_arr == NULL)
// 		return (NULL);
// 	count = 0;
// 	while (s[i])
// 	{
// 		if (s[i] != c)
// 		{
// 			j = i;
// 			while (s[i] != c)
// 			{
// 				i++;
// 				k++;
// 			}
// 			i = j;
// 			j = 0;
// 			temp = malloc(sizeof(char) * (k + 1));
// 			if (temp == NULL)
// 				return (NULL);
// 			while (s[i] != c)
// 			{
// 				temp[j] = s[i];
// 				if (s[i + 1] == c)
// 				{
// 					str_arr[count] = malloc((ft_strlen(temp) + 1)
// 							* sizeof(char));
// 					if (str_arr[count] == NULL)
// 						return (NULL);
// 					ft_strlcpy(str_arr[count], temp, ft_strlen(temp) + 1);
// 					count++;
// 					k = 0;
// 					break ;
// 				}
// 				i++;
// 				j++;
// 			}
// 		}
// 		i++;
// 	}
// 	return (str_arr);
// }

int	main(void)
{
	char *s = "ffhelrrloffhirrrifhorrwfyesrrf";
	char c = 'f';

	int i = 0;
	char **str = ft_split(s, c);
	while (i <= 3)
	{
		printf("%s\n", str[i]);
		i++;
	}
}