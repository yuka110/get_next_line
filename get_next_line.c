/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/21 09:47:19 by yitoh         #+#    #+#                 */
/*   Updated: 2022/12/30 13:21:56 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

/*
1. where to split function??
*/

char	*ft_bzero(char *b, size_t len)
{
	size_t			i;

	i = 0;
	while (i < len)
	{
		b[i] = '\0';
		++i;
	}
	return (b);
}


// char	*reset_buf(char *buf, int i)
// {
// 	int	tmp;

// 	tmp = BUFFER_SIZE - i;
// 	ft_memmove(buf, buf + i, tmp);
// 	ft_bzero(buf + tmp, BUFFER_SIZE - tmp);
// 	return (buf);
// }

// char	*search_new_line(int fd, char *comp)
// {
// 	static char	buf[BUFFER_SIZE];
// 	ssize_t		len;
// 	char		*tiny;
// 	int			i;
// 	int			j;

// 	i = 0;
// 	ft_bzero(comp, BUFFER_SIZE);
// 	while (i == 0)
// 	{
// 		len = read(fd, buf + j, (BUFFER_SIZE - j));
// 		if (len == 0)
// 			return (0);
// 		i = ft_strchr(buf);
// 		if (i == 0)
// 			comp = ft_strjoin(comp, buf);
// 		j = 0;
// 	}
// 	tiny = ft_substr(buf, 0, i - 1);
// 	comp = ft_strjoin(comp, tiny);
// 	free (tiny);
// 	j = BUFFER_SIZE - i;

// 	return (comp);
// }

// char	*get_next_line(int fd)
// {
// 	static char	buf[BUFFER_SIZE];
// 	int			i;
// 	static int	j;
// 	int			tmp;
// 	char		*comp;

// 	i = 0;
// 	comp = malloc (sizeof(char) * BUFFER_SIZE);
// 	if (!comp)
// 		free(comp);
// 	comp = search_new_line(fd, buf, j, comp);
// 	printf("final = %s, buf = %s, j = %d\n --------------\n", comp, buf, j);
// 	return (comp);
// }

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE];
	ssize_t		len;
	int			i;
	static int	j;
	// int			tmp;
	char		*comp;
	char		*tiny;

	i = 0;
	comp = malloc (sizeof(char) * BUFFER_SIZE);
	if (!comp)
		free(comp);
	ft_bzero(comp, BUFFER_SIZE);
	while (i == 0)
	{
		len = read(fd, buf + j, (BUFFER_SIZE - j));
		if (len == 0)
			return (0);
		i = ft_strchr(buf);
		if (i == 0)
			comp = ft_strjoin(comp, buf);
		j = 0;
	}
	tiny = ft_substr(buf, 0, i - 1);
	comp = ft_strjoin(comp, tiny);
	free (tiny);
	j = BUFFER_SIZE - i;
	// tmp = BUFFER_SIZE - i;
	ft_memmove(buf, buf + i, j);
	ft_bzero(buf + j, BUFFER_SIZE - j);
	return (comp);
}
