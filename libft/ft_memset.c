/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:55:18 by segan             #+#    #+#             */
/*   Updated: 2022/07/10 23:30:15 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = b;
	i = 0;
	while (i < len)
		ptr[i++] = c;
	return (b);
}

/*
#include <string.h>
#include <stdio.h>

int main(void){
	char str1[] = "abcde";
	printf("my func : ");		memset(str1, 65, 3);
	for(size_t i = 0; i < 5; i++) printf("%d ", str1[i]);
	printf("\nlib func : ");	memset(str1, 65, 3);
	for(size_t i = 0; i < 5; i++) printf("%d ", str1[i]);

	printf("\n\nmy func : ");	memset(str1, 1, 3);
	for(size_t i = 0; i < 5; i++) printf("%d ", str1[i]);
	printf("\nlib func : ");	memset(str1, 1, 3);
	for(size_t i = 0; i < 5; i++) printf("%d ", str1[i]);

}
*/
