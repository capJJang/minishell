/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:06:20 by segan             #+#    #+#             */
/*   Updated: 2022/12/27 03:03:43 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <readline/readline.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/stat.h>

# define IS_NOT_COMMAND 1
# define IS_COMMAND 0

# define IS_NOT_FOUND 0
# define EMPTY_LINE 0
# define P_READ 0
# define P_WRITE 1

typedef struct s_node		t_node;
typedef struct s_node_inf	t_node_inf;

struct s_node {
	char	*arr;
	t_node	*next;
	t_node	*prev;
} ;

struct s_node_inf {
	t_node	*head;
	t_node	*tail;
} ;

char		**ft_split(char const *s, char c);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlen(const char *s);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strtrim(char const *s1, char const *set);
void		*ft_calloc(size_t count, size_t size);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_isdigit(int c);
int			ft_atoi(const char *str);

void		*ft_malloc(size_t size);
pid_t		ft_fork(void);
int			ft_find_after_chr(char *arr, int start, char c);
void		ft_free_2d(char **arr);
void		ft_free_3d(char ***arr);
char		set_single_or_double(char *arr, int start);
int			ft_node_strncmp(t_node_inf *node_inf, const char *s2);

char		**get_path_env(void);
char		*get_path(char **path_env, char *command);
char		**get_readline(void);
// int			is_parent_1(pid_t pid, char *path, char *command);
// void		is_child_1(char *path, char **command);
t_node_inf	*new_node_inf(void);
t_node		*new_node(char *arr);
void		add_back_node(t_node_inf *node_inf, t_node *src_node);
void		add_prev_node(t_node_inf *node_inf, t_node *dst_node, t_node *src_node);
void		add_next_node(t_node_inf *node_inf, t_node *dst_node, t_node *src_node);
t_node_inf	*parsing(char *read_line);
t_node_inf	*free_node_inf(t_node_inf *node_inf);
int			is_empty_line(char *read_line);
char		***node_to_command(t_node_inf *node_inf);
void		execute_command(char **path_env, char ***command, t_node_inf *node_inf);
void		print_cmd_nfound(int error, char *command);

void		print_node(t_node_inf *node_inf);
void		print_command(char ***command);

//builtin funcs start
void		exe_builtin(t_node_inf *node_inf);
int			is_builtin(char **command);
void		builtin_cd(t_node_inf *node_inf);
void		builtin_exit(t_node_inf *node_inf);
void		builtin_echo(t_node_inf *node_inf);
//builtin funcs end

#endif
