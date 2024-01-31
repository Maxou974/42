/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:04:11 by mabriel           #+#    #+#             */
/*   Updated: 2021/11/22 16:45:42 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dst, \
		const void *restrict src, int c, size_t n)
{
	size_t	i;
	char	*ptr1;
	char	*ptr2;

	i = 0;
	ptr1 = (char *)dst;
	ptr2 = (char *)src;
	while (i < n && ptr2[i] != (char)c)
	{
		ptr1[i] = ptr2[i];
		i++;
	}
	if (i != n && ptr2[i] == (char)c)
	{
		ptr1[i] = ptr2[i];
		return ((void *)&ptr1[i + 1]);
	}
	else
		return (NULL);
}
