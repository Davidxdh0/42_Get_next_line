/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dyeboa <dyeboa@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/06 14:49:17 by dyeboa        #+#    #+#                 */
/*   Updated: 2022/03/16 13:58:15 by dyeboa        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

//	get_next_line_utils.c
size_t	ft_strlen(const char *s);
char	*ft_strjoin(const char *s1, const char *s2);
int		is_newline(char *str);

// get_next_line.c
char	*get_next_line(int fd);
char	*skip_line(char	*text);
char	*get_line(char	*text);
char	*read_all(int fd, char *text);

#endif
