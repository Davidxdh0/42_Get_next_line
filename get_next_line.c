/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dyeboa <dyeboa@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/06 14:18:48 by dyeboa        #+#    #+#                 */
/*   Updated: 2022/02/16 16:58:59 by dyeboa        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>
#include <libc.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>

int BUFFER_SIZE = 1;

char	*gnlread(int fd, char *str)
{
	char *buff;
	int i;
	
	i = 1;
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	while (i != 0)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[i] = '\0';
		str = ft_strjoin(str, buff);
	}
	free (buff);
	return (str);
}

char	*parse_line(char *str)
{
	char	*res;
	int		i;

	i = 0;
	if (str[i] == '\0')
		return (NULL);
	while (str[i++])
		if (str[i++] == '\n')
			break ;
	res = malloc(sizeof(char) * (i + 1));
	if (!res)
		return (NULL);
	i = -1;
	while (str[++i])
	{
		if (str[i] == '\n')
		{
			res[i] = str[i];
			i++;
			break ;
		}
		res[i] = str[i];
	}
	res[i] = '\0';
	return (res);
}

char	*clear_stat(char *stat)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (stat[i] && stat[i] != '\n')
		i++;
	if (stat[i] == '\0')
	{
		free(stat);
		return (NULL);
	}
	res = malloc(sizeof(char) * ft_strlen(stat) - i + 1);
	if (!res)
		return (NULL);
	i++;
	while (stat[i])
		res[j++] = stat[i++];
	res[j] = '\0';
	free(stat);
	return (res);
}

char *get_next_line(int fd)
{
	static char *str;
	char *b;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = gnlread(fd, str);
	if (!str)
		return (NULL);
	b = parse_line(str);
	str = clear_stat(str);
	return (b);
}

// int main()
// {
// 	int BUFFER_SIZE = 10;
//     const int fd = read("input.txt", O_RDONLY, BUFFER_SIZE);

// 	get_next_line(fd);
// 	system("leaks a.out");
//     return 0;
// }

/*
system("leaks a.out")

File descriptor to read from
Read line:  correct behavior
NULL: nothing else to read or an error occurred
read, malloc, free
Write a function which returns a line read from a
file descriptor

Does your function still work if the BUFFER_SIZE value is 9999? And
if the BUFFER_SIZE value is 1? And 10000000? Do you know why?

Plan van aanpak: 
Static functie bij lezen van file - waarde van '\n'
Lezen per byte, stoppen bij end of line character, doorgaan tot EOF en erna = 0

*/