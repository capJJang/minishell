/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 16:46:10 by segan             #+#    #+#             */
/*   Updated: 2022/07/15 17:32:27 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1_ptr;
	const unsigned char	*s2_ptr;

	s1_ptr = s1;
	s2_ptr = s2;
	while (n--)
	{
		if (*s1_ptr != *s2_ptr)
			return (*s1_ptr - *s2_ptr);
		else
		{
			s1_ptr++;
			s2_ptr++;
		}
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	printf("%d\n", ft_memcmp("abcdefghij", "abcdefgxyz", 7));
	printf("%d\n\n", memcmp("abcdefghij", "abcdefgxyz", 7));
	printf("%d\n", ft_memcmp("zyxbcdefgh", "abcdefgxyz", 0));
	printf("%d\n", memcmp("zyxbcdefgh", "abcdefgxyz", 0));
}

*/