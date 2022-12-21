/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/21 10:04:48 by yitoh         #+#    #+#                 */
/*   Updated: 2022/12/21 13:56:51 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	int	fd;

	fd = open("/test.txt", O_RDONLY);
	if (fd < 0)
		return (0);
	while ()
	{
		printf("%s\n", get_next_line(fd));
	}
	close(fd);
}