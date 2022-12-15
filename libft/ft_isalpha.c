/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 12:57:18 by segan             #+#    #+#             */
/*   Updated: 2022/07/07 15:30:21 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if (((c >= 65) && (c <= 90)) || ((c >= 97) && (c <= 122)))
		return (1);
	else
		return (0);
}
/*
#include <ctype.h>
#include <stdio.h>

int	main(void){
	printf("my func : %d\n", ft_isalpha('a'));
	printf("lib func : %d\n\n", ft_isalpha('a'));
	printf("my func : %d\n", ft_isalpha('z'));
	printf("lib func : %d\n\n", ft_isalpha('z'));
	printf("my func : %d\n", ft_isalpha('A'));
	printf("lib func : %d\n\n", ft_isalpha('A'));
	printf("my func : %d\n", ft_isalpha('Z'));
	printf("lib func : %d\n\n", ft_isalpha('Z'));
	printf("my func : %d\n", ft_isalpha(123));
	printf("lib func : %d", ft_isalpha(123));
}
*/
