/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dyeboa <dyeboa@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/06 14:18:48 by dyeboa        #+#    #+#                 */
/*   Updated: 2022/03/16 14:07:47 by dyeboa        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_all(int fd, char *text)
{
	char	*line;
	ssize_t	i;

	line = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!line)
		return (NULL);
	i = 1;
	while (is_newline(text) == 0 && i != 0)
	{	
		i = read(fd, line, BUFFER_SIZE);
		if (i == -1)
		{
			free(line);
			return (NULL);
		}
		line[i] = '\0';
		text = ft_strjoin(text, line);
	}
	free(line);
	return (text);
}

char	*get_line(char	*text)
{
	char			*line;
	unsigned int	len;
	unsigned int	i;

	len = 0;
	i = 0;
	if (text[0] == '\0')
		return (NULL);
	while (text[len] != '\n' && text[len] != '\0')
		len++;
	line = malloc(len + 1);
	if (!line)
		return (0);
	if (text[len] == '\n')
		len++;
	while (i < len)
	{
		line[i] = text[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*skip_line(char	*text)
{
	unsigned int	i;
	unsigned int	l;
	char			*new_text;

	i = 0;
	l = 0;
	while (text[i] != '\n' && text[i] != '\0')
		i++;
	if (!text[i])
	{
		free(text);
		return (NULL);
	}
	new_text = malloc(ft_strlen(text) - i + 1);
	if (!new_text)
		return (0);
	while (text[i++])
		new_text[l++] = text[i];
	new_text[l] = '\0';
	free(text);
	return (new_text);
}

char	*get_next_line(int fd)
{
	static char	*text;
	char		*line;

	if (fd == -1 || BUFFER_SIZE < 1)
		return (0);
	text = read_all(fd, text);
	if (!text)
		return (NULL);
	line = get_line(text);
	text = skip_line(text);
	return (line);
}
