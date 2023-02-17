/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:53:12 by seyang            #+#    #+#             */
/*   Updated: 2023/02/17 19:16:24 by segan            ###   ########.fr       */
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
			arr = ft_calloc(sizeof(char), 2);
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
			if (curr == node_inf->tail)
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
	if (curr->arr[end] != '\'' && curr->arr[end] != '\"' && curr->arr[end] != '$')
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

int	parsing2_quito(t_node_inf *node_inf, t_node *curr, int start)
{
	char	*temp;
	char	c;
	int		end;

	c = set_single_or_double(curr->arr, 0);
	if (c == 0 || c == -1)
		return (BREAK);
	start = ft_find_after_chr(curr->arr, start, c);
	end = ft_find_after_chr(curr->arr, start + 1, c);
	if (start == 0 && curr->arr[end + 1] == 0)
		return (BREAK);
	temp = curr->arr;
	if (start != 0)
	{
		end = start - 1;
		start = 0;
	}
	add_prev_node(node_inf, curr, \
		new_node(ft_substr(curr->arr, start, end + 1)));
	check_adhere(curr, end);
	curr->arr = ft_substr(curr->arr, end + 1, ft_strlen(curr->arr) - end);
	free(temp);
	return (0);
}

void	parsing_quote(t_node_inf *node_inf)
{
	t_node	*curr;
	int		start;

	curr = node_inf->head;
	while (1)
	{
		start = 0;
		while (1)
			if (parsing2_quito(node_inf, curr, start) == BREAK)
				break ;
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
		add_prev_node(node_inf, *curr, \
			new_node(ft_substr(arr, start, end - start)));
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
	int		end;
	int		arr_end;

	if (init_set_env(curr, &arr, temp, &start) == 1)
		return ;
	end = start + 1;
	while (arr[end] && (ft_isalpha(arr[end]) || arr[end] == '?' || arr[end] == '_'))
		end++;
	if (start != 0)
		add_prev_node(node_inf, curr, new_node(ft_substr(arr, 0, start)));
	env = ft_substr(arr, start + 1, end - 1);
	arr_end = ft_strlen(arr);
	if (arr[end] != 0)
	{
		add_next_node(node_inf, curr, \
			new_node(ft_substr(arr, end, arr_end - end)));
		curr->check_adhere_back = 1;
	}
	curr->arr = ft_strdup(ft_getenv(node_inf->vars, env));
	if (curr->arr == NULL)
		curr->arr = ft_strdup("");
	// curr->check_malloc = 0;
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

int	cut_front(t_node_inf *node_inf, t_node *curr, int start)
{
	char	*temp;

	add_prev_node(node_inf, curr, new_node(ft_substr(curr->arr, 0, start)));
	temp = curr->arr;
	curr->arr = ft_substr(curr->arr, start, ft_strlen(curr->arr) - start);
	free(temp);
	return (2);
}

int	parsing_redirection2(t_node_inf *node_inf, t_node *curr)
{
	char	*temp;
	int		start;
	int		end;

	start = ft_find_redirection(curr->arr, 0);
	if (curr->arr[start] == 0)
		return (BREAK);
	if (start != 0)
		return (cut_front(node_inf, curr, start));
	end = start;
	// while (curr->arr[end] == curr->arr[start])
	while (curr->arr[end] == '<' || curr->arr[end] == '>')
		end++;
	add_prev_node(node_inf, curr, \
		new_node(ft_substr(curr->arr, start, end - start)));
	while (curr->arr[end] == ' ')
		end++;
	start = end;
	while (curr->arr[end] && curr->arr[end] != ' ' \
		&& curr->arr[end] != '<' && curr->arr[end] != '>')
		end++;
	if (start == end)
	{
		temp = curr->arr;
		curr->arr = ft_substr(curr->arr, end, ft_strlen(curr->arr) - end);
		free(temp);
		return (CONTINUE);
	}
	add_prev_node(node_inf, curr, \
		new_node(ft_substr(curr->arr, start, end - start)));
	curr->prev->is_file = 1;
	temp = curr->arr;
	while (curr->arr[end] == ' ')
		end++;
	curr->arr = ft_substr(curr->arr, end, ft_strlen(curr->arr) - end);
	free(temp);
	return (0);
}

void	parsing_redirection(t_node_inf *node_inf)
{
	t_node	*curr;
	int		ret;

	curr = node_inf->head;
	while (1)
	{
		while (1)
		{
			ret = parsing_redirection2(node_inf, curr);
			if (ret == BREAK)
				break ;
			else if (ret == CONTINUE)
				continue ;
		}
		curr = curr->next;
		if (curr->prev->arr[0] == 0)
			delete_node(node_inf, curr->prev);
		if (curr == node_inf->head)
			break ;
	}
}

void	set_command_num(t_node_inf *node_inf)
{
	t_node	*curr;
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

int	check_parse_error(t_node_inf *node_inf)
{
	t_node	*curr;
	int		cmd_cnt;

	curr = node_inf->head;
	cmd_cnt = 1;
	while (1)
	{
		while (curr->next->command_num != cmd_cnt || curr != node_inf->tail)
			curr = curr->next;
		if (curr->arr[0] == '<' || curr->arr[0] == '>')
			return (1);
		if (curr == node_inf->tail)
			break ;
	}
	return (0);
}

t_node_inf	*parsing(t_vars *vars, char *read_line)
{
	t_node_inf	*node_inf;

	node_inf = new_node_inf();
	node_inf->vars = vars;
	line_to_node(node_inf, read_line);
	free(read_line);
	return (node_inf);
}
