/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 15:32:22 by mabriel           #+#    #+#             */
/*   Updated: 2021/08/17 14:49:48 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*dest;
	int	i;

	i = 0;
	max = max - min;
	if (max <= 0)
		return (NULL);
	else
		dest = malloc(sizeof(int) * (max + 1));
	while (i < max)
	{
		dest[i] = min;
		min++;
		i++;
	}
	return (dest);
}
