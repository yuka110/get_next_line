/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/21 09:47:19 by yitoh         #+#    #+#                 */
/*   Updated: 2022/12/22 16:41:11 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"


// char	*more_chr(char	*pre, char *buf)
// {
// 	char	*extra;
// 	char	*joint;

// 	extra = ft_substr(buf, 0, BUFFER_SIZE);
// 	joint = ft_strjoin(pre, extra);
// 	return (joint);
// }


char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE];
	ssize_t		len;
	int			i;
	char		*comp;
	char		*tiny;

	i = 0;
	comp = malloc (sizeof(char) * BUFFER_SIZE);
		if (!comp)
			free(comp);
	while (i == 0)
	{
		len = read(fd, buf, BUFFER_SIZE);
		if (len == 0)
			return (0);
		i = ft_strchr(buf);
		printf("len = %zu, i = %d, buf = %s\n", len, i, buf);
		if (i == 0)
			comp = ft_strjoin(comp, buf);
	}
	tiny = ft_substr(buf, 0, i);
	comp = ft_strjoin(comp, tiny);
	printf("comp = %s\n", comp);
	return (comp);
}


int	main(void)
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
		printf("file couldn't open\n");
	//while ()
	//{
	printf("next line is: %s\n", get_next_line(fd));
	//}
	close(fd);
}

	// comp = malloc(sizeof(char) * (i + 1));
	// if (!comp)
	// 	free (comp);
	
	// 	while (i == 0)
	// 	{
	// 		extra = ft_substr(buf, 0, BUFFER_SIZE);
	// 	}
	// 	else
	// 	{
	// 		comp = substr(buf, 0, i);
	// 		if (i != BUFFER_SIZE)
	// 			extra = substr(buf, i, BUFFER_SIZE - i);
	// 	}
	// 	if (extra)
		
	// }
	// return (comp);

/*
static 
read

read until BUFFER_SIZE or find '\n'
-> read return num of bytes read

if len < BUFFER_size, len = line_len
else repeat read + copy



*/

/*
hello\n
there


buf = store what is read

rem = remainder
comp = completed one line


while you read BUFFER_SIZE, 
1. str with \n
2. str without \n
look for '\n'
-> ft_strchr(buf, '\n')

1. BUFFER_SIZE = 7
//buf = hello\nt
i = ft_strchr(buf, '\n')
comp = substr(buf, 0, i)
if (i != BUFFER_SIZE)
	extra = substr(buf, i, BUFFER_SIZE - i)
	//extra = "t";
	read next buffer_size
	buf = here\0




2. BUFFER_SIZE = 2
buf = he
while (!ft_strchr(buf, '\n'))
{
	char	*extra[BUFFER_SIZE];
	extra = ft_substr(buf, 0, BUFFER_SIZE);
	//extra = "he"
	read next buffer_size
	//buf = "ll"
	
	
}


buf = lo\n
comp = ft_strjoin(buf1, buf)




*/
