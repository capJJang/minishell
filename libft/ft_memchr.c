/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 18:07:16 by segan             #+#    #+#             */
/*   Updated: 2022/08/06 18:24:21 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr;
	size_t				i;

	ptr = s;
	i = 0;
	while (n--)
	{
		if (ptr[i] == (unsigned char) c)
			return ((void *)&ptr[i]);
		i++;
	}
	return ((void *)0);
}
/*
#include <string.h>
#include <stdio.h>

void test_memchr(void)
{
	char *s1 = "";
	char *s2 = "abcdefabcdef";
	char *s3 = "11111111111111111111";

	printf("Testing memchr():\nTest1...");
	if (ft_memchr(s1, 'x', 0) == NULL)
		printf("passed.");
	else	printf("FAILED.");
	printf("\nTest2...");
	if (ft_memchr(s2, 'y', 0) == NULL)
		printf("passed.");
	else	printf("FAILED.");
	printf("\nTest3...");
	if ((char *)memchr(s2, 'a', 1) - s2 == 0)
		printf("passed.");
	else	printf("FAILED.");
	printf("\nTest4...");
	if (ft_memchr(s2, 'd', 2)  == NULL)
		printf("passed.");
	else	printf("FAILED.");
	printf("\nTest5...");
	if ((char *)ft_memchr(s2, 'd', 12)  - s2 == 3)
		printf("passed.");
	else	printf("FAILED.");
	printf("\nTest6...");
	if ((char *)ft_memchr(s2, 'f', 12)  - s2 == 5)
		printf("passed.");
	else	printf("FAILED.");
	printf("\nTest7...");
	if ((char *)ft_memchr(s3, '1', 20)  - s3 == 0)
		printf("passed.");
	else	printf("FAILED.");
	putchar('\n');
}

int	main(void)
{
	int tab[7] = {-49, 49, 1, -1, 0, -2, 2};
	int tab2[7] = {-49, 49, 1, -1, 0, -2, 2};

	printf("%s\n", (char *)ft_memchr(tab, -1, 7));
	printf("%s\n", (char *)memchr(tab2, -1, 7));

	test_memchr();
}
*/
