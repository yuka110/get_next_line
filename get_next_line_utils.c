/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/21 09:47:29 by yitoh         #+#    #+#                 */
/*   Updated: 2022/12/22 15:54:57 by yitoh         ########   odam.nl         */
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*arr;
	size_t	i;

	if (start >= ft_strlen(s))
		len = 0;
	if (len > ft_strlen(s))
		len = ft_strlen(s);
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
size_t	ft_strchr(const char *s)
{
	size_t	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (s[i] == '\n')
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
	size_t		i;
	size_t		j;

	prelen = ft_strlen(s1);
	suflen = ft_strlen(s2);
	i = 0;
	j = 0;
	arr = malloc((prelen + suflen + 1) * sizeof(char));
	if (!arr)
		return (NULL);
	while (i < prelen)
	{
		arr[i] = s1[i];
		++i;
	}
	while (i + j < prelen + suflen)
	{
		arr[i + j] = s2[j];
		++j;
	}
	arr[i + j] = '\0';
	return (arr);
}
