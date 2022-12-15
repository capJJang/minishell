/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 20:25:49 by segan             #+#    #+#             */
/*   Updated: 2022/07/10 23:57:01 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dst_ptr;
	const unsigned char	*src_ptr;

	if (dst == NULL && src == NULL)
		return ((void *) 0);
	i = 0;
	dst_ptr = dst;
	src_ptr = src;
	while (i < n)
	{
		dst_ptr[i] = src_ptr[i];
		i++;
	}
	return (dst);
}

//restrict pointer is for optimization
//inform compiler that pointer variables are pointing different address
//memcpy function checks memory area overlap

/*
#include <stdio.h>
#include <string.h>

int main(void){
	char str1[] = "Hello world!";
	char str2[30];
	char str3[30];
	ft_memcpy(str2, str1, 3);
	printf("my func : %s\n", str2);
	ft_bzero(str2, 30);
	memcpy(str3, str1, 3);
	printf("lib func : %s\n\n", str3);
	ft_bzero(str2, 30);
	ft_bzero(str3, 30);

	printf("my func : %s\n", ft_memcpy((void *)0, "test", 3));
	printf("lib func : %s", memcpy((void *)0, "test", 3));
}
*/
