/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 10:48:40 by segan             #+#    #+#             */
/*   Updated: 2023/01/25 11:22:49 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strjoin_sup_f(char const *s1, char const *s2, int s1_f, int s2_f)
{
	char	*ptr;
	size_t	s1_len;
	size_t	s2_len;
	size_t	ptr_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ptr_len = s1_len + s2_len;
	ptr = (char *)malloc(ptr_len + 1);
	if (ptr == (void *)0)
		exit(errno);
	ft_bzero(ptr, s1_len + s2_len);
	while (s1_len--)
		*ptr++ = *s1++;
	while (s2_len--)
		*ptr++ = *s2++;
	*ptr = 0;
	if (s1_f)
		free((void *)s1);
	if (s2_f)
		free((void *)s2);
	return (ptr - ptr_len);
}
