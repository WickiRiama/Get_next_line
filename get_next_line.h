/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 10:33:21 by mriant            #+#    #+#             */
/*   Updated: 2021/12/13 11:48:48 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

 #include <stdlib.h> //NULL malloc free
 #include <sys/types.h> // open read
 #include <sys/uio.h> // read
 #include <unistd.h> // read
 #include <stdio.h> // printf
 #include <sys/stat.h> // open
 #include <fcntl.h> // open

 size_t	ft_strlen(const char *s);
 void	ft_bzero(void *s, size_t n);
 void	*ft_calloc(size_t count, size_t size);
 char	*ft_strchr(const char *s, int c);
 char	*ft_strjoin(char const *s, char const *s2);
 char    *ft_substr(char const *s, unsigned int start, size_t len);

#endif
