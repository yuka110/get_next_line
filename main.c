/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/21 10:04:48 by yitoh         #+#    #+#                 */
/*   Updated: 2023/01/08 16:49:35 by yitoh         ########   odam.nl         */
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
