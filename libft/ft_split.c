/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyang <seyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 19:08:46 by seyang            #+#    #+#             */
/*   Updated: 2022/09/13 15:41:23 by seyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	error_free(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	word_count(char const *s, char c)
{
	int	wc;

	wc = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s == 0)
			break ;
		while (*s && *s != c)
			s++;
		wc++;
	}
	return (wc);
}

int	arr_memory_allocate(char const *s, char c, char **arr)
{
	int	size;

	while (*s)
	{
		size = 0;
		while (*s && *s == c)
			s++;
		if (*s == 0)
			break ;
		while (*s && *s != c)
		{
			size++;
			s++;
		}
		*arr = malloc(sizeof(char) * (size + 1));
		if (arr == NULL)
			return (1);
		arr++;
	}
	return (0);
}

void	string_to_arr(char const *s, char c, char **arr)
{
	int	size;

	while (*s)
	{
		size = 0;
		while (*s && *s == c)
			s++;
		if (*s == 0)
			break ;
		while (*s && *s != c)
		{
			*(*arr)++ = *s++;
			size++;
		}
		**arr = 0;
		*arr -= size;
		arr++;
	}
	*arr = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		wc;

	if (s == 0)
		return (0);
	arr = 0;
	wc = word_count(s, c);
	arr = (char **)malloc(sizeof(char *) * (wc + 1));
	if (arr == 0)
		return (0);
	if (arr_memory_allocate(s, c, arr))
	{
		error_free(arr);
		return (0);
	}
	string_to_arr(s, c, arr);
	return (arr);
}
