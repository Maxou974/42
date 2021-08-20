/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 14:50:53 by mabriel           #+#    #+#             */
/*   Updated: 2021/08/19 22:01:21 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;

	i = 0;
	max = max - min;
	if (max < 0)
	{
		*range = NULL;
		return (0);
	}
	*range = malloc(sizeof(int) * max);
	if (!(*range))
		return (-1);
	while (i < max)
	{
		(*range)[i] = min;
		min++;
		i++;
	}
	return (max);
}
