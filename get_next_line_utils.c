/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dyeboa <dyeboa@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/06 14:49:14 by dyeboa        #+#    #+#                 */
/*   Updated: 2022/02/16 16:33:49 by dyeboa        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stddef.h>
#include <stdlib.h> 

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len_src;

	len_src = ft_strlen(src);
	i = 0;
	while (src[i] && (i < size) && i < len_src)
	{
		dest[i] = src[i];
		i++;
		if (i == size)
		{
			dest[--i] = '\0';
			return (len_src);
		}
	}
	if (i < size)
		dest[i] = '\0';
	return (len_src);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		size;
	int		i;

	i = 0;
	size = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	str = (char *) malloc(((sizeof(char)) * size) + 2);
	if (!str)
		return (NULL);
	if (str)
	{
		if (s1 != NULL)
			ft_strlcpy(str, s1, (ft_strlen(s1) + 1));
		while (s2[i])
		{
			str[(ft_strlen(s1) + i)] = s2[i];
			i++;
		}
		str[((ft_strlen(s1)) + (ft_strlen(s2)))] = '\0';
		return (str);
	}
	return (NULL);
}
