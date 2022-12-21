/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/21 09:47:29 by yitoh         #+#    #+#                 */
/*   Updated: 2022/12/21 16:51:59 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"
//maybe not needed
char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	if (len != 0)
	{
		while (i < len - 1 && src[i] != '\0')
		{
			dst[i] = src[i];
			++i;
		}
		dst[i] = '\0';
	}
	return (dst);
}

//find character c in string s and return index
size_t	ft_strchr(const char *s, int c)
{
	char	a;
	size_t	i;

	a = (char) c;
	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (s[i] == a)
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
	arr = malloc((prelen + suflen + 1) * sizeof(char));
	i = 0;
	j = 0;
	if (arr == NULL)
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
