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

void	*allocate(char **str_arr, char const *s, char c)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = count_words(s, c);
	free(str_arr);
	str_arr = malloc(sizeof(char *) * words);
	if (str_arr == NULL)
		return (NULL);
	while (i < words)
	{
		str_arr[i] = malloc(1);
		if (str_arr[i] == NULL)
			return (NULL);
		*str_arr[i] = '\0';
		i++;
	}
	return (str_arr);
}

size_t	word_length(char const *s, char c, size_t i)
{
	size_t	j;

	j = 0;
	while (s[i] != c)
	{
		i++;
		j++;
	}
	return (j);
}

void	*copystr(char const *s, char c, char **str_arr, size_t i)
{
	size_t	count;
	size_t	j;
	size_t	k;

	count = 0;
	j = 0;
	k = word_length(s, c, i);
	while (*str_arr[count] != '\0')
		count++;
	free(str_arr[count]);
	str_arr[count] = malloc(sizeof(char) * (k + 1));
	if (str_arr[count] == NULL)
		return (NULL);
	while (s[i] != c)
	{
		str_arr[count][j] = s[i];
		j++;
		i++;
	}
	str_arr[count][j] = '\0';
	return (str_arr);
}

char	**ft_split(char const *s, char c)
{
	char	**str_arr;
	size_t	i;

	i = 0;
	str_arr = NULL;
	if (s == NULL)
	{
		return (NULL);
	}
	i = 0;
	str_arr = allocate(str_arr, s, c);
	while (s[i])
	{
		if ((s[i] == c) && (s[i + 1] != c) && (s[i + 1]) != '\0')
			copystr(s, c, str_arr, i + 1);
		i++;
	}
	return (str_arr);
}
// int	main(void)
// {
// 	char const *s = "whiisiiwjuuusuwkkkiisiwwkkslww";
// 	char c = 'w';

// 	size_t i = 0;
// 	char **str = ft_split(s, c);
// 	while (i < 4)
// 	{
// 		printf("%s\n", str[i]);
//         free(str[i]);
// 		i++;
// 	}
//     free(str);
// }