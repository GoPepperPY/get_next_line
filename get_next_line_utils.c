/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goda-sil <goda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:35:11 by goda-sil          #+#    #+#             */
/*   Updated: 2022/12/04 16:58:25 by goda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void    *ft_calloc(size_t       nmemb, size_t size)
{
	void    *pointer;

	pointer = malloc(nmemb * size);
	if (pointer == NULL)
		return (pointer);
	ft_bzero(pointer, size * nmemb);
	return (pointer);
}

char	*ft_strchr(const char *s, int c)
{
	char	*temporary;
 	int	counter;

	counter = 0;
 	temporary = (char *)s;
 	while (s[counter] != c)
	{
		if (s[counter] == '\0')
			return (NULL);
		temporary++;
		counter++;
	}
	return (temporary);
}

size_t ft_strlen(const char *s)
{
	size_t	counter;
	while (s[counter])
		counter++;
	return (counter);
}
