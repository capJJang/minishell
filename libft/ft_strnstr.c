/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 17:40:31 by segan             #+#    #+#             */
/*   Updated: 2022/07/15 20:24:55 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp2(const char *s1, const char *s2, size_t n)
{
	while (n-- && ((unsigned char)*s1 && (unsigned char) *s2))
	{
		if ((unsigned char)*s1 == (unsigned char)*s2)
		{
			s1++;
			s2++;
		}
		else
			return ((unsigned char)*s1 - (unsigned char)*s2);
	}
	return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	if (!*needle)
		return ((char *)haystack);
	while (*haystack && (len >= ft_strlen(needle)))
	{
		if (ft_strncmp2(haystack, needle, len) == 0)
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return ((void *)0);
}

/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	char *s1 = "AAAAAAAAAAAAA";
	size_t max = strlen(s1);
	char *i1 = strnstr(s1, s1, max);
	char *i2 = ft_strnstr(s1, s1, max);

	printf("%s\n", i1);
	printf("%s\n", i2);
}
*/
