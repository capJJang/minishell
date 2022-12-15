/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 13:14:38 by segan             #+#    #+#             */
/*   Updated: 2022/07/14 13:41:16 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (!(c >= 48 && c <= 57))
		return (0);
	else
		return (1);
}

/*
#include <ctype.h>
#include <stdio.h>

int	main(void){
	printf("my func : %d\n", ft_digit('1'));
	printf("lib func : %d\n\n", isdigit('1'));
	printf("my func : %d\n", ft_digit('9'));
	printf("lib func : %d\n\n", isdigit('9'));
	printf("my func : %d\n", ft_digit('a'));
	printf("lib func : %d\n\n", isdigit('a'));

}
*/
