/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 18:01:26 by segan             #+#    #+#             */
/*   Updated: 2022/08/06 19:25:26 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ret;
	size_t	len;

	len = ft_strlen(s) + 1;
	ret = 0;
	while (len--)
	{
		if (*s == (char) c)
			ret = (char *)s;
		s++;
	}
	return (ret);
}

/*
#include <string.h>
#include <stdio.h>

int main(void)
{
//	char	str3[] = "";
	char		str2[] = "bonjour";

	// printf("%s1", ft_strrchr(str3, '\0'));
	// printf("%s2\n", strrchr(str3, '\0'));

	printf("%s1", ft_strrchr(str2, '\0'));
	printf("%s2", strrchr(str2, '\0'));
}
*/
