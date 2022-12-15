/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 13:30:54 by segan             #+#    #+#             */
/*   Updated: 2022/07/10 20:29:09 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	else
		return (0);
}

/*
#include <ctype.h>
#include <stdio.h>

int main(void){
	printf("my func : %d\n", ft_isalnum('a'));
	printf("lib func : %d\n\n", isalnum('a'));
	printf("my func : %d\n", ft_isalnum('A'));
	printf("lib func : %d\n\n", isalnum('A'));
	printf("my func : %d\n", ft_isalnum('0'));
	printf("lib func : %d\n\n", isalnum('0'));
	printf("my func : %d\n", ft_isalnum('9'));
	printf("lib func : %d\n\n", isalnum('9'));
	printf("my func : %d\n", ft_isalnum('z'));
	printf("lib func : %d\n\n", isalnum('z'));
	printf("my func : %d\n", ft_isalnum('%'));
	printf("lib func : %d\n\n", isalnum('%'));
}
*/
