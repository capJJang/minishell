/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing6.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyang <seyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 19:06:46 by seyang            #+#    #+#             */
/*   Updated: 2023/03/19 17:30:38 by seyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	extract_key(char *arr, int *e, int start)
{
	*e = start + 1;
	while ((arr[*e] && (ft_isalpha(arr[*e]) || arr[*e] == '_')) \
		|| (*e != start + 1 && ft_isdigit(arr[*e])))
		(*e)++;
	*e += ((arr[*e] && (*e == start + 1)));
}

void	expand_env(t_node *curr, t_node_inf *node_inf, char *env, char *arr)
{
	if (ft_strncmp(env, "?", 2) == 0)
		curr->arr = ft_getenv(node_inf->vars, env);
	else
		curr->arr = ft_strdup(ft_getenv(node_inf->vars, env));
	if (curr->arr == NULL)
		curr->arr = ft_strdup("");
	parsing_env_free(env, arr);
}

void	split_node(t_node_inf *node_inf, t_node *curr, int start, char *arr)
{
	add_prev_node(node_inf, curr, new_node(ft_substr(arr, 0, start)));
	curr->prev->is_quote_include_pipe = (str_redirection_pipe2(curr->prev));
}

void	trim_quote(t_node_inf *node_inf, t_node *curr, char *set, char *temp)
{
	curr->is_quote_include_pipe = str_redirection_pipe(node_inf, curr);
	curr->arr = ft_strtrim(curr->arr, set);
	free(temp);
}
