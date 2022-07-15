/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dyeboa <dyeboa@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/06 14:49:17 by dyeboa        #+#    #+#                 */
/*   Updated: 2022/04/05 12:37:02 by dyeboa        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif
//	get_next_line_utils.c
size_t	ft_strlen(const char *s);
char	*ft_strjoin(const char *s1, const char *s2);
int		is_newline(char *str);

// get_next_line.c
char	*get_next_line(int fd);
char	*new_text(char	*text);
char	*get_line(char	*text);
#endif
