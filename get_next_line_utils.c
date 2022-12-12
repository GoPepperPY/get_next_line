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

char	*ft_strncpy(char* destiny, const char *source, size_t size)
{
	int	counter;

	counter = 0;
	while (source[counter] && size > counter)
	{
		destiny[counter] = source[counter];
		counter++;
	}
	destiny[counter] = '\0';
	return (destiny);
}
