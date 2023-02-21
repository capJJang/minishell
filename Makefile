# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seyang <seyang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/07 13:15:13 by segan             #+#    #+#              #
#    Updated: 2023/02/20 19:58:31 by seyang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRCS =	main.c ft_fork.c path.c set_node.c new_node.c\
		parsing.c parsing2.c parsing3.c parsing4.c parsing5.c\
		is_empty_line.c ft_malloc.c set_single_or_double.c node_to_command.c\
		execute_command.c execute_command2.c execute_command3.c \
		execute_command4.c execute_command5.c \
		print_error.c ft_node_strncmp.c ft_strjoin2.c\
		ft_free.c ft_getcwd.c print.c ft_find.c read_line.c\
		builtin_funcs/is_builtin.c builtin_funcs/exe_builtin.c\
		builtin_funcs/builtin_cd.c builtin_funcs/builtin_exit.c\
		builtin_funcs/builtin_echo.c builtin_funcs/builtin_pwd.c\
		builtin_funcs/builtin_env.c builtin_funcs/builtin_export.c\
		builtin_funcs/builtin_unset.c\
		var/init_env.c var/ft_getenv.c var/ft_addenv.c var/ft_unsetenv.c\
		var/ft_overwrite_env.c \
		redirection/set_redirection.c\
		var/init_var.c var/ft_add_sh_var.c var/ft_append_env.c \
		get_next_line/get_next_line.c get_next_line/get_next_line_utils.c\
		signal/signal.c signal/sigint_handler.c

CFLAGS = -g -Wall -Wextra -Werror -o

LIBS = -lft -L./libft

CLIBS = -lreadline -L ~/.brew/opt/readline/lib -I ~/.brew/opt/readline/include

all :
	make bonus -C libft
	$(CC) $(SRCS) $(CLIBS) $(LIBS) $(CFLAGS) $(NAME)
clean :
	make clean -C ./libft

fclean:
	make fclean -C ./libft
	rm $(NAME)
	rm -rf $(NAME).dSYM

re :
	make fclean
	make all

.PHONY : all clean fclean re
