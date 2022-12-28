# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: segan <segan@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/07 13:15:13 by segan             #+#    #+#              #
#    Updated: 2022/12/28 19:50:37 by segan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRCS =	main.c ft_fork.c path.c check_process.c read_line.c \
		ft_free.c parsing.c set_node.c print.c ft_find.c \
		is_empty_line.c ft_malloc.c set_single_or_double.c node_to_command.c \
		execute_command.c print_error.c ft_node_strncmp.c\
		builtin_funcs/is_builtin.c builtin_funcs/exe_builtin.c\
		builtin_funcs/builtin_cd.c builtin_funcs/builtin_exit.c\
		builtin_funcs/builtin_echo.c builtin_funcs/builtin_pwd.c\
		builtin_funcs/builtin_env.c


CFLAGS = -g3 -fsanitize=address -Wall -Wextra -Werror -o

LIBS = -lreadline -L ./libft -l ft

all :
	make -C libft
	$(CC)  $(SRCS) $(LIBS) $(CFLAGS) $(NAME)
clean :

fclean:
	make fclean -C ./libft
	rm $(NAME)
	rm -rf $(NAME).dSYM

re :
	make fclean
	make all

.PHONY : all clean fclean re
