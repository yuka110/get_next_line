/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/21 09:47:19 by yitoh         #+#    #+#                 */
/*   Updated: 2023/01/14 13:20:14 by yitoh         ########   odam.nl         */
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

//free buffer
char	*free_buf(char *ptr)
{
	free (ptr);
	ptr = NULL;
	return (ptr);
}

//read the file and join char until \n is found
char	*read_me(int fd, char *buf, int i)
{
	char		store[BUFFER_SIZE + 1];
	ssize_t		len;

	len = 1;
	while (i == 0 && len != 0)
	{
		ft_bzero(store, BUFFER_SIZE + 1);
		len = read(fd, store, BUFFER_SIZE);
		if (len == 0 && buf)
			return (buf);
		else if (len <= 0)
		{
			buf = free_buf(buf);
			return (buf);
		}
		else
		{
			buf = ft_strjoin(buf, store);
			if (!buf)
				break ;
			i = ft_strchr(buf);
		}
	}
	return (buf);
}

/*
1. buf = return what is read
2. find position of \n
3. return complete line with substr until \n
4. taking rest and put them back to buf
*/
char	*get_next_line(int fd)
{
	static char	*buf;
	char		*comp;
	int			i;

	i = 0;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buf = read_me(fd, buf, i);
	if (!buf)
	{
		buf = free_buf(buf);
		return (NULL);
	}
	i = ft_strchr(buf);
	if (i == 0)
		i = ft_strlen(buf);
	comp = ft_substr(buf, 0, i);
	if (!comp)
	{
		buf = free_buf(buf);
		return (NULL);
	}
	buf = reset_buf(buf);
	return (comp);
}
