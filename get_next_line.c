/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/21 09:47:19 by yitoh         #+#    #+#                 */
/*   Updated: 2023/01/13 14:19:06 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

//fill str with \0 for len bytes
char	*ft_bzero(char *b, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		b[i] = '\0';
		++i;
	}
	return (b);
}

//take char after \n and store them in buf
char	*reset_buf(char *buf)
{
	int		new_size;
	char	*tmp;
	int		i;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	new_size = ft_strlen(buf) - i;
	tmp = malloc((new_size) * sizeof(char));
	if (!tmp || new_size == 0)
	{
		free (tmp);
		free (buf);
		return (NULL);
	}
	ft_memmove(tmp, buf + i + 1, new_size);
	free (buf);
	return (tmp);
}



char	*get_next_line(int fd)
{
	static char	*buf;
	ssize_t		len;
	char		store[BUFFER_SIZE + 1];
	char		*comp;
	int			i;

	i = 0;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	while (i == 0)
	{
		ft_bzero(store, BUFFER_SIZE + 1);
		len = read(fd, store, BUFFER_SIZE);
		if (len == 0 && buf)
		{
			i = ft_strchr(buf);
			if (i == 0)
				i = ft_strlen(buf);
			break ;
		}
		else if (len <= 0)
		{
			free (buf);
			buf = NULL;
			return (NULL);
		}
		else
		{
			buf = ft_strjoin(buf, store);
			if (!buf)
			{
				free (buf);
				buf = NULL;
				return (NULL);
			}
			i = ft_strchr(buf);
		}
	}
	comp = ft_substr(buf, 0, i);
	if (!comp)
	{
		free (buf);
		buf = NULL;
		return (NULL);
	}
	buf = reset_buf(buf);
	return (comp);
}
