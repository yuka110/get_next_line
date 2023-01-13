/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/21 11:40:12 by yitoh         #+#    #+#                 */
/*   Updated: 2023/01/13 14:11:52 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef  BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
int		ft_strlen(const char *s);
char	*ft_substr(char const *s, int start, int len);
int		ft_strchr(const char *s);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_memmove(char *dst, char *src, int len);
char	*ft_bzero(char *b, int len);
char	*reset_buf(char *buf);

#endif