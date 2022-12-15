/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 05:36:05 by segan             #+#    #+#             */
/*   Updated: 2022/07/25 05:36:05 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*newstruct;

	newstruct = (t_list *)malloc(sizeof(t_list));
	if (newstruct == (void *)0)
		return ((void *)0);
	newstruct->content = content;
	newstruct->next = (t_list *) 0;
	return (newstruct);
}

/*
#include <stdio.h>

int main(void)
{
	t_list	*test;
	test = ft_lsttnew("test");
	printf("%s\n", (char *) test->content);
}
*/