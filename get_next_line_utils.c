/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/21 09:47:29 by yitoh         #+#    #+#                 */
/*   Updated: 2023/01/13 14:02:51 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		++i;
	return (i);
}

char	*ft_substr(char const *s, int start, int len)
{
	char	*arr;
	int		i;

	if (!s || len - start == 0)
		return (NULL);
	if (start >= ft_strlen(s))
		len = 0;
	if (len > (int) ft_strlen(s))
		len = (int) ft_strlen(s);
	arr = (char *)malloc((len + 1) * sizeof(char));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < len && s[start] != '\0')
	{
		arr[i] = s[start];
		++i;
		++start;
	}
	arr[i] = '\0';
	return (arr);
}

//find character c in string s and return index
// if s[0] == /n or \0, return 1
int	ft_strchr(const char *s)
{
	int	i;
	int	strlen;

	i = 1;
	strlen = ft_strlen(s);
	while (i - 1 < strlen && s)
	{
		if (s[i - 1] == '\n' || s[i - 1] == '\0')
			return (i);
		++i;
	}
	return (0);
}

// create new str by connecting s1 and s2
char	*ft_strjoin(char *s1, char *s2)
{
	char	*arr;
	int		prelen;
	int		suflen;

	suflen = ft_strlen(s2);
	if (!s1)
	{
		arr = ft_substr(s2, 0, suflen);
		if (!arr)
			return (NULL);
	}
	else
	{
		prelen = ft_strlen(s1);
		arr = malloc((prelen + suflen + 1) * sizeof(char));
		if (!arr)
			return (NULL);
		ft_bzero(arr, prelen + suflen + 1);
		ft_memmove(arr, s1, prelen);
		ft_memmove(arr + prelen, s2, suflen);
	}
	free (s1);
	return (arr);
}

//copy src to dst for len bytes
void	*ft_memmove(char *dst, char *src, int len)
{
	int			i;
	int			j;

	i = 0;
	j = i;
	if ((!dst && !src) || len == 0)
		return (NULL);
	if (dst > src)
	{
		i = len - 1;
		j = i;
		while (i >= 0 && j >= 0)
			dst[i--] = src[j--];
	}
	else
	{
		while (i < (int) len && j < (int) len)
			dst[i++] = src[j++];
	}
	return (dst);
}
