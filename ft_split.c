#include "libft.h"
#include <stdio.h>

size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if ((i == 0 && s[i] == c) || (s[i + 1] == '\0' && s[i] == c)
			|| (s[i] == c && s[i + 1] == c))
		{
			i++;
			continue ;
		}
		if (s[i] == c)
			count++;
		i++;
	}
	return (count + 1);
}

void	copystr(char const *s, char c, char **str_arr, size_t i)
{
	size_t	count;
	size_t	j;
	size_t	k;

	count = 0;
	k = i;
	while (s[i] != c)
	{
		i++;
		j++;
	}
	while (*str_arr[count] != '\0')
		count++;
	free(str_arr[count]);
	str_arr[count] = malloc(sizeof(char) * (j + 1));
	j = 0;
	while (s[k] != c)
	{
		str_arr[count][j] = s[k];
		j++;
		k++;
	}
	str_arr[count][j] = '\0';
}

char	**ft_split(char const *s, char c)
{
	char	**str_arr;
	size_t	i;

	i = 0;
	str_arr = malloc(sizeof(char *) * count_words(s, c));
	if (str_arr == NULL)
		return (NULL);
	while (i <= count_words(s, c))
	{
		str_arr[i] = malloc(1 * sizeof(char));
		if (str_arr[i] == NULL)
			return (NULL);
		ft_bzero(str_arr[i], 1);
		i++;
	}
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
			copystr(s, c, str_arr, i);
		i++;
	}
	return (str_arr);
}
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