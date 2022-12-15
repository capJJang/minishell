/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 16:31:24 by segan             #+#    #+#             */
/*   Updated: 2022/07/15 17:05:30 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int o)
{
	if (o == 0)
		return ((char *)s + ft_strlen(s));
	while (*s)
	{
		if (*s == (char)o)
			return ((char *) s);
		else
			s++;
	}
	return ((void *) 0);
}

/*
#include <string.h>
#include <stdio.h>

int	main(void)
{
	char s[] = "tripouille";
	// printf("%s\n", ft_strchr(s, 't' + 256));
	printf("%s", ft_strchr(s, 't' + 256));
}
*/
