/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/21 10:04:48 by yitoh         #+#    #+#                 */
/*   Updated: 2023/01/15 17:30:53 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"
#include "get_next_line_bonus.h"

// int	main(void)
// {
// 	int		fd;
// 	char	*next_line;

// 	next_line = "\0";
// 	fd = open("test.txt", O_RDONLY);
// 	if (fd < 0)
// 		printf("file couldn't open\n");
// 	while (next_line != NULL)
// 	{
// 		next_line = get_next_line(fd);
// 		if (!next_line)
// 			free (next_line);
// 		printf("next line is: %s", next_line);
// 		free (next_line);
// 	}
// 	close(fd);
// }

int	main(void)
{
	int		fd1;
	int		fd2;
	int		fd3;
	char	*next_line;

	next_line = "\0";
	fd1 = open("test.txt", O_RDONLY);
	fd2 = open("test1.txt", O_RDONLY);
	fd3 = open("test2.txt", O_RDONLY);
	if (fd1 < 0)
		printf("file 1 couldn't open\n");
	if (fd2 < 0)
		printf("file 2 couldn't open\n");
	if (fd3 < 0)
		printf("file 3 couldn't open\n");
	while (next_line != NULL)
	{
		next_line = get_next_line(fd1);
		if (!next_line)
			free (next_line);
		printf("next line 1 is: %s", next_line);
		free (next_line);
		next_line = get_next_line(fd2);
		if (!next_line)
			free (next_line);
		printf("next line 2 is: %s", next_line);
		free (next_line);
		next_line = get_next_line(fd3);
		if (!next_line)
			free (next_line);
		printf("next line 3 is: %s", next_line);
		free (next_line);
	}
	close(fd1);
	close(fd2);
	close(fd3);
}
