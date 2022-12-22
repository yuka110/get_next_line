/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/21 10:04:48 by yitoh         #+#    #+#                 */
/*   Updated: 2022/12/22 13:46:16 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"


// char	*ft_readfile(int fd)
// {
// 	int			fd;
// 	int			count;
// 	static char	buf[10];

// 	count = 1;
// 	fd = open("/test.txt", O_RDONLY);
// 	if (fd < 0)
// 		return (0);
// 	while (count = read(fd, buf, 9) > 0)
// 	{
// 		buf[count]
// 	}
// 	if (check < 0)
// 		return (0);
// 	close(fd);
// 	return
// }

int	main(void)
{
	int	fd;

	fd = open("/test.txt", O_RDONLY);
	if (fd < 0)
		printf("file couldn't open\n");
	//while ()
	//{
		printf("%s\n", get_next_line(fd));
	//}
	close(fd);
}
