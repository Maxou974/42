/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 14:50:53 by mabriel           #+#    #+#             */
/*   Updated: 2021/08/17 15:56:42 by mabriel          ###   ########.fr       */
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

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;

	i = 0;
	*range = ft_range(min, max);
	while (*range[i] != '\0')
		i++;
	if (*range == NULL)
		return (0);
	if (i > 0)
		return (i);
	else
		return (-1);
}

int main()
{
	int **range;
	int i = 0;

	ft_ultimate_range(range, 5, 10);

	printf("%d", range[0][0]);
}
