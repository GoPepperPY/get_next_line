/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goda-sil <goda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:34:47 by goda-sil          #+#    #+#             */
/*   Updated: 2022/12/12 17:06:51 by goda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// fd(file descriptor) - abstract indicator to indicate a file
// storage - it's where will store our temporary data

static char	*storage;

char    *get_next_line(int fd)
{
	int	bytes_readed;
	char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	
	return (*line);
}

int	main(void)
{
	int		file_descriptor;
	int		counter;
	char	*line;

	file_descriptor = open("test.txt", O_RDONLY);
	counter = 1;
	while ((line = get_next_line(file_descriptor)))
	{
		printf("line[%02d]: %s", counter, line);
		counter++;
	}
	close(file_descriptor);
	return (0);
}
