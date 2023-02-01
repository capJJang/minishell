/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 23:45:15 by segan             #+#    #+#             */
/*   Updated: 2022/09/29 03:24:40 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int o)
{
	size_t	i;
	size_t	len;

	i = 0;
	if (o == 0)
		return ((char *)s + ft_strlen(s));
	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	while (i < len)
	{
		if (s[i] == (char)o)
			return ((char *)(s + i));
		else
			i++;
	}
	return ((void *) 0);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	ret;

	ret = ft_strlen(src);
	if (dstsize == 0)
		return (ret);
	while (dstsize-- > 1 && *src)
		*dst++ = *src++;
	*dst = 0;
	return (ret);
}

char	*free_arr(char **arr)
{
	free(*arr);
	*arr = NULL;
	return (NULL);
}
