/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 11:59:53 by segan             #+#    #+#             */
/*   Updated: 2022/07/14 13:45:27 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

/*
#include <stdio.h>
#include <string.h>

int main(void)
{
    char src[] = "123456789";
    char dest[10];
    char src1[] = "abcde";
    char dest1[] = "123456789";

	printf("\n");
    printf("src : %s\ndest : [10]\nsize : 5\n", src);
    printf("your function : %d\n", ft_strlcpy(dest, src, 5));
    printf("com function : %lu\n\n", strlcpy(dest, src, 5));
    printf("src : %s\ndest : %s\nsize : 3\n", src1, dest1);
    printf("your function : %d\n", ft_strlcpy(dest1, src1, 3));
    printf("com function : %lu\n", strlcpy(dest1, src1, 3));
	printf("\n");
    return (0);
}
*/