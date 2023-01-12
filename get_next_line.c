/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/21 09:47:19 by yitoh         #+#    #+#                 */
/*   Updated: 2023/01/12 16:16:04 by yitoh         ########   odam.nl         */
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
		b[i]= '\0';
		++i;
	}
	return (b);
}

char	*reset_buf(char *buf)
{
	int		new_size;
	char	*tmp;
	int		i;

	i = 0;
	while (buf[i] != '\n')
		i++;
	new_size = ft_strlen(buf) - i;
	tmp = malloc ((new_size + 1) * sizeof(char));
	ft_memmove(tmp, buf + i, new_size);
	tmp[new_size] = '\0';
	free (buf);
	return (tmp);
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



char	*get_next_line(int fd)
{
	static char	*buf;
	ssize_t		len;
	char		store[BUFFER_SIZE + 1];
	char		*comp;
	int			i;

	if (!buf)
		buf = NULL;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	i = 0;
	while (i == 0)
	{
		//printf("test\n");
		len = read(fd, store, BUFFER_SIZE);
		if (len <= 0)
			return (NULL);
		buf = ft_strjoin(buf, store);
		//printf("store = %s, buf = %s\n", store, buf);
		i = ft_strchr(buf);
	}
	comp = ft_substr(buf, 0, i);
	if (!comp)
	{
		free (buf);
		return (NULL);
	}
	printf("buf before = %s\n", buf);
	buf = reset_buf(buf);
	printf("buf = %s\n", buf);
	return (comp);
}
// 	if (check != 0)
// 	{
// 		ft_memmove(buf, rest, BUFFER_SIZE);
// 		printf("buf after reset = %s\n", buf);
// 		check = ft_strchr(buf);
// 		printf("-----------\ncheck = %d\n", check);
// 		if (check != 0)
// 		{
// 			comp = ft_substr(buf, 0, check);
// 			ft_memmove(rest, buf + check, BUFFER_SIZE - check);
// 			ft_bzero(rest + check, BUFFER_SIZE - check);
// 			printf("-----------\nrest = %s, check = %d\n", rest, check);
// 			return (comp);
// 		}
// 		else
// 			next = ft_substr(buf, 0, BUFFER_SIZE);
// 	}
// 	while (check == 0)
// 	{
// 		len = read(fd, buf, BUFFER_SIZE);
// 		if (len <= 0)
// 			return (NULL);
// 		printf("buf after read = %s\n", buf);
// 		next = ft_strjoin(next, buf);
// 		if (!next)
// 			free (next);
// 		check = ft_strchr(next);
// 		printf("next = %s, check = %d\n", next, check);
// 	}
// 	comp = ft_substr(next, 0, check - 1);
// 	if (!comp)
// 		free (comp);
// 	//printf("comp = %s\n", comp);
// 	// printf("-----------\ncheck = %d\n", check);
// 	ft_memmove(rest, next + check, BUFFER_SIZE - check);
// 	ft_bzero(rest + check, BUFFER_SIZE - check);
// 	//check = ft_strlen(rest);
// 	printf("-----------\nrest = %s, check = %d\n", rest, check);
// 	//printf("buf = %s, rest = %s, check = %d\n", buf, rest, check);
// 	free (next);
// 	return (comp);
// }
// char	*get_next_line(int fd)
// {
// 	static char	buf[BUFFER_SIZE];
// 	ssize_t		len;
// 	int	i;
// 	static int	j;
// 	char		*next;
// 	char		*comp;

// 	next = NULL;
// 	i = 0;
// 	if (BUFFER_SIZE <= 0 || fd < 0)
// 		return (NULL);
// 	while (i == 0)
// 	{
// 		len = read(fd, buf + j, (BUFFER_SIZE - j));
// 		if (len == 0 && next != NULL)
// 		{
// 			comp = ft_substr(next, 0, ft_strlen(next));
// 			if (!comp)
// 				return (NULL);
// 			free (next);
// 			return (comp);
// 		}
// 		if (len <= 0)
// 			return (NULL);
// 		next = ft_strjoin(next, buf);
// 		if (!next)
// 			free (next);
// 		i = ft_strchr(next);
// 		if (i != 0)
// 			break ;
// 		j = 0;
// 	}
// 	comp = ft_substr(next, 0, i - 1);
// 	if (!comp)
// 	{
// 		free (next);
// 		return (NULL);
// 	}
// 	j = ft_strlen(next) - (size_t)i;
// 	ft_memmove(buf, next + i, j);
// 	ft_bzero(buf + j, BUFFER_SIZE - j);
// 	free (next);
// 	return (comp);
// }


/*

if there's rest
	store rest to tmp
	look for \n in tmp
	
	if no \n
		store tmp to next
	if \n
		store chars before \n to next
		store rest to tmp
		return next

read (fd, buf, BUFFER_SIZE)
next = ft_strjoin (next, buf)
if (!next)
	free (next)
i = strchr (next)

if no \n
	repeat read, joint, search \n
if there's \n
	comp = ft_substr(next, 0, i);
	rest = ft_substr(next, i, ft_strlen(next) - i)
	free (next)
ft_find_nl (look for \n)
= 1 found
= 0 not found 
= -1 allocation failed
*/