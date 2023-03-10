/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 03:10:13 by segan             #+#    #+#             */
/*   Updated: 2022/07/26 03:10:13 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL || lst->next == NULL)
		return (lst);
	else
		return (ft_lstlast(lst->next));
}

/*
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

t_list	*ft_lstnewone(void *content)
{
	t_list	*elem;

	elem = (t_list *)malloc(sizeof(t_list));
	if (!elem)
		return (NULL);
	if (!content)
		elem->content = NULL;
	else
		elem->content = content;
	elem->next = NULL;
	return (elem);
}

int main()
{
	int			i;
	char		*content;
	t_list		*val;
	t_list		*elem;
	t_list		*elem2;
	t_list		*elem3;
	t_list		*elem4;
	char		*str = strdup("lorem");
	char		*str2 = strdup("ipsum");
	char		*str3 = strdup("dolor");
	char		*str4 = strdup("sit");

	elem = ft_lstnewone(str);
	elem2 = ft_lstnewone(str2);
	elem3 = ft_lstnewone(str3);
	elem4 = ft_lstnewone(str4);
	alarm(5);
	
		elem->next = elem2;
		elem2->next = elem3;
		elem3->next = elem4;
		val = ft_lstlast(elem);
		i = 0;
		content = val->content;
		while (content[i])
			write(1, &(content[i++]), 1);
		write(1, "\n", 1);
		elem->next = NULL;
		val = ft_lstlast(elem);
		content = val->content;
		i = 0;
		while (content[i])
			write(1, &(content[i++]), 1);
		write(1, "\n", 1);
		elem = NULL;
		val = ft_lstlast(elem);
		if (val == NULL)
			write(1, "NULL", 4);
		write(1, "\n", 1);
	return (0);
}
*/