/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goda-sil <goda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:35:11 by goda-sil          #+#    #+#             */
/*   Updated: 2023/01/05 15:12:38 by goda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t	nmemb, size_t size)
{
	char			*pointer;
	size_t			counter;
	unsigned int	total;

	counter = 0;
	total = nmemb * size;
	pointer = malloc(total);
	if (!pointer)
		return (NULL);
	while (total > 0)
	{
		pointer[counter] = 0;
		total--;
		counter++;
	}
	return ((void *)pointer);
}

char	*ft_strchr(char *s, int c)
{
	int	counter;

	counter = 0;
	if (!s)
		return (NULL);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
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

	counter = 0;
	while (s[counter])
		counter++;
	return (counter);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t		counter_one;
	size_t		counter_two;
	char		*pointer;

	if (!s1)
	{
		s1 = malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	counter_one = -1;
	pointer = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (pointer == NULL)
		return (NULL);
	if (s1)
		while (s1[++counter_one])
			pointer[counter_one] = s1[counter_one];
	counter_two = 0;
	while (ft_strlen(s2) > counter_two)
		pointer[counter_one++] = s2[counter_two++];
	pointer[counter_one] = '\0';
	free(s1);
	return (pointer);
}
