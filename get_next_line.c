/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:22:05 by mriant            #+#    #+#             */
/*   Updated: 2021/12/09 17:02:33 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> //NULL malloc free
#include <sys/types.h> // open read
#include <sys/uio.h> // read
#include <unistd.h> // read
#include <stdio.h> // printf
#include <sys/stat.h> // open
#include <fcntl.h> // open

char	*get_next_line(int fd)
{
	int		ret;
	char	*buf;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (fd == -1)
		return (NULL);
	ret = read (fd, buf, BUFFER_SIZE);
	buf[ret] = '\0';
	return (buf);
}

int main()
{
	char	*str;
	int		fd;

	fd = open("/Users/mriant/Get_next_line/test_file", O_RDONLY);
	if (fd == -1)
		return (0);
	str = get_next_line(fd);
	printf("%s", str);
}
