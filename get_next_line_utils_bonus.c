/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goda-sil <goda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:49:46 by goda-sil          #+#    #+#             */
/*   Updated: 2023/01/04 16:46:11 by goda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_calloc(size_t	nmemb, size_t size)
{
	void	*pointer;

	pointer = malloc(nmemb * size);
	if (pointer == NULL)
		return (pointer);
	ft_bzero(pointer, size * nmemb);
	return (pointer);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	counter;

	counter = 0;
	if (!s)
		return (NULL);
	while (s[counter] != c)
	{
		if (s[counter] == '\0')
			return (NULL);
		counter++;
	}
	return ((char *)s + counter);
}

size_t	ft_strlen(char *s)
{
	size_t	counter;

	if (!s)
		return (0);
	counter = 0;
	while (*(s + counter) && s)
		counter++;
	return (counter);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	counter;

	counter = 0;
	while (counter < n)
		((unsigned char *)s)[counter++] = '\0';
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t		counter_one;
	size_t		counter_two;
	char		*pointer;
	size_t		limit;

	if (!s1)
		s1 = calloc(1, 1);
	if (!s1 || !s2)
		return (NULL);
	counter_one = -1;
	pointer = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!pointer)
		return (NULL);
	if (s1)
		while (s1[++counter_one] != '\0')
			pointer[counter_one] = s1[counter_one];
	counter_two = 0;
	limit = ft_strlen(s2);
	while (limit > counter_two)
		pointer[counter_one++] = s2[counter_two++];
	pointer[counter_one] = '\0';
	free(s1);
	return (pointer);
}
