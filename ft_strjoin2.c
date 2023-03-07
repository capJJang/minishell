/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyang <seyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 10:48:40 by segan             #+#    #+#             */
/*   Updated: 2023/03/06 20:23:51 by seyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strjoin2(char const *s1, char const *s2, int s1_f, int s2_f)
{
	char	*ret;

	if (!s1 || !s2)
		return (ft_strdup(""));
	ret = ft_strjoin(s1, s2);
	if (!ret)
		exit(-1);
	if (s1_f)
		free((void *)s1);
	if (s2_f)
		free((void *)s2);
	return (ret);
}
