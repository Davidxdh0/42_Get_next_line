/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dyeboa <dyeboa@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/06 14:18:48 by dyeboa        #+#    #+#                 */
/*   Updated: 2021/10/06 14:49:28 by dyeboa        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char *get_next_line(int fd)
{
	char * b;
	if (fd == -1)
		return (NULL);
	while (read(fd, void *buf, size_t count) == 1
	{
		
	}

}

/*

File descriptor to read from
Read line:  correct behavior
NULL: nothing else to read or an error occurred
read, malloc, free
Write a function which returns a line read from a
file descriptor

*/