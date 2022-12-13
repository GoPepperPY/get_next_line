/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goda-sil <goda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:35:11 by goda-sil          #+#    #+#             */
/*   Updated: 2022/12/13 16:14:43 by goda-sil         ###   ########.fr       */
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

size_t	ft_strlen(const char *s)
{
	size_t	counter;
	while (s[counter])
		counter++;
	return (counter);
}

void	ft_bzero(void *s, size_t n)
{
	size_t  counter;

	 counter = 0;
	while (counter < n)
		((unsigned char *)s)[counter++] = '\0';
}

char    *ft_strjoin(char const *s1, char const *s2)
{
        unsigned int    counter_one;
        unsigned int    counter_two;
        char                    *pointer;

        counter_one = 0;
        if (!s1 || !s2)
                return (NULL);
        pointer = malloc((ft_strlen(s1) + ft_strlen(s2)) + 1 * sizeof(char));
        if (pointer == NULL)
                return (NULL);
        while (s1[counter_one])
        {
                pointer[counter_one] = s1[counter_one];
                counter_one++;
        }
        counter_two = 0;
        while (s2[counter_two])
        {
                pointer[counter_one] = s2[counter_two];
                counter_one++;
                counter_two++;
        }
        pointer[counter_one] = '\0';
        return (pointer);
}

