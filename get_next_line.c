/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dyeboa <dyeboa@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/06 14:18:48 by dyeboa        #+#    #+#                 */
/*   Updated: 2021/10/26 16:43:32 by dyeboa        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <libc.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 20

static char *gnlfiller(int fd, int i, char *buffer)
{
	int	newline;
	char *str;
	int j;
	
	newline = 0;
	j = 0;
	str = (char *)malloc(sizeof(char) * (i + 1));
	// while (j < i)
	// {
	// 	str[j] = buffer[newline];
	// 	j++;
	// 	newline++;
	// }
	str[j] = '\0';
	j = 0;
	printf("test");
	return (str);
	
}

char *get_next_line(int fd)
{
	char buffer[BUFFER_SIZE];
	int k;
	int bytes_read;
	char *b;

	if (fd == -1)
		return (NULL);
	printf("test");
	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)	
	{
		buffer[bytes_read] = '\0';
		while ((buffer[k]) != '\n')
			k++;
		b = gnlfiller(fd, k, buffer);
		printf("test %s", b);		
	}
	printf("test");
	return (NULL);
}

int main()
{
    //char buffer[BUFFER_SIZE];
    const int fd = open("input.txt", O_RDONLY);
    //int bytes_read;
	get_next_line(fd);
   	// 	bytes_read = read(fd, buffer, 20);
   	// 	buffer[bytes_read] = '\0';
	//	if (buffer[4] == '\n')
	//	printf("bytes read: %d -> %c | \n", bytes_read, buffer[5]);
    //	printf("bytes read: %d -> %c | \n", bytes_read, buffer[5]);
	//	system("leaks a.out")
    return 0;
}
#endif
/*

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