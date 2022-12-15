/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 16:31:40 by segan             #+#    #+#             */
/*   Updated: 2022/07/15 16:31:46 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_size;
	size_t	src_size;

	dst_size = ft_strlen(dst);
	src_size = ft_strlen(src);
	if (size == 0 || size <= dst_size)
		return (size + src_size);
	dst += dst_size;
	while (dst_size + 1 < size-- && *src)
		*dst++ = *src++;
	*dst = 0;
	return (dst_size + src_size);
}

/*
#include <string.h>
#include <stdio.h>

int main()
{

	char str[10] = "Hello";
	char lib_str[10] = "Hello";
	char src[10] = " 42";

	char str2[10] = "Hello";
	char lib_str2[10] = "Hello";
	char src2[] = "";

	char str3[9] = "Hello";
	char lib_str3[9] = "Hello";
	char src3[10] = " 42";

	char str4[33] = "Hello";
	char lib_str4[33] = "Hello";
	char src4[23] = " 42, je m'appelle John";

	char str5[1] = "\0";
	char lib_str5[1] = "\0";
	char src5[7] = "Coucou";

	printf("\nTEST1 : $size parameter is smaller than $dest + 1\n");
	printf("-------------------------------\n");
	printf("str: \"%s\"\n", str);
	printf("src: \"%s\"\n", src);
	printf("size: 4\n\n");
	printf("Returned value:\n");
	printf("My  function: \"%lu\"\n", ft_strlcat(str, src, 4));
	printf("lib function: \"%d\"\n\n", strlcat(lib_str, src, 4));
	printf("My  concatened str: \"%s\"\n", str);
	printf("Lib concatened str: \"%s\"\n", lib_str);
	printf("-------------------------------\n\n");

	printf("\nTEST2 : $src parameter is null\n");
	printf("-------------------------------\n");
	printf("str: \"%s\"\n", str2);
	printf("src: \"%s\"\n", src2);
	printf("size: 6\n\n");
	printf("Returned value:\n");
	printf("My  function: \"%lu\"\n", ft_strlcat(str2, src2, 6));
	printf("lib function: \"%d\"\n\n", strlcat(lib_str2, src2, 6));
	printf("My  concatened str: \"%s\"\n", str2);
	printf("Lib concatened str: \"%s\"\n", lib_str2);
	printf("-------------------------------\n\n");

	printf("\nTEST3 : Concatenate only 2 characteres from src\n");
	printf("-------------------------------\n");
	printf("str: \"%s\"\n", str3);
	printf("src: \"%s\"\n", src3);
	printf("size: 7\n\n");
	printf("Returned value:\n");
	printf("My  function: \"%lu\"\n", ft_strlcat(str3, src3, 8));
	printf("lib function: \"%d\"\n\n", strlcat(lib_str3, src3, 8));
	printf("My  concatened str: \"%s\"\n", str3);
	printf("Lib concatened str: \"%s\"\n", lib_str3);
	printf("-------------------------------\n\n");

	printf("\nTEST4 : Concatenate all characteres from src\n");
	printf("-------------------------------\n");
	printf("str: \"%s\"\n", str4);
	printf("src: \"%s\"\n", src4);
	printf("size: 33\n\n");
	printf("Returned value:\n");
	printf("My  function: \"%lu\"\n", ft_strlcat(str4, src4, 33));
	printf("lib function: \"%d\"\n\n", strlcat(lib_str4, src4, 33));
	printf("My  concatened str: \"%s\"\n", str4);
	printf("Lib concatened str: \"%s\"\n", lib_str4);
	printf("-------------------------------\n\n");

	printf("\nTEST5 : dest is null\n");
	printf("-------------------------------\n");
	printf("str: \"%s\"\n", str5);
	printf("src: \"%s\"\n", src5);
	printf("size: 1\n\n");
	printf("Returned value:\n");
	printf("My  function: \"%lu\"\n", ft_strlcat(str5, src5, 1));
	printf("lib function: \"%d\"\n\n", strlcat(lib_str5, src5, 1));
	printf("My  concatened str: \"%s\"\n", str5);
	printf("Lib concatened str: \"%s\"\n", lib_str5);
	printf("-------------------------------\n\n");

}
*/
