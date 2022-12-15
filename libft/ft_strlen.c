/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 17:15:52 by segan             #+#    #+#             */
/*   Updated: 2022/07/14 13:27:47 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	printf("my func : %zu\n", ft_strlen("Hello World!"));
	printf("lib func : %zu\n\n", strlen("Hello World!"));
	printf("my func : %zu\n", ft_strlen(""));
	printf("lib func : %zu\n\n", strlen(""));
}
	// %z : format specifier for size_t, u is unsigned
*/
