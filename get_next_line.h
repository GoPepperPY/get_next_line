/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goda-sil <goda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:35:32 by goda-sil          #+#    #+#             */
/*   Updated: 2023/01/05 15:04:25 by goda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <strings.h>
# include <stddef.h>
# include <ctype.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

// Utils
char	*ft_strchr(char *s, int c);
void	*ft_calloc(size_t	nmemb, size_t size);
size_t	ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);

// main file
char	*read_file(int fd, char *storage);
char	*clear(char *storage);
char	*stash(char *storage);
char	*get_next_line(int fd);

#endif
