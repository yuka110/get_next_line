/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/21 11:40:12 by yitoh         #+#    #+#                 */
/*   Updated: 2023/01/12 16:06:27 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef  BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, int len);
size_t	ft_strchr(const char *s);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_memmove(void *dst, const void *src, size_t len);
char	*ft_bzero(char *b, size_t len);
char	*reset_buf(char *buf);
char	*check(char *comp, char *buf);

#endif