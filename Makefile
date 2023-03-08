# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: segan <segan@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/07 13:15:13 by segan             #+#    #+#              #
#    Updated: 2023/03/08 17:29:06 by segan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

NAME = minishell

SRCS =	main.c ft_fork.c path.c set_node.c new_node.c\
		parsing.c parsing2.c parsing3.c parsing4.c parsing5.c\
		is_empty_line.c ft_malloc.c set_single_or_double.c node_to_command.c\
		execute_command.c execute_command2.c execute_command3.c \
		execute_command4.c execute_command5.c execute_command6.c\
		print_error.c ft_node_strncmp.c ft_strjoin2.c\
		ft_free.c ft_getcwd.c print.c ft_find.c read_line.c\
		builtin_funcs/is_builtin.c builtin_funcs/exe_builtin.c\
		builtin_funcs/builtin_cd.c builtin_funcs/builtin_exit.c\
		builtin_funcs/builtin_echo.c builtin_funcs/builtin_pwd.c\
		builtin_funcs/builtin_env.c builtin_funcs/builtin_export.c\
		builtin_funcs/builtin_unset.c\
		var/init_env.c var/ft_getenv.c var/ft_addenv.c var/ft_unsetenv.c\
		var/ft_overwrite_env.c \
		var/init_var.c var/ft_add_sh_var.c var/ft_append_env.c \
		signal/signal.c signal/sigint_handler.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

LIBS = -lft -L./libft -lreadline -L/Users/$(USER)/.brew/opt/readline/lib

INCS = -I/Users/$(USER)/.brew/opt/readline/include

DEBUG = -g -fsanitize=address

all : $(NAME)

$(NAME) : $(OBJS)
	make bonus -C libft
	$(CC) $(DEBUG) $(LIBS) -o $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(DEBUG) $(INCS) $(CFLAGS) -c $< -o $@

clean :
	make clean -C ./libft
	rm -rf $(OBJS)

fclean:
	make fclean -C ./libft
	make clean
	rm $(NAME)
	rm -rf $(NAME).dSYM

re :
	make fclean
	make all

.PHONY : all clean fclean re
