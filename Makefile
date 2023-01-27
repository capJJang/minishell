# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: segan <segan@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/07 13:15:13 by segan             #+#    #+#              #
#    Updated: 2023/01/27 17:17:12 by segan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRCS =	main.c ft_fork.c path.c check_process.c read_line.c \
		ft_free.c parsing.c set_node.c print.c ft_find.c \
		is_empty_line.c ft_malloc.c set_single_or_double.c node_to_command.c\
		execute_command.c print_error.c ft_node_strncmp.c ft_strjoin2.c\
		is_equal.c\
		builtin_funcs/is_builtin.c builtin_funcs/exe_builtin.c\
		builtin_funcs/builtin_cd.c builtin_funcs/builtin_exit.c\
		builtin_funcs/builtin_echo.c builtin_funcs/builtin_pwd.c\
		builtin_funcs/builtin_env.c builtin_funcs/builtin_export.c\
		builtin_funcs/builtin_unset.c\
		var/init_env.c var/ft_getenv.c var/ft_addenv.c var/ft_unsetenv.c\
		var/init_var.c var/ft_add_sh_var.c var/ft_append_env.c\
		var/ft_overwrite_env.c

CFLAGS = -g -fsanitize=address -Wall -Wextra -Werror -o

LIBS = -lreadline -L ./libft -l ft

all :
	make bonus -C libft
	$(CC)  $(SRCS) $(LIBS) $(CFLAGS) $(NAME)
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
