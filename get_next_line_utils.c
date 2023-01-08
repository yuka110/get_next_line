/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/21 09:47:29 by yitoh         #+#    #+#                 */
/*   Updated: 2023/01/08 13:52:21 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t		i;

	i = 0;
	while (s[i] != '\0')
		++i;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, int len)
{
	char	*arr;
	int		i;

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
size_t	ft_strchr(const char *s)
{
	size_t	i;

	i = 1;
	while (i - 1 < BUFFER_SIZE && s)
	{
		if (s[i - 1] == '\n' || s[i - 1] == '\0')
			return (i);
		++i;
	}
	return (0);
}

// create new str by connecting s1 and s2
char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*arr;
	size_t		prelen;
	size_t		suflen;

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
		ft_bzero(arr, prelen + suflen + 1);
		if (!arr)
			return (NULL);
		ft_memmove(arr, s1, prelen);
		ft_memmove(arr + prelen, s2, suflen);
	}
	return (arr);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int			i;
	int			j;
	char		*arr1;
	const char	*arr2;

	i = 0;
	j = i;
	arr1 = (char *)dst;
	arr2 = (const char *)src;
	if (!arr1 && !arr2)
		return (NULL);
	if (dst > src)
	{
		i = len - 1;
		j = i;
		while (i >= 0 && j >= 0)
			arr1[i--] = arr2[j--];
	}
	else
	{
		while (i < (int) len && j < (int) len)
			arr1[i++] = arr2[j++];
	}
	return (dst);
}

// void	*ft_calloc(size_t count)
// {
// 	char	*p;
// 	size_t	i;

// 	i = 0;
// 	p = malloc(count * BUFFER_SIZE);
// 	if (p == NULL)
// 		return (NULL);
// 	while (i < count)
// 	{
// 		p[i] = '\0';
// 		++i;
// 	}
// 	return (p);
// }
