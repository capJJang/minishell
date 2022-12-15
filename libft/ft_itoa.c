/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 05:33:57 by segan             #+#    #+#             */
/*   Updated: 2022/07/25 05:33:57 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	intlen(int n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		sign;
	long	num;

	sign = 0;
	len = intlen(n);
	str = (char *)malloc(len + 1);
	if (str == NULL)
		return (NULL);
	num = n;
	if (n < 0)
	{
		str[0] = '-';
		num *= -1;
		sign = 1;
	}
	str[len--] = 0;
	while (len >= sign)
	{
		str[len] = num % 10 + '0';
		num /= 10;
		len--;
	}
	return (str);
}

/*
#include <stdio.h>

int main(void)
{
	char *test = ft_itoa(-2147483648);
	printf("%s", test);
}
*/
