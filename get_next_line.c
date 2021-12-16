/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:22:05 by mriant            #+#    #+#             */
/*   Updated: 2021/12/16 18:17:25 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_free(char *s, char const *s2)
{
	char	*result;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	result = ft_calloc(sizeof(char), (ft_strlen(s) + ft_strlen(s2) + 1));
	if (!result)
	{
		free (s);
		return (NULL);
	}
	while (s && s[i])
	{
		result[i] = s[i];
		i ++;
	}
	while (s2 && s2[j])
	{
		result[i] = s2[j];
		i ++;
		j ++;
	}
	free(s);
	return (result);
}

long int	ft_readline(int fd, char **buf, char **line)
{	
	long int	ret;

	ret = 1;
	while (ret > 0 && !ft_strchr(buf[0], '\n'))
	{
		line[0] = ft_strjoin_free(line[0], buf[0]);
		ret = read (fd, buf[0], BUFFER_SIZE);
		buf[0][ret] = '\0';
	}
	return (ret);
}

void	ft_setline(char **line, char **tail, char *buf)
{
	char	*endline;

	endline = ft_strchr(buf, '\n');
	if (endline)
	{
		free(*tail);
		*tail = ft_substr(buf, 0, endline - buf + 1);
		*line = ft_strjoin_free(*line, *tail);
		free(*tail);
		*tail = ft_strdup(endline + 1);
	}
	else
	{
		*line = ft_strjoin_free(*line, buf);
		free(*tail);
		*tail = NULL;
	}
}

void	ft_clean(char *buf, char *tail, char *line)
{
	free(buf);
	free(tail);
	free(line);
}

char	*get_next_line(int fd)
{
	long int	ret;
	char		*buf;
	static char	*tail[1024];
	char		*line;

	if (fd == -1 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	tail[fd] = ft_strjoin_free(tail[fd], "\0");
	line = ft_strdup(tail[fd]);
	ret = ft_readline(fd, &buf, &line);
	if (ret < 0)
	{
		ft_clean(buf, tail[fd], line);
		return (NULL);
	}
	ft_setline(&line, &tail[fd], buf);
	if (ret == 0 && !tail[fd] && line[0] == '\0')
	{
		free(line);
		line = NULL;
	}
	free(buf);
	return (line);
}

int	main(void)
{
	int		fd1;
	int		fd2;

	fd1 = open("test_file", O_RDONLY);
	fd2 = open("test_file_2", O_RDONLY);
	char	*str = get_next_line(fd1);
	printf("fd1 :%s", str);
	free(str);
	while (str)
	{
		str = get_next_line(0);
		printf("input : %s", str);
		free(str);
		str = get_next_line(fd2);
		printf("fd2 : %s", str);
		free(str);
		str = get_next_line(fd1);
		printf("fd1 : %s", str);
		free (str);
	}
	close (fd1);
	close (fd2);
}
