/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:36:54 by segan             #+#    #+#             */
/*   Updated: 2022/07/07 15:47:40 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}

/*
#include <ctype.h>
#include <stdio.h>

int main(void){
	printf("my func : %d\n", ft_isascii('%'));
	printf("lib func : %d\n\n", isascii('%'));
	printf("my func : %d\n", ft_isascii('A'));
	printf("lib func : %d\n\n", isascii('A'));
}
*/
