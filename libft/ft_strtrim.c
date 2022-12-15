/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 05:37:04 by segan             #+#    #+#             */
/*   Updated: 2022/07/25 05:37:04 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	start = 0;
	end = ft_strlen(s1);
	while ((end > 0) && ft_strchr(set, s1[end]))
		end--;
	while ((start < ft_strlen(s1)) && ft_strchr(set, s1[start]))
		start++;
	if (start > end)
		return (ft_strdup(""));
	return (ft_substr(s1, start, end - start + 1));
}

/*
#include <stdio.h>

int	main(void)
{
	char *str = ft_strtrim("     ", " ");
	printf("%s\n", str);
	free(str);
	return (0);
}
*/
