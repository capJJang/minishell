/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 20:48:30 by segan             #+#    #+#             */
/*   Updated: 2022/07/15 21:16:26 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(size * count);
	if (ptr != NULL)
		ft_bzero(ptr, count * size);
	if (ptr == NULL)
		exit(-1);
	return (ptr);
}

/*
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int	main()
{
	void * diff1 = ft_calloc(1, 1);
	void * diff2 = calloc(1, 1);

	printf("%s\n", diff1);
	printf("%s", diff2);
	free(diff1);
	free(diff2);
}
*/
