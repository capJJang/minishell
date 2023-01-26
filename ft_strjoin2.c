/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 10:48:40 by segan             #+#    #+#             */
/*   Updated: 2023/01/26 11:45:59 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strjoin2(char const *s1, char const *s2, int s1_f, int s2_f)
{
	char	*ret;

	ret = ft_strjoin(s1, s2);
	if (s1_f)
		free((void *)s1);
	if (s2_f)
		free((void *)s2);
	return (ret);
}
