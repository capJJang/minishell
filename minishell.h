/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyang <seyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:06:20 by segan             #+#    #+#             */
/*   Updated: 2023/03/09 19:57:45 by seyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <stdbool.h>
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
# define R_RETURN 3

typedef struct s_node		t_node;
typedef struct s_node_inf	t_node_inf;
typedef struct s_child		t_child;
typedef struct s_vars		t_vars;

struct s_child {
	char		*path;
	char		***cmd;
	int			launch_cnt;
	int			**fd;
	pid_t		*pid;
	t_node_inf	*node_inf;
} ;

struct s_node {
	int		command_num;
	char	*arr;
	int		check_malloc;
	int		check_adhere_back;
	int		is_file;
	bool	is_quote_include_pipe;
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
void		ft_free_runtime(pid_t *pid, int **fd, char **path_env);
int			ft_find_redirection(char *arr, int start);
char		set_single_or_double(char *arr, int start);
int			ft_node_strncmp(t_node_inf *node_inf, const char *s2);
char		*ft_strjoin2(char const *s1, char const *s2, int s1_f, int s2_f);
char		*ft_getcwd(int *stat);

void		ft_free(t_node_inf *node_inf);
void		ft_free_vars(t_vars *vars);

char		**get_path_env(t_vars *vars);
char		*get_path(char **path_env, char *cmd, int *stat);
char		**get_readline(void);

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
int			is_redirection3(t_node_inf *node_inf);
int			str_redirection_pipe(t_node *curr);
void		update__(t_child child);

//parsing funcs start
void		parsing_pipe(t_node_inf *node_inf);
void		parsing_space(t_node_inf *node_inf);
void		parsing_command(t_node_inf *node_inf);
void		check_adhere(t_node *curr, int end);

int			parsing2_quito(t_node_inf *node_inf, t_node *curr, int start);
void		parsing_quote(t_node_inf *node_inf);
void		set_normal_arr(t_node_inf *node_inf, t_node **curr, char *arr);
void		parsing_normal_arr(t_node_inf *node_inf);

int			init_set_env(t_node *curr, char **arr, char *temp, int *start);
void		set_env(t_node_inf *node_inf, t_node *curr, char *arr, char *temp);
void		replace_env(t_node_inf *node_inf);
void		adhere_some_node(t_node_inf *node_inf);

int			cut_front(t_node_inf *node_inf, t_node *curr, int start);
int			parsing_redirection3(t_node_inf *node_inf, \
	t_node *curr, int end, int start);
int			parsing_redirection2(t_node_inf *node_inf, t_node *curr);
void		parsing_redirection(t_node_inf *node_inf);
void		set_command_num(t_node_inf *node_inf);

void		extract_key(char *arr, int *e, int start);
void		expand_env(t_node *curr, t_node_inf *node_inf, char *env);
//parsing funcs end

//node to command start
void		set_command(char ***cmd, t_node_inf *node_inf);
//node to command end

//execute command funcs start
t_node		*is_redirection(t_child child);
t_node		*is_all_redirection(t_child child);
void		redirect_outfile(t_node *curr, bool *out);
void		redirect_infile(t_node *curr, bool *in, t_node_inf *node_inf);
void		rollback_std_fd(t_node_inf *node_inf, int *std_fd);

int			is_break(char *get_line, t_node *curr);
void		heredoc(t_node *curr, bool *in);
void		append_file(t_node *curr, bool *out);
void		close_fd(bool in, bool out, t_child child);
void		redirect_pipe(t_child *child, \
	t_node *curr, bool check);

void		set_first_pipe(t_child *child, t_node *curr, int size);
void		set_end_pipe(t_child *child, t_node *curr, int size);
void		set_middle_pipe(t_child *child, t_node *curr, int size);
void		child_heredoc(t_child *child);
t_node		*is_redirection22(t_child child);

int			**new_pipe(char ***cmd);
void		close_pipe(int **fd);
int			init_cmd_var(t_child *child, char ***cmd, t_node_inf *node_inf);
int			check_is_file(t_node_inf *node_inf);
void		end_execute(t_node_inf *node_inf, int std_fd[2], \
	t_child *child, char ***path_env);

void		reset_stat(void);
void		heredoc_child(char *get_line, t_node *curr, int temp_fd);

//execute command funcs end

//builtin funcs start
void		exe_builtin(t_node_inf *node_inf);
int			is_builtin(char **cmd);
void		builtin_cd(t_node_inf *node_inf);
void		builtin_exit(t_node_inf *node_inf);
void		builtin_echo(t_node_inf *node_inf);
void		builtin_pwd(int	*stat);
void		builtin_env(t_vars *vars);
void		builtin_export(t_node_inf *node_inf);
void		builtin_export2(t_node_inf *node_inf, char *key, char *val, int i);
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
bool		check_duplication_var(t_vars *var, char *val);
//env_funcs end

//signal start
void		set_readline_signal(void);
void		sigint_readline(int signo);
void		set_parent_signal(void);
void		restore_signal(void);
void		set_heredoc_signal(void);
void		sigint_heredoc(int signo);
void		set_heredoc_signal(void);
//signal end

void		print_errno_in_child(char *cmd);

void		print_node(t_node_inf *node_inf);
void		print_command(char ***cmd);

#endif
