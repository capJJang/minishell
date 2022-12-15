/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 23:40:45 by segan             #+#    #+#             */
/*   Updated: 2022/07/14 13:52:23 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*src_ptr;
	unsigned char	*dst_ptr;

	if (dst == NULL && src == NULL)
		return ((void *) 0);
	src_ptr = (unsigned char *)src;
	dst_ptr = dst;
	if (src_ptr >= dst_ptr)
	{
		while (len--)
			*dst_ptr++ = *src_ptr++;
	}
	else
	{
		while (len--)
			*(dst_ptr + len) = *(src_ptr + len);
	}
	return (dst);
}

/*
#include <stdio.h>
#include <string.h>

int main(void){
	char	src[] = "lorem ipsum dolor sit amet";
	char	*dest1;
	char	*dest2;

	dest1 = src + 1;
	dest2 = src + 1;
	ft_memmove(dest1, "consectetur", 5);
	printf("%s\n", dest1);
	//memmove(dest2, (void *) 0, 5);
	//printf("%s", dest2);
}
*/
