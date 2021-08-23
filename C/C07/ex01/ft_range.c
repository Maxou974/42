/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 13:13:35 by mabriel           #+#    #+#             */
/*   Updated: 2021/08/23 16:46:59 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int				*dest;
	unsigned int	i;
	unsigned int	size;

	i = 0;
	if (min >= max)
		return (NULL);
	size = max - min;
	dest = malloc(sizeof(int) * size);
	if (!dest)
		return (NULL);
	while (i < size)
	{
		dest[i] = min + i;
		i++;
	}
	return (dest);
}
