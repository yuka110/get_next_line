/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/21 09:47:19 by yitoh         #+#    #+#                 */
/*   Updated: 2023/01/08 17:02:30 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

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

void	reset_buf(char *buf, int i, int j, ssize_t len)
{
	ft_memmove(buf, buf + i, j);
	if (ft_strchr(buf) == 0 && (len != i || len != BUFFER_SIZE))
		ft_bzero(buf + len - 1, BUFFER_SIZE - len);
	else
		ft_bzero(buf + j, BUFFER_SIZE - j);
}

char	*joint_last(char *comp, char *buf, int i)
{
	char		*tiny;

	tiny = ft_substr(buf, 0, i - 1);
	comp = ft_strjoin(comp, tiny);
	if (!comp)
		free (comp);
	free (tiny);
	return (comp);
}

char	*check(char *comp, char *buf)
{
	comp = ft_strjoin(comp, buf);
	if (!comp)
	{
		free (comp);
		return (NULL);
	}
	return (comp);
}

// char	*search_new_line(int fd, char *buf, char *comp, int j)
// {
// 	ssize_t	len;
// 	int		i;

// 	i = 0;
// 	while (i == 0)
// 	{
// 		len = read(fd, buf + j, (BUFFER_SIZE - j));
// 		if (len == 0)
// 			return (NULL);
// 		i = ft_strchr(buf);
// 		if (i == 0)
// 			comp = ft_strjoin(comp, buf);
// 		j = 0;
// 	}
// 	comp = joint_last(comp, buf, i);
// 	return (comp);
// }

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE];
	ssize_t		len;
	int	i;
	static int	j;
	char		*comp;

	comp = NULL;
	if ((int) ft_strlen(buf) < j)
	{
		j = (int) ft_strlen(buf);
		return (check(comp, buf));
	}
	// comp = search_new_line(fd, buf, comp, j);
	i = 0;
	while (i == 0)
	{
		len = read(fd, buf + j, (BUFFER_SIZE - j));
		if (len <= 0)
			return (NULL);
		i = ft_strchr(buf);
		if (i == 0)
		{
			comp = ft_strjoin(comp, buf);
			if (!comp)
				free (comp);
		}
		j = 0;
	}
	comp = joint_last(comp, buf, i);
	j = BUFFER_SIZE - i;
	reset_buf (buf, i, j, len);
	return (comp);
}
