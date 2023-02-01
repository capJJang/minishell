/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:23:04 by segan             #+#    #+#             */
/*   Updated: 2022/09/29 03:35:57 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*slicing_line(char *ret, char **leftover, int read_count)
{
	size_t	new_ret_len;
	size_t	new_leftover_len;
	char	*new_ret;
	char	*new_leftover;

	if (ret == 0 || leftover == 0)
		return (0);
	if (read_count == 0 && ft_strchr(ret, '\n') == 0)
		return (ret);
	new_ret_len = ft_strchr(ret, '\n') - ret + 1;
	new_ret = (char *)malloc(new_ret_len + 1);
	if (new_ret == NULL)
		return (NULL);
	ft_strlcpy(new_ret, ret, new_ret_len + 1);
	new_leftover_len = ft_strchr(ret, 0) - ft_strchr (ret, '\n') + 1;
	new_leftover = (char *)malloc(new_leftover_len + 1);
	if (new_leftover == NULL)
		return (free_arr(&new_ret));
	ft_strlcpy(new_leftover, ret + new_ret_len, new_leftover_len);
	free_arr(leftover);
	*leftover = new_leftover;
	free_arr(&ret);
	return (new_ret);
}

char	*concat_line(char *ret, char *buff, int read_count)
{
	char	*new_ret;

	if (ret == NULL)
	{
		new_ret = (char *)malloc(ft_strlen(buff) + 1);
		if (new_ret == NULL)
			return (NULL);
	}
	else
	{
		new_ret = (char *)malloc(ft_strlen(ret) + read_count + 1);
		if (new_ret == NULL)
			return (free_arr(&ret));
	}
	ft_strlcpy(new_ret, ret, ft_strlen(ret) + 1);
	ft_strlcpy(new_ret + ft_strlen(ret), buff, read_count + 1);
	free_arr(&ret);
	return (new_ret);
}

char	*get_next_line(int fd)
{
	static char	*leftover;
	char		*buff;
	char		*ret;
	int			read_count;

	buff = (char *)malloc(BUFFER_SIZE + 1);
	if (buff == NULL)
		return (NULL);
	buff[BUFFER_SIZE] = 0;
	ret = concat_line(NULL, leftover, ft_strlen(leftover));
	while (1)
	{
		read_count = read(fd, buff, BUFFER_SIZE);
		if ((read_count == 0 || read_count == -1))
			break ;
		ret = concat_line(ret, buff, read_count);
		if (ft_strchr(ret, '\n'))
			break ;
	}
	free_arr(&buff);
	if (read_count == 0)
		free_arr(&leftover);
	if (read_count == -1 || ret == NULL || (read_count == 0 && *ret == 0))
		return (free_arr(&ret));
	return (slicing_line(ret, &leftover, read_count));
}

/*
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int fd = open("test.txt", O_RDONLY);
	char *str;
	// do {
	// 	str = get_next_line(fd);
	// 	printf("%s", str);
	// }
	// while (str)
	// ;
	str = get_next_line(fd);
	printf("%s", str);
	str = get_next_line(fd);
	printf("%s", str);
	str = get_next_line(fd);
	printf("%s", str);
	str = get_next_line(fd);
	printf("%s", str);
	str = get_next_line(fd);
	printf("%s", str);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	str = NULL;
//	system("leaks a.out > leaks_result; cat leaks_result && rm -rf leaks_result");
}
*/
