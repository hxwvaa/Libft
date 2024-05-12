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
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

void	*copystr(char const *s, char c, char *str)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	str = (char *)ft_calloc((i + 1), sizeof(char));
	if (!str)
	{
		while (i != 0)
		{
			free(&str[i]);
			i--;
		}
		return (NULL);
	}
	ft_memcpy(str, s, i);
	return (str);
}

void	*allocate(char **str_arr, char const *s, char c)
{
	size_t	i;
	size_t	words;

	words = count_words(s, c);
	free(str_arr);
	str_arr = (((char **)malloc(sizeof(char *) * (words + 1))));
	if (!str_arr)
		return (NULL);
	i = 0;
	while (i < words)
	{
		while (*s == c)
			s++;
		str_arr[i] = copystr(s, c, str_arr[i]);
		while (*s && *s != c)
			s++;
		i++;
	}
	str_arr[i] = NULL;
	return (str_arr);
}

size_t	word_length(char const *s, char c, size_t i)
{
	size_t	j;

	j = 0;
	while (s[i] && s[i] != c)
	{
		i++;
		j++;
	}
	return (j);
}

char	**ft_split(char const *s, char c)
{
	char	**str_arr;

	str_arr = '\0';
	if (s == NULL)
	{
		return (NULL);
	}
	str_arr = allocate(str_arr, s, c);
	return (str_arr);
}
