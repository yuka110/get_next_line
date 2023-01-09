/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/21 10:04:48 by yitoh         #+#    #+#                 */
/*   Updated: 2023/01/09 14:29:14 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"


int	main(void)
{
	int	fd;
	char	*next_line;

	next_line = "\0";
	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
		printf("file couldn't open\n");
	while (next_line != NULL)
	{
		next_line = get_next_line(fd);
		if (!next_line)
			free (next_line);
		printf("next line is: %s\n", next_line);
		free (next_line);
	}
	close(fd);
}


/*
buffer size = 3
1234567
123
124142322322
2322

stash = null + buf1
stash(buf1) + buf2
stash(buf1 + buf2) + buf3

*/