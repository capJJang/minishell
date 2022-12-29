/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:53:12 by seyang            #+#    #+#             */
/*   Updated: 2022/12/24 19:12:05 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parsing_pipe(t_node_inf *node_inf, char *read_line)
{
	int		start;
	int		finish;
	char	*arr;

	start = 0;
	finish = 0;
	while (read_line[finish])
	{
		finish = ft_find_after_chr(read_line, start, '|');
		if (finish - start == 0)
		{
			arr = ft_calloc(sizeof(char), 1);
			arr[0] = '|';
			add_back_node(node_inf, new_node(arr));
			finish = ++start;
			continue ;
		}
		arr = ft_substr(read_line, start, finish - start);
		add_back_node(node_inf, new_node(arr));
		start = finish;
	}
}

void	parsing_space(t_node_inf *node_inf)
{
	t_node	*curr;
	char	*temp;

	curr = node_inf->head;
	while (1)
	{
		temp = curr->arr;
		curr->arr = ft_strtrim(curr->arr, " ");
		free(temp);
		if (curr == node_inf->tail)
			break ;
		curr = curr->next;
	}
}

void	parsing_command(t_node_inf *node_inf)
{
	t_node	*curr;
	char	*temp;
	int		i;

	curr = node_inf->head;
	while (1)
	{
		i = ft_find_after_chr(curr->arr, 0, ' ');
		if (curr->arr[i] == 0)
		{
			if (curr == node_inf->tail) // 20221216 seyang : add : if only one word
				break ;
			curr = curr->next;
			continue ;
		}
		temp = curr->arr;
		add_prev_node(node_inf, curr, new_node(ft_substr(curr->arr, 0, i)));
		curr->arr = ft_substr(curr->arr, i + 1, ft_strlen(curr->arr) - i);
		free(temp);
		if (curr == node_inf->tail)
			break ;
		curr = curr->next;
	}
}

void	check_adhere(t_node *curr, int end)
{
	if (curr->arr[end] != '\'' && curr->arr[end] != '\"')
	{
		if (curr->arr[end] != ' ')
			curr->prev->check_adhere_back = 1;
	}
	else
	{
		if (curr->arr[end + 1] != ' ')
			curr->prev->check_adhere_back = 1;
	}
}

void	parsing_quote(t_node_inf *node_inf)
{
	t_node	*curr;
	char	*temp;
	char	c;
	int		start;
	int		end;

	curr = node_inf->head;
	while (1)
	{
		start = 0;
		while (1)
		{
			c = set_single_or_double(curr->arr, 0);
			if (c == 0 || c == -1)
				break ;
			start = ft_find_after_chr(curr->arr, start, c);
			end = ft_find_after_chr(curr->arr, start + 1, c);
			if (start == 0 && curr->arr[end + 1] == 0)
			 	break ;
			temp = curr->arr;
			if (start != 0)
			{
				end = start - 1;
				start = 0;
			}
			add_prev_node(node_inf, curr, new_node(ft_substr(curr->arr, start, end + 1)));
			check_adhere(curr, end);
			curr->arr = ft_substr(curr->arr, end + 1, ft_strlen(curr->arr) - end);
			free(temp);
		}
		if (curr == node_inf->tail)
			break ;
		curr = curr->next;
	}
}

void	set_normal_arr(t_node_inf *node_inf, t_node **curr, char *arr)
{
	t_node	*temp;
	int		start;
	int		end;

	start = 0;
	while (1)
	{
		end = ft_find_after_chr(arr, start, ' ');
		add_prev_node(node_inf, *curr, new_node(ft_substr(arr, start, end - start)));
		while (arr[end] == ' ')
			end++;
		if (arr[end] == 0)
			break ;
		start = end;
	}
	if ((*curr)->check_adhere_back == 1)
		(*curr)->prev->check_adhere_back = 1;
	if ((*curr)->is_file == 1)
		(*curr)->prev->is_file = 1;
	temp = *curr;
	*curr = (*curr)->next;
	delete_node(node_inf, temp);
}

void	parsing_normal_arr(t_node_inf *node_inf)
{
	t_node	*curr;

	curr = node_inf->head;
	while (1)
	{
		if (curr->arr[0] != '\'' && curr->arr[0] != '\"')
			set_normal_arr(node_inf, &curr, curr->arr);
		else
			curr = curr->next;
		if (curr == node_inf->head || node_inf->head == node_inf->tail)
			break ;
	}
}

void	set_env(t_node_inf *node_inf, t_node *curr, char *arr, char *temp)
{
	char	*env;
	int		start;
	int		end;
	int		arr_end;

	arr = ft_strtrim(arr, "\"");
	free(temp);
	start = ft_find_after_chr(arr, 0, '$');
	if (start == -1 || arr[start] == 0)
	{
		curr->arr = arr;
		return ;
	}
	start = ft_find_after_chr(arr, 0, '$');
	end = start + 1;
	while (arr[end] && (('a' <= arr[end] && arr[end] <= 'z') || ('A' <= arr[end] && arr[end] <= 'Z')))
		end++;
	if (start != 0)
		add_prev_node(node_inf, curr, new_node(ft_substr(arr, 0, start)));
	env = ft_substr(arr, start + 1, end - 1);
	arr_end = ft_strlen(arr);
	if (arr[end] != 0)
		add_next_node(node_inf, curr, new_node(ft_substr(arr, end + 1, arr_end - end)));
	curr->arr = getenv(env);
	if (curr->arr == NULL)
		curr->arr = "";
	curr->check_malloc = 0;
	free(env);
	free(arr);
}

void	replace_env(t_node_inf *node_inf)
{
	t_node	*curr;
	char	*temp;

	curr = node_inf->head;
	while (1)
	{
		temp = curr->arr;
		if (curr->arr[0] == '\'')
		{
			curr->arr = ft_strtrim(curr->arr, "\'");
			free(temp);
		}
		else
			set_env(node_inf, curr, curr->arr, temp);
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
			curr->check_adhere_back = curr->next->check_adhere_back;
			delete_node(node_inf, curr->next);
		}
		if (curr == node_inf->tail)
			break ;
		curr = curr->next;
	}
}

void	parsing_redirection(t_node_inf *node_inf)
{
	t_node	*curr;
	char	*temp;
	int		start;
	int		end;

	curr = node_inf->head;
	while (1)
	{
		while (1)
		{
			start = ft_find_redirection(curr->arr, 0);
			if (curr->arr[start] == 0)
				break ;
			if (start != 0)
			{
				add_prev_node(node_inf, curr, new_node(ft_substr(curr->arr, 0, start)));
				temp = curr->arr;
				curr->arr = ft_substr(curr->arr, start, ft_strlen(curr->arr) - start);
				free(temp);
				continue ;
			}
			end = start;
			while (curr->arr[end] == curr->arr[start])
				end++;
			add_prev_node(node_inf, curr, new_node(ft_substr(curr->arr, start, end - start)));
			while (curr->arr[end] == ' ')
				end++;
			start = end;
			while (curr->arr[end] && curr->arr[end] != ' ' && curr->arr[end] != '<' && curr->arr[end] != '>')
				end++;
			if (start == end)
			{
				temp = curr->arr;
				curr->arr = ft_substr(curr->arr, end, ft_strlen(curr->arr) - end);
				free(temp);
				continue ;
			}
			add_prev_node(node_inf, curr, new_node(ft_substr(curr->arr, start, end - start)));
			curr->prev->is_file = 1;
			temp = curr->arr;
			while (curr->arr[end] == ' ')
				end++;
			curr->arr = ft_substr(curr->arr, end, ft_strlen(curr->arr) - end);
			free(temp);
		}
		curr = curr->next;
		if (curr->prev->arr[0] == 0)
			delete_node(node_inf, curr->prev);
		if (curr == node_inf->head)
			break;
	}
}

void	set_command_num(t_node_inf *node_inf)
{
	t_node *curr;
	int		command_num;

	command_num = 1;
	curr = node_inf->head;
	while (1)
	{
		curr->command_num = command_num;
		if (curr->arr[0] == '|')
			command_num++;
		curr = curr->next;
		if (curr == node_inf->head)
			break ;
	}
}

void	line_to_node(t_node_inf *node_inf, char *read_line)
{
	parsing_pipe(node_inf, read_line);
	parsing_space(node_inf);
	// parsing_command(node_inf);
	// parsing_space(node_inf);
	parsing_quote(node_inf);
	parsing_space(node_inf);
	parsing_redirection(node_inf);
	parsing_space(node_inf);
	parsing_normal_arr(node_inf);
	replace_env(node_inf);
	adhere_some_node(node_inf);
	set_command_num(node_inf);
}

t_node_inf	*parsing(char *read_line)
{
	t_node_inf	*node_inf;

	if (is_empty_line(read_line))
		return (EMPTY_LINE);
	node_inf = new_node_inf();
	line_to_node(node_inf, read_line);
	free(read_line);
	return (node_inf);
}
