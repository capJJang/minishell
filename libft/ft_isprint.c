/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 17:11:47 by segan             #+#    #+#             */
/*   Updated: 2022/07/07 17:35:00 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}

/*
#include <ctype.h>
#include <stdio.h>

int main(void){
	printf("my func : %d\n", ft_isprint(' '));
	printf("lib func : %d\n\n", isprint(' '));
	printf("my func : %d\n", ft_isprint('~'));
	printf("lib func : %d\n\n", isprint('~'));
}
*/
