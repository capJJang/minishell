/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:06:20 by segan             #+#    #+#             */
/*   Updated: 2023/02/17 19:00:07 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include </Users/segan/.brew/opt/readline/include/readline/readline.h>
# include <readline/history.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <stdbool.h>
# include "get_next_line/get_next_line.h"
# include <signal.h>
# include <termios.h>

# define IS_NOT_COMMAND 1
# define IS_COMMAND 0

# define IS_NOT_FOUND 0
# define EMPTY_LINE 0
# define P_READ 0
# define P_WRITE 1
# define SUCCESS 0
# define PERMISSION_DENIED 13
# define BREAK 1
# define CONTINUE 2

typedef struct s_node		t_node;
typedef struct s_node_inf	t_node_inf;
typedef struct s_child		t_child;
typedef struct s_vars		t_vars;

struct s_child {
	char		*path;
	char		***cmd;
	int			launch_cnt;
	int			**fd;
	pid_t		pid;
	t_node_inf	*node_inf;
} ;

struct s_node {
	int		command_num;
	char	*arr;
	int		check_malloc;
	int		check_adhere_back;
	int		is_file;
	t_node	*next;
	t_node	*prev;
} ;

struct s_node_inf {
	t_node	*head;
	t_node	*tail;
	t_vars	*vars;
	char	**cmd;
} ;

struct s_vars {
	char	**env;
	char	**sh_var;
	int		*stat;
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
char		*ft_strdup(const char *s1);
char		*ft_strchr(const char *s, int o);
char		*ft_strrchr(const char *s, int c);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
char		*ft_itoa(int n);


void		*ft_malloc(size_t size);
pid_t		ft_fork(void);
int			ft_find_after_chr(char *arr, int start, char c);
void		ft_free_2d(char **arr);
void		ft_free_3d(char ***arr);
int			ft_find_redirection(char *arr, int start);
char		set_single_or_double(char *arr, int start);
int			ft_node_strncmp(t_node_inf *node_inf, const char *s2);
char		*ft_strjoin2(char const *s1, char const *s2, int s1_f, int s2_f);
char		*ft_getcwd(int *stat);

void		ft_free(t_node_inf *node_inf);
void		ft_free_vars(t_vars *vars);

char		**get_path_env(t_vars *vars);
char		*get_path(char **path_env, char *cmd);
char		**get_readline(void);
// int			is_parent_1(pid_t pid, char *path, char *cmd);
// void		is_child_1(char *path, char **cmd);

t_node_inf	*new_node_inf(void);
t_node		*new_node(char *arr);
void		add_back_node(t_node_inf *node_inf, t_node *src_node);
void		add_prev_node(t_node_inf *node_inf, \
	t_node *dst_node, t_node *src_node);
void		add_next_node(t_node_inf *node_inf, \
	t_node *dst_node, t_node *src_node);
void		delete_node(t_node_inf *node_inf, t_node *dst_node);
t_node		*find_node(t_node_inf *node_inf, int command_num);

t_node_inf	*parsing(t_vars *vars, char *read_line);
int			is_empty_line(char *read_line);
char		***node_to_command(t_node_inf *node_inf);
void		execute_command(char **path_env, \
	char ***cmd, t_node_inf *node_inf);
void		print_cmd_nfound(int error, char *cmd);
void		print_error(int error, char *cmd);
void		print_invalid_id(t_node_inf *node_inf, char *key, char *arg);
void		ft_free(t_node_inf *node_inf);
int			check_parse_error(t_node_inf *node_inf);
t_node		*is_redirection(t_child child);
int			is_redirection2(t_node_inf *node_inf);

//builtin funcs start
void		exe_builtin(t_node_inf *node_inf);
int			is_builtin(char **cmd);
void		builtin_cd(t_node_inf *node_inf);
void		builtin_exit(t_node_inf *node_inf);
void		builtin_echo(t_node_inf *node_inf);
void		builtin_pwd(int	*stat);
void		builtin_env(t_vars *vars);
void		builtin_export(t_node_inf *node_inf);
void		builtin_unset(t_node_inf *node_inf);
//builtin funcs end

//env_funcs start
int			check_valid_key(char *key);
t_vars		*init_var(void);
char		**init_env(void);
void		print_environ(char **environ);
int			ft_strlen_2d(char **arr);
char		**ft_strdup_2d(char **src);
char		*ft_getenv(t_vars *vars, const char *str);
void		ft_addenv(t_vars *var, char *key, char *val);
void		ft_unsetenv(t_vars *var, char *val);
void		ft_unset_sh_var(t_vars *vars, char *key);
void		ft_add_sh_var(t_vars *var, char *val);
char		*ft_getkey(char *var);
void		ft_append_env(t_vars *vars, char *key, char *value);
void		ft_overwrite_env(t_vars *vars, char *key, char *val);
void		print_sh_var(t_vars *vars);
int			check_valid_key(char *key);
//env_funcs end

//signal start
void		set_readline_signal(void);
void		sigint_readline(int signo);
void		set_parent_signal(void);
void		restore_signal(void);
void		set_heredoc_signal(void);
void		sigint_heredoc(int signo);
//signal end

void		print_errno_in_child(char *cmd);

void		print_node(t_node_inf *node_inf);
void		print_command(char ***cmd);

#endif
