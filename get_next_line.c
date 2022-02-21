/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dyeboa <dyeboa@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/06 14:18:48 by dyeboa        #+#    #+#                 */
/*   Updated: 2022/02/21 18:16:52 by yeboa         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

char	*read_all(int fd, char *text)
{
	char	*line;
	ssize_t		i;

	line = (char *)malloc(BUFFER_SIZE + 1);
	if (!line)
		return (NULL);
	i = 1;
	while (!(ft_strchr(text, '\n')) && i != 0)
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
	char	*line;
	size_t	len;
	size_t	y;

	len = 0;
	y = 0;
	if (text[0] == '\0')
		return (NULL);
	while (text[len] != '\n' && text[len] != '\0')
		len++;
	if (text[len] == '\n')
		len++;
	line = (char *)malloc(len + 1);
	if (!line)
		return (0);
	while (y < len)
	{
		line[y] = text[y];
		y++;
	}
	line[y] = '\0';
	return (line);
}

char	*skip_line(char	*text)
{
	size_t	i;
	size_t	l;
	char	*newtxt;

	i = 0;
	l = 0;
	while (text[i] != '\n' && text[i] != '\0')
		i++;
	if (!text[i])
	{
		free(text);
		return (NULL);
	}
	newtxt = (char *)malloc(ft_strlen(text) - i + 1);
	if (!newtxt)
		return (0);
	while (text[i++])
		newtxt[l++] = text[i];
	newtxt[l] = '\0';
	free(text);
	return (newtxt);
}

char	*get_next_line(int fd)
{
	static	char	*text;
	char	*line;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (0);
	text = read_all(fd, text);
	if (!text)
		return (NULL);
	line = get_line(text);
	text = skip_line(text);
	return (line);
}

/*int main()
{
	int		i;
	i = open("yahya.txt", O_RDWR);
	printf("%s", get_next_line(i));
	printf("%s", get_next_line(i));
	printf("%s", get_next_line(i));
	printf("%s", get_next_line(i));
}*/

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