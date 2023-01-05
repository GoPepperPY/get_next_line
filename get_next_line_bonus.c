/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goda-sil <goda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:49:25 by goda-sil          #+#    #+#             */
/*   Updated: 2023/01/05 16:56:03 by goda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

// fd(file descriptor) - abstract indicator to indicate a file
// storage - it's where will store our temporary data
// when read returns 0 means that there is not more data

char	*read_file(int fd, char	*storage)
{
	char	*temporary;
	int		read_bytes;

	if (ft_strchr(storage, '\n'))
		return (storage);
	read_bytes = 1;
	temporary = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	while (!ft_strchr(storage, '\n') && read_bytes > 0)
	{
		read_bytes = read(fd, temporary, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(temporary);
			return (NULL);
		}
		storage = ft_strjoin(storage, temporary);
	}
	free(temporary);
	return (storage);
}

char	*clear(char *storage)
{
	int		counter;
	char	*line;

	counter = 0;
	if (!storage[counter])
		return (NULL);
	while (storage[counter] && storage[counter] != '\n')
		counter++;
	line = ft_calloc((counter + 2), sizeof(char));
	counter = 0;
	while (storage[counter] && storage[counter] != '\n')
	{
		line[counter] = storage[counter];
		counter++;
	}
	line[counter] = storage[counter];
	return (line);
}

char	*stash(char *storage)
{
	int		counter_one;
	int		counter_two;
	char	*string;

	counter_one = 0;
	while (storage[counter_one] && storage[counter_one] != '\n')
		counter_one++;
	if (!storage[counter_one])
	{
		free(storage);
		return (NULL);
	}
	string = ft_calloc((ft_strlen(storage) - counter_one + 1), sizeof(char));
	counter_one++;
	counter_two = 0;
	while (storage[counter_one])
		string[counter_two++] = storage[counter_one++];
	free(storage);
	return (string);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*storage[FOPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FOPEN_MAX)
		return (0);
	storage[fd] = read_file(fd, storage[fd]);
	if (!storage[fd])
		return (NULL);
	line = clear(storage[fd]);
	storage[fd] = stash(storage[fd]);
	return (line);
}

/*int     main(void)
{
        int             fd1;
	int		fd2;
        int             i;
        char    *line1;
   	char	*line2;

        fd1 = open("test/test.txt", O_RDONLY);
        fd2 = open("test/test2.txt", O_RDONLY);
        i = 1;
        while (i <= 30)
        {
		line1 = get_next_line(fd1);
	 	printf("line [%02d]: %s", i, line1);
		free(line1);
		line2 = get_next_line(fd2);
		printf("line [%02d]: %s", i, line2);
		free(line2);
		i++;
        }
        close(fd1);
  	close(fd2);
        return (0);
}

*/
