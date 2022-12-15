/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 16:35:26 by segan             #+#    #+#             */
/*   Updated: 2022/07/15 20:23:43 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{	
	while (n-- && ((unsigned char)*s1 || (unsigned char) *s2))
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
/*
#include <stdio.h>
#include <string.h>
int main()
{
	char s1[] = "Hello";
	char s2[] = "Hello";

	printf("\nCase 1\n");
	printf("-------------------\n");
	printf("s1: %s\n", s1);
	printf("s2: %s\n\n", s2);
	printf("Return values:\n");
	printf("My  function: %d\n", ft_strncmp(s1, s2, 8));
	printf("lib function: %d\n", strncmp(s1, s2, 8));
	printf("-------------------\n\n");


	char s3[] = "Hallo";
	char s4[] = "Hello";

	printf("Case 2\n");
	printf("-------------------\n");
	printf("s1: %s\n", s3);
	printf("s2: %s\n\n", s4);
	printf("Return values:\n");
	printf("My  function: %d\n", ft_strncmp(s3, s4, 8));
	printf("lib function: %d\n", strncmp(s3, s4, 8));
	printf("-------------------\n\n");


	char s5[] = "Hello";
	char s6[] = "HelaloA";

	printf("Case 3\n");
	printf("-------------------\n");
	printf("s1: %s\n", s5);
	printf("s2: %s\n\n", s6);
	printf("Return values:\n");
	printf("My  function: %d\n", ft_strncmp(s5, s6, 8));
	printf("lib function: %d\n", strncmp(s5, s6, 8));
	printf("-------------------\n\n");

	char s7[] = "Hello";
	char s8[] = "HelloA";

	printf("Case4 \n");
	printf("-------------------\n");
	printf("s1: %s\n", s7);
	printf("s2: %s\n\n", s8);
	printf("Return values:\n");
	printf("My  function: %d\n", ft_strncmp(s7, s8, 8));
	printf("lib function: %d\n", strncmp(s7, s8, 8));
	printf("-------------------\n\n");
}
*/