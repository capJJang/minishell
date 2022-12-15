/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 20:56:42 by segan             #+#    #+#             */
/*   Updated: 2022/07/15 20:57:01 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str_ptr;
	size_t	len;

	len = ft_strlen(s1);
	str_ptr = (char *)malloc(len + 1);
	if (str_ptr == (void *)0)
		return ((void *)0);
	while (*s1)
		*str_ptr++ = *(char *)s1++;
	*str_ptr = 0;
	return (str_ptr - (len));
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*str1 = "Hello World!";
	char	*str2 = strdup(str1);
	char	*str3 = ft_strdup(str1);
	printf("my func : %s\n", str3);
	printf("lib func : %s\n\n", str2);
}
*/