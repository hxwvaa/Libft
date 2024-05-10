// #include "libft.h"
// #include <stdio.h>

// size_t	count_words(char const *s, char c)
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
// 	return (count + 1);
// }
// void	*allocate(char **str_arr, char const *s, char c)
// {
// 	size_t	i;

// 	i = 0;
//     free(str_arr);
// 	str_arr = malloc(sizeof(char *) * (count_words(s, c) + 1));
// 	if (str_arr == NULL)
// 		return (NULL);
// 	while (i < count_words(s, c))
// 	{
// 		str_arr[i] = malloc(1);
// 		if (str_arr[i] == NULL)
// 			return (NULL);
// 		*str_arr[i] = '\0';
// 		i++;
// 	}
// 	return (str_arr);
// }

// size_t	word_length(char const *s, char c, size_t i)
// {
// 	size_t	j;

// 	j = 0;
// 	while (s[i] != c)
// 	{
// 		i++;
// 		j++;
// 	}
// 	return (j);
// }

// void	*copystr(char const *s, char c, char **str_arr, size_t i)
// {
// 	size_t	count;
// 	size_t	j;
// 	size_t	k;

// 	count = 0;
// 	j = 0;
// 	k = word_length(s, c, i);
// 	while (*str_arr[count] != '\0')
// 		count++;
// 	free(str_arr[count]);
// 	str_arr[count] = malloc(sizeof(char) * (k + 1));
// 	if (str_arr == NULL)
// 		return (NULL);
// 	while (s[i] != c)
// 	{
// 		str_arr[count][j] = s[i];
// 		j++;
// 		i++;
// 	}
// 	str_arr[count][j] = '\0';
// 	return (str_arr);
// }

// char	**ft_split(char const *s, char c)
// {
// 	char	**str_arr;
// 	size_t	i;

// 	// i = 0;
// 	// str_arr = malloc(sizeof(char *) * (count_words(s, c) + 1));
// 	// if (str_arr == NULL)
// 	// 	return (NULL);
// 	// while (i < count_words(s, c))
// 	// {
// 	// 	str_arr[i] = malloc(1);
// 	// 	if (str_arr[i] == NULL)
// 	// 		return (NULL);
// 	// 	*str_arr[i] = '\0';
// 	// 	i++;
// 	// }
//     str_arr = NULL;
// 	str_arr = allocate(str_arr, s, c);
// 	i = 0;
// 	while (s[i])
// 	{
// 		if ((s[i] == c) && (s[i + 1] != c) && (s[i + 1]) != '\0')
// 			copystr(s, c, str_arr, i + 1);
// 		i++;
// 	}
// 	return (str_arr);
// }
// int	main(void)
// {
// 	char *s = "ffhellofhifffyesfhowfff";
// 	char c = 'f';

// 	int i = 0;
// 	char **str = ft_split(s, c);
// 	while (i <= 3)
// 	{
// 		printf("%s\n", str[i]);
// 		i++;
// 	}
// 	free(str);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 11:59:10 by prossi            #+#    #+#             */
/*   Updated: 2021/09/20 19:17:53 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static void	ft_freeup(char *strs)
{
	int	i;

	i = 0;
	while (strs[i] != '\0')
	{
		free(strs);
		i++;
	}
	free(strs);
}

static int	ft_wordcount(char *str, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			word++;
			while (str[i] != c && str[i] != '\0')
				i++;
			if (str[i] == '\0')
				return (word);
		}
		i++;
	}
	return (word);
}

static void	ft_strcpy(char *word, char *str, char c, int j)
{
	int	i;

	i = 0;
	while (str[j] != '\0' && str[j] == c)
		j++;
	while (str[j + i] != c && str[j + i] != '\0')
	{
		word[i] = str[j + i];
		i++;
	}
	word[i] = '\0';
}

static char	*ft_stralloc(char *str, char c, int *k)
{
	char	*word;
	int		j;

	j = *k;
	word = NULL;
	while (str[*k] != '\0')
	{
		if (str[*k] != c)
		{
			while (str[*k] != '\0' && str[*k] != c)
				*k += 1;
			word = (char *)malloc(sizeof(char) * (*k + 1));
			if (word == NULL)
				return (NULL);
			break ;
		}
		*k += 1;
	}
	ft_strcpy(word, str, c, j);
	return (word);
}

char	**ft_split(char const *str, char c)
{
	char	**strs;
	int		i;
	int		j;
	int		pos;

	if (str == NULL)
		return (NULL);
	i = 0;
	pos = 0;
	j = ft_wordcount((char *)str, c);
	strs = (char **)malloc(sizeof(char *) * (j + 1));
	if (strs == NULL)
		return (NULL);
	strs[j] = NULL;
	while (i < j)
	{
		strs[i] = ft_stralloc(((char *)str), c, &pos);
		if (strs[i] == NULL)
		{
			ft_freeup(strs[i]);
		}
		i++;
	}
	return (strs);
}

int	main(void)
{
	char const *s = "whiiiiwjuuuuwkkkiiiwwkklww";
	char c = 'w';

	size_t i = 0;
	char **str = ft_split(s, c);
	while (i < 4)
	{
		printf("%s\n", str[i]);
        free(str[i]);
		i++;
	}
    free(str);
}