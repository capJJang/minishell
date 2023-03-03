/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyang <seyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 19:42:09 by seyang            #+#    #+#             */
/*   Updated: 2023/02/28 12:50:47 by seyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	init_set_env(t_node *curr, char **arr, char *temp, int *start)
{
	*arr = ft_strtrim(*arr, "\"");
	free(temp);
	*start = ft_find_after_chr(*arr, 0, '$');
	if (*start == -1 || (*arr)[*start] == 0)
	{
		curr->arr = *arr;
		return (1);
	}
	return (0);
}

void	set_env(t_node_inf *node_inf, t_node *curr, char *arr, char *temp)
{
	char	*env;
	int		start;
	int		e;
	int		arr_end;

	if (init_set_env(curr, &arr, temp, &start) == 1)
		return ;
	e = start + 1;
	while (arr[e] && ((ft_isalpha(arr[e]) || arr[e] == '?' || arr[e] == '_')))
		e++;
	if (start != 0)
		add_prev_node(node_inf, curr, new_node(ft_substr(arr, 0, start)));
	curr->prev->check_adhere_back = \
		(start != 0 || curr->prev->check_adhere_back);
	env = ft_substr(arr, start + 1, e - start - 1);
	arr_end = ft_strlen(arr);
	if (arr[e] != 0)
		add_next_node(node_inf, curr, new_node(ft_substr(arr, e, arr_end - e)));
	curr->check_adhere_back = (arr[e] != 0 || curr->check_adhere_back);
	curr->arr = ft_strdup(ft_getenv(node_inf->vars, env));
	if (curr->arr == NULL)
		curr->arr = ft_strdup("");
	free(env);
	free(arr);
}

void	replace_env(t_node_inf *node_inf)
{
	t_node	*curr;
	char	*temp;
	int		end;

	curr = node_inf->head;
	while (1)
	{
		end = 0;
		temp = curr->arr;
		while (curr->arr[end])
			end++;
		if (end >= 2 && curr->arr[0] == '\'' && curr->arr[end - 1] == '\'')
		{
			curr->arr = ft_strtrim(curr->arr, "\'");
			free(temp);
		}
		else
		{
			if (ft_strncmp(curr->prev->arr, "<<", 3) != 0)
				set_env(node_inf, curr, curr->arr, temp);
		}
		if (curr == node_inf->tail)
			break ;
		curr = curr->next;
	}
}

void	adhere_some_node(t_node_inf *node_inf)
{
	t_node	*curr;
	char	*temp;

	curr = node_inf->head;
	while (1)
	{
		while (curr->check_adhere_back == 1)
		{
			temp = curr->arr;
			curr->arr = ft_strjoin(curr->arr, curr->next->arr);
			free(temp);
			curr->check_adhere_back = curr->next->check_adhere_back;
			delete_node(node_inf, curr->next);
		}
		if (curr == node_inf->tail)
			break ;
		curr = curr->next;
	}
}
