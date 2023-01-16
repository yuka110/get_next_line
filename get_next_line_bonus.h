/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.h                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/15 13:22:18 by yitoh         #+#    #+#                 */
/*   Updated: 2023/01/16 07:25:41 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef  BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
// # define __FD_SETSIZE OPEN_MAX
// # ifndef  OPEN_MAX
// #  define OPEN_MAX 1024
// # endif

char	*get_next_line(int fd);
char	*gnl_original(int fd);
int		ft_strlen(const char *s);
char	*ft_substr(char const *s, int start, int len);
int		ft_strchr(const char *s);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_memmove(char *dst, char *src, int len);
char	*ft_bzero(char *b, int len);
char	*read_me(int fd, char *buf, int i);
char	*reset_buf(char *buf);

#endif