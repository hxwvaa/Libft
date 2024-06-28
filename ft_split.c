/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbasheer <hbasheer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:15:53 by hbasheer          #+#    #+#             */
/*   Updated: 2024/06/28 11:46:59 by hbasheer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	str = ft_calloc((i + 1), sizeof(char));
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
	str_arr = ((malloc(sizeof(char *) * (words + 1))));
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

char	**ft_split(char const *s, char c)
{
	char	**str_arr;

	str_arr = NULL;
	if (s == NULL)
	{
		return (NULL);
	}
	str_arr = allocate(str_arr, s, c);
	return (str_arr);
}
