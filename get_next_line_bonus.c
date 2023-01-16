/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/15 13:23:04 by yitoh         #+#    #+#                 */
/*   Updated: 2023/01/16 07:18:41 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include "get_next_line_bonus.h"

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
		return (free(tmp), free(buf), NULL);
	ft_memmove(tmp, buf + i + 1, new_size);
	return (free(buf), tmp);
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
		if (len <= 0)
		{
			if (buf != NULL)
				free(buf);
			return (NULL);
		}
		buf = ft_strjoin(buf, store);
		if (!buf)
			break ;
		i = ft_strchr(buf);
	}
	return (buf);
}

/*
1. buf = return what is read
2. find position of \n
3. return complete line with substr until \n
4. taking rest and put them back to buf
*/
char	*gnl_original(int fd)
{
	static char	*buf[OPEN_MAX];
	char		*comp;
	int			i;

	i = 0;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buf[fd] = read_me(fd, buf[fd], i);
	if (!buf[fd])
		return (NULL);
	i = ft_strchr(buf[fd]);
	if (i == 0)
		i = ft_strlen(buf[fd]);
	comp = ft_substr(buf[fd], 0, i);
	if (!comp)
	{
		free (buf[fd]);
		buf[fd] = NULL;
		return (NULL);
	}
	buf[fd] = reset_buf(buf[fd]);
	return (comp);
}

char	*get_next_line(int fd)
{
	char	*handler[OPEN_MAX];

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	handler[fd] = gnl_original(fd);
	if (!handler[fd])
		return (NULL);
	return (handler[fd]);
}
